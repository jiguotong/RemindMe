#include "Mainwindow.h"
#include <QDebug>
#include <QCheckBox>
#include <QMessageBox>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTimer>
#include <QDateTime>
#include <QTime>
#include <QPropertyAnimation>
#include <QMovie>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardPaths>
#include "DlgTasks.h"
#include "DlgClocks.h"
#include "MyDialog.h"

Mainwindow::Mainwindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    initWindow();
    initCheckBox();
    initConnect();
    initTable();
    loadData();
}

Mainwindow::~Mainwindow()
{
    for (auto& c : m_clockVec) killTimer(c.timerId);
}

void Mainwindow::initWindow()
{
    setWindowIcon(QIcon(":/res/windowIcon.png"));
    setWindowTitle("RemindMe");

    ui.btnAdd->setShortcut(tr("Ctrl+Q"));
    ui.btnDel->setShortcut(tr("Ctrl+W"));
    ui.btnAddClock->setShortcut(tr("Ctrl+E"));
    ui.btnDelClock->setShortcut(tr("Ctrl+R"));

    QMovie *movie = new QMovie(":/res/panda.gif", QByteArray(), this);
    ui.labelImage->setMovie(movie);
    movie->start();
    ui.labelImage->show();

    m_soundEffect = new QSoundEffect(this);
    m_soundEffect->setSource(QUrl::fromLocalFile(":/res/Alarm01.wav"));
    m_soundEffect->setLoopCount(QSoundEffect::Infinite);
    m_soundEffect->setVolume(0.25f);

    m_tray = new QSystemTrayIcon(this);
    m_tray->setIcon(QIcon(":/res/windowIcon.png"));
    m_tray->setToolTip(QStringLiteral("RemindMe"));
    m_tray->show();

    // Tray right-click menu
    QMenu* trayMenu = new QMenu(this);
    QAction* actionOpen = trayMenu->addAction("Open RemindMe");
    m_actionMute = trayMenu->addAction("Mute");
    QAction* actionQuit = trayMenu->addAction("Quit");
    m_tray->setContextMenu(trayMenu);
    connect(actionOpen, &QAction::triggered, this, &QWidget::showNormal);
    connect(m_actionMute, &QAction::triggered, this, [this]() {
        soundSwitch = !soundSwitch;
        m_actionMute->setText(soundSwitch ? "Mute" : "Unmute");
        QIcon icon(soundSwitch ? ":/res/switch_on.png" : ":/res/switch_off.png");
        ui.btnSwitch->setIcon(icon);
    });
    connect(actionQuit, &QAction::triggered, this, [this]() { isClosed = true; close(); });

    ui.frameSettings->hide();

    p_timeUpdate = new QTimer(this);
    p_timeUpdate->start(1000);
}

void Mainwindow::initConnect()
{
    connect(ui.btnAdd,      &QPushButton::clicked, this, &Mainwindow::onBtnAddTaskClicked);
    connect(ui.btnDel,      &QPushButton::clicked, this, &Mainwindow::onBtnDelTaskClicked);
    connect(ui.btnAddClock, &QPushButton::clicked, this, &Mainwindow::onBtnAddClockClicked);
    connect(ui.btnDelClock, &QPushButton::clicked, this, &Mainwindow::onBtnDelClockClicked);
    connect(p_timeUpdate,   &QTimer::timeout,      this, &Mainwindow::slotTimerUpdate);
    connect(m_tray, &QSystemTrayIcon::activated, this, &Mainwindow::onActivatedSysTrayIcon);
    connect(ui.btnClear,    &QPushButton::clicked, this, &Mainwindow::ClearAll);
    connect(ui.btnSwitch,   &QPushButton::clicked, this, &Mainwindow::onBtnSwitchClicked);
    connect(ui.btnShowSettings, &QPushButton::clicked, this, &Mainwindow::ShowSettings);
    connect(ui.btnHideSettings, &QPushButton::clicked, this, &Mainwindow::HideSettings);

    // Always-on-top toggle
    connect(ui.btnAlwaysOnTop, &QPushButton::clicked, this, [this]() {
        m_alwaysOnTop = !m_alwaysOnTop;
        Qt::WindowFlags flags = windowFlags();
        if (m_alwaysOnTop) flags |= Qt::WindowStaysOnTopHint;
        else               flags &= ~Qt::WindowStaysOnTopHint;
        setWindowFlags(flags);
        show();
        ui.btnAlwaysOnTop->setText(m_alwaysOnTop ? "On Top: ON" : "Always On Top");
    });

    // Opacity slider
    connect(ui.sliderOpacity, &QSlider::valueChanged, this, [this](int v) {
        setWindowOpacity(v / 100.0);
    });
}

void Mainwindow::initCheckBox()
{
    p_listwidget = new QListWidget(this);
    p_listwidget->setFrameShape(QFrame::NoFrame);
}

void Mainwindow::initTable()
{
    p_tableView = new QTableView(this);
    p_tableView->setFrameShape(QFrame::NoFrame);
    p_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    p_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    p_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    p_tableView->verticalHeader()->hide();
    p_tableView->horizontalHeader()->hide();
    p_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    p_model = new QStandardItemModel(this);
    p_model->setHorizontalHeaderLabels({ "Time", "Content" });
    p_tableView->setModel(p_model);
    p_tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    p_tableView->setColumnWidth(0, 60);
    p_tableView->show();

    // Keyboard delete shortcuts (registered after widgets are created)
    QShortcut* scDelTask = new QShortcut(QKeySequence(Qt::Key_Delete), p_listwidget);
    connect(scDelTask, &QShortcut::activated, this, &Mainwindow::onBtnDelTaskClicked);
    QShortcut* scDelClock = new QShortcut(QKeySequence(Qt::Key_Delete), p_tableView);
    connect(scDelClock, &QShortcut::activated, this, &Mainwindow::onBtnDelClockClicked);

    repositionWidgets();
}

void Mainwindow::checkboxStateChanged(int)
{
    QStringList itemList;
    for (int i = 0; i < p_listwidget->count(); i++) {
        QListWidgetItem* item = p_listwidget->item(i);
        QCheckBox* checkbox = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
        if (checkbox->isChecked())
            itemList.append(checkbox->text());
    }
    qDebug() << itemList;
}

void Mainwindow::onBtnAddTaskClicked()
{
    DlgTasks* dlgTask = new DlgTasks(this);
    connect(dlgTask, &DlgTasks::SendText, this, &Mainwindow::recQStr);
    dlgTask->exec();
    delete dlgTask;
}

void Mainwindow::onBtnDelTaskClicked()
{
    int row = p_listwidget->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Tip", "Please select and check an item to delete.");
        return;
    }
    QListWidgetItem* item = p_listwidget->item(row);
    QCheckBox* checkbox = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
    if (checkbox->isChecked()) {
        p_listwidget->takeItem(row);
        delete checkbox;
    } else {
        QMessageBox::information(this, "Tip", "Please check the item before deleting.");
    }
}

void Mainwindow::onBtnAddClockClicked()
{
    DlgClocks* dlgClock = new DlgClocks(this);
    connect(dlgClock, &DlgClocks::sendMsg, this, &Mainwindow::recMsg);
    dlgClock->exec();
    delete dlgClock;
}

void Mainwindow::onBtnDelClockClicked()
{
    QModelIndex index = p_tableView->currentIndex();
    int row = index.row();
    if (row < 0 || row >= m_clockVec.size()) return;
    killTimer(m_clockVec[row].timerId);
    m_clockVec.removeAt(row);
    p_tableView->model()->removeRow(row);
}

void Mainwindow::slotTimerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    ui.labelDate->setText(time.toString("yyyy-MM-dd dddd"));
    ui.labelTime->setText(time.toString("hh:mm:ss"));
}

void Mainwindow::recQStr(QString str, QString priority)
{
    QListWidgetItem* item = new QListWidgetItem(p_listwidget);
    item->setSizeHint(QSize(0, 30));

    QColor bgColor("#A0F4E7");
    if (priority == "high")     bgColor = QColor("#FFB3B3");
    else if (priority == "low") bgColor = QColor("#D0D0D0");
    item->setBackground(QBrush(bgColor));

    QCheckBox* checkbox = new QCheckBox;
    checkbox->setText(str);
    checkbox->setStyleSheet("QCheckBox{color:white;font-weight:bold;height:30px}");
    p_listwidget->addItem(item);
    p_listwidget->setItemWidget(item, checkbox);

    connect(checkbox, &QCheckBox::stateChanged, this, [this, checkbox](int state) {
        QFont f = checkbox->font();
        f.setStrikeOut(state == Qt::Checked);
        checkbox->setFont(f);
        checkboxStateChanged(state);
    });
}

void Mainwindow::recMsg(QString time, QString content)
{
    int insertRow = CalRow(time);
    QStandardItem* item1 = new QStandardItem(time);
    QStandardItem* item2 = new QStandardItem(content);
    item1->setTextAlignment(Qt::AlignCenter);
    item2->setTextAlignment(Qt::AlignCenter);
    item1->setFont(QFont("Microsoft YaHei", 10));
    item2->setFont(QFont("Microsoft YaHei", 10));
    item1->setForeground(QBrush(QColor("#FFFFFF")));
    item2->setForeground(QBrush(QColor("#FFFFFF")));
    item1->setBackground(QBrush(QColor("#A0F4E7")));
    item2->setBackground(QBrush(QColor("#A0F4E7")));
    QList<QStandardItem*> itemList;
    itemList << item1 << item2;
    p_model->insertRow(insertRow, itemList);

    QDateTime currentTime_ = QDateTime::currentDateTime();
    QString strDate = currentTime_.toString("yyyy-MM-dd");
    QString strClockTime = QString("%1 %2:00").arg(strDate).arg(time);
    QDateTime clockTime_ = QDateTime::fromString(strClockTime, "yyyy-MM-dd hh:mm:ss");

    qint64 elapsed = currentTime_.msecsTo(clockTime_);
    if (elapsed <= 0) {
        QMessageBox::warning(this, "Warning", "The time has already passed.");
        p_model->removeRow(insertRow);
        return;
    }

    int timeId = startTimer((int)elapsed);
    ClockNode clockNode;
    clockNode.timerId = timeId;
    clockNode.time    = time;
    clockNode.content = content;
    m_clockVec.insert(insertRow, clockNode);
}

void Mainwindow::recCloseCommand()
{
    m_soundEffect->stop();
}

void Mainwindow::closeEvent(QCloseEvent* event)
{
    QMessageBox::StandardButton result = QMessageBox::question(
        this,
        "Confirm",
        "Exit will clear all unsaved data. Are you sure?",
        QMessageBox::Yes | QMessageBox::Cancel,
        QMessageBox::Yes);

    if (result == QMessageBox::Yes) {
        saveData();
        isClosed = true;
        event->accept();
    } else {
        event->ignore();
    }
}

void Mainwindow::hideEvent(QHideEvent* event)
{
    if (isClosed) {
        event->accept();
        return;
    }
    if (m_tray->isVisible()) {
        m_tray->showMessage("RemindMe", "Minimized to tray.");
        event->ignore();
    } else {
        event->accept();
    }
}

void Mainwindow::timerEvent(QTimerEvent* event)
{
    int timerid = event->timerId();
    QString time;
    QString content;
    QString repeat = "none";
    int foundRow = -1;

    for (int i = 0; i < m_clockVec.size(); i++) {
        if (m_clockVec[i].timerId == timerid) {
            time     = m_clockVec[i].time;
            content  = m_clockVec[i].content;
            repeat   = m_clockVec[i].repeat;
            foundRow = i;
            break;
        }
    }

    killTimer(timerid);

    if (foundRow < 0) return;

    // Handle repeat: reschedule before removing from vec
    if (repeat != "none") {
        QDateTime now = QDateTime::currentDateTime();
        QString strDate = now.toString("yyyy-MM-dd");
        QDateTime nextTrigger = QDateTime::fromString(
            QString("%1 %2:00").arg(strDate).arg(time), "yyyy-MM-dd hh:mm:ss");

        if (repeat == "daily") {
            nextTrigger = nextTrigger.addDays(1);
        } else if (repeat == "weekly") {
            nextTrigger = nextTrigger.addDays(7);
        } else if (repeat == "workday") {
            nextTrigger = nextTrigger.addDays(1);
            while (nextTrigger.date().dayOfWeek() >= 6)
                nextTrigger = nextTrigger.addDays(1);
        }

        qint64 elapsed = now.msecsTo(nextTrigger);
        if (elapsed > 0) {
            int newId = startTimer((int)elapsed);
            m_clockVec[foundRow].timerId = newId;
            // Keep the table row, just update display if needed
        } else {
            m_clockVec.removeAt(foundRow);
            p_model->removeRow(foundRow);
        }
    } else {
        m_clockVec.removeAt(foundRow);
        p_model->removeRow(foundRow);
    }

    if (soundSwitch) m_soundEffect->play();

    this->showNormal();
    MyDialog* remindPop = new MyDialog(this);
    remindPop->SetLabelContent(content);
    remindPop->SetLabelIcon(":/res/windowIcon.png");
    remindPop->setAttribute(Qt::WA_DeleteOnClose);
    remindPop->show();
    connect(remindPop, &MyDialog::signalMyDialogBtnCloseClicked,
            this, &Mainwindow::recCloseCommand);
    connect(remindPop, &MyDialog::signalSnooze, this, [this, content](int minutes) {
        QDateTime now = QDateTime::currentDateTime();
        QString snoozeTime = now.addSecs(minutes * 60).toString("hh:mm");
        recMsg(snoozeTime, content);
    });
}

void Mainwindow::onActivatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
    case QSystemTrayIcon::DoubleClick:
        this->showNormal();
        break;
    default:
        break;
    }
}

int Mainwindow::CalRow(QString newTime)
{
    QTime _newTime = QTime::fromString(newTime, "hh:mm");
    for (int i = 0; i < m_clockVec.size(); i++) {
        QTime _tmpTime = QTime::fromString(m_clockVec[i].time, "hh:mm");
        if (_newTime <= _tmpTime) return i;
    }
    return m_clockVec.size();
}

void Mainwindow::ShowSettings()
{
    int panelY = (height() - PANEL_H) / 2;
    ui.btnShowSettings->hide();
    ui.frameSettings->show();
    QPropertyAnimation* animation = new QPropertyAnimation(ui.frameSettings, "geometry", this);
    animation->setDuration(500);
    animation->setStartValue(QRect(QPoint(0, panelY), QSize(0, PANEL_H)));
    animation->setEndValue(QRect(QPoint(0, panelY), QSize(150, PANEL_H)));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Mainwindow::HideSettings()
{
    int panelY = (height() - PANEL_H) / 2;
    QPropertyAnimation* animation = new QPropertyAnimation(ui.frameSettings, "geometry", this);
    animation->setDuration(100);
    animation->setStartValue(QRect(QPoint(0, panelY), QSize(150, PANEL_H)));
    animation->setEndValue(QRect(QPoint(0, panelY), QSize(0, PANEL_H)));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    ui.btnShowSettings->show();
}

void Mainwindow::ClearAll()
{
    QMessageBox::StandardButton result = QMessageBox::question(
        this,
        "Confirm",
        "Clear all tasks and alarms?",
        QMessageBox::Yes | QMessageBox::Cancel,
        QMessageBox::Yes);

    if (result == QMessageBox::Yes) {
        p_listwidget->clear();
        for (auto& c : m_clockVec) killTimer(c.timerId);
        m_clockVec.clear();
        p_tableView->model()->removeRows(0, p_tableView->model()->rowCount());
    }
}

void Mainwindow::onBtnSwitchClicked()
{
    soundSwitch = !soundSwitch;
    QIcon icon(soundSwitch ? ":/res/switch_on.png" : ":/res/switch_off.png");
    ui.btnSwitch->setIcon(icon);
    if (m_actionMute) m_actionMute->setText(soundSwitch ? "Mute" : "Unmute");
}

// ---------------------------------------------------------------------------
// Persistent storage
// ---------------------------------------------------------------------------
void Mainwindow::saveData()
{
    QJsonArray tasks;
    for (int i = 0; i < p_listwidget->count(); i++) {
        QListWidgetItem* item = p_listwidget->item(i);
        QCheckBox* cb = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
        QJsonObject t;
        t["text"]     = cb->text();
        t["checked"]  = cb->isChecked();
        t["priority"] = item->background().color().name(); // store color as priority proxy
        tasks.append(t);
    }

    QJsonArray clocks;
    for (auto& c : m_clockVec) {
        QJsonObject o;
        o["time"]    = c.time;
        o["content"] = c.content;
        o["repeat"]  = c.repeat;
        clocks.append(o);
    }

    QJsonObject root;
    root["tasks"]  = tasks;
    root["clocks"] = clocks;

    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile file(dir + "/remindme_data.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(root).toJson());
        file.close();
    }
}

void Mainwindow::loadData()
{
    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile file(dir + "/remindme_data.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    if (!doc.isObject()) return;

    QJsonObject root = doc.object();

    // Restore tasks
    for (auto v : root["tasks"].toArray()) {
        QJsonObject t = v.toObject();
        QString priority = "normal";
        QString colorName = t["priority"].toString();
        if (colorName == QColor("#FFB3B3").name()) priority = "high";
        else if (colorName == QColor("#D0D0D0").name()) priority = "low";
        recQStr(t["text"].toString(), priority);
        // restore checked state
        if (t["checked"].toBool()) {
            QListWidgetItem* item = p_listwidget->item(p_listwidget->count() - 1);
            QCheckBox* cb = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
            cb->setChecked(true);
        }
    }

    // Restore clocks
    QDateTime now = QDateTime::currentDateTime();
    for (auto v : root["clocks"].toArray()) {
        QJsonObject o = v.toObject();
        QString time    = o["time"].toString();
        QString content = o["content"].toString();
        QString repeat  = o["repeat"].toString("none");

        // Calculate next trigger
        QString strDate   = now.toString("yyyy-MM-dd");
        QDateTime trigger = QDateTime::fromString(
            QString("%1 %2:00").arg(strDate).arg(time), "yyyy-MM-dd hh:mm:ss");

        if (trigger <= now) {
            if (repeat == "none") continue; // past one-shot, skip
            // advance to next occurrence
            if (repeat == "daily") {
                while (trigger <= now) trigger = trigger.addDays(1);
            } else if (repeat == "weekly") {
                while (trigger <= now) trigger = trigger.addDays(7);
            } else if (repeat == "workday") {
                trigger = trigger.addDays(1);
                while (trigger <= now || trigger.date().dayOfWeek() >= 6)
                    trigger = trigger.addDays(1);
            }
        }

        qint64 elapsed = now.msecsTo(trigger);
        if (elapsed <= 0) continue;

        int insertRow = CalRow(time);
        QStandardItem* item1 = new QStandardItem(time);
        QStandardItem* item2 = new QStandardItem(content);
        item1->setTextAlignment(Qt::AlignCenter);
        item2->setTextAlignment(Qt::AlignCenter);
        item1->setBackground(QBrush(QColor("#A0F4E7")));
        item2->setBackground(QBrush(QColor("#A0F4E7")));
        item1->setForeground(QBrush(QColor("#FFFFFF")));
        item2->setForeground(QBrush(QColor("#FFFFFF")));
        QList<QStandardItem*> row;
        row << item1 << item2;
        p_model->insertRow(insertRow, row);

        int timeId = startTimer((int)elapsed);
        ClockNode cn;
        cn.timerId = timeId;
        cn.time    = time;
        cn.content = content;
        cn.repeat  = repeat;
        m_clockVec.insert(insertRow, cn);
    }
}

// ---------------------------------------------------------------------------
// Responsive layout
// ---------------------------------------------------------------------------
void Mainwindow::repositionWidgets()
{
    int W = width();
    int H = height();

    const int btnBarY = H - BTN_BAR_H;
    const int listH   = btnBarY - LIST_TOP - 10;
    const int colW    = W / 4;
    const int leftX   = colW / 2 - 100;
    const int rightX  = W - colW / 2 - 100;

    ui.label->setGeometry(leftX, HEADER_Y, 200, HEADER_H);

    if (p_listwidget)
        p_listwidget->setGeometry(leftX, LIST_TOP, 200, listH);

    int clockX = (W - 200) / 2;
    ui.labelDate->setGeometry(clockX, LIST_TOP, 200, 41);
    ui.labelTime->setGeometry(clockX, LIST_TOP + 50, 200, 51);
    ui.labelImage->setGeometry(clockX - 40, LIST_TOP + 200, 281, 191);

    ui.label_2->setGeometry(rightX, HEADER_Y, 60, HEADER_H);
    ui.label_3->setGeometry(rightX + 60, HEADER_Y, 140, HEADER_H);

    if (p_tableView)
        p_tableView->setGeometry(rightX, LIST_TOP, 200, listH);

    ui.widget->setGeometry(0, btnBarY, W, BTN_BAR_H);

    int btnShowY = (H - 80) / 2;
    ui.btnShowSettings->setGeometry(0, btnShowY, 10, 80);

    if (!ui.frameSettings->isHidden()) {
        int panelY = (H - PANEL_H) / 2;
        ui.frameSettings->setGeometry(0, panelY, 150, PANEL_H);
    }
}

void Mainwindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    repositionWidgets();
}
