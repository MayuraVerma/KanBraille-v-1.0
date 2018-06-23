// ThejasviDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Thejasvi.h"
#include "ThejasviDlg.h"
#include "..\KanBrail\KanBrail.h"
//#include "..\Netravathi\Netravathi.h"
#include "SpeechLib.h"

#define BUFSIZE MAX_PATH

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

 TCHAR Buffer[BUFSIZE];
 DWORD dwRet;


int voice_s = 1;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThejasviDlg dialog

CThejasviDlg::CThejasviDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThejasviDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThejasviDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThejasviDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThejasviDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX, IDC_STATIC_MALE, m_MaleVoice);
	DDX_Control(pDX, IDC_STATIC_FEMALE, m_FemaleVoice);
	DDX_Control(pDX, IDC_STATIC_CONVERTER, m_Converter);
	DDX_Control(pDX, IDC_STATIC_BRAILLIE, m_Braillie);
	DDX_Control(pDX, IDC_STATIC_KAN_BRAILLIE, m_KanBraillie);

	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThejasviDlg, CDialog)
	//{{AFX_MSG_MAP(CThejasviDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	//ON_BN_CLICKED(IDC_RADIO_MALE, OnMale)
	//ON_BN_CLICKED(IDC_RADIO_FEMALE, OnFemale)

	//ON_BN_CLICKED(IDC_TEXT_CONVERTER, OnTextConverter)
	//ON_BN_CLICKED(IDC_KAN_BRAILLIE, OnKanBraillie)
	//ON_BN_CLICKED(IDC_BUTTON_BRAILLIE, OnButtonBraillie)
	
	//ON_BN_CLICKED(IDC_STATIC,OnButtonBraillie)


	ON_BN_CLICKED(IDC_STATIC_MALE, OnMale)
	ON_BN_CLICKED(IDC_STATIC_FEMALE, OnFemale)

	ON_BN_CLICKED(IDC_STATIC_CONVERTER, OnTextConverter)
	ON_BN_CLICKED(IDC_STATIC_KAN_BRAILLIE, OnKanBraillie)
	ON_BN_CLICKED(IDC_STATIC_BRAILLIE, OnButtonBraillie)
	ON_BN_CLICKED(IDC_STATIC_HELP,OnHelp)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThejasviDlg message handlers

BOOL CThejasviDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	LOGFONT lf;

    memset(&lf,0,sizeof(LOGFONT));
	lf.lfHeight = 26; // Request a 100-pixel-height font

	// DP and LP are always the same on CE - The conversion below is used by CFont::CreateFontIndirect

	HDC hDC=::GetDC(NULL);

	//lf.lfHeight = ::GetDeviceCaps(hDC,LOGPIXELSY) * lf.lfHeight;

//	ReleaseDC(hDC);

	//lf.lfHeight /= 720; // 72 points/inch, 10 decipoints/point

//	if(lf.lfHeight > 0)

  //   lf.lfHeight *= -1;

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//	InstallKeyboardHook_KanBrail(GetSafeHwnd(),1);

	 //Speak(NOCONSTRAINT,"G:\\Track 10.mp3",NOCONSTRAINT,NOCONSTRAINT,NOCONSTRAINT,NOCONSTRAINT,20,50);
	m_FemaleVoice.LoadButtonBitmaps(IDB_FEMALE,IDB_FEMALE,IDB_FEMALE_1);
	m_MaleVoice.LoadButtonBitmaps(IDB_MALE,IDB_MALE,IDB_MALE_1);
	m_Converter.LoadButtonBitmaps(IDB_Parivarthaka,IDB_Parivarthaka,IDB_Parivarthaka);
	
	m_Braillie.LoadButtonBitmaps(IDB_Anikethana,IDB_Anikethana,IDB_Anikethana_1);

	m_KanBraillie.LoadButtonBitmaps(IDB_Anutthara,IDB_Anutthara,IDB_Anutthara_1);
	
    OnResetButtonImages();




lstrcpy(lf.lfFaceName, _T("Ani"));

HFONT font =::CreateFontIndirect(&lf);

CWnd* myButton = GetDlgItem(IDC_ANIKETANA); //The Button with regular font
myButton->SendMessage(WM_SETFONT, (WPARAM)font, TRUE);

 myButton = GetDlgItem(IDC_F_VOICE); //The Button with regular font
myButton->SendMessage(WM_SETFONT, (WPARAM)font, TRUE);

 myButton = GetDlgItem(IDC_M_VOICE); //The Button with regular font
myButton->SendMessage(WM_SETFONT, (WPARAM)font, TRUE);

 myButton = GetDlgItem(IDC_EXIT); //The Button with regular font
myButton->SendMessage(WM_SETFONT, (WPARAM)font, TRUE);

lstrcpy(lf.lfFaceName, _T("Anu"));

font =::CreateFontIndirect(&lf);

 myButton = GetDlgItem(IDC_ANUTTARA); //The Button with regular font
myButton->SendMessage(WM_SETFONT, (WPARAM)font, TRUE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CThejasviDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CThejasviDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CThejasviDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CThejasviDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


HWND GetActiveForegroundWindow()
{
	HWND m_FrgWindow;

	m_FrgWindow = GetFocus();

	if(m_FrgWindow == NULL)
		m_FrgWindow = (HWND)GetForegroundWindow();

	return m_FrgWindow;
}


void CThejasviDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	//	InstallKeyboardHook_Test_1(GetSafeHwnd());
	//	  InstallKeyboardHook_Netravathi(GetSafeHwnd());

//	InstallKeyboardHook_KanBrail(GetSafeHwnd(),1);
//	InstallKeyboardHook_Test_1(GetSafeHwnd());
/*Speak(HWND hWnd,const char *files,float m_time,
								 int length,int start_percent,int end_percent,
								 int Speed,int Volume);

	HWND m_Speech = MCIWndCreate(GetActiveForegroundWindow(),AfxGetInstanceHandle(),MCIWNDF_NOOPEN|MCIWNDF_NOPLAYBAR |MCIWNDF_NOMENU,"G:\\Track 10.mp3");
*/
 /*   Speak(NOCONSTRAINT,"G:\\Track 10.mp3",NOCONSTRAINT,
								 NOCONSTRAINT,NOCONSTRAINT,NOCONSTRAINT,
	*/					//		 20,50,0);
//	Test();
} 


   

void CThejasviDlg::OnTextConverter() 
{
	// TODO: Add your control notification handler code here

	STARTUPINFO si_splash;
	PROCESS_INFORMATION pi_splash;
	
	ZeroMemory(&si_splash,sizeof(si_splash));
//	ZeroMemory(&si_window,sizeof(si_window));

	si_splash.cb = sizeof(si_splash);
//	si_window.cb = sizeof(si_window);

	ZeroMemory(&pi_splash,sizeof(pi_splash));


	 if(!CreateProcess(NULL,
		"Text_Converter.exe",
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si_splash,
		&pi_splash))
	
	 ::WaitForSingleObjectEx(pi_splash.hProcess,INFINITE,FALSE);
	//printf("Child Complete");

	//closes handles
	CloseHandle(pi_splash.hProcess);
    CloseHandle(pi_splash.hThread);
}

void CThejasviDlg::OnKanBraillie() 
{

	//		m_FemaleVoice.ResetButton();
	//m_MaleVoice.ResetButton();
//	m_Converter.ResetButton();
//	m_KanBraillie.ResetButton();
	m_Braillie.ResetButton();
	
	TCHAR Buffer1[255];

//	FILE *fp;

 //  dwRet = GetCurrentDirectory(BUFSIZE,Buffer);
	GetCurrentDirectory(BUFSIZE,Buffer);
//	GetSystemDirectory(Buffer1,BUFSIZE);

//	strcat(Buffer1,"\\VoiceFolder.txt");

 //  ::MessageBox(NULL,"File read",Buffer,MB_OK);

//	fp = fopen(Buffer1,"w");
//		fprintf(fp,"%s",Buffer);
//	fclose(fp);

//setVoiceFilePath("c:\\KanBrail\\");
		DeInstallKeyboardHook_KanBrail();
		//DeInstallKeyboardHook_KanBrail_v1();
		InstallKeyboardHook_KanBrail_v1(GetSafeHwnd());

	// TODO: Add your control notification handler code here

PlaySound("c:\\kanBrail\\voice\\b1.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\ba225.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\bb377.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\b41.wav",NULL,SND_SYNC);

}

void CThejasviDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	DeInstallKeyboardHook_KanBrail();
	DeInstallKeyboardHook_KanBrail_v1();

	PlaySound("c:\\kanBrail\\voice\\ba399.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\b41.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\ba32.wav ",NULL,SND_SYNC);

	CDialog::OnCancel();
}

void CThejasviDlg::OnButtonBraillie() 
{

	m_KanBraillie.ResetButton();

	TCHAR Buffer1[MAX_PATH];

//	FILE *fp;

 //  dwRet = GetCurrentDirectory(BUFSIZE,Buffer);
	GetCurrentDirectory(BUFSIZE,Buffer);
//	GetSystemDirectory(Buffer1,BUFSIZE);

//	strcat(Buffer1,"\\VoiceFolder.txt");

 //  ::MessageBox(NULL,"File read",Buffer,MB_OK);

//	fp = fopen(Buffer1,"w");
//		fprintf(fp,"%s",Buffer);
//	fclose(fp);

	//setVoiceFilePath("c:\\KanBrail\\");

	// TODO: Add your control notification handler code here
		DeInstallKeyboardHook_KanBrail_v1();
	//	DeInstallKeyboardHook_KanBrail();
		InstallKeyboardHook_KanBrail(GetSafeHwnd());

PlaySound("c:\\kanBrail\\voice\\b1.wav ",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\ba223.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\ba7.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\b30.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\b34.wav",NULL,SND_SYNC);

}

void CThejasviDlg::OnMale()
{

	m_FemaleVoice.ResetButton();
	//m_MaleVoice.ResetButton();
	m_Converter.ResetButton();
	//	m_KanBraillie.ResetButton();
	//	m_Braillie.ResetButton();

	//	::MessageBox(NULL,"gfbv","fgbgf",MB_OK);
	FILE *fp;
int a = 8;

 //  dwRet = GetCurrentDirectory(BUFSIZE,Buffer);
	//GetSystemDirectory(Buffer,BUFSIZE);
    //strcat(Buffer,"\\VoiceConfig.txt");

 //  ::MessageBox(NULL,"File read",Buffer,MB_OK);

	fp = fopen("c:\\KanBrail\\VoiceConfig.txt","w");
		fprintf(fp,"%d",a);
	fclose(fp);

	PlaySound("c:\\kanBrail\\voice\\ba238.wav",NULL,SND_SYNC);
	PlaySound("c:\\kanBrail\\voice\\ba316.wav",NULL,SND_SYNC);
	PlaySound("c:\\kanBrail\\voice\\b45.wav",NULL,SND_SYNC);
	PlaySound("c:\\kanBrail\\voice\\bb436.wav",NULL,SND_SYNC);
	PlaySound("c:\\kanBrail\\voice\\ba223.wav",NULL,SND_SYNC);


	return;
}

void CThejasviDlg::OnFemale()
{

	//	m_FemaleVoice.ResetButton();
	m_MaleVoice.ResetButton();
	m_Converter.ResetButton();
//	m_KanBraillie.ResetButton();
//	m_Braillie.ResetButton();



	FILE *fp;
int a = 0;

  // dwRet = GetCurrentDirectory(BUFSIZE,Buffer);
//GetSystemDirectory(Buffer,BUFSIZE);

   //strcat(Buffer,"\\VoiceConfig.txt");

  // ::MessageBox(NULL,"File read",Buffer,MB_OK);
	fp = fopen("c:\\KanBrail\\VoiceConfig.txt","w");
		fprintf(fp,"%d",a);
	fclose(fp);

	PlaySound("c:\\kanBrail\\voice\\a39.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\aa392.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\aa404.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\ab436.wav",NULL,SND_SYNC);
PlaySound("c:\\kanBrail\\voice\\aa223.wav",NULL,SND_SYNC);
	return;
}


void CThejasviDlg::OnHelp()
{

}

void CThejasviDlg::OnResetButtonImages()
{
	m_FemaleVoice.ResetButton();
	m_MaleVoice.ResetButton();
	m_Converter.ResetButton();
	m_KanBraillie.ResetButton();
	m_Braillie.ResetButton();

}


