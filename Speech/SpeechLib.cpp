// SpeechLib.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "SpeechLib.h"
#include "NonExported.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CSpeechLibApp

BEGIN_MESSAGE_MAP(CSpeechLibApp, CWinApp)
	//{{AFX_MSG_MAP(CSpeechLibApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpeechLibApp construction


HWND GetActiveForegroundWindow()
{
	HWND m_FrgWindow;

	m_FrgWindow = GetFocus();

	if(m_FrgWindow == NULL)
		m_FrgWindow = (HWND)GetForegroundWindow();

	return m_FrgWindow;
}

BOOL EXPORTED_DLL_FUNCTION Speak(HWND hWnd,const char *files,float m_time,int speed,
								 int length,int start_percent,int end_percent,
								 int Speed,int Volume)
{
	/*
	m_Video = MCIWndCreate(frgWnd,AfxGetInstanceHandle(),MCIWNDF_NOOPEN|MCIWNDF_NOPLAYBAR |MCIWNDF_NOMENU,"D:\\Braillie\\output\\da.mp3");
	MCIWndSetSpeed(m_Video,1050);
	MCIWndPlay(m_Video);
	Sleep(MCIWndGetLength(m_Video));
	DestroyWindow(m_Video);
	*/

	HWND m_Speech;
	long t;
	int Vol;
	int Spd;

	if(hWnd == NOCONSTRAINT)
	{
	hWnd = GetActiveForegroundWindow();
	}


	m_Speech = MCIWndCreate(hWnd,AfxGetInstanceHandle(),MCIWNDF_NOOPEN|MCIWNDF_NOPLAYBAR |MCIWNDF_NOMENU,files);

	
	if(Speed == NOCONSTRAINT)
	{
		t = MCIWndGetLength(m_Speech);

	}
	else
	{
		t = (long)m_time*1000;
	}

	if(Volume == NOCONSTRAINT)
	{
		Vol = 1000;

	}
	else
	{
		Vol = MCIWndSetVolume(m_Speech,Volume*1000);
	}

	if(Speed == NOCONSTRAINT)
	{
		Spd = 1000;
	}
	else
	{
		Spd = MCIWndSetVolume(m_Speech,Speed*1000);
	}



//	if(speed != NOCONSTRAINT)
//	MCIWndSetSpeed(m_Speech,speed);

//	if(length != NOCONSTRAINT)
//	MCIWndSetLength(m_Speech,speed);

//	if(start_percent != NOCONSTRAINT)
//	MCIWndSetSpeed(m_Speech,speed);

//	if(end_percent != NOCONSTRAINT)
//	MCIWndSetSpeed(m_Speech,speed);

	Play(m_Speech,t);
	DestroyWindow(m_Speech);
	
	return TRUE;
}



CSpeechLibApp::CSpeechLibApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSpeechLibApp object

CSpeechLibApp theApp;
