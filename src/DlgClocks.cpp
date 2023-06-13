#include <QMessageBox>
#include <QDateTime>
#include "DlgClocks.h"

DlgClocks::DlgClocks(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); // �ޱ߿�����
	setAttribute(Qt::WA_TranslucentBackground);// ����͸������
	//ui.lineEditTime->setFocus(); //����Ĭ�Ͻ���
	connect(ui.btnConfirm, &QPushButton::clicked, this, &DlgClocks::OnBtnConfirm);
	connect(ui.btnCancel, &QPushButton::clicked, this, &DlgClocks::OnBtnCancel);
}

DlgClocks::~DlgClocks()
{}

void DlgClocks::OnBtnConfirm() {
	QString timeStr = ui.lineEditTime->text();
	QString contentStr = ui.lineEditContent->text();
	if (timeStr.isEmpty()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    ʱ�䲻����Ϊ��    "));
		return;
	}
	if (contentStr.isEmpty()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    ���ݲ�����Ϊ��    "));
		return;
	}
	// ��ֹ���������µķֺ�
	timeStr = timeStr.replace(QStringLiteral("��"), ":");

	// ���ʱ���ʽ�Ƿ�Ϊhh:mm
	QDateTime date = QDateTime::fromString(timeStr, "hh:mm");
	if (!date.isValid()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    ʱ���ʽ����ȷ    "));
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
