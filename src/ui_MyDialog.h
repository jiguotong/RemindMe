/********************************************************************************
** Form generated from reading UI file 'MyDialogYRkOjz.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MYDIALOGYRKOJZ_H
#define MYDIALOGYRKOJZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyDialogClass
{
public:
    QLabel *labelIcon;
    QLabel *labelContent;
    QPushButton *btnClose;

    void setupUi(QDialog *MyDialogClass)
    {
        if (MyDialogClass->objectName().isEmpty())
            MyDialogClass->setObjectName(QString::fromUtf8("MyDialogClass"));
        MyDialogClass->resize(457, 122);
        labelIcon = new QLabel(MyDialogClass);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setGeometry(QRect(50, 20, 50, 50));
        labelIcon->setMinimumSize(QSize(50, 50));
        labelIcon->setMaximumSize(QSize(50, 50));
        labelContent = new QLabel(MyDialogClass);
        labelContent->setObjectName(QString::fromUtf8("labelContent"));
        labelContent->setGeometry(QRect(190, 20, 250, 50));
        labelContent->setAlignment(Qt::AlignCenter);
        btnClose = new QPushButton(MyDialogClass);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(180, 90, 75, 23));

        retranslateUi(MyDialogClass);

        QMetaObject::connectSlotsByName(MyDialogClass);
    } // setupUi

    void retranslateUi(QDialog *MyDialogClass)
    {
        MyDialogClass->setWindowTitle(QCoreApplication::translate("MyDialogClass", "MyDialog", nullptr));
        labelIcon->setText(QCoreApplication::translate("MyDialogClass", "TextLabel", nullptr));
        labelContent->setText(QCoreApplication::translate("MyDialogClass", "TextLabel", nullptr));
        btnClose->setText(QCoreApplication::translate("MyDialogClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyDialogClass: public Ui_MyDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MYDIALOGYRKOJZ_H
