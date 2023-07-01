#ifndef _MYDIALOG_H
#define _MYDIALOG_H
#include <QDialog>
#include <QCloseEvent>
#include "ui_MyDialog.h"

class MyDialog : public QDialog
{
	Q_OBJECT

public:
	MyDialog(QWidget *parent = nullptr);
	~MyDialog();
	void SetLabelContent(QString);
	void SetLabelIcon(QString);

signals:
	void signalMyDialogBtnCloseClicked();		// 当点击关闭按钮时，发送此消息
public slots:
	void onBtnCloseClicked();

private:
	void closeEvent(QCloseEvent* event);
private:
	Ui::MyDialogClass ui;
};

#endif
