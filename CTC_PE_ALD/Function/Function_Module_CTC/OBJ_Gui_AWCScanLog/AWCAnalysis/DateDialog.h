#if !defined(AFX_DATEDIALOG_H__E6A72B1A_844F_4E31_B739_9517F7BCFB88__INCLUDED_)
#define AFX_DATEDIALOG_H__E6A72B1A_844F_4E31_B739_9517F7BCFB88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DateDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDateDialog dialog

class CAWCAnalysisDlg;
class CDateDialog : public CDialog
{
// Construction
public:
	CDateDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDateDialog)
	enum { IDD = IDD_DATE_DIALOG };
	CMonthCalCtrl	m_Calendar;
	//}}AFX_DATA


	int  GetCurSelYear();
	int  GetCurSelMonth();
	int  GetCurSelDay();
	void SetMode(BOOL bMode);

	SYSTEMTIME  m_SysTime;
	CAWCAnalysisDlg *m_pParent;
	BOOL        m_bMode;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDateDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDateDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATEDIALOG_H__E6A72B1A_844F_4E31_B739_9517F7BCFB88__INCLUDED_)
