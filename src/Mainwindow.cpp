#include "Mainwindow.h"
#include <QDebug>
#include <QCheckBox>
#include <QMessageBox>
#include <QTextLine>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTimer>
#include <QDateTime>
#include <QMovie>
#include "DlgTasks.h"
#include "DlgClocks.h"

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

    // 窗口
    setFixedSize(1200, 800);
    setWindowIcon(QIcon(":/res/windowIcon.png"));
    setWindowTitle(QStringLiteral("今天你全力以赴了吗？"));
    // 控件
    ui.btnAdd->setShortcut(tr("Ctrl+Q"));
    ui.btnDel->setShortcut(tr("Ctrl+W"));
    ui.btnAddClock->setShortcut(tr("Ctrl+E"));
    ui.btnDelClock->setShortcut(tr("Ctrl+R"));

    // 
    QMovie *movie = new QMovie(":/res/panda.gif");
    ui.labelImage->setMovie(movie);
    movie->start();
    ui.labelImage->show();

    // 闹钟链表初始化，增加头节点
    ClockNode* headNode= new ClockNode;
    p_head = headNode;
    p_clockList = headNode;

    // 用于实时刷新时间的定时器
    p_timeUpdate = new QTimer(this);
    p_timeUpdate->start(1000);

}

void Mainwindow::initConnect() {
    connect(ui.btnAdd, &QPushButton::clicked, this, &Mainwindow::on_addBtn_clicked);
    connect(ui.btnDel, &QPushButton::clicked, this, &Mainwindow::on_delBtn_clicked);
    connect(ui.btnAddClock, &QPushButton::clicked, this, &Mainwindow::onBtnAddClockClicked);
    connect(ui.btnDelClock, &QPushButton::clicked, this, &Mainwindow::onBtnDelClockClicked);
    connect(p_timeUpdate, &QTimer::timeout, this, &Mainwindow::slotTimerUpdate);
}

void Mainwindow::initCheckBox(){
    p_listwidget = new QListWidget(this);
    p_listwidget->move(200, 100);
    p_listwidget->resize(200, 500);
    //p_listwidget->setStyleSheet("background-color:transparent");
    p_listwidget->setFrameShape(QFrame::NoFrame);

    //for (int i = 0; i < 10; i++){
    //    QListWidgetItem* item = new QListWidgetItem(p_listwidget);
    //    QCheckBox* checkbox = new QCheckBox;
    //    checkbox->setText(QString("%1").arg(i));
    //    //设置item的高度
    //    item->setSizeHint(QSize(0, 20));
    //    p_listwidget->addItem(item);

    //    // 将item与checkbox关联
    //    p_listwidget->setItemWidget(item, checkbox);
    //    //遍历每个checkbox
    //    connect(checkbox, &QCheckBox::stateChanged, this, &Mainwindow::checkboxStateChanged);
    //}
}

void Mainwindow::initTable() {
    /* 创建表格视图 */
    p_tableView = new QTableView(this);

    /* 设置表格视图大小 */
    p_tableView->resize(200, 500);
    p_tableView->move(800, 100);
    p_tableView->setFrameShape(QFrame::NoFrame);
    //p_tableView->setStyleSheet("background-color:transparent");                                       
    p_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);                //设置为不可编辑
    p_tableView->verticalHeader()->hide();
    p_tableView->horizontalHeader()->hide();
    p_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    // 自适应所有列，让它布满空间
    


    /*p_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:  \
qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 220),stop:1 rgba(20,196,188, 230));\
color: white;}");*/
    /*p_tableView->verticalHeader()->setStyleSheet("QHeaderView::section {background-color:  \
qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 220),stop:1 rgba(20,196,188, 230));\
color: white;}");*/



    // 创建数据模型 */
    p_model = new QStandardItemModel();
    
    // 设置表格标题行(输入数据为QStringList类型)
    p_model->setHorizontalHeaderLabels({ "Time", "Content" });

    ///* 加载共10行数据，并每行有6列数据 */
    //for (int i = 0; i < 10; i++) {
    //    /* 加载第一列(ID)数据 */
    //    model->setItem(i, 0, new QStandardItem(QString("100%1").arg(i)));
    //    /* 加载第二列(User Name)数据 */
    //    model->setItem(i, 1, new QStandardItem(QString("User%1").arg(i)));
    //}

    /* 设置表格视图数据 */
    p_tableView->setModel(p_model);

    p_tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//对第0列单独设置固定宽度
    p_tableView->setColumnWidth(0, 60);       //设置第1列宽100

    /* 显示 */
    p_tableView->show();
}

void Mainwindow::checkboxStateChanged(int)
{
    QStringList itemList;
    //遍历当前的listwidget
    for (int i = 0; i < p_listwidget->count(); i++){
        QListWidgetItem* item = p_listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox* checkbox = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
        if (checkbox->isChecked())
        {
            QString checkboxStr = checkbox->text();
            itemList.append(checkboxStr);
        }
    }
    qDebug() << itemList;
}

void Mainwindow::on_addBtn_clicked()
{
    DlgTasks* dlgTask = new DlgTasks(this);
    connect(dlgTask, &DlgTasks::SendText, this, &Mainwindow::recQStr);
    //dlgTask->show();

    dlgTask->exec();

    //销毁视图
    delete dlgTask;
    dlgTask = NULL; 
}

void Mainwindow::on_delBtn_clicked()
{
    //获取当前选中行
    int row = p_listwidget->currentRow();
    if (row < 0) {
        return;
    }
    for (int i = 0; i < p_listwidget->count(); i++) {
        QListWidgetItem* item = p_listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox* checkbox = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
        if (checkbox->isChecked()) {
            p_listwidget->takeItem(row);
        }
    }
}

void Mainwindow::recQStr(QString str) {   
    //获取当前的行数
    int row = p_listwidget->count();
    QListWidgetItem* item = new QListWidgetItem(p_listwidget);
    item->setSizeHint(QSize(0, 30));
    //在当前行添加item  checkbox
    QCheckBox* checkbox = new QCheckBox;
    item->setBackground(QBrush(QColor("#A0F4E7")));
    checkbox->setText(str);
    checkbox->setStyleSheet("QCheckBox{color:white;font-weight:bold;height:30px}");
    p_listwidget->addItem(item);
    p_listwidget->setItemWidget(item, checkbox);
    connect(checkbox, &QCheckBox::stateChanged, this, &Mainwindow::checkboxStateChanged);
}

void Mainwindow::recMsg(QString time, QString content) {
    // 获取表格当前的行数
    int row = p_tableView->model()->rowCount();
    QStandardItem* item1 = new QStandardItem(time);
    QStandardItem* item2 = new QStandardItem(content);
    item1->setTextAlignment(Qt::AlignCenter);
    item2->setTextAlignment(Qt::AlignCenter);
    item1->setFont(QFont(QStringLiteral("思源黑体 CN BOLD"), 10));
    item2->setFont(QFont(QStringLiteral("思源黑体 CN BOLD"), 10));
    item1->setForeground(QBrush(QColor("#FFFFFF")));
    item2->setForeground(QBrush(QColor("#FFFFFF")));
    item1->setBackground(QBrush(QColor("#A0F4E7")));
    item2->setBackground(QBrush(QColor("#A0F4E7")));
    p_model->setItem(row, 0, item1);
    p_model->setItem(row, 1, item2);

    // 获取此刻时间
    QDateTime currentTime_ = QDateTime::currentDateTime();//获取当前日期和时间
    QString strDate = currentTime_.toString("yyyy-MM-dd");
    //QString strdTime = currentTime.toString("hh:mm:ss");//格式为年-月-日 小时-分钟-秒 星期
    //QString strSecond = currentTime_.toString("ss");
    qDebug() << QStringLiteral("当前时间为：") << currentTime_;
    
    // 拼接闹钟时间
    QString strClockTime = QString("%1 %2:%3")
        .arg(strDate).arg(time).arg("00");
    QDateTime clockTime_ = QDateTime::fromString(strClockTime, "yyyy-MM-dd hh:mm:ss");
    qDebug() << QStringLiteral("闹钟时间为：") << clockTime_;

    
    // 计算时间差
    int elapsed = currentTime_.msecsTo(clockTime_);     // 单位是毫秒
    qDebug() << QStringLiteral("还剩时间：") << elapsed << QStringLiteral("毫秒");

    // 开始计时
    int timeId = startTimer(elapsed);              // startTimer的单位是毫秒
    ClockNode* clockNode = new ClockNode{ timeId, time, content,NULL };
    p_clockList->next = clockNode;
    p_clockList = clockNode;        // 更新链表指针到最后一个节点
}

void Mainwindow::onBtnAddClockClicked() {
    DlgClocks* dlgClock = new DlgClocks(this);
    connect(dlgClock, &DlgClocks::sendMsg, this, &Mainwindow::recMsg);
    // 进行阻塞
    dlgClock->exec();

    //销毁视图
    delete dlgClock;
    dlgClock = NULL;
}

void Mainwindow::onBtnDelClockClicked() {
    
}

void Mainwindow::slotTimerUpdate() {
    QDateTime time = QDateTime::currentDateTime();//获取当前日期和时间
    QString strdDate = time.toString("yyyy-MM-dd dddd");//格式为年-月-日 小时-分钟-秒 星期
    QString strdTime = time.toString("hh:mm:ss");//格式为年-月-日 小时-分钟-秒 星期
    ui.labelDate->setText(strdDate);
    ui.labelTime->setText(strdTime);
}

void Mainwindow::timerEvent(QTimerEvent* event) {
    int timerid = event->timerId();
    QString time;
    QString content;
    qDebug() << timerid;

    // 从闹钟链表中移除该项并返回时钟与内容
    removeClock(timerid, time, content);

    // 表格中删除相应内容
    
    // 弹窗
    QMessageBox::warning(this, "Warning", content);

    // 音乐


    // 取消掉此计时器
    killTimer(timerid); 
}

void Mainwindow::removeClock(int timerid, QString &time, QString &content) {
    ClockNode* p = p_head->next;          // 遍历指针     
    ClockNode* q = p_head;               // 指向上一节点的指针
    while (p != NULL) {
        if (p->timerId = timerid) {
            time = p->time;
            content = p->content;
            q->next = p->next;
            delete p;
            p = NULL;

            if (q->next == NULL)         // 此时说明删除的是最后一个节点，需要将p_clockList重新指向头节点
                p_clockList = p_head;
            return;
        }
        q = p;
        p = p->next;
    }
}

void Mainwindow::closeEvent(QCloseEvent* event) {
    //窗口关闭时询问是否退出
    QMessageBox::StandardButton result = QMessageBox::question(this, QStringLiteral("确认"), QStringLiteral("退出程序将会清空所有内容，确定要退出本程序吗？"),
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
        QMessageBox::No);

    if (result == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}