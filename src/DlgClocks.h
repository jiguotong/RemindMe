#pragma once

#include <QDialog>
#include "ui_DlgClocks.h"

class DlgClocks : public QDialog
{
	Q_OBJECT

signals:
	void sendMsg(QString,QString);
public:
	DlgClocks(QWidget *parent = nullptr);
	~DlgClocks();

public:
	void OnBtnConfirm();
	void OnBtnCancel();
	void closeEvent(QCloseEvent* e);
private:
	Ui::DlgClocksClass ui;
};