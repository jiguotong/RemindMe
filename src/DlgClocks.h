#pragma once

#include <QDialog>
#include "ui_DlgClocks.h"

class DlgClocks : public QDialog
{
    Q_OBJECT

signals:
    void sendMsg(QString time, QString content);

public:
    DlgClocks(QWidget *parent = nullptr);
    ~DlgClocks();

private slots:
    void OnBtnConfirm();
    void OnBtnCancel();

private:
    void closeEvent(QCloseEvent* e);
    void showEvent(QShowEvent* event);

private:
    Ui::DlgClocksClass ui;
};
