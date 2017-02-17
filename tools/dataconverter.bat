@echo off
SETLOCAL ENABLEDELAYEDEXPANSION

echo Cleanup in ..\data\*.c
del ..\data\*.c

REM echo #include "dataLoader.h" > ..\src\system\dataLoader.c
REM echo #include "graphics.h" >> ..\src\system\dataLoader.c
REM echo #include "texture.h" >> ..\src\system\dataLoader.c

REM echo: >> ..\src\system\dataLoader.c

SET SFX=..\data\*.mod
SET GFX=..\data\*.tga

FOR %%i IN (%SFX%) DO (
echo Converting %%i to ..\data\%%~ni.c
echo #include ^<windows.h^> > ..\data\%%~ni.c
echo #include ^<wtypes.h^> >> ..\data\%%~ni.c
echo: >> ..\data\%%~ni.c
..\tools\bin2h.exe %%i >> ..\data\%%~ni.c -id=%%~ni
)

SET /a COUNTER=0
FOR %%i IN (%GFX%) DO (
echo Converting %%i to ..\data\%%~ni.c
echo #include ^<windows.h^> > ..\data\%%~ni.c
echo #include ^<wtypes.h^> >> ..\data\%%~ni.c
echo: >> ..\data\%%~ni.c
..\tools\bin2h.exe %%i >> ..\data\%%~ni.c -id=%%~ni
REM echo extern unsigned char %%~ni; >> ..\src\system\dataLoader.c
REM echo extern unsigned int %%~ni_len; >> ..\src\system\dataLoader.c
set /a COUNTER=!COUNTER+1
)

REM echo Generating ..\src\system\dataLoader.c

REM echo: >> ..\src\system\dataLoader.c
REM echo GLuint textures[!COUNTER!]; >> ..\src\system\dataLoader.c
REM echo: >> ..\src\system\dataLoader.c

REM echo void loadData(){ >> ..\src\system\dataLoader.c

SET /a COUNTER=0
FOR %%i IN (%GFX%) DO (
REM echo textures[!COUNTER!] = loadTextureFromMemory^(^&%%~ni, %%~ni_len^); >> ..\src\system\dataLoader.c
set /a COUNTER=!COUNTER+1
)

REM echo } >> ..\src\system\dataLoader.c

echo Done