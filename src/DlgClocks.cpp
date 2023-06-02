#include <QMessageBox>
#include "DlgClocks.h"

DlgClocks::DlgClocks(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); // 无边框设置
	setAttribute(Qt::WA_TranslucentBackground);// 背景透明设置

	connect(ui.btnConfirm, &QPushButton::clicked, this, &DlgClocks::OnBtnConfirm);
	connect(ui.btnCancel, &QPushButton::clicked, this, &DlgClocks::OnBtnCancel);
}

DlgClocks::~DlgClocks()
{}

void DlgClocks::OnBtnConfirm() {
	QString timeStr = ui.lineEditTime->text();
	QString contentStr = ui.lineEditContent->text();
	if (timeStr.isEmpty()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("时间不允许为空"));
		return;
	}
	if (contentStr.isEmpty()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("内容不允许为空"));
		return;
	}
	emit sendMsg(timeStr, contentStr);
	this->close();
}
void DlgClocks::OnBtnCancel() {
	this->close();
}

void DlgClocks::closeEvent(QCloseEvent* e) {
	this->close();
}
