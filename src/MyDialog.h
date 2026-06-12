#ifndef _MYDIALOG_H
#define _MYDIALOG_H
#include <QDialog>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QSpinBox>
#include "ui_MyDialog.h"

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(QWidget *parent = nullptr);
    ~MyDialog();
    void SetLabelContent(const QString&);
    void SetLabelIcon(const QString&);

signals:
    void signalMyDialogBtnCloseClicked();
    void signalSnooze(int minutes);

private slots:
    void onBtnCloseClicked();
    void onBtnSnoozeClicked();

protected:
    void closeEvent(QCloseEvent* event);
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::MyDialogClass ui;
};

#endif
