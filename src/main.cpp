#include <QApplication>
#include <QMutex>
#include <QDebug>
#include <QSharedMemory>
#include <QMessageBox>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "Mainwindow.h"
int main(int argc, char *argv[])
{
    // 检测内存泄漏
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    QApplication a(argc, argv);
    qDebug() << "QApplication start!";
    // 设置一个互斥量
    QMutex mutex;
    mutex.lock();// 开启临界区
    // 在临界区内创建SingleApp的共享内存块
    static QSharedMemory* shareMem = new QSharedMemory("SingleApp");
    if (!shareMem->create(1)) {
        mutex.unlock();// 关闭临界区
        QMessageBox::information(0, "Tip", "DentalScan has been running!");
        return -1;  // 创建失败，说明已有一个程序在运行，退出当前程序
    }
    mutex.unlock();// 关闭临界区

    Mainwindow w;
    w.show(); 

    return a.exec(); 
}

// 参考资料
//https://blog.csdn.net/lion_cxq/article/details/115101356
//https://blog.csdn.net/CXYYL/article/details/129275039

//https://blog.csdn.net/weixin_42692504/article/details/108065692 最小化到托盘

// 系统托盘
//trayIcon = new QSystemTrayIcon();
//trayIcon->setIcon(QIcon(":/logo.ico"));
//
//QMenu* menu = new QMenu();
//QAction* action = menu->addAction("退出");
//connect(action, &QAction::triggered, this, &Widget::systemExit);
//
//trayIcon->setContextMenu(menu);
//trayIcon->show();

// 表格QTableView
//https://blog.csdn.net/u010031316/article/details/116886567

//对话框需要改成单例模式避免一直申请内存
