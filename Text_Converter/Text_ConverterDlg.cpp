// Text_ConverterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Text_Converter.h"
#include "Text_ConverterDlg.h"
#include "Converter.h"
	STARTUPINFO si_splash;
	PROCESS_INFORMATION pi_splash;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CText_ConverterDlg dialog

CText_ConverterDlg::CText_ConverterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CText_ConverterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CText_ConverterDlg)
		// NOTE: the ClassWizard will add member initialization here
		m_strSRC = _T("");
		m_strDST = _T("");
		m_chkScale = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CText_ConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CText_ConverterDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Text(pDX, IDC_SRC_PATH, m_strSRC);
	DDV_MaxChars(pDX, m_strSRC, 255);
	DDX_Text(pDX, IDC_DST_PATH, m_strDST);
	DDV_MaxChars(pDX, m_strDST, 255);
	DDX_Control(pDX,IDC_PROGRESS1,m_ctlProgress);
//	DDX_Control(pDX,IDC_STATIC,m_ctlBmp);
//	DDX_Check(pDX, IDC_CHECK_SCALE, m_chkScale);

	DDX_Control(pDX, IDC_STATIC_BTOK, m_BtoS);
	DDX_Control(pDX, IDC_STATIC_KTOB, m_StoB);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CText_ConverterDlg, CDialog)
	//{{AFX_MSG_MAP(CText_ConverterDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_SURABHI, OnSurabhi)
	ON_BN_CLICKED(IDC_STATIC_BTOK, OnSrg)
	ON_BN_CLICKED(IDC_RADIO_AKRUTHI, OnAkruthi)
	ON_BN_CLICKED(IDC_SRC, OnSrcFileSelect)
	ON_BN_CLICKED(IDC_DST, OnDscFileSelect)
	ON_BN_CLICKED(IDC_STATIC_CONVERT, OnConvert)
	ON_BN_CLICKED(IDC_STATIC_KTOB, OnSreeLipi)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CText_ConverterDlg message handlers

BOOL CText_ConverterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
//////////////////////////////////////////////////////////////////////////
	// BIT MAP INITIALIASATION CODE//

	m_ctlBmp.LoadBitmap(IDB_BITMAP1);

	BlitBitmap(m_rcLft,m_ctlBmp);

	m_rcLft.left = 523 ;m_rcLft.right = 598;
	m_rcLft.top = 70; m_rcLft.bottom = 145;

		m_BtoS.LoadButtonBitmaps(IDB_BTOS,IDB_BTOS,IDB_BTOS_1);
		m_StoB.LoadButtonBitmaps(IDB_STOB,IDB_STOB,IDB_STOB_1);

		m_BtoS.ResetButton();
		m_StoB.ResetButton();

/////////////////////////////////////////////////////////////////////////
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CText_ConverterDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CText_ConverterDlg::OnPaint() 
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





void CText_ConverterDlg::OnSrcFileSelect() 
{
	// TODO: Add your control notification handler code here
		CString OpenFilter;
	OpenFilter = "TXT Files (*.txt)|*.txt||";

//	::MessageBox(NULL,"dfvd","bgb",MB_OK):		

	//file open dialog for selecting XML files
	CFileDialog FileOpenDialog(
		TRUE,
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_PATHMUSTEXIST,
		OpenFilter,					// filter
		AfxGetMainWnd());		
	//::MessageBox(NULL,"gffr","brgb",MB_OK);
	if(FileOpenDialog.DoModal()==IDOK)
	{
		m_strSRC = FileOpenDialog.GetPathName();
		UpdateData(FALSE);
	}	

}

void CText_ConverterDlg::OnDscFileSelect() 
{
	// TODO: Add your control notification handler code here
		CString OpenFilter;
	OpenFilter = "TXT Files (*.txt)|*.txt||";
		

	//file open dialog for selecting XML files
	CFileDialog FileOpenDialog(
		TRUE,
		NULL,
		NULL,
		OFN_HIDEREADONLY | OFN_PATHMUSTEXIST,
		OpenFilter,					// filter
		AfxGetMainWnd());	
	if(FileOpenDialog.DoModal()==IDOK)
	{
		m_strDST = FileOpenDialog.GetPathName();
		UpdateData(FALSE);
	}	
//	else
///		m_strDST = '\0';
}




// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CText_ConverterDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CText_ConverterDlg::OnSreeLipi() 
{
	// TODO: Add your control notification handler code here
	m_BtoS.ResetButton();
	Choice = 2;
	
}

void CText_ConverterDlg::OnSurabhi() 
{
	// TODO: Add your control notification handler code here
	Choice = 3;
}

void CText_ConverterDlg::OnSrg() 
{
	// TODO: Add your control notification handler code here
	m_StoB.ResetButton();
	Choice = 1;
}

void CText_ConverterDlg::OnAkruthi() 
{
	// TODO: Add your control notification handler code here
	Choice = 4;
}


void CText_ConverterDlg::OnCancel() 
{
	// TODO: Add extra cleAkruthip here
CDialog::OnCancel();
}


//on OK 
void CText_ConverterDlg::OnConvert() 
{
	int Conv_Status;
	int l,m;
	TCHAR  Buffer[255];
	FILE *fp2;


	GetSystemDirectory(Buffer,255);

    strcat(Buffer,"\\File_names.txt");

    fp2 = fopen(Buffer,"w");
	
//	fscanf(fp2,"%s%s",input_file,output_file);
//	printf("%s%s",input_file,output_file);

	fprintf(fp2,m_strSRC);
	fprintf(fp2,"|");
	fprintf(fp2,m_strDST);

	fclose(fp2);

	
	UpdateData(TRUE);

	// TODO: Add your control notification handler code here
	//::MessageBox(NULL,m_strSRC,m_strDST,MB_OK);
//	Text_Converter t_conv;


	
switch (Choice)
	{
		case 1:
	
   m_ctlProgress.SetRange(0, 100);
for (l = 0; l < 50; l++)
{
     m_ctlProgress.SetPos(l);
	 m = 10;
	 while(m>0)
	 {
	//	 Sleep(1);
		 m--;
	 }
}

   Conv_Status = TRUE;//t_conv.Srg_To_Kuvempu(m_strSRC,m_strDST);


	ZeroMemory(&si_splash,sizeof(si_splash));
//	ZeroMemory(&si_window,sizeof(si_window));

	si_splash.cb = sizeof(si_splash);
//	si_window.cb = sizeof(si_window);

	ZeroMemory(&pi_splash,sizeof(pi_splash));


	 if(!CreateProcess(NULL,
		"Converter_Comp_1.exe",
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

for (l = 50; l < 100; l++)
{
     m_ctlProgress.SetPos(l);
	 m = 10;
	 while(m>0)
	 {
	//	 Sleep(1);
		 m--;
	 }
}
		break;

case 2:
	m_ctlProgress.SetRange(0, 100);
for (l = 0; l < 50; l++)
{
     m_ctlProgress.SetPos(l);
	 m = 10;
	 while(m>0)
	 {
	//	 Sleep(1);
		 m--;
	 }
}

		Conv_Status = TRUE;//t_conv.SreeLipi_To_Kuvempu(m_strSRC,m_strDST);
	
	ZeroMemory(&si_splash,sizeof(si_splash));
//	ZeroMemory(&si_window,sizeof(si_window));

	si_splash.cb = sizeof(si_splash);
//	si_window.cb = sizeof(si_window);

	ZeroMemory(&pi_splash,sizeof(pi_splash));


	 if(!CreateProcess(NULL,
		"Converter_Comp_2.exe",
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




			for (l = 50; l < 100; l++)
{
     m_ctlProgress.SetPos(l);
	 m = 10;
	 while(m>0)
	 {
	//	 Sleep(1);
		 m--;
	 }
}
//::MessageBox(NULL,"Conversion Completed SreeLipi_To_Kuvempu" ,"ALERT....",MB_OK);
		break;
	}
	if(Conv_Status == TRUE)
	{
		//::MessageBox(NULL,"File Conversion OK","Status",MB_OK);
	}
	else
	{
		//::MessageBox(NULL,"Conversion FAILED !!! Check Path Names","Status",MB_OK);
	}
}

void CText_ConverterDlg::BlitBitmap(CRect& rc,CBitmap& bm) 
{
	CClientDC dc(this);

	CDC dcMem;
	HBITMAP hbmpOld;

	dcMem.CreateCompatibleDC(&dc);
	hbmpOld = (HBITMAP)dcMem.SelectObject(bm);

	GetDC()->BitBlt(rc.left,rc.top,rc.right,rc.bottom,&dcMem,0,0,SRCCOPY);
	dcMem.SelectObject(hbmpOld);
}
