#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QSoundEffect>
#include <QSystemTrayIcon>
#include <QResizeEvent>
#include "ui_Mainwindow.h"

typedef struct ClockNode {
	int timerId;
	QString time;
	QString content;
	ClockNode* next = NULL;
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
	void removeClock(int);
	void insertClock(int, ClockNode*);
	void clearClock();
	int CalRow(QString newTime);
	void ShowSettings();
	void HideSettings();
	void ClearAll();
private slots:
	void checkboxStateChanged(int);
	void onBtnAddTaskClicked();
	void onBtnDelTaskClicked();
	void onBtnAddClockClicked();
	void onBtnDelClockClicked();
	void onBtnSwitchClicked();
	void onActivatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
	void slotTimerUpdate();
	void recQStr(QString);
	void recMsg(QString,QString);
	void recCloseCommand();


private:
	void timerEvent(QTimerEvent* event);
	void closeEvent(QCloseEvent* event);
	void hideEvent(QHideEvent* event);
	void resizeEvent(QResizeEvent* event);
	void repositionWidgets();

private:
	Ui::MainwindowClass ui;
	bool isClosed = false;
	QListWidget* p_listwidget;
	QTableView* p_tableView;
	QStandardItemModel* p_model;
	QTimer* p_timeUpdate;
	QVector<ClockNode> m_clockVec;
	ClockList p_clockList;				// ������ӽڵ������
	ClockNode* p_head;					// ͷָ��

	bool soundSwitch = true;			// ���ֿ���
	QSoundEffect* m_soundEffect;		// ��Ч����
	QSystemTrayIcon* m_tray = nullptr;	// ϵͳ����
};

#endif //MAINWINDOW_H
