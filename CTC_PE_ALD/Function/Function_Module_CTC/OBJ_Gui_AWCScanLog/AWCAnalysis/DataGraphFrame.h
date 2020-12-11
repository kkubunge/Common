// DataGraphFrame.h: interface for the CDataGraphFrame class.
//
//////////////////////////////////////////////////////////////////////
//2014.03.13 Created by mgsong
//           그래프 영역의 중심을 원점으로 하는 그래프 그리기
//           

#if !defined(AFX_DATAGRAPHFRAME_H__30E3FD1A_CF7D_4769_B509_BBB621753F86__INCLUDED_)
#define AFX_DATAGRAPHFRAME_H__30E3FD1A_CF7D_4769_B509_BBB621753F86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Constant.h"

class CAWCAnalysisDlg;
class CDataGraphFrame  
{
public:
	CDataGraphFrame(CAWCAnalysisDlg *pParent);
	virtual ~CDataGraphFrame();

	void     SetGraphTitle(char *szTitle);
	bool     Init    (CRect *pFrameRect , int nXDevide , int nYDevide , double dbXMaxValue , double dbYMaxValue);
	bool     Draw    (CDC *pDC);

	void     SetXMax(double  dbMax);
	void     SetYMax(double  dbMax);
	void     GetXMax(double& dbMax);
	void     GetYMax(double& dbMax);

private:

	void     PrintText(HDC hDC , int x , int y , int theta , char *szText , COLORREF cTextColor);
	bool     DrawFrame(CDC *pDC);
	bool     DrawGraph(CDC *pDC);

private:
	//Graph 전체 영역
	CRect m_FrameRect;

	//Graph의 Data영역
	CRect m_GraphRect;

	char  m_szTitle[128];

	//Y축 눈금을 몇 칸으로 나눌 지
	int   m_nYDevide;

	//X축 눈금을 몇 칸으로 나눌 지
	int   m_nXDevide;

	//X축 상 표현할 최대 / 최소 값
	double m_dbXMaxValue;
	double m_dbXMinValue;

	//Y축 상 표현할 최대 / 최소 값
	double m_dbYMaxValue;
	double m_dbYMinValue;

	//그래프 그리기 마진
	//마진영역에 Title이런거 쓴다.
	int m_nLeftMargin;	
	int m_nRightMargin;	
	int m_nTopMargin;	
	int m_nBottomMargin;	

	//Grid관련
	//전체 넓이에 Grid를 몇 칸 그릴 건지
	bool     m_bGridDraw;
	int      m_nXGridLineCount;
	int      m_nYGridLineCount;
	int      m_nGridLineType;
	COLORREF m_cGridLineColor;

	//각종 구성 부 색상
	COLORREF m_cFrameLine;
	COLORREF m_CFrameTextColor;
	COLORREF m_cFrameBackground;
	COLORREF m_cGraphBackground;
	COLORREF m_cTextColor;
	
	COLORREF m_cTable[MAX_MODULE_COUNT];

	//
	CAWCAnalysisDlg *m_pParent;

};

#endif // !defined(AFX_DATAGRAPHFRAME_H__30E3FD1A_CF7D_4769_B509_BBB621753F86__INCLUDED_)
