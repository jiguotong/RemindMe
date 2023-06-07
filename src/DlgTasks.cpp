#include "DlgTasks.h"
#include <QMessageBox>
DlgTasks::DlgTasks(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); // 无边框设置
	setAttribute(Qt::WA_TranslucentBackground);// 背景透明设置

	//ui.lineEdit->setFocus(Qt::ActiveWindowFocusReason); //设置默认焦点

	connect(ui.btnConfirm, &QPushButton::clicked, this, &DlgTasks::OnBtnConfirm);
	connect(ui.btnCancel, &QPushButton::clicked, this, &DlgTasks::OnBtnCancel);
}

DlgTasks::~DlgTasks()
{}

void DlgTasks::OnBtnConfirm() {
	QString text = ui.lineEdit->text();
	if (text.isEmpty()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    内容不允许为空    "));
		return;
	}
	emit SendText(text);
	this->close();
}
void DlgTasks::OnBtnCancel() {
	this->close();
}

void DlgTasks::closeEvent(QCloseEvent* e) {
	this->close();
}