#include "DlgTasks.h"
#include <QMessageBox>
#include <QCloseEvent>

DlgTasks::DlgTasks(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    connect(ui.btnConfirm, &QPushButton::clicked, this, &DlgTasks::OnBtnConfirm);
    connect(ui.btnCancel,  &QPushButton::clicked, this, &DlgTasks::OnBtnCancel);
}

DlgTasks::~DlgTasks() {}

void DlgTasks::OnBtnConfirm()
{
    QString text = ui.lineEdit->text();
    if (text.isEmpty()) {
        QMessageBox::warning(this, "Warning", "    Content cannot be empty    ");
        return;
    }
    QString priorityText = ui.comboPriority->currentText();
    QString priority = "normal";
    if (priorityText == "High Priority")     priority = "high";
    else if (priorityText == "Low Priority") priority = "low";

    emit SendText(text, priority);
    this->close();
}

void DlgTasks::OnBtnCancel()
{
    this->close();
}

void DlgTasks::closeEvent(QCloseEvent* e)
{
    e->accept();
}

void DlgTasks::showEvent(QShowEvent* event)
{
    activateWindow();
    ui.lineEdit->setFocus();
    QDialog::showEvent(event);
}
