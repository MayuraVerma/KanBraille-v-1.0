@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by THEJASVI.HPJ. >"hlp\Thejasvi.hm"
echo. >>"hlp\Thejasvi.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Thejasvi.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Thejasvi.hm"
echo. >>"hlp\Thejasvi.hm"
echo // Prompts (IDP_*) >>"hlp\Thejasvi.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Thejasvi.hm"
echo. >>"hlp\Thejasvi.hm"
echo // Resources (IDR_*) >>"hlp\Thejasvi.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Thejasvi.hm"
echo. >>"hlp\Thejasvi.hm"
echo // Dialogs (IDD_*) >>"hlp\Thejasvi.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Thejasvi.hm"
echo. >>"hlp\Thejasvi.hm"
echo // Frame Controls (IDW_*) >>"hlp\Thejasvi.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Thejasvi.hm"
REM -- Make help for Project THEJASVI


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Thejasvi.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Thejasvi.hlp" goto :Error
if not exist "hlp\Thejasvi.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Thejasvi.hlp" Debug
if exist Debug\nul copy "hlp\Thejasvi.cnt" Debug
if exist Release\nul copy "hlp\Thejasvi.hlp" Release
if exist Release\nul copy "hlp\Thejasvi.cnt" Release
echo.
goto :done

:Error
echo hlp\Thejasvi.hpj(1) : error: Problem encountered creating help file

:done
echo.
