// KanBrail.h : main header file for the KanBrail DLL
//

#if !defined(AFX_KanBrail_H__DF869228_FFA7_11D9_B107_0050BA32743E__INCLUDED_)
#define AFX_KanBrail_H__DF869228_FFA7_11D9_B107_0050BA32743E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CKanBrailApp
// See KanBrail.cpp for the implementation of this class
//

#define EXPORTED_DLL_FUNCTION \
	__declspec(dllexport)__stdcall

LRESULT EXPORTED_DLL_FUNCTION lSet_KeyBoard_KanBrail(int nCode,WPARAM wParam,LPARAM lParam);

BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_KanBrail(HWND hWnd);

BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_KanBrail();

LRESULT EXPORTED_DLL_FUNCTION lSet_KeyBoard_KanBrail_v1(int nCode,WPARAM wParam,LPARAM lParam);

BOOL EXPORTED_DLL_FUNCTION InstallKeyboardHook_KanBrail_v1(HWND hWnd);

BOOL EXPORTED_DLL_FUNCTION DeInstallKeyboardHook_KanBrail_v1();

BOOL EXPORTED_DLL_FUNCTION setVoiceFilePath(char *path);

void set_voice(int v);

static char text_to_read[127];
static int read_index = 0;
static int raw;


	static	  int f_key = 0;
	static	  int d_key = 0;
	static    int s_key = 0;
	static	  int j_key = 0;
	static	  int k_key = 0;
	static    int l_key = 0;

	int counter = 0;
char f1,f2;

void setChars(int f,int d,int s,int j,int k,int l);
void delete_char();
void read_word();
void read_last_letter(char c);
void addKey(int c);
void addKey_v2(int c);
void setVoiceFolder();
char* getVoiceFolder();

int compsubstr(char var[11],char buffer[127],int len,int k);
int compsubstr(char var[11],char buffer[127],int len);
int compstr(char buffer[127],int k);

int spacedchar();

char getBig(char c);

static char voiceFilePath[255];


class CKanBrailApp : public CWinApp
{
public:
	CKanBrailApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKanBrailApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	//}}AFX_VIRTUAL

	//{{AFX_MSG(CKanBrailApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KanBrail_H__DF869228_FFA7_11D9_B107_0050BA32743E__INCLUDED_)