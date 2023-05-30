#include <QApplication>
#include <QMutex>
#include <QDebug>
#include <QSharedMemory>
#include <QMessageBox>
#include "Mainwindow.h"
int main(int argc, char *argv[])
{
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
