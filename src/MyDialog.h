#ifndef _MYDIALOG_H
#define _MYDIALOG_H
#include <QDialog>
#include "ui_MyDialog.h"

class MyDialog : public QDialog
{
	Q_OBJECT

public:
	MyDialog(QWidget *parent = nullptr);
	~MyDialog();
	void SetLabelContent(QString);
	void SetLabelIcon(QString);
private:
	Ui::MyDialogClass ui;
};

#endif
