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
