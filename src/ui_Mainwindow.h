/********************************************************************************
** Form generated from reading UI file 'MainwindowZOnhRv.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWZONHRV_H
#define MAINWINDOWZONHRV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainwindowClass
{
public:
    QWidget *centralWidget;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

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
""));
        centralWidget = new QWidget(MainwindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(150);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 600, 0, 0);
        frame = new QFrame(centralWidget);
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

        frame_2 = new QFrame(centralWidget);
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

        MainwindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainwindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        MainwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainwindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainwindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainwindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainwindowClass->setStatusBar(statusBar);

        retranslateUi(MainwindowClass);

        QMetaObject::connectSlotsByName(MainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainwindowClass)
    {
        MainwindowClass->setWindowTitle(QCoreApplication::translate("MainwindowClass", "Mainwindow", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainwindowClass", "\345\242\236\345\212\240", nullptr));
        btnDel->setText(QCoreApplication::translate("MainwindowClass", "\345\210\240\351\231\244", nullptr));
        btnAddClock->setText(QCoreApplication::translate("MainwindowClass", "\346\267\273\345\212\240", nullptr));
        btnDelClock->setText(QCoreApplication::translate("MainwindowClass", "\347\274\226\350\276\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainwindowClass: public Ui_MainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWZONHRV_H
