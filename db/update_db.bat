@ECHO OFF

REM ------------------------------------
REM Paths
REM ------------------------------------
SET PRJ_ROOT=..\..\driver_g140v2
SET PRJ_src=%PRJ_ROOT%\src
SET PRJ_inc=%PRJ_ROOT%\inc
SET LOCAL_PATH=%~dp0
SET GUI_BUILD_DEBUG_X64=..\build\Debug\x64

REM ------------------------------------
REM  Genera Database da excel
REM ------------------------------------
ECHO:
ECHO Elimina files...

del params_data.csv
del process_data.csv
del param_process_data.c
del param_process_data.h
ECHO ^> done.

REM ------------------------------------
REM  Genera Database da excel
REM ------------------------------------
ECHO:
ECHO Generazione database...

start generate_database.exe
if %ERRORLEVEL% EQU 0 ECHO ^> done.
timeout 3

REM ------------------------------------
REM Copia dei files
REM ------------------------------------
ECHO:
ECHO Copia dei dati...

copy param_process_data.c %PRJ_src%\param_process_data.c
copy param_process_data.h %PRJ_inc%\param_process_data.h
copy params_data.csv %GUI_BUILD_DEBUG_X64%\params_data.csv
copy process_data.csv %GUI_BUILD_DEBUG_X64%\process_data.csv

ECHO ^> done.

:N
ECHO See you!
pause