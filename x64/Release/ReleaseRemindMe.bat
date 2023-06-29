C:\Qt\Qt5.14.1\5.14.1\msvc2017_64\bin\windeployqt.exe RemindMe.exe
xcopy .\Qt5Core.dll                 .\RemindMe\    /C /Y
xcopy .\Qt5Gui.dll                  .\RemindMe\    /C /Y
xcopy .\Qt5Svg.dll                  .\RemindMe\    /C /Y
xcopy .\Qt5Widgets.dll              .\RemindMe\    /C /Y
xcopy .\RemindMe.exe              .\RemindMe\    /C /Y
xcopy .\iconengines                 .\RemindMe\iconengines\     /C /E /H /Y
xcopy .\imageformats                 .\RemindMe\imageformats\     /C /E /H /Y
xcopy .\platforms                 .\RemindMe\platforms\     /C /E /H /Y
xcopy .\styles                 .\RemindMe\styles\     /C /E /H /Y
xcopy .\translations                 .\TextEdiRemindMetor\translations\     /C /E /H /Y
"C:\Program Files\WinRAR\WinRAR.exe" a ".\RemindMe.zip" ".\RemindMe"  /Y