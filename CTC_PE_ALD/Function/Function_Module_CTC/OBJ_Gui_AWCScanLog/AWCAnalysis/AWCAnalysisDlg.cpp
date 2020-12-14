// AWCAnalysisDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AWCAnalysis.h"
#include "AWCAnalysisDlg.h"
#include "DataGraphFrame.h"
#include "DateDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
extern char g_szModule[MAX_MODULE_COUNT][64];

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum
	{
		IDD = IDD_ABOUTBOX
	};
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange *pDX); // DDX/DDV support
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

void CAboutDlg::DoDataExchange(CDataExchange *pDX)
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
// CAWCAnalysisDlg dialog

CAWCAnalysisDlg::CAWCAnalysisDlg(CWnd *pParent /*=NULL*/)
	: CDialog(CAWCAnalysisDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAWCAnalysisDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pstModuleAWCData = NULL;

	memset(m_szDirPath, 0, sizeof(m_szDirPath));

	m_nCurrentArm = A1_ARM;
	m_nCurrentModule = BM1;
	m_nCurrentDataType = MISS1;
}

void CAWCAnalysisDlg::DoDataExchange(CDataExchange *pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAWCAnalysisDlg)
	DDX_Control(pDX, IDC_COMBO_TYPE, m_cboType);
	DDX_Control(pDX, IDC_COMBO_MODULE, m_cboModule);
	DDX_Control(pDX, IDC_COMBO_ARM, m_cboArm);
	DDX_Control(pDX, IDC_LIST_AWC, m_listAWC);
	DDX_Control(pDX, IDC_STATIC_PATH, m_staticDirPath);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAWCAnalysisDlg, CDialog)
//{{AFX_MSG_MAP(CAWCAnalysisDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON_MINUS_YMAX, OnButtonMinusYmax)
ON_BN_CLICKED(IDC_BUTTON_PLUS_YMAX, OnButtonPlusYmax)
ON_BN_CLICKED(IDC_BUTTON_MINUS_XMAX, OnButtonMinusXmax)
ON_BN_CLICKED(IDC_BUTTON_PLUS_XMAX, OnButtonPlusXmax)
ON_WM_SHOWWINDOW()
ON_BN_CLICKED(IDC_BUTTON_DIRECTORY, OnButtonDirectory)
ON_BN_CLICKED(IDC_BUTTON_LOAD, OnButtonLoad)
ON_CBN_SELCHANGE(IDC_COMBO_MODULE, OnSelchangeComboModule)
ON_CBN_SELCHANGE(IDC_COMBO_ARM, OnSelchangeComboArm)
ON_CBN_SELCHANGE(IDC_COMBO_TYPE, OnSelchangeComboType)
ON_LBN_SELCHANGE(IDC_LIST_AWC, OnSelchangeListAwc)
ON_BN_CLICKED(IDC_STATIC_PATH, OnStaticPath)
ON_WM_LBUTTONDOWN()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAWCAnalysisDlg message handlers

BOOL CAWCAnalysisDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_bPoint = false;

	// Add "About..." menu item to system menu.
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu *pSysMenu = GetSystemMenu(FALSE);
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
	SetIcon(m_hIcon, TRUE);	 // Set big icon
	SetIcon(m_hIcon, FALSE); // Set small icon

	//실행 시 Logfile Directory 경로와 Title이 넘어오는지 여부에 따라서 처리가 달라짐

	char szCommand[256] = {
		0,
	};
	char szDirPath[256] = {
		0,
	};
	char szTitle[128] = {
		0,
	};

	sprintf(szCommand, AfxGetApp()->m_lpCmdLine);
	if (strlen(szCommand) > 0)
	{
		sscanf(szCommand, "%s %d %d %d %d", szDirPath, &m_nLeft, &m_nTop, &m_nRight, &m_nBottom);
	}

	if (strlen(szDirPath) > 0)
	{
		//해당되는 경로에 해당하는 파일 Data를 시작하면서 Load한다.
		strcpy(m_szDirPath, szDirPath);
		m_staticDirPath.SetWindowText(m_szDirPath);
	}

	//
	//m_pstModuleAWCData = new MODULE_AWC_DATA[MAX_MODULE_COUNT];
	m_pstModuleAWCData = (MODULE_AWC_DATA *)malloc(sizeof(MODULE_AWC_DATA) * MAX_MODULE_COUNT);
	memset(m_pstModuleAWCData, 0x00, sizeof(MODULE_AWC_DATA) * MAX_MODULE_COUNT);

	//From To Data Initialize
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	memset(&m_stFromDate, 0x00, sizeof(_DATE_INFO));
	memset(&m_stToDate, 0x00, sizeof(_DATE_INFO));
	m_stFromDate.nYear = m_stToDate.nYear = sys.wYear;
	m_stFromDate.nMonth = m_stToDate.nMonth = sys.wMonth;
	m_stFromDate.nDay = m_stToDate.nDay = sys.wDay;

	char szTemp[128] = {
		0,
	};
	sprintf(szTemp, "%d/%02d/%02d ~", m_stFromDate.nYear, m_stFromDate.nMonth, m_stFromDate.nDay);
	m_staticFromDate.SetWindowText(szTemp);

	memset(szTemp, 0, sizeof(szTemp));
	sprintf(szTemp, "~ %d/%02d/%02d", m_stToDate.nYear, m_stToDate.nMonth, m_stToDate.nDay);
	m_staticToDate.SetWindowText(szTemp);

	CRect rcGraph;
	CWnd *pWnd = GetDlgItem(IDC_STATIC_GRAPH);
	if (NULL != pWnd)
	{
		pWnd->GetWindowRect(&rcGraph);
		ScreenToClient(&rcGraph);

		m_pAWCGraphFrame = new CDataGraphFrame(this);
		if (strlen(szTitle) > 0)
		{
			m_pAWCGraphFrame->SetGraphTitle(szTitle);
		}
		else
		{
			m_pAWCGraphFrame->SetGraphTitle("AWC Trend Graph");
		}

		m_pAWCGraphFrame->Init(&rcGraph, 50, 50, 5, 5);
	}
	else
	{
		exit(-1);
	}

	m_cboModule.SetCurSel(0);
	m_cboArm.SetCurSel(0);
	m_cboType.SetCurSel(0);

	OnSelchangeComboModule();
	OnSelchangeComboArm();
	OnSelchangeComboType();

	return TRUE; // return TRUE  unless you set the focus to a control
}

void CAWCAnalysisDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

/*
BOOL CAWCAnalysisDlg::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}
*/

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAWCAnalysisDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM)dc.GetSafeHdc(), 0);

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

		CPaintDC dc(this);
		if (NULL != m_pAWCGraphFrame)
		{
			m_pAWCGraphFrame->Draw(&dc);
		}

		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAWCAnalysisDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

MODULE_AWC_DATA *
CAWCAnalysisDlg::GetData(int nIndex)
{
	return &m_pstModuleAWCData[nIndex];
}

void CAWCAnalysisDlg::ReDrawGraph()
{
	CRect rcGraph;
	CWnd *pWnd = GetDlgItem(IDC_STATIC_GRAPH);
	if (NULL != pWnd)
	{
		pWnd->GetWindowRect(&rcGraph);
		ScreenToClient(&rcGraph);
		InvalidateRect(&rcGraph);
	}
	else
	{
		Invalidate();
	}
}

void CAWCAnalysisDlg::OnButtonMinusYmax()
{
	double dbMax = 0;

	if (NULL != m_pAWCGraphFrame)
	{
		m_pAWCGraphFrame->GetYMax(dbMax);

		if (dbMax > 0.5)
		{
			dbMax -= 0.1;
			m_pAWCGraphFrame->SetYMax(dbMax);
			ReDrawGraph();
		}
	}
}

void CAWCAnalysisDlg::OnButtonPlusYmax()
{
	double dbMax = 0;

	if (NULL != m_pAWCGraphFrame)
	{
		m_pAWCGraphFrame->GetYMax(dbMax);

		dbMax += 0.1;

		m_pAWCGraphFrame->SetYMax(dbMax);

		ReDrawGraph();
	}
}

void CAWCAnalysisDlg::OnButtonMinusXmax()
{
	double dbMax = 0;

	if (NULL != m_pAWCGraphFrame)
	{
		m_pAWCGraphFrame->GetXMax(dbMax);

		if (dbMax > 0.5)
		{
			dbMax -= 0.1;
			m_pAWCGraphFrame->SetXMax(dbMax);
			ReDrawGraph();
		}
	}
}

void CAWCAnalysisDlg::OnButtonPlusXmax()
{
	double dbMax = 0;

	if (NULL != m_pAWCGraphFrame)
	{
		m_pAWCGraphFrame->GetXMax(dbMax);
		dbMax += 0.1;

		m_pAWCGraphFrame->SetXMax(dbMax);

		ReDrawGraph();
	}
}

void CAWCAnalysisDlg::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialog::OnShowWindow(bShow, nStatus);

	if (TRUE == bShow)
	{
		/*
		int nCX = GetSystemMetrics(SM_CXSCREEN);
		int nCY = GetSystemMetrics(SM_CYSCREEN);

		CRect rect;
		GetWindowRect(&rect);
		int nWidth  = rect.Width();
		int nHeight = rect.Height();
		*/

		SetWindowPos(&wndTopMost, m_nLeft, m_nTop, m_nRight - m_nLeft, m_nBottom - m_nTop, SWP_SHOWWINDOW);
		//SetWindowPos(&wndTopMost, (nCX - nWidth)/2 , (nCY - nHeight) / 2 , nWidth, nHeight, SWP_SHOWWINDOW);
	}
}

void CAWCAnalysisDlg::OnButtonDirectory()
{
	LPMALLOC ShellMalloc;
	LPITEMIDLIST idRoot, idBrowse;
	BROWSEINFO BrowseInfo;
	char *shBuff = NULL;
	char szPath[MAX_PATH] = {
		0,
	};

	if (SHGetMalloc(&ShellMalloc) == NOERROR)
	{

		SHGetSpecialFolderLocation(0, CSIDL_COMMON_PROGRAMS, &idRoot);
		shBuff = (char *)ShellMalloc->Alloc(MAX_PATH);

		if (shBuff != NULL)
		{
			BrowseInfo.hwndOwner = this->m_hWnd;
			BrowseInfo.pidlRoot = NULL;
			BrowseInfo.pszDisplayName = shBuff;
			BrowseInfo.lpszTitle = "Select AWC Log Folder Select Only Folder not file";
			BrowseInfo.ulFlags = BIF_DONTGOBELOWDOMAIN;
			BrowseInfo.lpfn = NULL;
			BrowseInfo.lParam = 0;

			idBrowse = SHBrowseForFolder(&BrowseInfo);
			if (idBrowse != NULL)
			{
				SHGetPathFromIDList(idBrowse, szPath);
			}
		}

		ShellMalloc->Free(shBuff);
		ShellMalloc->Free(idBrowse);
		ShellMalloc->Free(idRoot);
	}

	ShellMalloc->Release();

	if (strlen(szPath) > 0)
	{
		memset(m_szDirPath, 0, sizeof(m_szDirPath));
		strcpy(m_szDirPath, szPath);

		m_staticDirPath.SetWindowText(m_szDirPath);

		m_listAWC.ResetContent();
	}
}

void CAWCAnalysisDlg::OnButtonLoad()
{
	BOOL bRet = FALSE;

	if (strlen(m_szDirPath) <= 0)
	{
		AfxMessageBox("Select Directory First");
	}

	//기존 Data Reset
	memset(m_pstModuleAWCData, 0x00, sizeof(MODULE_AWC_DATA) * MAX_MODULE_COUNT);
	m_listAWC.ResetContent();

	//Data Load
	CFileFind FindFile;
	char szLogPath[256] = {
		0,
	};

	sprintf(szLogPath, "%s/TM_AWS_*.log", m_szDirPath);
	//sprintf(szLogPath, "%s/*.log", m_szDirPath);

	bRet = FindFile.FindFile(szLogPath);

	while (bRet)
	{
		bRet = FindFile.FindNextFile();

		//최상위 Job 생성일자 폴더
		if (FindFile.IsDirectory())
		{
			//Directory는 무시
		}
		else
		{
			//File Name이 AWCLog가 포함되는지 확인
			char szFileName[256] = {
				0,
			};
			sprintf(szFileName, "%s", FindFile.GetFileName());

			if (NULL == strstr(szFileName, ""))
			{
				//상관 없는 File이므로 무시
			}
			else
			{
				//선택된 날짜 범주에 드는지 확인

				//File 생성 시간을 Systemtime으로 변환하여 출력 파일 결정
				FILETIME ftime;
				SYSTEMTIME systime;

				FindFile.GetCreationTime(&ftime);
				FileTimeToSystemTime(&ftime, &systime);

				// File 생성 시간이 아닌 File 이름의 날짜를 기준으로 출력 파일 결정
				CString strFileYear, strFileMoth, strFileDay, strTemp;
				AfxExtractSubString(strFileYear, szFileName, 2, '_');
				AfxExtractSubString(strFileMoth, szFileName, 3, '_');
				AfxExtractSubString(strTemp, szFileName, 4, '_');
				AfxExtractSubString(strFileDay, strTemp, 0, '.');

				char szAWCFile[256] = {
					0,
				};
				sprintf(szAWCFile, "%s/%s", m_szDirPath, FindFile.GetFileName());

				//Load File
				LoadAWCLog(szAWCFile);

				//List에 추가
				m_listAWC.AddString(FindFile.GetFileName());
			}
		}
	}

	ReDrawGraph();
}

BOOL CAWCAnalysisDlg::LoadAWCLog(char *szAWCLogFile)
{
	BOOL bRet = FALSE;

	FILE *fp = NULL;

	int nModuleID = 0, nCount = 0; //Target Module

	char Debug[256] = {
		0,
	};

	char strBuf01[256], strBuf02[256], strBuf03[256];
	char strDate[256], strTime[256], strSRC[256], strTGT[256];
	char strARM01[256], strARM01_X1[256], strARM01_X2[256], strARM01_Y1[256], strARM01_Y2[256];
	char strARM02[256], strARM02_X1[256], strARM02_X2[256], strARM02_Y1[256], strARM02_Y2[256];

	fp = fopen(szAWCLogFile, "r");

	if (NULL != fp)
	{
		while (!feof(fp))
		{
			char szBuf[1024] = {
				0,
			};
			char szCopy[1024] = {
				0,
			};
			char szDate[128] = {
				0,
			};
			char szTime[128] = {
				0,
			};
			char szAction[128] = {
				0,
			};
			char szModule[128] = {
				0,
			};
			char szArm[128] = {
				0,
			};
			char szMissX2[128] = {
				0,
			};
			char szMissY2[128] = {
				0,
			};
			char szMissX1[128] = {
				0,
			};
			char szMissY1[128] = {
				0,
			};
			char szDummy[128] = {
				0,
			};
			char szCorrectR[128] = {
				0,
			};
			char szCorrectT[128] = {
				0,
			};

			char szTok[] = " \t\r\n";
			char *pChar = NULL;

			//01. Line Read
			if (!fgets(szBuf, 256, fp))
				continue;
			else
				strcpy(szCopy, szBuf);

			if (*szCopy != 0)
			{
				STR_SEPERATE(szCopy, strDate, strBuf01, 256);
				STR_SEPERATE(strBuf01, strTime, strBuf01, 256);
				STR_SEPERATE(strBuf01, strSRC, strBuf01, 256);
				STR_SEPERATE(strBuf01, strTGT, strBuf01, 256);

				//1Side Arm X, Y Axis
				STR_SEPERATE_CHAR(strBuf01, '<', strBuf02, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, ':', strARM01, strBuf01, 256);

				STR_SEPERATE_CHAR(strBuf01, '[', strBuf02, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, '/', strARM01_X1, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, ']', strARM01_X2, strBuf01, 256);

				STR_SEPERATE_CHAR(strBuf01, '[', strBuf02, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, '/', strARM01_Y1, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, ']', strARM01_Y2, strBuf01, 256);

				//2Side Arm X, Y Axis
				STR_SEPERATE_CHAR(strBuf01, '<', strBuf03, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, ':', strARM02, strBuf01, 256);

				STR_SEPERATE_CHAR(strBuf01, '[', strBuf03, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, '/', strARM02_X1, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, ']', strARM02_X2, strBuf01, 256);

				STR_SEPERATE_CHAR(strBuf01, '[', strBuf03, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, '/', strARM02_Y1, strBuf01, 256);
				STR_SEPERATE_CHAR(strBuf01, ']', strARM02_Y2, strBuf01, 256);
			}

			if ((0 == strcmp("A_BM1", strTGT)) || (0 == strcmp("B_BM1", strTGT)))
				nModuleID = 0;
			else if ((0 == strcmp("A_BM2", strTGT)) || (0 == strcmp("B_BM2", strTGT)))
				nModuleID = 1;
			else if ((0 == strcmp("A_PM1", strTGT)) || (0 == strcmp("B_PM1", strTGT)))
				nModuleID = 2;
			else if ((0 == strcmp("A_PM2", strTGT)) || (0 == strcmp("B_PM2", strTGT)))
				nModuleID = 3;
			else if ((0 == strcmp("A_PM3", strTGT)) || (0 == strcmp("B_PM3", strTGT)))
				nModuleID = 4;
			else if ((0 == strcmp("A_PM4", strTGT)) || (0 == strcmp("B_PM4", strTGT)))
				nModuleID = 5;
			else if ((0 == strcmp("A_PM5", strTGT)) || (0 == strcmp("B_PM5", strTGT)))
				nModuleID = 6;

			nCount = m_pstModuleAWCData[nModuleID].nCount;
			if (nCount >= MAX_ITEM_COUNT)
				continue;

			if (0 == strncmp("A1", strARM01, 2))
				m_pstModuleAWCData[nModuleID].stPlaceData[nCount].nArmType = A1_ARM;
			else if (0 == strncmp("A2", strARM02, 2))
				m_pstModuleAWCData[nModuleID].stPlaceData[nCount].nArmType = A1_ARM;
			else if (0 == strncmp("B1", strARM01, 2))
				m_pstModuleAWCData[nModuleID].stPlaceData[nCount].nArmType = B1_ARM;
			else if (0 == strncmp("B2", strARM02, 2))
				m_pstModuleAWCData[nModuleID].stPlaceData[nCount].nArmType = B1_ARM;

			m_pstModuleAWCData[nModuleID].stPlaceData[nCount].dbMissX1 = atof(strARM01_X1);
			m_pstModuleAWCData[nModuleID].stPlaceData[nCount].dbMissY1 = atof(strARM01_Y1);

			m_pstModuleAWCData[nModuleID].stPlaceData[nCount].dbMissX2 = atof(strARM02_X1);
			m_pstModuleAWCData[nModuleID].stPlaceData[nCount].dbMissY2 = atof(strARM02_Y1);

			m_pstModuleAWCData[nModuleID].stPlaceData[nCount].dbCorrectR = atof(szCorrectR);
			m_pstModuleAWCData[nModuleID].stPlaceData[nCount].dbCorrectT = atof(szCorrectT);

			m_pstModuleAWCData[nModuleID].nCount++;

			/*
			//Date
			pChar = strtok(szCopy , szTok);
			if (NULL != pChar)
				strcpy(szDate , pChar);

			//Time
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szTime , pChar);

			//szModule
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szModule , pChar);

			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szAction , pChar);

			//szArm
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szArm , pChar);

			//szMissX2
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szMissX2 , pChar);

			//szMissY2
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szMissY2 , pChar);

			//szMissX1
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szMissX1 , pChar);

			//szMissY1
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szMissY1 , pChar);

			//szDummy
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szDummy , pChar);

			//szCorrectR
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szCorrectR , pChar);

			//szCorrectT
			pChar = strtok(NULL , szTok);
			if (NULL != pChar)
				strcpy(szCorrectT , pChar);

			int pIndex = GetIndex(szModule);

			if ( -1 != pIndex )
			{
				int nCount = m_pstModuleAWCData[pIndex].nCount;

				if ( nCount >= MAX_ITEM_COUNT )	continue;

				if      ( 0 == strncmp( "A1_ARM" , strARM01 , 6 ) )	m_pstModuleAWCData[pIndex].stPlaceData[nCount].nArmType = A1_ARM;
				else if ( 0 == strncmp( "A2_ARM" , strARM01 , 6 ) )	m_pstModuleAWCData[pIndex].stPlaceData[nCount].nArmType = A2_ARM;
				else if ( 0 == strncmp( "B1_ARM" , strARM02 , 6 ) )	m_pstModuleAWCData[pIndex].stPlaceData[nCount].nArmType = B1_ARM;
				else if ( 0 == strncmp( "B2_ARM" , strARM02 , 6 ) )	m_pstModuleAWCData[pIndex].stPlaceData[nCount].nArmType = B2_ARM;

				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbMissX1   = atof(strARM01_X1);
				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbMissY1   = atof(strARM01_Y1);

				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbMissX2   = atof(strARM02_X1);
				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbMissY2   = atof(strARM02_Y1);

				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbCorrectR = atof(szCorrectR);
				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbCorrectT = atof(szCorrectT);

				m_pstModuleAWCData[pIndex].nCount++;

				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbMissX1   = atof(szMissX1);
				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbMissY1   = atof(szMissY1);
				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbMissX2   = atof(szMissX2);
				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbMissY2   = atof(szMissY2);
				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbCorrectR = atof(szCorrectR);
				m_pstModuleAWCData[pIndex].stPlaceData[nCount].dbCorrectT = atof(szCorrectT);

				m_pstModuleAWCData[pIndex].nCount++;
			}
  		*/
		}

		fclose(fp);
	}

	return bRet;
}

int CAWCAnalysisDlg::GetIndex(char *szModuleName)
{
	for (int i = 0; i < MAX_MODULE_COUNT; i++)
	{
		if (0 == strcmp(g_szModule[i], szModuleName))
			return i;
	}

	return -1;
}

int CAWCAnalysisDlg::GetCurrentModule()
{
	return m_nCurrentModule;
}

int CAWCAnalysisDlg::GetCurrentArm()
{
	return m_nCurrentArm;
}

int CAWCAnalysisDlg::GetCurrentDataType()
{
	return m_nCurrentDataType;
}

void CAWCAnalysisDlg::OnSelchangeComboModule()
{
	int nCurSel;
	nCurSel = m_cboModule.GetCurSel();

	if (CB_ERR != nCurSel)
		m_nCurrentModule = nCurSel;
	else
		m_nCurrentModule = ALL_MODULE;

	ReDrawGraph();
}

void CAWCAnalysisDlg::OnSelchangeComboArm()
{
	int nCurSel;
	nCurSel = m_cboArm.GetCurSel();

	if (CB_ERR != nCurSel)
		m_nCurrentArm = nCurSel;
	else
		m_nCurrentArm = ALL_ARM;

	ReDrawGraph();
}

void CAWCAnalysisDlg::OnSelchangeComboType()
{
	int nCurSel;
	nCurSel = m_cboType.GetCurSel();

	/*
	if (CB_ERR != nCurSel)
		m_nCurrentDataType = nCurSel;
	else
		m_nCurrentDataType = ALL_DATA;
	*/

	m_nCurrentDataType = ALL_DATA;

	ReDrawGraph();
}

void CAWCAnalysisDlg::OnSelchangeListAwc()
{
	int nCurSel = m_listAWC.GetCurSel();
	if (nCurSel >= 0)
	{
		CString str;
		m_listAWC.GetText(nCurSel, str);

		memset(m_pstModuleAWCData, 0x00, sizeof(MODULE_AWC_DATA) * MAX_MODULE_COUNT);

		char szAWCFile[256] = {
			0,
		};
		sprintf(szAWCFile, "%s/%s", m_szDirPath, str);
		//Load File
		LoadAWCLog(szAWCFile);

		ReDrawGraph();
	}
}

void CAWCAnalysisDlg::OnStaticPath()
{
	// TODO: Add your control notification handler code here
}

void CAWCAnalysisDlg::STR_SEPERATE(char *SourceString, char *ResultString1, char *ResultString2, int ReadMaxCount)
{
	int Mode = 0, count = 0;

	while (*SourceString)
	{
		if (Mode == 0)
		{
			if (*SourceString == ' ')
			{
				*ResultString1 = 0;
				Mode = 1;
				count = 0;
			}
			else
			{
				if (count < ReadMaxCount)
				{
					*ResultString1 = *SourceString;
					*ResultString1++;
					count++;
				}
			}
		}
		else if (Mode == 1)
		{
			if (count != 0 || *SourceString != ' ')
			{
				*ResultString2 = *SourceString;
				*ResultString2++;
				count++;

				if (count >= ReadMaxCount)
					break;
			}
		}

		*SourceString++;
	}

	if (Mode == 0)
	{
		*ResultString1 = 0;
		*ResultString2 = 0;
	}
	else if (Mode == 1)
	{
		*ResultString2 = 0;
	}
}

void CAWCAnalysisDlg::STR_SEPERATE_CHAR(char *SourceString, char delimiterChar, char *ResultString1, char *ResultString2, int ReadMaxCount)
{
	int Mode = 0, count = 0;

	while (*SourceString)
	{
		if (Mode == 0)
		{
			if (*SourceString == delimiterChar)
			{
				*ResultString1 = 0;
				Mode = 1;
				count = 0;
			}
			else
			{
				if (count < ReadMaxCount)
				{
					*ResultString1 = *SourceString;
					*ResultString1++;
					count++;
				}
			}
		}
		else if (Mode == 1)
		{
			if (count < ReadMaxCount)
			{
				*ResultString2 = *SourceString;
				*ResultString2++;
				count++;
			}
		}
		*SourceString++;
	}

	if (Mode == 0)
	{
		*ResultString1 = 0;
		*ResultString2 = 0;
	}
	else if (Mode == 1)
	{
		*ResultString2 = 0;
	}
}
void CAWCAnalysisDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	ReleaseCapture();

	if (m_bPoint)
	{
		SetCapture();
		PostQuitMessage(0);
	}

	CDialog::OnLButtonDown(nFlags, point);
}
BOOL CAWCAnalysisDlg::PreTranslateMessage(MSG *pMsg)
{
	// 96 92
	int x, y;

	x = pMsg->pt.x;
	y = pMsg->pt.y;

	if (pMsg->message == WM_MOUSEMOVE)
	{
		// if ((x >= m_nRight - 5 && x <= m_nRight + 96) ||   // right
		// 	(y >= m_nBottom - 5 && y >= m_nBottom + 92) || // bottom
		// 	(y <= m_nTop + 5))							   // top
		if ((x >= m_nRight - 5) ||  // right
			(y >= m_nBottom - 5) || // bottom
			(y <= m_nTop + 5))		// top
		{
			SetCapture();
			m_bPoint = true;
		}
		else
		{
			m_bPoint = false;
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
