#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QTableView>
#include <QStandardItemModel>
#include "ui_Mainwindow.h"

typedef struct ClockNode {
	int timerId;
	QString time;
	QString content;
	ClockNode* next;
}*ClockList;
class Mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	Mainwindow(QWidget *parent = nullptr);
	~Mainwindow();
	void initWindow();
	void initCheckBox();
	void initConnect();
	void initTable();

public:
	void removeClock(int, QString&, QString&);
private slots:
	void checkboxStateChanged(int);
	void on_addBtn_clicked();
	void on_delBtn_clicked();
	void onBtnAddClockClicked();
	void onBtnDelClockClicked();
	void slotTimerUpdate();
	void recQStr(QString);
	void recMsg(QString,QString);

private:
	void timerEvent(QTimerEvent* event);
	void closeEvent(QCloseEvent* event);

private:
	Ui::MainwindowClass ui;
	QListWidget* p_listwidget;
	QTableView* p_tableView;
	QStandardItemModel* p_model;
	QTimer* p_timeUpdate;
	QVector<ClockNode> m_clockVec;
	ClockList p_clockList;				// 存放闹钟节点的链表
	ClockNode* p_head;					// 头指针
};

#endif //MAINWINDOW_H
