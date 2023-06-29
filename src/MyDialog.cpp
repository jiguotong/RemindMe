#include "MyDialog.h"

MyDialog::MyDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
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
