// AWCAnalysisDlg.h : header file
//

#if !defined(AFX_AWCANALYSISDLG_H__F39997E4_D477_4817_8FF0_9C840E06CF84__INCLUDED_)
#define AFX_AWCANALYSISDLG_H__F39997E4_D477_4817_8FF0_9C840E06CF84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAWCAnalysisDlg dialog
#include "resource.h"
#include "Constant.h"

class CDataGraphFrame;
class CAWCAnalysisDlg : public CDialog
{
// Construction
public:
	CAWCAnalysisDlg(CWnd* pParent = NULL);	// standard constructor
	int GetModuleCount();
	MODULE_AWC_DATA* GetData(int nIndex);

	int GetCurrentModule();
	int GetCurrentArm();
	int GetCurrentDataType();

	void STR_SEPERATE( char *SourceString , char *ResultString1 , char *ResultString2 , int ReadMaxCount );
	void STR_SEPERATE_CHAR( char *SourceString , char delimiterChar , char *ResultString1 , char *ResultString2 , int ReadMaxCount );
// Dialog Data
	//{{AFX_DATA(CAWCAnalysisDlg)
	enum { IDD = IDD_AWCANALYSIS_DIALOG };
	CComboBox	m_cboType;
	CComboBox	m_cboModule;
	CComboBox	m_cboArm;
	CListBox	m_listAWC;
	CStatic	m_staticDirPath;
	CButton	m_btnTo;
	CButton	m_m_btnFrom;
	CStatic	m_staticToDate;
	CStatic	m_staticFromDate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAWCAnalysisDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAWCAnalysisDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonMinusYmax();
	afx_msg void OnButtonPlusYmax();
	afx_msg void OnButtonMinusXmax();
	afx_msg void OnButtonPlusXmax();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnButtonDirectory();
	afx_msg void OnButtonFrom();
	afx_msg void OnButtonTo();
	afx_msg void OnButtonLoad();
	afx_msg void OnSelchangeComboModule();
	afx_msg void OnSelchangeComboArm();
	afx_msg void OnSelchangeComboType();
	afx_msg void OnSelchangeListAwc();
	afx_msg void OnStaticPath();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void ReDrawGraph();
	BOOL LoadAWCLog(char *szAWCLogFile);
	int  GetIndex(char *szModuleName);
private:
	CDataGraphFrame    *m_pAWCGraphFrame;
	MODULE_AWC_DATA    *m_pstModuleAWCData;
	int                 m_nModuleCount;

	char                m_szDirPath[256];

	_DATE_INFO          m_stFromDate;
	_DATE_INFO          m_stToDate;

	//Current Select Option
	int                 m_nCurrentArm;
	int                 m_nCurrentModule;
	int                 m_nCurrentDataType;

	//window position
	int                 m_nLeft;
	int                 m_nTop;
	int                 m_nRight;
	int                 m_nBottom;

	BOOL				m_bPoint;
	int x, y;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AWCANALYSISDLG_H__F39997E4_D477_4817_8FF0_9C840E06CF84__INCLUDED_)
