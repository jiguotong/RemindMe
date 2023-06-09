#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
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
	QDateTime time = QDateTime::currentDateTime();//获取当前日期和时间
	QString strdTime = time.toString("hh:mm");//格式为年-月-日 小时-分钟-秒 星期
	time = QDateTime::fromString(strdTime, "hh:mm");
	if (date < time) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    请输入晚于此刻的时间    "));
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
void DlgClocks::showEvent(QShowEvent* event) {
	activateWindow();
	ui.lineEditTime->setFocus(); //设置默认焦点
}