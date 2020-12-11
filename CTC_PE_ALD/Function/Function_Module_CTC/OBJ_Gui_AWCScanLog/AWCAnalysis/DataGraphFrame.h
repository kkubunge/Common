// DataGraphFrame.h: interface for the CDataGraphFrame class.
//
//////////////////////////////////////////////////////////////////////
//2014.03.13 Created by mgsong
//           �׷��� ������ �߽��� �������� �ϴ� �׷��� �׸���
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
	//Graph ��ü ����
	CRect m_FrameRect;

	//Graph�� Data����
	CRect m_GraphRect;

	char  m_szTitle[128];

	//Y�� ������ �� ĭ���� ���� ��
	int   m_nYDevide;

	//X�� ������ �� ĭ���� ���� ��
	int   m_nXDevide;

	//X�� �� ǥ���� �ִ� / �ּ� ��
	double m_dbXMaxValue;
	double m_dbXMinValue;

	//Y�� �� ǥ���� �ִ� / �ּ� ��
	double m_dbYMaxValue;
	double m_dbYMinValue;

	//�׷��� �׸��� ����
	//���������� Title�̷��� ����.
	int m_nLeftMargin;	
	int m_nRightMargin;	
	int m_nTopMargin;	
	int m_nBottomMargin;	

	//Grid����
	//��ü ���̿� Grid�� �� ĭ �׸� ����
	bool     m_bGridDraw;
	int      m_nXGridLineCount;
	int      m_nYGridLineCount;
	int      m_nGridLineType;
	COLORREF m_cGridLineColor;

	//���� ���� �� ����
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
