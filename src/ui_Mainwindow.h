/********************************************************************************
** Form generated from reading UI file 'MainwindowawXLfF.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWAWXLFF_H
#define MAINWINDOWAWXLFF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainwindowClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAdd;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnDel;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnAddClock;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btnDelClock;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelDate;
    QLabel *labelTime;
    QLabel *labelImage;

    void setupUi(QMainWindow *MainwindowClass)
    {
        if (MainwindowClass->objectName().isEmpty())
            MainwindowClass->setObjectName(QString::fromUtf8("MainwindowClass"));
        MainwindowClass->resize(1200, 800);
        MainwindowClass->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	font: 25 12pt '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"	color: rgb(255,255,255);\n"
"	background-color: rgb(20,196,188);\n"
"	border:none;\n"
"	min-width:75px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:24px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
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
"#centralWidget\n"
"{\n"
"	background-color: #E7F7F3;\n"
"}\n"
""));
        centralWidget = new QWidget(MainwindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 80, 200, 20));
        label->setStyleSheet(QString::fromUtf8("\n"
"	font: 25 12pt '\346\200\235\346\272\220\351\273\221\344\275\223 CN BOLD';\n"
"	color: rgb(255,255,255);\n"
"	background-color: rgb(251,102,102);\n"
"	border:none;\n"
""));
        label->setAlignment(Qt::AlignCenter);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 680, 1200, 60));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(150);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(300, 60));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnAdd = new QPushButton(frame);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        horizontalLayout->addWidget(btnAdd);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btnDel = new QPushButton(frame);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));

        horizontalLayout->addWidget(btnDel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        horizontalLayout_3->addWidget(frame);

        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(300, 60));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(34, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnAddClock = new QPushButton(frame_2);
        btnAddClock->setObjectName(QString::fromUtf8("btnAddClock"));

        horizontalLayout_2->addWidget(btnAddClock);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        btnDelClock = new QPushButton(frame_2);
        btnDelClock->setObjectName(QString::fromUtf8("btnDelClock"));

        horizontalLayout_2->addWidget(btnDelClock);

        horizontalSpacer_4 = new QSpacerItem(34, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        horizontalLayout_3->addWidget(frame_2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(800, 80, 60, 20));
        label_2->setStyleSheet(QString::fromUtf8("border-right-style: solid;\n"
"border-right-width: 1px;\n"
"border-right-color: white;\n"
"border-right: 1px solid white;\n"
"\n"
"font: 25 12pt '\346\200\235\346\272\220\351\273\221\344\275\223 CN BOLD';\n"
"color: rgb(255,255,255);\n"
"background-color: rgb(251,102,102);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(860, 80, 140, 20));
        label_3->setStyleSheet(QString::fromUtf8("font: 25 12pt '\346\200\235\346\272\220\351\273\221\344\275\223 CN BOLD';\n"
"color: rgb(255,255,255);\n"
"background-color: rgb(251,102,102);\n"
"border:none;"));
        label_3->setAlignment(Qt::AlignCenter);
        labelDate = new QLabel(centralWidget);
        labelDate->setObjectName(QString::fromUtf8("labelDate"));
        labelDate->setGeometry(QRect(512, 110, 171, 41));
        labelDate->setStyleSheet(QString::fromUtf8("font: 25 12pt '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"color : #F89F92;\n"
"font-weight:bold;\n"
"border:none;\n"
"background-color: #E7F7F3;"));
        labelDate->setAlignment(Qt::AlignCenter);
        labelTime = new QLabel(centralWidget);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(510, 170, 171, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Pixel LCD7"));
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        labelTime->setFont(font);
        labelTime->setStyleSheet(QString::fromUtf8("font: 25 20pt 'Pixel LCD7';\n"
"color : #F89F92;\n"
"font-weight:bold;\n"
"border:none;\n"
"background-color: #E7F7F3;"));
        labelTime->setAlignment(Qt::AlignCenter);
        labelImage = new QLabel(centralWidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(460, 360, 281, 191));
        labelImage->setPixmap(QPixmap(QString::fromUtf8(":/res/panda.gif")));
        labelImage->setScaledContents(true);
        MainwindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainwindowClass);

        QMetaObject::connectSlotsByName(MainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainwindowClass)
    {
        MainwindowClass->setWindowTitle(QCoreApplication::translate("MainwindowClass", "Mainwindow", nullptr));
        label->setText(QCoreApplication::translate("MainwindowClass", "\346\210\221  \347\232\204  \346\227\245  \347\250\213", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainwindowClass", "\346\267\273\345\212\240", nullptr));
        btnDel->setText(QCoreApplication::translate("MainwindowClass", "\345\210\240\351\231\244", nullptr));
        btnAddClock->setText(QCoreApplication::translate("MainwindowClass", "\346\267\273\345\212\240", nullptr));
        btnDelClock->setText(QCoreApplication::translate("MainwindowClass", "\347\274\226\350\276\221", nullptr));
        label_2->setText(QCoreApplication::translate("MainwindowClass", "\346\227\266  \351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("MainwindowClass", "\345\206\205      \345\256\271", nullptr));
        labelDate->setText(QCoreApplication::translate("MainwindowClass", "2023\345\271\2646\346\234\2107\346\227\245 \346\230\237\346\234\237\344\270\211", nullptr));
        labelTime->setText(QCoreApplication::translate("MainwindowClass", "00:00:00", nullptr));
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainwindowClass: public Ui_MainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWAWXLFF_H
