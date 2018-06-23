// ThejasviDlg.h : header file
//
#include "BmpButton.h"

#if !defined(AFX_THEJASVIDLG_H__D3431746_C353_464F_8B27_DAEFF804DFD2__INCLUDED_)
#define AFX_THEJASVIDLG_H__D3431746_C353_464F_8B27_DAEFF804DFD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CThejasviDlg dialog
//int voice_s = 1;

class CThejasviDlg : public CDialog
{
// Construction
public:
	CThejasviDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CThejasviDlg)
	enum { IDD = IDD_THEJASVI_DIALOG };
		// NOTE: the ClassWizard will add data members here

	CBmpButton	m_MaleVoice;
	CBmpButton	m_FemaleVoice;
	CBmpButton	m_Converter;

	CBmpButton	m_Braillie;
	CBmpButton	m_KanBraillie;

	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThejasviDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CThejasviDlg)
	virtual BOOL OnInitDialog();

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnTextConverter();
	afx_msg void OnKanBraillie();
	afx_msg void OnFemale();
	virtual void OnCancel();
	afx_msg void OnButtonBraillie();
	afx_msg void OnMale();
	afx_msg void OnHelp();
	afx_msg void OnResetButtonImages();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THEJASVIDLG_H__D3431746_C353_464F_8B27_DAEFF804DFD2__INCLUDED_)
