#include <QApplication>
#include <QMutex>
#include <QDebug>
#include <QSharedMemory>
#include <QMessageBox>
#include <QDateTime>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include "Mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("RemindMe");
    qDebug() << "QApplication start!";

    // Time-limited build: valid for 180 days from base date
    QDateTime baseTime    = QDateTime::fromString("2026-01-01 00:00:00", "yyyy-MM-dd hh:mm:ss");
    QDateTime currentTime = QDateTime::currentDateTime();
    qint64 startTime = baseTime.toSecsSinceEpoch();
    qint64 endTime   = currentTime.toSecsSinceEpoch();
    if (endTime - startTime > 86400LL * 180) {
        QMessageBox::warning(nullptr, "Error", "Time permission exceeded! Please contact the developer!");
        return -1;
    }

    // Single-instance guard via shared memory.
    // Intentionally never deleted: shared memory must outlive the process
    // to block a second instance from launching.
    QMutex mutex;
    mutex.lock();
    static QSharedMemory* shareMem = new QSharedMemory("SingleApp");
    if (!shareMem->create(1)) {
        mutex.unlock();
        QMessageBox::information(nullptr, "Tip", "RemindMe is already running!");
        return -1;
    }
    mutex.unlock();

    Mainwindow w;
    w.showMaximized();

    int ret = a.exec();
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
    return ret;
}
