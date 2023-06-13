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

    // ����
    setFixedSize(1200, 800);
    setWindowIcon(QIcon(":/res/windowIcon.png"));
    setWindowTitle(QStringLiteral("������ȫ���Ը�����"));
    // �ؼ�
    ui.btnAdd->setShortcut(tr("Ctrl+Q"));
    ui.btnDel->setShortcut(tr("Ctrl+W"));
    ui.btnAddClock->setShortcut(tr("Ctrl+E"));
    ui.btnDelClock->setShortcut(tr("Ctrl+R"));

    // 
    QMovie *movie = new QMovie(":/res/panda.gif");
    ui.labelImage->setMovie(movie);
    movie->start();
    ui.labelImage->show();

    // ���������ʼ��������ͷ�ڵ�
    ClockNode* headNode= new ClockNode;
    p_head = headNode;
    p_clockList = headNode;

    // ����ʵʱˢ��ʱ��Ķ�ʱ��
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
    //    //����item�ĸ߶�
    //    item->setSizeHint(QSize(0, 20));
    //    p_listwidget->addItem(item);

    //    // ��item��checkbox����
    //    p_listwidget->setItemWidget(item, checkbox);
    //    //����ÿ��checkbox
    //    connect(checkbox, &QCheckBox::stateChanged, this, &Mainwindow::checkboxStateChanged);
    //}
}

void Mainwindow::initTable() {
    /* ���������ͼ */
    p_tableView = new QTableView(this);

    /* ���ñ����ͼ��С */
    p_tableView->resize(200, 500);
    p_tableView->move(800, 100);
    p_tableView->setFrameShape(QFrame::NoFrame);
    //p_tableView->setStyleSheet("background-color:transparent");                                       
    p_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);                //����Ϊ���ɱ༭
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
    
    // ���ñ�������(��������ΪQStringList����)
    p_model->setHorizontalHeaderLabels({ "Time", "Content" });

    ///* ���ع�10�����ݣ���ÿ����6������ */
    //for (int i = 0; i < 10; i++) {
    //    /* ���ص�һ��(ID)���� */
    //    model->setItem(i, 0, new QStandardItem(QString("100%1").arg(i)));
    //    /* ���صڶ���(User Name)���� */
    //    model->setItem(i, 1, new QStandardItem(QString("User%1").arg(i)));
    //}

    /* ���ñ����ͼ���� */
    p_tableView->setModel(p_model);

    p_tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//�Ե�0�е������ù̶����
    p_tableView->setColumnWidth(0, 60);       //���õ�1�п�100

    /* ��ʾ */
    p_tableView->show();
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

void Mainwindow::on_addBtn_clicked()
{
    DlgTasks* dlgTask = new DlgTasks(this);
    connect(dlgTask, &DlgTasks::SendText, this, &Mainwindow::recQStr);
    //dlgTask->show();

    dlgTask->exec();

    //������ͼ
    delete dlgTask;
    dlgTask = NULL; 
}

void Mainwindow::on_delBtn_clicked()
{
    //��ȡ��ǰѡ����
    int row = p_listwidget->currentRow();
    if (row < 0) {
        return;
    }
    for (int i = 0; i < p_listwidget->count(); i++) {
        QListWidgetItem* item = p_listwidget->item(i);
        //��QWidget ת��ΪQCheckBox  ��ȡ��i��item �Ŀؼ�
        QCheckBox* checkbox = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
        if (checkbox->isChecked()) {
            p_listwidget->takeItem(row);
        }
    }
}

void Mainwindow::recQStr(QString str) {   
    //��ȡ��ǰ������
    int row = p_listwidget->count();
    QListWidgetItem* item = new QListWidgetItem(p_listwidget);
    item->setSizeHint(QSize(0, 30));
    //�ڵ�ǰ�����item  checkbox
    QCheckBox* checkbox = new QCheckBox;
    item->setBackground(QBrush(QColor("#A0F4E7")));
    checkbox->setText(str);
    checkbox->setStyleSheet("QCheckBox{color:white;font-weight:bold;height:30px}");
    p_listwidget->addItem(item);
    p_listwidget->setItemWidget(item, checkbox);
    connect(checkbox, &QCheckBox::stateChanged, this, &Mainwindow::checkboxStateChanged);
}

void Mainwindow::recMsg(QString time, QString content) {
    // ��ȡ���ǰ������
    int row = p_tableView->model()->rowCount();
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
    p_model->setItem(row, 0, item1);
    p_model->setItem(row, 1, item2);

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
    p_clockList->next = clockNode;
    p_clockList = clockNode;        // ��������ָ�뵽���һ���ڵ�
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
    
}

void Mainwindow::slotTimerUpdate() {
    QDateTime time = QDateTime::currentDateTime();//��ȡ��ǰ���ں�ʱ��
    QString strdDate = time.toString("yyyy-MM-dd dddd");//��ʽΪ��-��-�� Сʱ-����-�� ����
    QString strdTime = time.toString("hh:mm:ss");//��ʽΪ��-��-�� Сʱ-����-�� ����
    ui.labelDate->setText(strdDate);
    ui.labelTime->setText(strdTime);
}

void Mainwindow::timerEvent(QTimerEvent* event) {
    int timerid = event->timerId();
    QString time;
    QString content;
    qDebug() << timerid;

    // �������������Ƴ��������ʱ��������
    removeClock(timerid, time, content);

    // �����ɾ����Ӧ����
    
    // ����
    QMessageBox::warning(this, "Warning", content);

    // ����


    // ȡ�����˼�ʱ��
    killTimer(timerid); 
}

void Mainwindow::removeClock(int timerid, QString &time, QString &content) {
    ClockNode* p = p_head->next;          // ����ָ��     
    ClockNode* q = p_head;               // ָ����һ�ڵ��ָ��
    while (p != NULL) {
        if (p->timerId = timerid) {
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

void Mainwindow::closeEvent(QCloseEvent* event) {
    //���ڹر�ʱѯ���Ƿ��˳�
    QMessageBox::StandardButton result = QMessageBox::question(this, QStringLiteral("ȷ��"), QStringLiteral("�˳����򽫻�����������ݣ�ȷ��Ҫ�˳���������"),
        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel,
        QMessageBox::No);

    if (result == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}