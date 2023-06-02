#include "Mainwindow.h"
#include <QDebug>
#include <QCheckBox>
#include <QMessageBox>
#include <QTextLine>
#include <QHeaderView>
#include <QStandardItemModel>
#include "DlgTasks.h"
#include "DlgClocks.h"

Mainwindow::Mainwindow(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);

    setFixedSize(1200, 800);
    initCheckBox();
    initConnect(); 
    initTable();
}

Mainwindow::~Mainwindow(){}

void Mainwindow::initConnect() {
    connect(ui.btnAdd, &QPushButton::clicked, this, &Mainwindow::on_addBtn_clicked);
    connect(ui.btnDel, &QPushButton::clicked, this, &Mainwindow::on_delBtn_clicked);
    connect(ui.btnAddClock, &QPushButton::clicked, this, &Mainwindow::onBtnAddClockClicked);
    connect(ui.btnDelClock, &QPushButton::clicked, this, &Mainwindow::onBtnDelClockClicked);
}

void Mainwindow::initCheckBox(){
    p_listwidget = new QListWidget(this);
    p_listwidget->move(250, 100);
    p_listwidget->resize(100, 500);
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
    p_tableView->setWindowFlags(Qt::FramelessWindowHint);                           //设置无边框
    p_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);                //设置为不可编辑
    p_tableView->verticalHeader()->hide();
    p_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);    // 自适应所有列，让它布满空间
    p_tableView->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:  \
qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 220),stop:1 rgba(20,196,188, 230));\
color: white;}");
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

void Mainwindow::recQStr(QString str) {   
    //获取当前的行数
    int row = p_listwidget->count();
    QListWidgetItem* item = new QListWidgetItem(p_listwidget);
    //在当前行添加item  checkbox
    QCheckBox* checkbox = new QCheckBox;
    checkbox->setText(str);
    p_listwidget->addItem(item);
    p_listwidget->setItemWidget(item, checkbox);
    connect(checkbox, &QCheckBox::stateChanged, this, &Mainwindow::checkboxStateChanged);
}

void Mainwindow::recMsg(QString time, QString content) {
    // 获取表格当前的行数
    int row = p_tableView->model()->rowCount();
    QStandardItem* item1 = new QStandardItem(time);
    QStandardItem* item2 = new QStandardItem(content);

    item1->setBackground(QBrush(QColor("#58b5b0")));
    item2->setBackground(QBrush(QColor("#58b5b0")));
    p_model->setItem(row, 0, item1);
    p_model->setItem(row, 1, item2);
}


void Mainwindow::on_delBtn_clicked()
{
    //获取当前选中行
    int row = p_listwidget->currentRow();
    if (row < 0){
        return;
    }
    for (int i = 0; i < p_listwidget->count(); i++){
        QListWidgetItem* item = p_listwidget->item(i);
        //将QWidget 转化为QCheckBox  获取第i个item 的控件
        QCheckBox* checkbox = static_cast<QCheckBox*>(p_listwidget->itemWidget(item));
        if (checkbox->isChecked()){
            p_listwidget->takeItem(row);
        }
    }
}

void Mainwindow::onBtnAddClockClicked() {
    DlgClocks* dlgClock = new DlgClocks(this);
    connect(dlgClock, &DlgClocks::sendMsg, this, &Mainwindow::recMsg);
    //dlgClock->show();

    dlgClock->exec();

    //销毁视图
    delete dlgClock;
    dlgClock = NULL;
}

void Mainwindow::onBtnDelClockClicked() {

}