# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build

```powershell
$env:QTDIR = 'D:\Qt\5.14.1\msvc2017_64'
$env:QtMsBuild = 'C:\Users\72218526\AppData\Local\QtMsBuild'
& 'C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\MSBuild\Current\Bin\MSBuild.exe' `
  'E:\AI\Projects\Github\RemindMe\RemindMe.sln' `
  /p:Configuration=Release /p:Platform=x64 `
  '/p:QTDIR=D:\Qt\5.14.1\msvc2017_64' '/p:QtMsBuild=C:\Users\72218526\AppData\Local\QtMsBuild' /m /v:minimal
```

**Run:** `Start-Process 'E:\AI\Projects\Github\RemindMe\x64\Release\RemindMe.exe'` (add `D:\Qt\5.14.1\msvc2017_64\bin` to PATH first)

**Active branch:** `feature/ai-upgrade`

## Current Features

- Real-time clock display (LCD font, date + time)
- Task list with priority (High=red / Normal=green / Low=gray), checkbox completion with strikethrough
- Alarms with time-sorted table, repeat modes (none/daily/weekly/workday), sound alert
- Reminder popup with Snooze (1–60 min spinbox) + Enter/Esc keyboard dismiss
- Data persistence: auto-save on exit / auto-load on startup via JSON (`AppDataLocation/remindme_data.json`)
- System tray: minimize to tray, right-click menu (Open / Mute / Quit)
- Settings panel (slide-in drawer): sound toggle, always-on-top, opacity slider
- Keyboard shortcuts: Ctrl+Q/W (task add/del), Ctrl+E/R (alarm add/del), Delete key on list/table
- Fullscreen/resizable layout — all widgets reflow via `repositionWidgets()` on resize

## Architecture

- `Mainwindow` — main window; alarms in `QVector<ClockNode>`; layout via `repositionWidgets()` / `resizeEvent`
- `DlgTasks` — add task dialog; emits `SendText(text, priority)` → `recQStr(str, priority)`
- `DlgClocks` — add alarm dialog; emits `sendMsg(time, content)` → `recMsg(time, content)`
- `MyDialog` — reminder popup; emits `signalSnooze(int minutes)` and `signalMyDialogBtnCloseClicked`
- `Mainwindow::saveData()` / `loadData()` — JSON persistence via `QStandardPaths` + `QJsonDocument`

## Key Constraints

- Mixed encoding (original GBK + new UTF-8); `/utf-8` compiler flag set in `.vcxproj` — **never write Chinese string literals in `.cpp`/`.h`**, use English or `QString::fromUtf8()`
- `.ui` files are UTF-8 and can contain Chinese safely
- Layout constants in `Mainwindow.h` as `static constexpr int`: `PANEL_H`, `BTN_BAR_H`, `HEADER_Y`, `HEADER_H`, `LIST_TOP`
- `ClockNode.repeat`: `"none"` / `"daily"` / `"weekly"` / `"workday"`
- Full-width colon input handled via `QString::fromUtf8("\xef\xbc\x9a")` replacement in `DlgClocks`
- Settings panel z-order: `p_listwidget` and `p_tableView` must be parented to `ui.centralWidget` so `raise()` works correctly
