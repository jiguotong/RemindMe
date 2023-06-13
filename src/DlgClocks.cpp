#include <QMessageBox>
#include <QDateTime>
#include "DlgClocks.h"

DlgClocks::DlgClocks(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); // 无边框设置
	setAttribute(Qt::WA_TranslucentBackground);// 背景透明设置
	//ui.lineEditTime->setFocus(); //设置默认焦点
	connect(ui.btnConfirm, &QPushButton::clicked, this, &DlgClocks::OnBtnConfirm);
	connect(ui.btnCancel, &QPushButton::clicked, this, &DlgClocks::OnBtnCancel);
}

DlgClocks::~DlgClocks()
{}

void DlgClocks::OnBtnConfirm() {
	QString timeStr = ui.lineEditTime->text();
	QString contentStr = ui.lineEditContent->text();
	if (timeStr.isEmpty()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    时间不允许为空    "));
		return;
	}
	if (contentStr.isEmpty()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    内容不允许为空    "));
		return;
	}
	// 防止输入中文下的分号
	timeStr = timeStr.replace(QStringLiteral("："), ":");

	// 检查时间格式是否为hh:mm
	QDateTime date = QDateTime::fromString(timeStr, "hh:mm");
	if (!date.isValid()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    时间格式不正确    "));
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
