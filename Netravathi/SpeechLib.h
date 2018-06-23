// SpeechLib.h : main header file for the SPEECHLIB DLL
//

#define NOCONSTRAINT 0

#if !defined(AFX_SPEECHLIB_H__64066187_2B6F_4EB4_90F5_0A9F1BFF4C6C__INCLUDED_)
#define AFX_SPEECHLIB_H__64066187_2B6F_4EB4_90F5_0A9F1BFF4C6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSpeechLibApp
// See SpeechLib.cpp for the implementation of this class
//

#define EXPORTED_DLL_FUNCTION \
	__declspec(dllexport)__stdcall

/*
LRESULT EXPORTED_DLL_FUNCTION lSet_KeyBoard_Test_1(int nCode,WPARAM wParam, LPARAM lParam);

BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_Test_1( HWND hWnd);

BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_Test_1();*/


BOOL EXPORTED_DLL_FUNCTION Speak(HWND hWnd,const char *files,float m_time,
								 int length,int start_percent,int end_percent,
								 int Speed,int Volume);

BOOL EXPORTED_DLL_FUNCTION Speak_v2(HWND hWnd,const char *files,float m_time,
								 int length,int start_percent,int end_percent,
								 int Speed,int Volume);

BOOL EXPORTED_DLL_FUNCTION Test();

class CSpeechLibApp : public CWinApp
{
public:
	CSpeechLibApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpeechLibApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CSpeechLibApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEECHLIB_H__64066187_2B6F_4EB4_90F5_0A9F1BFF4C6C__INCLUDED_)
