// DataGraphFrame.cpp: implementation of the CDataGraphFrame class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DataGraphFrame.h"
#include <math.h>
#include "AWCAnalysisDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
char g_szModule[MAX_MODULE_COUNT][64] = {"BM1"   , "BM2"   , "PM1"   , "PM2" , "PM3" , "PM4" , "PM5" , "PM6" , "PM7" , "PM8"};
char g_szArm   [MAX_ARM_COUNT]   [32] = {"ARM-A" , "ARM-B" , "ARM-C" , "ARM-D"}; 

CDataGraphFrame::CDataGraphFrame(CAWCAnalysisDlg *pParent)
{
	m_pParent = pParent;

	memset(m_szTitle , 0 , sizeof(m_szTitle));

	//Y축 눈금을 몇 칸으로 나눌 지
	m_nYDevide = 50;
	//X축 눈금을 몇 칸으로 나눌 지
	m_nXDevide = 50;

	//Y축 상 표현할 최대 / 최소 값
	m_dbXMaxValue =  5;
	m_dbXMinValue = -5;

	//Y축 상 표현할 최대 / 최소 값
	m_dbYMaxValue =  5;
	m_dbYMinValue = -5;

	//그래프 그리기 마진
	//마진영역에 Title이런거 쓴다.
	m_nLeftMargin = m_nRightMargin = m_nTopMargin = m_nBottomMargin = 0;

	//Grid관련
	//전체 넓이에 Grid를 몇 칸 그릴 건지
	m_bGridDraw = true;
	m_nXGridLineCount = 20;
	m_nYGridLineCount = 20;
	m_nGridLineType   = PS_DOT;
	m_cGridLineColor  = RGB(0,0,200);

	//각종 색상
	m_cFrameLine      = RGB(0,0,0);
	m_CFrameTextColor = RGB(0,0,0);
	m_cFrameBackground= RGB(157,157,255);
	m_cGraphBackground= RGB(255,255,255);
	m_cTextColor      = RGB(255,0,0);

}

CDataGraphFrame::~CDataGraphFrame()
{
}

void     
CDataGraphFrame::SetGraphTitle(char *szTitle)
{
	if (NULL != szTitle)
		strcpy(m_szTitle , szTitle);
}

bool     
CDataGraphFrame::Init(CRect *pFrameRect , int nXDevide , int nYDevide , double dbXMaxValue , double dbYMaxValue)
{
	bool bRet = false;
	do {
		// 전체 Frame영역 저장
		m_FrameRect.left   = pFrameRect->left;
		m_FrameRect.top    = pFrameRect->top;
		m_FrameRect.right  = pFrameRect->right;
		m_FrameRect.bottom = pFrameRect->bottom;

		// 좌/우 /위 / 아래 Margin을 적당히 확보한다.
		m_nBottomMargin = (m_FrameRect.bottom - m_FrameRect.top)  / 15;
		m_nTopMargin    = (m_FrameRect.bottom - m_FrameRect.top)  / 10;
		m_nLeftMargin   = (m_FrameRect.right  - m_FrameRect.left) / 10;
		m_nRightMargin  = (m_FrameRect.right  - m_FrameRect.left) / 10;

		//실제 그래프가 그려지 영역 저장
		m_GraphRect.left   = m_FrameRect.left  + m_nLeftMargin;
		m_GraphRect.right  = m_FrameRect.right - m_nRightMargin;
		m_GraphRect.top    = m_FrameRect.top   + m_nTopMargin;
		m_GraphRect.bottom = m_FrameRect.bottom- m_nBottomMargin;

		//내부 변수 저장
		m_nXDevide = nXDevide;
		m_nYDevide = nYDevide;

		//표현값 Min/Max
		m_dbXMinValue = dbXMaxValue*(-1);
		m_dbXMaxValue = dbXMaxValue;
		m_dbYMinValue = dbYMaxValue*(-1);
		m_dbYMaxValue = dbYMaxValue;


		//각 모듈별로 모양 말고 귀찮으니깐 색깔로 구분하자
		m_cTable[0] = RGB(0,0,255);
		m_cTable[1] = RGB(128,0,255);
		m_cTable[2] = RGB(255,0,0);
		m_cTable[3] = RGB(255,128,0);
		m_cTable[4] = RGB(255,255,0);
		m_cTable[5] = RGB(0,128,0);
		m_cTable[6] = RGB(0,0,0);
		m_cTable[7] = RGB(0,0,0);
		m_cTable[8] = RGB(0,0,0);
		m_cTable[9] = RGB(0,0,0);

		
		bRet = true;
	} while (0);

	return bRet;
}

void     
CDataGraphFrame::SetXMax(double  dbMax)
{
	m_dbXMaxValue = dbMax;
	m_dbXMinValue = dbMax*(-1);
}

void     
CDataGraphFrame::SetYMax(double  dbMax)
{
	m_dbYMaxValue = dbMax;
	m_dbYMinValue = dbMax*(-1);
}

void     
CDataGraphFrame::GetXMax(double& dbMax)
{
	dbMax = m_dbXMaxValue;
}

void     
CDataGraphFrame::GetYMax(double& dbMax)
{
	dbMax = m_dbYMaxValue;
}

bool     
CDataGraphFrame::Draw(CDC *pDC)
{
	bool bRet = false;

	//깜박임 방지위해 생쇼함
	CDC MemoryDC;
	CBitmap   Bitmap , *OldBitmap;
	MemoryDC.CreateCompatibleDC(pDC);
	Bitmap.CreateCompatibleBitmap(pDC , m_FrameRect.Width()+m_FrameRect.left , m_FrameRect.Height()+m_FrameRect.top);
	OldBitmap = MemoryDC.SelectObject(&Bitmap);

	do {
		if (false == DrawFrame(&MemoryDC))
			break;

		if (false == DrawGraph(&MemoryDC))
			break;

		bRet = true;
	} while (0);

	pDC->BitBlt(m_FrameRect.left  , m_FrameRect.top , m_FrameRect.Width() , m_FrameRect.Height() , &MemoryDC , m_FrameRect.left , m_FrameRect.top , SRCCOPY);
	MemoryDC.SelectObject(OldBitmap);

	MemoryDC.DeleteDC();
	Bitmap.DeleteObject();

	return bRet;
}

void
CDataGraphFrame::PrintText(HDC hDC , int x , int y , int theta , char *szText , COLORREF cTextColor)
{
	#define  PiV     3.14159265358979324                       
	#define  ConstV  180

	WORD    Height, Width;
	UINT    PreSet;
	double  thta;
	
	PreSet = ::SetTextAlign(hDC, TA_LEFT|TA_TOP);

	SIZE  size;
	::GetTextExtentPoint32(hDC, szText, lstrlen(szText), &size);
	Height = (WORD)size.cy;
	Width  = (WORD)size.cx;
                                             
       thta   = PiV*theta/ConstV;
    
	x = (int)(x - Width/2. * cos(thta) - Height/2.*sin(thta));
	y = (int)(y + Width/2. * sin(thta) - Height/2.*cos(thta));
	
	::SetTextColor(hDC , cTextColor);
	::TextOut(hDC, x, y, szText, lstrlen(szText));
	::SetTextAlign(hDC, PreSet);
}

bool     
CDataGraphFrame::DrawFrame(CDC *pDC)
{
	pDC->SetBkMode(TRANSPARENT);
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//1. 전체그래프영역그리기 시작
	////////////////////////////////////////////////////////////////////////////////////////////////
	CBrush Brush , *OldBrush;
	CPen   Pen   , *OldPen;

	Brush.CreateSolidBrush(m_cFrameBackground);
	OldBrush = pDC->SelectObject(&Brush);

	pDC->Rectangle(&m_FrameRect);
	
	pDC->SelectObject(OldBrush);
	Brush.DeleteObject();
	///////////////////////////////////////////////////////////////////////////////////////////////
	//전체 그래프 영역 그리기 끝
	////////////////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////////////
	//2. Data Plot 영역 그리기 시작
	///////////////////////////////////////////////////////////////////////////////////////////////
	Brush.CreateSolidBrush(m_cGraphBackground);
	Pen  .CreatePen       (PS_SOLID , 1 , m_cFrameLine);
	OldBrush = pDC->SelectObject(&Brush);	
	OldPen   = pDC->SelectObject(&Pen);

	pDC->Rectangle(&m_GraphRect);

	pDC->SelectObject(OldBrush);
	pDC->SelectObject(OldPen);
	Brush.DeleteObject();
	Pen.DeleteObject();
	///////////////////////////////////////////////////////////////////////////////////////////////
	//Data Plot 영역 그리기 끝
	///////////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////////////
	//3. Grid Line 그리기 시작
	/////////////////////////////////////////////////////////////////////////////////////////////
	Pen.CreatePen(m_nGridLineType , 0 , m_cGridLineColor);
	OldPen = pDC->SelectObject(&Pen);

	int j = 0;
	//x축 그리드
	for (int i = 1; i < m_nXGridLineCount; i ++) {
		//이 부분은 넓이를 10등분해서 앞에서 부터 그리는 방식 아닌 여기서는 일반적으로
		//전체 넓이를 등분으로 나눈뒤 총 등분 Count로 나눈 값을 i 값을 증가시키면서 곱하는 방식 어차피 같다.
		j = m_GraphRect.left + (int)(i * (m_GraphRect.right-m_GraphRect.left) / m_nXGridLineCount);
		pDC->MoveTo(j, m_GraphRect.top+1);
		pDC->LineTo(j, m_GraphRect.bottom-1);
	}

	//y축 그리드
	for (i = 1; i < m_nYGridLineCount; i ++) {
		//이 부분은 넓이를 10등분해서 앞에서 부터 그리는 방식 아닌 여기서는 일반적으로
		//전체 넓이를 등분으로 나눈뒤 총 등분 Count로 나눈 값을 i 값을 증가시키면서 곱하는 방식 어차피 같다.
		j = m_GraphRect.top + (int)(i * (m_GraphRect.bottom-m_GraphRect.top) / m_nYGridLineCount);
		pDC->MoveTo(m_GraphRect.left+1 , j);
		pDC->LineTo(m_GraphRect.right-1 , j);
	}

	pDC->SelectObject(OldPen);
	Pen.DeleteObject();
	////////////////////////////////////////////////////////////////////////////////////////////////
	//Grid Line 그리기 끝
	////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	///////////////////////////////////////////////////////////////////////////////////////////////
	//4. X,Y축 그리기
	///////////////////////////////////////////////////////////////////////////////////////////////

	//초기 계산 인자
	int xOrigin = m_GraphRect.left + m_GraphRect.Width()  / 2;
	int yOrigin = m_GraphRect.top  + m_GraphRect.Height() / 2;

	pDC->MoveTo(m_GraphRect.left , yOrigin);
	pDC->LineTo(m_GraphRect.right, yOrigin);

	pDC->MoveTo(xOrigin , m_GraphRect.top);
	pDC->LineTo(xOrigin , m_GraphRect.bottom);

	double xSlope     = (double)((m_GraphRect.right - m_GraphRect.left) / (m_dbXMaxValue - m_dbXMinValue));
	double xIntercept = (double)((m_GraphRect.Width() / 2) + m_GraphRect.left);

	double ySlope     = (double)((m_GraphRect.bottom - m_GraphRect.top) / (m_dbYMaxValue - m_dbYMinValue));
	double yIntercept = (double)((m_GraphRect.Height() / 2) + m_GraphRect.top);

	//x축 눈금 그리기
	i = 1;	
	double dbXGap = (double)((m_dbXMaxValue - m_dbXMinValue) / m_nXDevide);
	for (double dbTemp = (m_dbXMinValue + dbXGap) ; dbTemp < m_dbXMaxValue ; dbTemp+=dbXGap) {
		int yb , ye;
		int xb , xe;
		xb = xe = (int)(dbTemp*xSlope + xIntercept);

		if ((i % 5) == 0) {
			yb = yOrigin - 5;
			ye = yOrigin + 5;
		}
		else {
			yb = yOrigin - 2;
			ye = yOrigin + 2;
		}

		pDC->MoveTo(xb, yb);
		pDC->LineTo(xe, ye);

		if ((i % 5) == 0) {
			char xText[64] = {0,};
			sprintf(xText , "%.1f" , dbTemp);
			PrintText(pDC->m_hDC , xb , m_GraphRect.bottom+15 , 0 , xText , RGB(255,255,0));
		}

		i++;

	}

	//y축 눈금그리기
	i = 1;
	double dbYGap = (double)((m_dbYMaxValue - m_dbYMinValue) / m_nYDevide);
	for (dbTemp = (m_dbYMinValue + dbYGap) ; dbTemp < m_dbYMaxValue ; dbTemp+=dbYGap) {
		int yb , ye;
		int xb , xe;
		yb = ye = (int)(yIntercept - dbTemp*ySlope);

		if ((i % 5) == 0) {
			xb = xOrigin - 5;
			xe = xOrigin + 5;
		}
		else {
			xb = xOrigin - 2;
			xe = xOrigin + 2;
		}

		pDC->MoveTo(xb, yb);
		pDC->LineTo(xe, ye);

		if ((i % 5) == 0) {
			char xText[64] = {0,};
			sprintf(xText , "%.1f" , dbTemp);
			PrintText(pDC->m_hDC , m_GraphRect.left-15 , yb , 0 , xText , RGB(255,255,0));
		}

		i++;

	}


	//Title 그리기
	HFONT m_hFont;
	//변경된 Size로 폰트조정
	pDC->SetTextColor(m_cTextColor);	
	m_hFont = CreateFont(30,0,0,0,400,false,false,false,
				ANSI_CHARSET,
				OUT_OUTLINE_PRECIS ,
				CLIP_DEFAULT_PRECIS,
				PROOF_QUALITY,
				DEFAULT_PITCH|FF_MODERN,
				"tahoma");


	HFONT hOldFont = (HFONT)SelectObject(pDC->m_hDC , m_hFont);
	pDC->SetBkMode(TRANSPARENT);

	SIZE TextSize;
	RECT tmpRect;
	GetTextExtentPoint32(pDC->m_hDC,m_szTitle,strlen(m_szTitle),&TextSize);
	tmpRect.left   = long(m_FrameRect.left-TextSize.cx/2);
	tmpRect.top    = long(m_FrameRect.top+TextSize.cy/2);
	tmpRect.right  = long(m_FrameRect.right+TextSize.cx/2);
	tmpRect.bottom = long(m_FrameRect.left+m_nTopMargin-TextSize.cy/2);

	DrawText(pDC->m_hDC,m_szTitle,-1,&tmpRect,DT_CENTER | DT_VCENTER );

	SelectObject(pDC->m_hDC , hOldFont);
	DeleteObject(m_hFont);		

	return true;
}


bool     
CDataGraphFrame::DrawGraph(CDC *pDC)
{
	int nModule = m_pParent->GetCurrentModule();
	int nArm    = m_pParent->GetCurrentArm();
	int nType   = m_pParent->GetCurrentDataType();

	//초기 계산 인자
	int xOrigin = m_GraphRect.left + m_GraphRect.Width()  / 2;
	int yOrigin = m_GraphRect.top  + m_GraphRect.Height() / 2;

	pDC->MoveTo(m_GraphRect.left , yOrigin);
	pDC->LineTo(m_GraphRect.right, yOrigin);

	pDC->MoveTo(xOrigin , m_GraphRect.top);
	pDC->LineTo(xOrigin , m_GraphRect.bottom);

	double xSlope     = (double)((m_GraphRect.right - m_GraphRect.left) / (m_dbXMaxValue - m_dbXMinValue));
	double xIntercept = (double)((m_GraphRect.Width() / 2) + m_GraphRect.left);

	double ySlope     = (double)((m_GraphRect.bottom - m_GraphRect.top) / (m_dbYMaxValue - m_dbYMinValue));
	double yIntercept = (double)((m_GraphRect.Height() / 2) + m_GraphRect.top);
	
	CBrush Brush , *OldBrush;

	if (ALL_MODULE == nModule) {
		for (int i = 0 ; i < MAX_MODULE_COUNT ; i++) {
			Brush.CreateSolidBrush(m_cTable[i]);
			OldBrush = pDC->SelectObject(&Brush);

			MODULE_AWC_DATA *pData = m_pParent->GetData(i);
			
			for (int j = 0 ; j < (int)pData->nCount ; j++)
			{

				if((nArm == A1_ARM || nArm == A2_ARM) && pData->stPlaceData[j].nArmType != A1_ARM)	continue;
				if((nArm == B1_ARM || nArm == B2_ARM) && pData->stPlaceData[j].nArmType != B1_ARM)	continue;

				int xPos , yPos;
				if(ALL_ARM == nArm) {
					//Miss1
					if (pData->stPlaceData[j].dbMissX1 <= m_dbXMaxValue && pData->stPlaceData[j].dbMissX1 >= m_dbXMinValue && 
					    pData->stPlaceData[j].dbMissY1 <= m_dbYMaxValue && pData->stPlaceData[j].dbMissY1 >= m_dbYMinValue) {
						xPos = (int)(pData->stPlaceData[j].dbMissX1*xSlope + xIntercept);
						yPos = (int)(yIntercept - pData->stPlaceData[j].dbMissY1*ySlope);
						pDC->Ellipse( xPos-3, yPos-3, xPos+3, yPos+3 );
					}

					//Miss2
					if (pData->stPlaceData[j].dbMissX2 <= m_dbXMaxValue && pData->stPlaceData[j].dbMissX2 >= m_dbXMinValue && 
					    pData->stPlaceData[j].dbMissY2 <= m_dbYMaxValue && pData->stPlaceData[j].dbMissY2 >= m_dbYMinValue) {
						xPos = (int)(pData->stPlaceData[j].dbMissX2*xSlope + xIntercept);
						yPos = (int)(yIntercept - pData->stPlaceData[j].dbMissY2*ySlope);
						pDC->Rectangle(xPos-3, yPos-3, xPos+3, yPos+3);
					}

// 					//Correct
// 					if (pData->stPlaceData[j].dbCorrectR <= m_dbXMaxValue && pData->stPlaceData[j].dbCorrectR >= m_dbXMinValue && 
// 					    pData->stPlaceData[j].dbCorrectT <= m_dbYMaxValue && pData->stPlaceData[j].dbCorrectT >= m_dbYMinValue) {
// 						xPos = (int)(pData->stPlaceData[j].dbCorrectR*xSlope + xIntercept);
// 						yPos = (int)(yIntercept - pData->stPlaceData[j].dbCorrectT*ySlope);
// 						pDC->Ellipse( xPos-3, yPos-3, xPos+3, yPos+3 );
// 						pDC->Ellipse( xPos-1, yPos-1, xPos+1, yPos+1 );
// 					}
				}
				else if (A1_ARM == nArm || B1_ARM == nArm) {
					if (pData->stPlaceData[j].dbMissX1 <= m_dbXMaxValue && pData->stPlaceData[j].dbMissX1 >= m_dbXMinValue && 
					    pData->stPlaceData[j].dbMissY1 <= m_dbYMaxValue && pData->stPlaceData[j].dbMissY1 >= m_dbYMinValue) {
						xPos = (int)(pData->stPlaceData[j].dbMissX1*xSlope + xIntercept);
						yPos = (int)(yIntercept - pData->stPlaceData[j].dbMissY1*ySlope);
						pDC->Ellipse( xPos-3, yPos-3, xPos+3, yPos+3 );
					}
				}
				else if (A2_ARM == nArm || B2_ARM == nArm) {
					if (pData->stPlaceData[j].dbMissX2 <= m_dbXMaxValue && pData->stPlaceData[j].dbMissX2 >= m_dbXMinValue && 
					    pData->stPlaceData[j].dbMissY2 <= m_dbYMaxValue && pData->stPlaceData[j].dbMissY2 >= m_dbYMinValue) {
						xPos = (int)(pData->stPlaceData[j].dbMissX2*xSlope + xIntercept);
						yPos = (int)(yIntercept - pData->stPlaceData[j].dbMissY2*ySlope);
						pDC->Rectangle(xPos-3, yPos-3, xPos+3, yPos+3);
					}
				} 
// 				else if (CORRECT == nArm) {
// 					if (pData->stPlaceData[j].dbCorrectR <= m_dbXMaxValue && pData->stPlaceData[j].dbCorrectR >= m_dbXMinValue && 
// 					    pData->stPlaceData[j].dbCorrectT <= m_dbYMaxValue && pData->stPlaceData[j].dbCorrectT >= m_dbYMinValue) {
// 						xPos = (int)(pData->stPlaceData[j].dbCorrectR*xSlope + xIntercept);
// 						yPos = (int)(yIntercept - pData->stPlaceData[j].dbCorrectT*ySlope);
// 						pDC->Ellipse( xPos-3, yPos-3, xPos+3, yPos+3 );
// 						pDC->Ellipse( xPos-2, yPos-2, xPos+2, yPos+2 );
// 					}
// 				}
			}

			pDC->SelectObject(OldBrush);
			Brush.DeleteObject();
		}
	}
	else {
		Brush.CreateSolidBrush(m_cTable[nModule]);
		OldBrush = pDC->SelectObject(&Brush);

		MODULE_AWC_DATA *pData = m_pParent->GetData(nModule);
		
		for (int j = 0 ; j < (int)pData->nCount ; j++)
		{
			if((nArm == A1_ARM || nArm == A2_ARM) && pData->stPlaceData[j].nArmType != A1_ARM)	continue;
			if((nArm == B1_ARM || nArm == B2_ARM) && pData->stPlaceData[j].nArmType != B1_ARM)	continue;

			int xPos , yPos;
			if(ALL_ARM == nArm) {
				//Miss1
				if (pData->stPlaceData[j].dbMissX1 <= m_dbXMaxValue && pData->stPlaceData[j].dbMissX1 >= m_dbXMinValue && 
				    pData->stPlaceData[j].dbMissY1 <= m_dbYMaxValue && pData->stPlaceData[j].dbMissY1 >= m_dbYMinValue) {
					xPos = (int)(pData->stPlaceData[j].dbMissX1*xSlope + xIntercept);
					yPos = (int)(yIntercept - pData->stPlaceData[j].dbMissY1*ySlope);
					pDC->Ellipse( xPos-3, yPos-3, xPos+3, yPos+3 );
				}

				//Miss2
				if (pData->stPlaceData[j].dbMissX2 <= m_dbXMaxValue && pData->stPlaceData[j].dbMissX2 >= m_dbXMinValue && 
				    pData->stPlaceData[j].dbMissY2 <= m_dbYMaxValue && pData->stPlaceData[j].dbMissY2 >= m_dbYMinValue) {
					xPos = (int)(pData->stPlaceData[j].dbMissX2*xSlope + xIntercept);
					yPos = (int)(yIntercept - pData->stPlaceData[j].dbMissY2*ySlope);
					pDC->Rectangle(xPos-3, yPos-3, xPos+3, yPos+3);
				}

// 				//Correct
// 				if (pData->stPlaceData[j].dbCorrectR <= m_dbXMaxValue && pData->stPlaceData[j].dbCorrectR >= m_dbXMinValue && 
// 				    pData->stPlaceData[j].dbCorrectT <= m_dbYMaxValue && pData->stPlaceData[j].dbCorrectT >= m_dbYMinValue) {
// 					xPos = (int)(pData->stPlaceData[j].dbCorrectR*xSlope + xIntercept);
// 					yPos = (int)(yIntercept - pData->stPlaceData[j].dbCorrectT*ySlope);
// 					pDC->Ellipse( xPos-3, yPos-3, xPos+3, yPos+3 );
// 					pDC->Ellipse( xPos-1, yPos-1, xPos+1, yPos+1 );
// 				}
			}
			else if (A1_ARM == nArm || B1_ARM == nArm) {
				if (pData->stPlaceData[j].dbMissX1 <= m_dbXMaxValue && pData->stPlaceData[j].dbMissX1 >= m_dbXMinValue && 
				    pData->stPlaceData[j].dbMissY1 <= m_dbYMaxValue && pData->stPlaceData[j].dbMissY1 >= m_dbYMinValue) {
					xPos = (int)(pData->stPlaceData[j].dbMissX1*xSlope + xIntercept);
					yPos = (int)(yIntercept - pData->stPlaceData[j].dbMissY1*ySlope);
					pDC->Ellipse( xPos-3, yPos-3, xPos+3, yPos+3 );
				}
			}
			else if (A2_ARM == nArm || B2_ARM == nArm) {
				if (pData->stPlaceData[j].dbMissX2 <= m_dbXMaxValue && pData->stPlaceData[j].dbMissX2 >= m_dbXMinValue && 
				    pData->stPlaceData[j].dbMissY2 <= m_dbYMaxValue && pData->stPlaceData[j].dbMissY2 >= m_dbYMinValue) {
					xPos = (int)(pData->stPlaceData[j].dbMissX2*xSlope + xIntercept);
					yPos = (int)(yIntercept - pData->stPlaceData[j].dbMissY2*ySlope);
					pDC->Rectangle(xPos-3, yPos-3, xPos+3, yPos+3);
				}
			} 
// 			else if (CORRECT == nType) {
// 				if (pData->stPlaceData[j].dbCorrectR <= m_dbXMaxValue && pData->stPlaceData[j].dbCorrectR >= m_dbXMinValue && 
// 				    pData->stPlaceData[j].dbCorrectT <= m_dbYMaxValue && pData->stPlaceData[j].dbCorrectT >= m_dbYMinValue) {
// 					xPos = (int)(pData->stPlaceData[j].dbCorrectR*xSlope + xIntercept);
// 					yPos = (int)(yIntercept - pData->stPlaceData[j].dbCorrectT*ySlope);
// 					pDC->Ellipse( xPos-3, yPos-3, xPos+3, yPos+3 );
// 					pDC->Ellipse( xPos-2, yPos-2, xPos+2, yPos+2 );
// 				}
// 			}
		}

		pDC->SelectObject(OldBrush);
		Brush.DeleteObject();
	}

	return true;
}
