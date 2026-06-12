#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include "DlgClocks.h"

DlgClocks::DlgClocks(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); // �ޱ߿�����
	setAttribute(Qt::WA_TranslucentBackground);// ����͸������
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
	QDateTime date = QDateTime::fromString(timeStr, "h:mm");
	if (!date.isValid()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    ʱ���ʽ����ȷ    "));
		return;
	}
	QDateTime time = QDateTime::currentDateTime();//��ȡ��ǰ���ں�ʱ��
	QString strdTime = time.toString("h:mm");
	time = QDateTime::fromString(strdTime, "h:mm");
	if (date < time) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    ���������ڴ˿̵�ʱ��    "));
		return;
	}


	
	// 归一化为 hh:mm（补零），保证主窗口 CalRow/recMsg 解析一致
	timeStr = QDateTime::fromString(timeStr, "h:mm").toString("hh:mm");
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
	ui.lineEditTime->setFocus(); //����Ĭ�Ͻ���
}