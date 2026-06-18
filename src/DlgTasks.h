#pragma once

#include <QDialog>
#include "ui_DlgTasks.h"

class DlgTasks : public QDialog
{
    Q_OBJECT

signals:
    void SendText(QString text, QString priority);

public:
    DlgTasks(QWidget *parent = nullptr);
    ~DlgTasks();

private slots:
    void OnBtnConfirm();
    void OnBtnCancel();

private:
    void closeEvent(QCloseEvent* e);
    void showEvent(QShowEvent* event);

private:
    Ui::DlgTasksClass ui;
};
