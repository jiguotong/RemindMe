/********************************************************************************
** Form generated from reading UI file 'MyDialogjKeNET.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MYDIALOGJKENET_H
#define MYDIALOGJKENET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MyDialogClass
{
public:
    QFrame *frame;
    QLabel *labelIcon;
    QLabel *labelContent;
    QPushButton *btnClose;

    void setupUi(QDialog *MyDialogClass)
    {
        if (MyDialogClass->objectName().isEmpty())
            MyDialogClass->setObjectName(QString::fromUtf8("MyDialogClass"));
        MyDialogClass->resize(450, 125);
        MyDialogClass->setMinimumSize(QSize(450, 125));
        MyDialogClass->setMaximumSize(QSize(450, 125));
        MyDialogClass->setStyleSheet(QString::fromUtf8("#frame\n"
"{\n"
" 	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 220), stop:1 rgba(20,196,188, 230));\n"
"	border:none;\n"
"	border-radius:10px;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"	font: 25 12pt '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"	color: rgb(255,255,255);\n"
"	background-color: rgb(20,196,188);\n"
"	border:none;\n"
"	border-radius:10px;\n"
"}\n"
"QPushButton\n"
"{\n"
"	font: 25 12pt '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"	color: rgb(255,255,255);\n"
"	background-color: rgb(20,196,188);\n"
"	border:none;\n"
"	border-radius:10px;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(22,218,208);\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: rgb(17,171,164);\n"
"}\n"
"#labelContent\n"
"{\n"
"    font: bold normal 18px \"Microsoft YaHei\";\n"
"	color: rgb(255,255,255);\n"
"}"));
        frame = new QFrame(MyDialogClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 10, 450, 111));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        labelIcon = new QLabel(frame);
        labelIcon->setObjectName(QString::fromUtf8("labelIcon"));
        labelIcon->setGeometry(QRect(10, 8, 20, 20));
        labelIcon->setMinimumSize(QSize(20, 20));
        labelIcon->setMaximumSize(QSize(20, 20));
        labelContent = new QLabel(frame);
        labelContent->setObjectName(QString::fromUtf8("labelContent"));
        labelContent->setGeometry(QRect(66, 20, 311, 50));
        labelContent->setAlignment(Qt::AlignCenter);
        btnClose = new QPushButton(frame);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(180, 80, 75, 23));

        retranslateUi(MyDialogClass);

        QMetaObject::connectSlotsByName(MyDialogClass);
    } // setupUi

    void retranslateUi(QDialog *MyDialogClass)
    {
        MyDialogClass->setWindowTitle(QCoreApplication::translate("MyDialogClass", "MyDialog", nullptr));
        labelIcon->setText(QString());
        labelContent->setText(QString());
        btnClose->setText(QCoreApplication::translate("MyDialogClass", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyDialogClass: public Ui_MyDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MYDIALOGJKENET_H
