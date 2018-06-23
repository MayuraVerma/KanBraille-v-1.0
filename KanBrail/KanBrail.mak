# Microsoft Developer Studio Generated NMAKE File, Based on KanBrail.dsp
!IF "$(CFG)" == ""
CFG=KanBrail - Win32 Debug
!MESSAGE No configuration specified. Defaulting to KanBrail - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "KanBrail - Win32 Release" && "$(CFG)" != "KanBrail - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "KanBrail.mak" CFG="KanBrail - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "KanBrail - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "KanBrail - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "KanBrail - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\KanBrail.dll"


CLEAN :
	-@erase "$(INTDIR)\KanBrail.obj"
	-@erase "$(INTDIR)\KanBrail.pch"
	-@erase "$(INTDIR)\KanBrail.res"
	-@erase "$(INTDIR)\KeyComb.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\KanBrail.dll"
	-@erase "$(OUTDIR)\KanBrail.exp"
	-@erase "$(OUTDIR)\KanBrail.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\KanBrail.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\KanBrail.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\KanBrail.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\KanBrail.pdb" /machine:I386 /def:".\KanBrail.def" /out:"$(OUTDIR)\KanBrail.dll" /implib:"$(OUTDIR)\KanBrail.lib" 
DEF_FILE= \
	".\KanBrail.def"
LINK32_OBJS= \
	"$(INTDIR)\KanBrail.obj" \
	"$(INTDIR)\KeyComb.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\KanBrail.res"

"$(OUTDIR)\KanBrail.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "KanBrail - Win32 Debug"

OUTDIR=.\..\output
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\..\output
# End Custom Macros

ALL : "$(OUTDIR)\KanBrail.dll" "$(OUTDIR)\KanBrail.bsc"


CLEAN :
	-@erase "$(INTDIR)\KanBrail.obj"
	-@erase "$(INTDIR)\KanBrail.pch"
	-@erase "$(INTDIR)\KanBrail.res"
	-@erase "$(INTDIR)\KanBrail.sbr"
	-@erase "$(INTDIR)\KeyComb.obj"
	-@erase "$(INTDIR)\KeyComb.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\KanBrail.bsc"
	-@erase "$(OUTDIR)\KanBrail.dll"
	-@erase "$(OUTDIR)\KanBrail.exp"
	-@erase "$(OUTDIR)\KanBrail.ilk"
	-@erase "$(OUTDIR)\KanBrail.lib"
	-@erase "$(OUTDIR)\KanBrail.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

"$(INTDIR)" :
    if not exist "$(INTDIR)/$(NULL)" mkdir "$(INTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WINDLL" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\KanBrail.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\KanBrail.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\KanBrail.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\KanBrail.sbr" \
	"$(INTDIR)\KeyComb.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\KanBrail.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=..\output\SpeechLib.lib vfw32.lib Winmm.lib Kernel32.lib /nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\KanBrail.pdb" /debug /machine:I386 /def:".\KanBrail.def" /out:"$(OUTDIR)\KanBrail.dll" /implib:"$(OUTDIR)\KanBrail.lib" /pdbtype:sept 
DEF_FILE= \
	".\KanBrail.def"
LINK32_OBJS= \
	"$(INTDIR)\KanBrail.obj" \
	"$(INTDIR)\KeyComb.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\KanBrail.res"

"$(OUTDIR)\KanBrail.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("KanBrail.dep")
!INCLUDE "KanBrail.dep"
!ELSE 
!MESSAGE Warning: cannot find "KanBrail.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "KanBrail - Win32 Release" || "$(CFG)" == "KanBrail - Win32 Debug"
SOURCE=.\KanBrail.cpp

!IF  "$(CFG)" == "KanBrail - Win32 Release"


"$(INTDIR)\KanBrail.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\KanBrail.pch"


!ELSEIF  "$(CFG)" == "KanBrail - Win32 Debug"


"$(INTDIR)\KanBrail.obj"	"$(INTDIR)\KanBrail.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\KanBrail.pch"


!ENDIF 

SOURCE=.\KanBrail.rc

"$(INTDIR)\KanBrail.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\KeyComb.cpp

!IF  "$(CFG)" == "KanBrail - Win32 Release"


"$(INTDIR)\KeyComb.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\KanBrail.pch"


!ELSEIF  "$(CFG)" == "KanBrail - Win32 Debug"


"$(INTDIR)\KeyComb.obj"	"$(INTDIR)\KeyComb.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\KanBrail.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "KanBrail - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\KanBrail.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\KanBrail.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "KanBrail - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WINDLL" /D "_AFXDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\KanBrail.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\KanBrail.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

