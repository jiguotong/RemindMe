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
    // ����ڴ�й©
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    QApplication a(argc, argv);
    qDebug() << "QApplication start!";
    // ����һ��������
    QMutex mutex;
    mutex.lock();// �����ٽ���
    // ���ٽ����ڴ���SingleApp�Ĺ����ڴ��
    static QSharedMemory* shareMem = new QSharedMemory("SingleApp");
    if (!shareMem->create(1)) {
        mutex.unlock();// �ر��ٽ���
        QMessageBox::information(0, "Tip", "DentalScan has been running!");
        return -1;  // ����ʧ�ܣ�˵������һ�����������У��˳���ǰ����
    }
    mutex.unlock();// �ر��ٽ���

    Mainwindow w;
    w.show(); 

    return a.exec(); 
}

// �ο�����
//https://blog.csdn.net/lion_cxq/article/details/115101356
//https://blog.csdn.net/CXYYL/article/details/129275039

//https://blog.csdn.net/weixin_42692504/article/details/108065692 ��С��������

// ϵͳ����
//trayIcon = new QSystemTrayIcon();
//trayIcon->setIcon(QIcon(":/logo.ico"));
//
//QMenu* menu = new QMenu();
//QAction* action = menu->addAction("�˳�");
//connect(action, &QAction::triggered, this, &Widget::systemExit);
//
//trayIcon->setContextMenu(menu);
//trayIcon->show();

// ���QTableView
//https://blog.csdn.net/u010031316/article/details/116886567

//�Ի�����Ҫ�ĳɵ���ģʽ����һֱ�����ڴ�
