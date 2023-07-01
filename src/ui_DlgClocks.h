/********************************************************************************
** Form generated from reading UI file 'DlgClocksvIkrne.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLGCLOCKSVIKRNE_H
#define DLGCLOCKSVIKRNE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DlgClocksClass
{
public:
    QFrame *frame;
    QPushButton *btnConfirm;
    QPushButton *btnCancel;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditTime;
    QLineEdit *lineEditContent;

    void setupUi(QDialog *DlgClocksClass)
    {
        if (DlgClocksClass->objectName().isEmpty())
            DlgClocksClass->setObjectName(QString::fromUtf8("DlgClocksClass"));
        DlgClocksClass->resize(470, 157);
        frame = new QFrame(DlgClocksClass);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 441, 131));
        frame->setStyleSheet(QString::fromUtf8("#frame\n"
"{\n"
" 	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(251,102,102, 220), stop:1 rgba(20,196,188, 230));\n"
"	border:none;\n"
"	border-radius:10px;\n"
"}\n"
"#lineEditTime\n"
"{\n"
"	font: 25 12pt '\345\276\256\350\275\257\351\233\205\351\273\221 Light';\n"
"	color: rgb(31,31,31);\n"
"	padding-left:20px; \n"
"	background-color: rgb(255, 255, 255);\n"
"	border:1px solid rgb(20,196,188);\n"
"	border-radius:10px;\n"
"}\n"
"#lineEditContent\n"
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
"	font: 25 12pt '\345\276\256\350\275\257\351\233\205"
                        "\351\273\221';\n"
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
""));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        btnConfirm = new QPushButton(frame);
        btnConfirm->setObjectName(QString::fromUtf8("btnConfirm"));
        btnConfirm->setGeometry(QRect(130, 90, 71, 21));
        btnConfirm->setFocusPolicy(Qt::StrongFocus);
        btnCancel = new QPushButton(frame);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(230, 90, 61, 21));
        btnCancel->setFocusPolicy(Qt::StrongFocus);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(60, 30, 316, 45));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEditTime = new QLineEdit(frame_2);
        lineEditTime->setObjectName(QString::fromUtf8("lineEditTime"));

        horizontalLayout->addWidget(lineEditTime);

        lineEditContent = new QLineEdit(frame_2);
        lineEditContent->setObjectName(QString::fromUtf8("lineEditContent"));
        lineEditContent->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(lineEditContent);


        retranslateUi(DlgClocksClass);

        QMetaObject::connectSlotsByName(DlgClocksClass);
    } // setupUi

    void retranslateUi(QDialog *DlgClocksClass)
    {
        DlgClocksClass->setWindowTitle(QCoreApplication::translate("DlgClocksClass", "DlgClocks", nullptr));
        btnConfirm->setText(QCoreApplication::translate("DlgClocksClass", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("DlgClocksClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgClocksClass: public Ui_DlgClocksClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLGCLOCKSVIKRNE_H
