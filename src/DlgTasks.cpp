#include "DlgTasks.h"
#include <QMessageBox>
DlgTasks::DlgTasks(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool); // �ޱ߿�����
	setAttribute(Qt::WA_TranslucentBackground);// ����͸������

	//ui.lineEdit->setFocus(Qt::ActiveWindowFocusReason); //����Ĭ�Ͻ���

	connect(ui.btnConfirm, &QPushButton::clicked, this, &DlgTasks::OnBtnConfirm);
	connect(ui.btnCancel, &QPushButton::clicked, this, &DlgTasks::OnBtnCancel);
}

DlgTasks::~DlgTasks()
{}

void DlgTasks::OnBtnConfirm() {
	QString text = ui.lineEdit->text();
	if (text.isEmpty()) {
		QMessageBox::warning(this, "Warning", QStringLiteral("    ���ݲ�����Ϊ��    "));
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