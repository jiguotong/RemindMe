#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QTableView>
#include <QStandardItemModel>
#include "ui_Mainwindow.h"

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
	QVector<int> timerIds;
};

#endif //MAINWINDOW_H
