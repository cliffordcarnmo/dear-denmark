@echo off
SETLOCAL ENABLEDELAYEDEXPANSION

echo Cleanup in ..\data\
del ..\data\*.h

SET SFX=..\data\*.mod
SET GFX=..\data\*.tga

SET /a COUNTER=0

FOR %%i IN (%SFX%) DO (
echo Converting %%i to ..\data\%%~ni.h
echo #include ^<windows.h^> > ..\data\%%~ni.h
echo #include ^<wtypes.h^> >> ..\data\%%~ni.h
echo: >> ..\data\%%~ni.h
..\tools\bin2h.exe %%i >> ..\data\%%~ni.h -id=%%~ni
set /a COUNTER=!COUNTER+1
)

FOR %%i IN (%GFX%) DO (
echo Converting %%i to ..\data\%%~ni.h
echo #include ^<windows.h^> > ..\data\%%~ni.h
echo #include ^<wtypes.h^> >> ..\data\%%~ni.h
echo: >> ..\data\%%~ni.h
..\tools\bin2h.exe %%i >> ..\data\%%~ni.h -id=%%~ni
set /a COUNTER=!COUNTER+1
)

echo Converted !COUNTER! files