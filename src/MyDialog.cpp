#include "MyDialog.h"

MyDialog::MyDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::Tool);		// �ޱ߿�����
	setAttribute(Qt::WA_TranslucentBackground);				// ����͸������
	ui.labelContent->setWordWrap(true);                     // true���Զ�����
	connect(ui.btnClose, &QPushButton::clicked, this, &MyDialog::onBtnCloseClicked);
}

MyDialog::~MyDialog()
{}

void MyDialog::SetLabelContent(QString content)
{
	ui.labelContent->setText(content);
}

void MyDialog::SetLabelIcon(QString icon)
{
	QImage image(icon);
	
	ui.labelIcon->setPixmap(QPixmap::fromImage(image));
	ui.labelIcon->setScaledContents(true);
}

void MyDialog::onBtnCloseClicked() {
	this->close();
}

void MyDialog::closeEvent(QCloseEvent* event) {
	emit signalMyDialogBtnCloseClicked();
	event->accept();
}
