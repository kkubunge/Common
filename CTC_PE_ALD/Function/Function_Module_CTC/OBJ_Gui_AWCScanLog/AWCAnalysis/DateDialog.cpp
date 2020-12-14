// DateDialog.cpp : implementation file
//

#include "stdafx.h"
#include "AWCAnalysis.h"
#include "DateDialog.h"
#include "AWCAnalysisDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDateDialog dialog


CDateDialog::CDateDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CDateDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDateDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_pParent = (CAWCAnalysisDlg*)pParent;
	m_bMode   = FALSE;
}


void CDateDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDateDialog)
	DDX_Control(pDX, IDC_MONTHCALENDAR1, m_Calendar);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDateDialog, CDialog)
	//{{AFX_MSG_MAP(CDateDialog)
	ON_NOTIFY(MCN_SELCHANGE, IDC_MONTHCALENDAR1, OnSelchangeMonthcalendar1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDateDialog message handlers
void 
CDateDialog::SetMode(BOOL bMode)
{
	m_bMode = bMode;
}

BOOL CDateDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//오늘 날짜를 Default로 저장한다.
	m_Calendar.GetToday(&m_SysTime);

	//Dialog 위치 이동하여 버튼 밑으로 나타나게 한다.
	if (NULL != m_pParent) {
		CRect rect;
		if (TRUE == m_bMode) {
			(m_pParent->GetDlgItem(IDC_BUTTON_FROM))->GetWindowRect(&rect);
		}
		else {
			(m_pParent->GetDlgItem(IDC_BUTTON_TO))->GetWindowRect(&rect);
		}

		MoveWindow(rect.right , rect.bottom , 400 , 300);
	}
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDateDialog::OnSelchangeMonthcalendar1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	m_Calendar.GetCurSel(&m_SysTime); 
	
	*pResult = 0;
}

int 
CDateDialog::GetCurSelYear()
{
	return m_SysTime.wYear;
}

int 
CDateDialog::GetCurSelMonth()
{
	return m_SysTime.wMonth;
}

int 
CDateDialog::GetCurSelDay()
{
	return m_SysTime.wDay;
}


