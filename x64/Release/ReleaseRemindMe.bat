C:\Qt\Qt5.14.1\5.14.1\msvc2017_64\bin\windeployqt.exe RemindMe.exe
xcopy .\*.dll                        .\RemindMeApp\    /C /Y
xcopy .\RemindMe.exe                 .\RemindMeApp\    /C /Y

xcopy .\audio                        .\RemindMeApp\audio\     /C /E /H /Y
xcopy .\bearer                       .\RemindMeApp\bearer\     /C /E /H /Y
xcopy .\iconengines                  .\RemindMeApp\iconengines\     /C /E /H /Y
xcopy .\imageformats                 .\RemindMeApp\imageformats\     /C /E /H /Y
xcopy .\mediaservice                 .\RemindMeApp\mediaservice\     /C /E /H /Y
xcopy .\playlistformats              .\RemindMeApp\playlistformats\     /C /E /H /Y
xcopy .\platforms                    .\RemindMeApp\platforms\     /C /E /H /Y
xcopy .\styles                       .\RemindMeApp\styles\     /C /E /H /Y
xcopy .\translations                 .\RemindMeApp\translations\     /C /E /H /Y
xcopy ..\..\font                     .\RemindMeApp\font\     /C /E /H /Y
"C:\Program Files\WinRAR\WinRAR.exe" a ".\RemindMeApp.rar" ".\RemindMeApp"  /Y