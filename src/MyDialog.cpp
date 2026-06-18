#include "MyDialog.h"

MyDialog::MyDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    ui.labelContent->setWordWrap(true);
    connect(ui.btnClose,  &QPushButton::clicked, this, &MyDialog::onBtnCloseClicked);
    connect(ui.btnSnooze, &QPushButton::clicked, this, &MyDialog::onBtnSnoozeClicked);
    ui.btnClose->setDefault(true);
    ui.btnClose->setFocus();
}

MyDialog::~MyDialog() {}

void MyDialog::SetLabelContent(const QString& content)
{
    ui.labelContent->setText(content);
}

void MyDialog::SetLabelIcon(const QString& icon)
{
    QImage image(icon);
    ui.labelIcon->setPixmap(QPixmap::fromImage(image));
    ui.labelIcon->setScaledContents(true);
}

void MyDialog::onBtnCloseClicked()
{
    this->close();
}

void MyDialog::onBtnSnoozeClicked()
{
    int minutes = ui.spinSnooze->value();
    emit signalSnooze(minutes);
    this->close();
}

void MyDialog::closeEvent(QCloseEvent* event)
{
    emit signalMyDialogBtnCloseClicked();
    event->accept();
}

void MyDialog::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Escape)
        close();
    else
        QDialog::keyPressEvent(event);
}
