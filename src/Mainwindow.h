#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QSoundEffect>
#include <QSystemTrayIcon>
#include <QResizeEvent>
#include <QKeyEvent>
#include <QMenu>
#include <QAction>
#include <QShortcut>
#include <QSlider>
#include "ui_Mainwindow.h"

struct ClockNode {
    int timerId = 0;
    QString time;
    QString content;
    QString repeat = "none"; // none/daily/weekly/workday
};

class Mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    Mainwindow(QWidget *parent = nullptr);
    ~Mainwindow();
    void initWindow();
    void initCheckBox();
    void initConnect();
    void initTable();

    static constexpr int PANEL_H   = 270;
    static constexpr int BTN_BAR_H = 60;
    static constexpr int HEADER_Y  = 80;
    static constexpr int HEADER_H  = 20;
    static constexpr int LIST_TOP  = 110;

public:
    int CalRow(QString newTime);
    void ShowSettings();
    void HideSettings();
    void ClearAll();
    void saveData();
    void loadData();

private slots:
    void checkboxStateChanged(int);
    void onBtnAddTaskClicked();
    void onBtnDelTaskClicked();
    void onBtnAddClockClicked();
    void onBtnDelClockClicked();
    void onBtnSwitchClicked();
    void onActivatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void slotTimerUpdate();
    void recQStr(QString, QString);
    void recMsg(QString, QString);
    void recCloseCommand();

private:
    void timerEvent(QTimerEvent* event);
    void closeEvent(QCloseEvent* event);
    void hideEvent(QHideEvent* event);
    void resizeEvent(QResizeEvent* event);
    void repositionWidgets();

private:
    Ui::MainwindowClass ui;
    bool isClosed = false;
    QListWidget* p_listwidget = nullptr;
    QTableView*  p_tableView  = nullptr;
    QStandardItemModel* p_model = nullptr;
    QTimer* p_timeUpdate = nullptr;
    QVector<ClockNode> m_clockVec;

    bool soundSwitch = true;
    QSoundEffect* m_soundEffect = nullptr;
    QSystemTrayIcon* m_tray = nullptr;
    bool m_alwaysOnTop = false;
    QAction* m_actionMute = nullptr;
};

#endif //MAINWINDOW_H
