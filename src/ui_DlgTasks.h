/********************************************************************************
** Form generated from reading UI file 'DlgTasksevmQQM.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLGTASKSEVMQQM_H
#define DLGTASKSEVMQQM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgTasksClass
{
public:
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *btnConfirm;
    QPushButton *btnCancel;

    void setupUi(QWidget *DlgTasksClass)
    {
        if (DlgTasksClass->objectName().isEmpty())
            DlgTasksClass->setObjectName(QString::fromUtf8("DlgTasksClass"));
        DlgTasksClass->resize(402, 85);
        DlgTasksClass->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(DlgTasksClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 371, 61));
        frame->setStyleSheet(QString::fromUtf8("#frame\n"
"{\n"
" 	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 220), stop:1 rgba(20,196,188, 230));\n"
"	border:none;\n"
"	border-radius:10px;\n"
"}\n"
"#lineEdit\n"
"{\n"
"	font: 25 12pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"	color: rgb(31,31,31);\n"
"	padding-left:20px; \n"
"	background-color: rgb(255, 255, 255);\n"
"	border:1px solid rgb(20,196,188);\n"
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
"	background-color: rgb(17,171,1"
                        "64);\n"
"}\n"
""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        btnConfirm = new QPushButton(frame);
        btnConfirm->setObjectName(QString::fromUtf8("btnConfirm"));

        horizontalLayout->addWidget(btnConfirm);

        btnCancel = new QPushButton(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        retranslateUi(DlgTasksClass);

        QMetaObject::connectSlotsByName(DlgTasksClass);
    } // setupUi

    void retranslateUi(QWidget *DlgTasksClass)
    {
        DlgTasksClass->setWindowTitle(QCoreApplication::translate("DlgTasksClass", "DlgTasks", nullptr));
        btnConfirm->setText(QCoreApplication::translate("DlgTasksClass", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgTasksClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgTasksClass: public Ui_DlgTasksClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLGTASKSEVMQQM_H
