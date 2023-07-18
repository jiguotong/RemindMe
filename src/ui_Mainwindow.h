/********************************************************************************
** Form generated from reading UI file 'MainwindowamFEIE.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWAMFEIE_H
#define MAINWINDOWAMFEIE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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
    QFrame *frameSettings;
    QPushButton *btnHideSettings;
    QPushButton *btnClear;
    QPushButton *btnSwitch;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btnShowSettings;

    void setupUi(QMainWindow *MainwindowClass)
    {
        if (MainwindowClass->objectName().isEmpty())
            MainwindowClass->setObjectName(QString::fromUtf8("MainwindowClass"));
        MainwindowClass->resize(1200, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/windowIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainwindowClass->setWindowIcon(icon);
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
        frameSettings = new QFrame(centralWidget);
        frameSettings->setObjectName(QString::fromUtf8("frameSettings"));
        frameSettings->setEnabled(true);
        frameSettings->setGeometry(QRect(0, 270, 150, 270));
        frameSettings->setStyleSheet(QString::fromUtf8("#frameSettings\n"
"{\n"
"	background-color: #fb6666;\n"
"}\n"
"#btnSwitch\n"
"{\n"
"	min-width:0px;		/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"	min-height:0px;	/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"	background-color: #fb6666;\n"
"	background-image: url('qrc:/res/switch_on.png');\n"
"    background-position: center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"#btnClear\n"
"{\n"
"	min-width:0px;		/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"	min-height:0px;	/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"	background-color: #fb6666;\n"
"    background-position: center;\n"
"    background-repeat: no-repeat;\n"
"}\n"
"#btnClear:hover\n"
"{\n"
"	background-color: rgb(22,218,208);\n"
"}\n"
"#btnClear:pressed\n"
"{\n"
"	background-color: rgb(17,171,164);\n"
"}\n"
"#btnHideSettings\n"
"{\n"
"/*\n"
"	font: 25 12pt '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
""
                        "	color: rgb(255,255,255);\n"
"	background-color: rgb(20,196,188);\n"
"	border:none;\n"
"	min-width:75px;		//\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246\n"
"    min-height:24px;	//\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246\n"
"	border-radius:10px;*/\n"
"	background-color: #fb6666;\n"
"	min-width:0px;		/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"	min-height:0px;	/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"}\n"
"#btnHideSettings:hover\n"
"{\n"
"	background-color: rgb(22,218,208);\n"
"}\n"
"QLabel\n"
"{\n"
"	font: 25 12pt '\346\200\235\346\272\220\351\273\221\344\275\223 CN BOLD';\n"
"	color: rgb(255,255,255);\n"
"	border:border\n"
"}"));
        frameSettings->setFrameShape(QFrame::StyledPanel);
        frameSettings->setFrameShadow(QFrame::Raised);
        btnHideSettings = new QPushButton(frameSettings);
        btnHideSettings->setObjectName(QString::fromUtf8("btnHideSettings"));
        btnHideSettings->setGeometry(QRect(135, 105, 15, 80));
        btnHideSettings->setMinimumSize(QSize(0, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/line_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHideSettings->setIcon(icon1);
        btnClear = new QPushButton(frameSettings);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setGeometry(QRect(82, 50, 31, 24));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/res/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear->setIcon(icon2);
        btnSwitch = new QPushButton(frameSettings);
        btnSwitch->setObjectName(QString::fromUtf8("btnSwitch"));
        btnSwitch->setGeometry(QRect(77, 90, 51, 24));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/res/switch_on.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSwitch->setIcon(icon3);
        btnSwitch->setIconSize(QSize(80, 40));
        label_4 = new QLabel(frameSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(-4, 50, 71, 21));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5 = new QLabel(frameSettings);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(16, 90, 51, 20));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(frameSettings);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 150, 30));
        label_6->setStyleSheet(QString::fromUtf8("border-bottom-style: solid;\n"
"border-bottom-width: 1px;\n"
"border-bottom-color: white;\n"
"border-bottom: 1px solid white;"));
        label_6->setAlignment(Qt::AlignCenter);
        btnShowSettings = new QPushButton(centralWidget);
        btnShowSettings->setObjectName(QString::fromUtf8("btnShowSettings"));
        btnShowSettings->setGeometry(QRect(0, 375, 10, 80));
        btnShowSettings->setStyleSheet(QString::fromUtf8("#btnShowSettings\n"
"{\n"
"/*\n"
"	font: 25 12pt '\345\276\256\350\275\257\351\233\205\351\273\221';\n"
"	color: rgb(255,255,255);\n"
"	background-color: rgb(20,196,188);\n"
"	border:none;*/\n"
"	border-radius:0px;\n"
"	background-color: #fb6666;\n"
"	min-width:0px;		/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"	min-height:0px;	/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"}\n"
"#btnShowSettings:hover\n"
"{\n"
"	background-color: rgb(22,218,208);\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/res/line_right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnShowSettings->setIcon(icon4);
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
        btnDelClock->setText(QCoreApplication::translate("MainwindowClass", "\345\210\240\351\231\244", nullptr));
        label_2->setText(QCoreApplication::translate("MainwindowClass", "\346\227\266  \351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("MainwindowClass", "\345\206\205      \345\256\271", nullptr));
        labelDate->setText(QCoreApplication::translate("MainwindowClass", "2023\345\271\2646\346\234\2107\346\227\245 \346\230\237\346\234\237\344\270\211", nullptr));
        labelTime->setText(QCoreApplication::translate("MainwindowClass", "00:00:00", nullptr));
        labelImage->setText(QString());
        btnHideSettings->setText(QString());
        btnClear->setText(QString());
        btnSwitch->setText(QString());
        label_4->setText(QCoreApplication::translate("MainwindowClass", "\344\270\200\351\224\256\346\270\205\347\251\272", nullptr));
        label_5->setText(QCoreApplication::translate("MainwindowClass", "\346\217\220\347\244\272\351\237\263", nullptr));
        label_6->setText(QCoreApplication::translate("MainwindowClass", "\350\256\276  \347\275\256", nullptr));
        btnShowSettings->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainwindowClass: public Ui_MainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWAMFEIE_H
