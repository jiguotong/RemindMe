#pragma once

#include <QDialog>
#include "ui_DlgTasks.h"
//Q_GLOBAL_STATIC(DlgTasks, g_dlgTasks);
class DlgTasks : public QDialog
{
	Q_OBJECT

signals:
	void SendText(QString str);
public:
	DlgTasks(QWidget *parent = nullptr);
	~DlgTasks();

public:
	void OnBtnConfirm();
	void OnBtnCancel();
	
private:
	void closeEvent(QCloseEvent* e);
private:
	Ui::DlgTasksClass ui;
};
