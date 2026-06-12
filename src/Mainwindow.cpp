#include "Mainwindow.h"
#include <QDebug>
#include <QCheckBox>
#include <QMessageBox>
#include <QTextLine>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTimer>
#include <QDateTime>
#include <QPropertyAnimation>
#include <QMovie>
#include "DlgTasks.h"
#include "DlgClocks.h"
#include "MyDialog.h"

Mainwindow::Mainwindow(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);

    

    initWindow();
    initCheckBox();
    initConnect(); 
    initTable();
}

Mainwindow::~Mainwindow(){}

void Mainwindow::initWindow() {

    // ����
    setWindowIcon(QIcon(":/res/windowIcon.png"));
    setWindowTitle(QStringLiteral("������ȫ���Ը�����"));
    // �ؼ�
    ui.btnAdd->setShortcut(tr("Ctrl+Q"));
    ui.btnDel->setShortcut(tr("Ctrl+W"));
    ui.btnAddClock->setShortcut(tr("Ctrl+E"));
    ui.btnDelClock->setShortcut(tr("Ctrl+R"));

    // ��ʼ����̬ͼ
    QMovie *movie = new QMovie(":/res/panda.gif");
    ui.labelImage->setMovie(movie);
    movie->start();
    ui.labelImage->show();

    // ��ʼ����������
    m_soundEffect = new QSoundEffect(this);
    //m_soundEffect->setSource(QUrl::fromLocalFile("C:\\Users\\Administrator\\Desktop\\RemindMe\\src\\res\\Alarm01.wav"));
    m_soundEffect->setSource(QUrl::fromLocalFile(":/res/Alarm01.wav"));
    m_soundEffect->setLoopCount(QSoundEffect::Infinite);
    m_soundEffect->setVolume(0.25f);

    // ����������ʼ��������ͷ�ڵ�
    ClockNode* headNode= new ClockNode;
    p_head = headNode;
    p_clockList = headNode;

    // ϵͳ����
    m_tray = new QSystemTrayIcon(this);
    m_tray->setIcon(QIcon(":/res/windowIcon.png"));
    m_tray->setToolTip(QStringLiteral("RemindMe"));
    m_tray->show();

    // ���ô�������
    ui.frameSettings->hide();
    // ����ʵʱˢ��ʱ��Ķ�ʱ��
    p_timeUpdate = new QTimer(this);
    p_timeUpdate->start(1000);
}

void Mainwindow::initConnect() {
    connect(ui.btnAdd, &QPushButton::clicked, this, &Mainwindow::onBtnAddTaskClicked);
    connect(ui.btnDel, &QPushButton::clicked, this, &Mainwindow::onBtnDelTaskClicked);
    connect(ui.btnAddClock, &QPushButton::clicked, this, &Mainwindow::onBtnAddClockClicked);
    connect(ui.btnDelClock, &QPushButton::clicked, this, &Mainwindow::onBtnDelClockClicked);
    connect(p_timeUpdate, &QTimer::timeout, this, &Mainwindow::slotTimerUpdate);
    connect(m_tray, &QSystemTrayIcon::activated, this, &Mainwindow::onActivatedSysTrayIcon);
    connect(ui.btnClear, &QPushButton::clicked, this, &Mainwindow::ClearAll);
    connect(ui.btnSwitch, &QPushButton::clicked, this, &Mainwindow::onBtnSwitchClicked);
    // ����ר��
    connect(ui.btnShowSettings, &QPushButton::clicked, this, &Mainwindow::ShowSettings);
    connect(ui.btnHideSettings, &QPushButton::clicked, this, &Mainwindow::HideSettings);
}

void Mainwindow::initCheckBox(){
    p_listwidget = new QListWidget(this);
    p_listwidget->setFrameShape(QFrame::NoFrame);
}

void Mainwindow::initTable() {
    /* ����������ͼ */
    p_tableView = new QTableView(this);

    /* 尺寸与位置由 repositionWidgets() 在 resizeEvent 中统一设置 */
    p_tableView->setFrameShape(QFrame::NoFrame);
    //p_tableView->setStyleSheet("background-color:transparent");                                       
    p_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);                // ����Ϊ���ɱ༭
    p_tableView->setSelectionMode(QAbstractItemView::NoSelection);                  // ����Ϊ����ѡ��

    p_tableView->verticalHeader()->hide();
    p_tableView->horizontalHeader()->hide();
    p_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    // ����Ӧ�����У����������ռ�
    


    /*p_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:  \
qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 220),stop:1 rgba(20,196,188, 230));\
color: white;}");*/
    /*p_tableView->verticalHeader()->setStyleSheet("QHeaderView::section {background-color:  \
qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 220),stop:1 rgba(20,196,188, 230));\
color: white;}");*/

    // ��������ģ�� */
    p_model = new QStandardItemModel();
    
    // ���ñ��������(��������ΪQStringList����)
    p_model->setHorizontalHeaderLabels({ "Time", "Content" });

    ///* ���ع�10�����ݣ���ÿ����6������ */
    //for (int i = 0; i < 10; i++) {
    //    /* ���ص�һ��(ID)���� */
    //    model->setItem(i, 0, new QStandardItem(QString("100%1").arg(i)));
    //    /* ���صڶ���(User Name)���� */
    //    model->setItem(i, 1, new QStandardItem(QString("User%1").arg(i)));
    //}

    /* ���ñ�����ͼ���� */
    p_tableView->setModel(p_model);

    p_tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//�Ե�0�е������ù̶�����
    p_tableView->setColumnWidth(0, 60);       //���õ�1�п�100

    /* ��ʾ */
    p_tableView->show();
    // 初始布局（窗口尺寸在 show() 后才确定，resizeEvent 会二次触发）
    repositionWidgets();
}

void Mainwindow::checkboxStateChanged(int)
{
    QStringList itemList;
    //������ǰ��listwidget
    for (int i = 0; i < p_listwidget->count(); i++){
        QListWidgetItem* item = p_listwidget->item(i);
        //��QWidget ת��ΪQCheckBox  ��ȡ��i��item �Ŀؼ�
        QCheckBox* checkbox = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
        if (checkbox->isChecked())
        {
            QString checkboxStr = checkbox->text();
            itemList.append(checkboxStr);
        }
    }
    qDebug() << itemList;
}

void Mainwindow::onBtnAddTaskClicked()
{
    DlgTasks* dlgTask = new DlgTasks(this);
    connect(dlgTask, &DlgTasks::SendText, this, &Mainwindow::recQStr);
    //dlgTask->show();

    dlgTask->exec();

    //������ͼ
    delete dlgTask;
    dlgTask = NULL; 
}

void Mainwindow::onBtnDelTaskClicked()
{
    //��ȡ��ǰѡ����
    int row = p_listwidget->currentRow();
    if (row < 0) {
        return;
    }
    QListWidgetItem* item = p_listwidget->item(row);
    //��QWidget ת��ΪQCheckBox  ��ȡ��row��item �Ŀؼ�
    QCheckBox* checkbox = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
    if (checkbox->isChecked()) {
        p_listwidget->takeItem(row);
        delete checkbox;
    }
}

void Mainwindow::onBtnAddClockClicked() {
    DlgClocks* dlgClock = new DlgClocks(this);
    connect(dlgClock, &DlgClocks::sendMsg, this, &Mainwindow::recMsg);
    // ��������
    dlgClock->exec();

    //������ͼ
    delete dlgClock;
    dlgClock = NULL;
}

void Mainwindow::onBtnDelClockClicked() {
    QModelIndex index = p_tableView->currentIndex();
    int row = index.row();
    p_tableView->model()->removeRow(row);
    removeClock(row);
}

void Mainwindow::slotTimerUpdate() {
    QDateTime time = QDateTime::currentDateTime();//��ȡ��ǰ���ں�ʱ��
    QString strdDate = time.toString("yyyy-MM-dd dddd");//��ʽΪ��-��-�� Сʱ-����-�� ����
    QString strdTime = time.toString("hh:mm:ss");//��ʽΪ��-��-�� Сʱ-����-�� ����
    ui.labelDate->setText(strdDate);
    ui.labelTime->setText(strdTime);
}

void Mainwindow::recQStr(QString str) {
    //��ȡ��ǰ������
    int row = p_listwidget->count();
    QListWidgetItem* item = new QListWidgetItem(p_listwidget);
    item->setSizeHint(QSize(0, 30));
    //�ڵ�ǰ������item  checkbox
    QCheckBox* checkbox = new QCheckBox;
    item->setBackground(QBrush(QColor("#A0F4E7")));
    checkbox->setText(str);
    checkbox->setStyleSheet("QCheckBox{color:white;font-weight:bold;height:30px}");
    //checkbox->setStyleSheet("QCheckBox{color:#F89F92;font-weight:bold;height:30px}");
    p_listwidget->addItem(item);
    p_listwidget->setItemWidget(item, checkbox);
    connect(checkbox, &QCheckBox::stateChanged, this, &Mainwindow::checkboxStateChanged);
}

void Mainwindow::recMsg(QString time, QString content) {
    // ��ȡ����ǰ������
    int row = p_tableView->model()->rowCount();
    int insertRow = CalRow(time);
    QStandardItem* item1 = new QStandardItem(time);
    QStandardItem* item2 = new QStandardItem(content);
    item1->setTextAlignment(Qt::AlignCenter);
    item2->setTextAlignment(Qt::AlignCenter);
    item1->setFont(QFont(QStringLiteral("˼Դ���� CN BOLD"), 10));
    item2->setFont(QFont(QStringLiteral("˼Դ���� CN BOLD"), 10));
    item1->setForeground(QBrush(QColor("#FFFFFF")));
    item2->setForeground(QBrush(QColor("#FFFFFF")));
    item1->setBackground(QBrush(QColor("#A0F4E7")));
    item2->setBackground(QBrush(QColor("#A0F4E7")));
    QList<QStandardItem*> itemList;
    itemList << item1;
    itemList << item2;
    p_model->insertRow(insertRow, itemList);
    //p_model->setItem(insertRow, 0, item1);
    //p_model->setItem(insertRow, 1, item2);

    // ��ȡ�˿�ʱ��
    QDateTime currentTime_ = QDateTime::currentDateTime();//��ȡ��ǰ���ں�ʱ��
    QString strDate = currentTime_.toString("yyyy-MM-dd");
    //QString strdTime = currentTime.toString("hh:mm:ss");//��ʽΪ��-��-�� Сʱ-����-�� ����
    //QString strSecond = currentTime_.toString("ss");
    qDebug() << QStringLiteral("��ǰʱ��Ϊ��") << currentTime_;

    // ƴ������ʱ��
    QString strClockTime = QString("%1 %2:%3")
        .arg(strDate).arg(time).arg("00");
    QDateTime clockTime_ = QDateTime::fromString(strClockTime, "yyyy-MM-dd hh:mm:ss");
    qDebug() << QStringLiteral("����ʱ��Ϊ��") << clockTime_;


    // ����ʱ���
    int elapsed = currentTime_.msecsTo(clockTime_);     // ��λ�Ǻ���
    qDebug() << QStringLiteral("��ʣʱ�䣺") << elapsed << QStringLiteral("����");

    // ��ʼ��ʱ
    int timeId = startTimer(elapsed);              // startTimer�ĵ�λ�Ǻ���
    ClockNode* clockNode = new ClockNode{ timeId, time, content,NULL };
    insertClock(insertRow, clockNode);
}

void Mainwindow::recCloseCommand()
{
    p_tableView->model()->removeRow(0);
    m_soundEffect->stop();
}

void Mainwindow::insertClock(int insertIndex, ClockNode* clockNode) {
    ClockNode* p = p_head->next;          // ����ָ��     
    ClockNode* q = p_head;               // ָ����һ�ڵ��ָ��
    int index = 0;
    while (p != NULL && index != insertIndex) {
        q = p;
        p = p->next;
        index++;
    }
    q->next = clockNode;
    clockNode->next = p;
}

void Mainwindow::removeClock(int timerid, QString &time, QString &content) {
    ClockNode* p = p_head->next;          // ����ָ��     
    ClockNode* q = p_head;               // ָ����һ�ڵ��ָ��
    while (p != NULL) {
        if (p->timerId == timerid) {
            time = p->time;
            content = p->content;
            q->next = p->next;
            delete p;
            p = NULL;

            if (q->next == NULL)         // ��ʱ˵��ɾ���������һ���ڵ㣬��Ҫ��p_clockList����ָ��ͷ�ڵ�
                p_clockList = p_head;
            return;
        }
        q = p;
        p = p->next;
    }
}

void Mainwindow::removeClock(int index) {
    ClockNode* p = p_head->next;          // ����ָ��     
    ClockNode* q = p_head;               // ָ����һ�ڵ��ָ��
    int count=0;
    while (p != NULL && index!=count) {
        count++;
        q = p;
        p = p->next;
    }
    if (p == NULL)
        return;
    q->next = p->next;
    killTimer(p->timerId);  // �ص��󶨵ļ�ʱ��
    delete p;
    p = NULL;
}

void Mainwindow::clearClock()
{
    ClockNode* p = p_head->next;          // ����ָ��     
    ClockNode* q = p_head;               // ָ����һ�ڵ��ָ��
    while (p!=NULL){
        q = p->next; //q�������p����һָ����
        killTimer(p->timerId);  // �ص��󶨵ļ�ʱ��
        delete p; //�ͷ�p
        p = q; //��q�����е����ݷ�����p
    }
    p_head->next = NULL;
}

void Mainwindow::closeEvent(QCloseEvent* event) {
    //���ڹر�ʱѯ���Ƿ��˳�
    QMessageBox::StandardButton result = QMessageBox::question(this, QStringLiteral("ȷ��"), QStringLiteral("�˳����򽫻�����������ݣ�ȷ��Ҫ�˳���������"),
        QMessageBox::Yes | QMessageBox::Cancel,
        QMessageBox::Yes);

    if (result == QMessageBox::Yes){
        isClosed = true;
        event->accept();
    }
        
    else
        event->ignore();
}

void Mainwindow::hideEvent(QHideEvent* event)
{
    if (isClosed){              // ��ֹ�رմ���ʱ����ʾ���ص�����
        event->accept();
        return;
    }
    if (m_tray->isVisible())
    {
        qDebug() << QStringLiteral("���ص�����");
        m_tray->showMessage("RemindMe", QStringLiteral("���ص�����ͼ����")); //��ʾ�û����ص�������
        event->ignore(); //�����¼�
    }
    else
        event->accept();
}

void Mainwindow::timerEvent(QTimerEvent* event) {
    int timerid = event->timerId();
    QString time;
    QString content;
    qDebug() << timerid;

    // �������������Ƴ��������ʱ��������
    removeClock(timerid, time, content);

    // ������ɾ����Ӧ����

    // ����
    if(soundSwitch)
         m_soundEffect->play();

    // ����
    this->showNormal();
    MyDialog* remindPop = new MyDialog(this);
    remindPop->SetLabelContent(content);
    remindPop->SetLabelIcon(":/res/windowIcon.png");
    remindPop->setAttribute(Qt::WA_DeleteOnClose);		// �����˳��Զ�����
    remindPop->show();
    connect(remindPop, &MyDialog::signalMyDialogBtnCloseClicked, this, &Mainwindow::recCloseCommand);

    // ȡ�����˼�ʱ��
    killTimer(timerid);
}

void Mainwindow::onActivatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        this->showNormal();
        break;
    case QSystemTrayIcon::DoubleClick:
        this->showNormal();
        break;
    default:
        break;
    }
}

int Mainwindow::CalRow(QString newTime) {
    QDateTime _newTime = QDateTime::fromString(newTime, "hh:mm");
    ClockNode* p = p_head->next;          // ����ָ��     
    ClockNode* q = p_head;               // ָ����һ�ڵ��ָ��
    int index = 0;
    while (p != NULL) {
        QDateTime _tmpTime = QDateTime::fromString(p->time, "hh:mm");
        if (_newTime <= _tmpTime) {
            return index;
        }
        q = p;
        p = p->next;
        index++;
    }
    return index;
}

void Mainwindow::ShowSettings()
{
    int h = height();
    int panelH = 270;
    int panelY = (h - panelH) / 2;

    ui.btnShowSettings->hide();
    ui.frameSettings->show();
    QPropertyAnimation* animation = new QPropertyAnimation(ui.frameSettings, "geometry");
    animation->setDuration(500);
    animation->setStartValue(QRect(QPoint(0, panelY), QSize(0, panelH)));
    animation->setEndValue(QRect(QPoint(0, panelY), QSize(150, panelH)));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void Mainwindow::HideSettings() {
    int h = height();
    int panelH = 270;
    int panelY = (h - panelH) / 2;

    QPropertyAnimation* animation = new QPropertyAnimation(ui.frameSettings, "geometry");
    animation->setDuration(100);
    animation->setStartValue(QRect(QPoint(0, panelY), QSize(150, panelH)));
    animation->setEndValue(QRect(QPoint(0, panelY), QSize(0, panelH)));
    animation->start(QAbstractAnimation::DeleteWhenStopped);
    ui.btnShowSettings->show();
}

void Mainwindow::ClearAll()
{
    QMessageBox::StandardButton result = QMessageBox::question(this, QStringLiteral("ȷ��"), QStringLiteral("��ȷ��Ҫ��������ճ�������������"),
        QMessageBox::Yes | QMessageBox::Cancel,
        QMessageBox::Yes);

    if (result == QMessageBox::Yes) {
        // 1.����ճ�
        p_listwidget->clear();
        qDebug() << QStringLiteral("�ճ������");
        // 2.�����������
        clearClock();
        qDebug() << QStringLiteral("���������");
        // 3.���������ʾ
        p_tableView->model()->removeRows(0, p_tableView->model()->rowCount()); //ɾ��������;
        qDebug() << QStringLiteral("������ʾ�����");
    }
}

void Mainwindow::onBtnSwitchClicked() {
    if (soundSwitch) {
        soundSwitch = false;
        QIcon icon(":/res/switch_off.png");  // ����Դ�ļ�����ͼ�꣬ע���滻��ȷ��·��
        ui.btnSwitch->setIcon(icon);
    }
    else {
        soundSwitch = true;
        QIcon icon(":/res/switch_on.png");  // ����Դ�ļ�����ͼ�꣬ע���滻��ȷ��·��
        ui.btnSwitch->setIcon(icon);
    }
}

// ---------------------------------------------------------------------------
// 响应式布局：所有绝对定位控件随窗口尺寸重新计算位置与大小
// ---------------------------------------------------------------------------
void Mainwindow::repositionWidgets()
{
    int W = width();
    int H = height();

    // 布局常量
    const int headerH   = 20;   // 标题标签高度
    const int headerY   = 80;   // 标题行 Y
    const int listTop   = 110;  // 列表/表格起始 Y
    const int btnBarH   = 60;   // 底部按钮栏高度
    const int btnBarY   = H - btnBarH;
    const int listH     = btnBarY - listTop - 10;

    // 列宽：左侧日程区 / 中间时钟区 / 右侧闹钟区 各占 1/4 宽度
    const int colW      = W / 4;
    const int leftX     = colW / 2 - 100;           // 日程列表左边距（列中心 - 半宽）
    const int rightX    = W - colW / 2 - 100;       // 闹钟表格左边距

    // — 日程标题标签
    ui.label->setGeometry(leftX, headerY, 200, headerH);

    // — 日程列表（代码创建）
    if (p_listwidget)
        p_listwidget->setGeometry(leftX, listTop, 200, listH);

    // — 时钟区（居中）
    int clockX = (W - 200) / 2;
    ui.labelDate->setGeometry(clockX, listTop, 200, 41);
    ui.labelTime->setGeometry(clockX, listTop + 50, 200, 51);
    ui.labelImage->setGeometry(clockX - 40, listTop + 200, 281, 191);

    // — 闹钟表头
    ui.label_2->setGeometry(rightX, headerY, 60, headerH);
    ui.label_3->setGeometry(rightX + 60, headerY, 140, headerH);

    // — 闹钟表格（代码创建）
    if (p_tableView)
        p_tableView->setGeometry(rightX, listTop, 200, listH);

    // — 底部按钮栏
    ui.widget->setGeometry(0, btnBarY, W, btnBarH);

    // — 展开按钮（左侧边缘，竖向居中）
    const int panelH = 270;
    int btnShowY = (H - 80) / 2;
    ui.btnShowSettings->setGeometry(0, btnShowY, 10, 80);

    // — 设置面板（若展开状态，同步更新位置）
    if (!ui.frameSettings->isHidden()) {
        int panelY = (H - panelH) / 2;
        ui.frameSettings->setGeometry(0, panelY, 150, panelH);
    }
}

void Mainwindow::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);
    repositionWidgets();
}