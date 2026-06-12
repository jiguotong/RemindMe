#include <QMessageBox>
#include <QDateTime>
#include <QTime>
#include <QDebug>
#include <QCloseEvent>
#include "DlgClocks.h"

DlgClocks::DlgClocks(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    connect(ui.btnConfirm, &QPushButton::clicked, this, &DlgClocks::OnBtnConfirm);
    connect(ui.btnCancel,  &QPushButton::clicked, this, &DlgClocks::OnBtnCancel);
}

DlgClocks::~DlgClocks() {}

void DlgClocks::OnBtnConfirm()
{
    QString timeStr    = ui.lineEditTime->text();
    QString contentStr = ui.lineEditContent->text();

    if (timeStr.isEmpty()) {
        QMessageBox::warning(this, "Warning", "    Time cannot be empty    ");
        return;
    }
    if (contentStr.isEmpty()) {
        QMessageBox::warning(this, "Warning", "    Content cannot be empty    ");
        return;
    }

    // Allow Chinese colon
    timeStr = timeStr.replace(QString::fromUtf8("\xef\xbc\x9a"), ":"); // full-width colon -> half-width

    // Accept both h:mm and hh:mm
    QTime inputTime = QTime::fromString(timeStr, "h:mm");
    if (!inputTime.isValid()) {
        QMessageBox::warning(this, "Warning", "    Invalid time format. Use hh:mm    ");
        return;
    }

    // Validate not in the past (compare full datetime)
    QDateTime now = QDateTime::currentDateTime();
    QDateTime target(now.date(), inputTime);
    if (target <= now) {
        QMessageBox::warning(this, "Warning", "    Cannot set a time in the past    ");
        return;
    }

    // Normalize to hh:mm
    timeStr = inputTime.toString("hh:mm");
    emit sendMsg(timeStr, contentStr);
    this->close();
}

void DlgClocks::OnBtnCancel()
{
    this->close();
}

void DlgClocks::closeEvent(QCloseEvent* e)
{
    e->accept();
}

void DlgClocks::showEvent(QShowEvent* event)
{
    activateWindow();
    ui.lineEditTime->setFocus();
    QDialog::showEvent(event);
}
