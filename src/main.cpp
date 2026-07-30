#include <QApplication>
#include <QMutex>
#include <QDebug>
#include <QSharedMemory>
#include <QMessageBox>
#include <QDateTime>
#include <QInputDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QCoreApplication>
#include <QCryptographicHash>
#include <QDir>
#ifdef Q_OS_WIN
#include <windows.h>
#endif
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>

#include "Mainwindow.h"

// Prompt user to pick Guest / Owner mode at startup.
// Returns true if Owner mode chosen with correct password; false otherwise.
static bool askOwnerMode()
{
    QMessageBox box;
    box.setWindowTitle("RemindMe");
    box.setText(QString::fromUtf8("\xe8\xaf\xb7\xe9\x80\x89\xe6\x8b\xa9\xe4\xbd\xbf\xe7\x94\xa8\xe6\xa8\xa1\xe5\xbc\x8f"));   // 请选择使用模式
    QPushButton* guestBtn = box.addButton(QString::fromUtf8("\xe8\xae\xbf\xe5\xae\xa2\xe6\xa8\xa1\xe5\xbc\x8f"), QMessageBox::AcceptRole);      // 访客模式
    QPushButton* ownerBtn = box.addButton(QString::fromUtf8("\xe4\xb8\xbb\xe4\xba\xba\xe6\xa8\xa1\xe5\xbc\x8f"), QMessageBox::AcceptRole);      // 主人模式
    box.setDefaultButton(guestBtn);
    box.exec();

    if (box.clickedButton() != ownerBtn) {
        return false;  // Guest mode
    }

    // Owner mode: ask for password
    bool ok = false;
    QString pwd = QInputDialog::getText(
        nullptr,
        "RemindMe",
        QString::fromUtf8("\xe8\xaf\xb7\xe8\xbe\x93\xe5\x85\xa5\xe4\xb8\xbb\xe4\xba\xba\xe5\xaf\x86\xe7\xa0\x81\xef\xbc\x9a"),  // 请输入主人密码：
        QLineEdit::Password,
        QString(),
        &ok);
    if (!ok) {
        return false;  // Cancelled -> fall back to guest mode
    }
    // Compare against SHA-256 hash of the owner password (never store plaintext in binary).
    // Hash of "Jim1776220977":
    static const QByteArray kOwnerPwdSha256 =
        QByteArray::fromHex("f583220a41755853f6d393720fbe0a344ff31f74a12825ed38b8ed7a79ec14aa");
    QByteArray inputHash = QCryptographicHash::hash(pwd.toUtf8(), QCryptographicHash::Sha256);
    if (inputHash == kOwnerPwdSha256) {
        return true;
    }
    QMessageBox::warning(nullptr, "RemindMe",
        QString::fromUtf8("\xe5\xaf\x86\xe7\xa0\x81\xe9\x94\x99\xe8\xaf\xaf\xef\xbc\x8c\xe5\xb0\x86\xe4\xbb\xa5\xe8\xae\xbf\xe5\xae\xa2\xe6\xa8\xa1\xe5\xbc\x8f\xe8\xbf\x9b\xe5\x85\xa5"));  // 密码错误，将以访客模式进入
    return false;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("RemindMe");
    a.setOrganizationName("RemindMe");
    qDebug() << "QApplication start!";

    // Startup mode selection: only prompt on first launch; persist decision.
    // Persist to a file next to the exe (not plaintext -- store SHA-256 hash token).
    // Guest = time-limited (original 180-day logic); Owner = unlimited (password gated).
    static const QByteArray kOwnerPwdSha256 =
        QByteArray::fromHex("f583220a41755853f6d393720fbe0a344ff31f74a12825ed38b8ed7a79ec14aa");
    const QString modeFilePath = QCoreApplication::applicationDirPath() + "/.remindme_mode";
    // Fixed-length obfuscation tokens so the on-disk file reveals no plaintext keywords.
    const QByteArray kGuestToken = QCryptographicHash::hash(QByteArray("RemindMe::guest"), QCryptographicHash::Sha256).toHex();
    const QByteArray kOwnerToken = kOwnerPwdSha256.toHex();

    bool ownerMode = false;
    bool needPrompt = true;
    {
        QFile f(modeFilePath);
        if (f.exists() && f.open(QIODevice::ReadOnly)) {
            QByteArray token = f.readAll().trimmed();
            f.close();
            if (token == kOwnerToken) { ownerMode = true;  needPrompt = false; }
            else if (token == kGuestToken) { ownerMode = false; needPrompt = false; }
        }
    }
    if (needPrompt) {
        ownerMode = askOwnerMode();
        QFile f(modeFilePath);
        if (f.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
            f.write(ownerMode ? kOwnerToken : kGuestToken);
            f.close();
            // Best-effort hide the marker on Windows.
            SetFileAttributesW(reinterpret_cast<LPCWSTR>(QDir::toNativeSeparators(modeFilePath).utf16()),
                               FILE_ATTRIBUTE_HIDDEN);
        }
    }

    if (!ownerMode) {
        // Guest mode: time-limited build, valid for 180 days from base date
        QDateTime baseTime    = QDateTime::fromString("2026-07-01 00:00:00", "yyyy-MM-dd hh:mm:ss");
        QDateTime currentTime = QDateTime::currentDateTime();
        qint64 startTime = baseTime.toSecsSinceEpoch();
        qint64 endTime   = currentTime.toSecsSinceEpoch();
        if (endTime - startTime > 86400LL * 180) {
            QMessageBox::warning(nullptr, "Error", "Time permission exceeded! Please contact the developer!");
            return -1;
        }
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
