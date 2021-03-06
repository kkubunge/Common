// DynamicIO.h: interface for the CDynamicIO class.
// Create : 2005.11.01
// Last Update : 2005.12.07
// Writer : Chang-su, Kim.
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNAMICIO_H__69A96A6D_AC54_41AB_ACC0_BE69D32D76FD__INCLUDED_)
#define AFX_DYNAMICIO_H__69A96A6D_AC54_41AB_ACC0_BE69D32D76FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//--------------------------------------------------------------------
typedef struct _IO_LIST
{
	char szIOName[40];
	int nIOType;
	int nIOPoint;
} IO_LIST;

//--------------------------------------------------------------------
class CDynamicIO  
{
public:
	CDynamicIO();
	virtual ~CDynamicIO();

	// Member Function
public:
	BOOL InitIOList(IO_LIST pIOList[], bool bIOValidErrCheck = true, int nIOValidCheckIdx = 0);
	BOOL IOValid(int nIoIdxEnum);

	void dWRITE_DIGITAL(int nIoIdxEnum, int nValue, BOOL *pResult);
	int dREAD_DIGITAL(int nIoIdxEnum, BOOL *pResult);

	void dWRITE_ANALOG(int nIoIdxEnum, double dbValue, BOOL *pResult);
	double dREAD_ANALOG(int nIoIdxEnum, BOOL *pResult);

	void dWRITE_STRING(int nIoIdxEnum, char *pValue, BOOL *pResult);
	char *dREAD_STRING(int nIoIdxEnum, char *pValue, BOOL *pResult);

private:
	bool m_bIOValidErrCheck;
	IO_LIST *m_pIOList;
	int m_nIOCount;
};

#endif // !defined(AFX_DYNAMICIO_H__69A96A6D_AC54_41AB_ACC0_BE69D32D76FD__INCLUDED_)
//////////////////////////////////////////////////////////////////////
/* Sample
//--------------------------------------------------------------------
#include "DynamicIO.h"
//--------------------------------------------------------------------
// Dynamic IO Enum List Definition
static enum {
	PRO_PostRunDM,
	PRO_PostCmptDM,
	PRMD_Refill_Opt,
	NotDefined_1,
	NotDefined_2,
	Valve10;
} IO_INDEX_ENUM;
//--------------------------------------------------------------------
// Dynamic IO List Definition
static IO_LIST	g_pIOList[] =
{
	{"PRO_PostRunDM",		_K_D_IO, 0},
	{"PRO_PostCmptDM",		_K_D_IO, 0},
	{"PRMD_Refill_Opt",		_K_D_IO, 0},
	{"NotDefined_1",		_K_D_IO, 0},
	{"NotDefined_2",		_K_D_IO, 0},
	{"Valve10",				_K_D_IO, 0},
	""
};
//--------------------------------------------------------------------
*/

//////////////////////////////////////////////////////////////////////
/* Update History
2005.11.01	Created.
			???????? I/O?? ???? ?? ?????? ???????? ???? ???? Class ????.
			C-Code?? ???? ???? Function?? Class?? ????????.
2005.11.02	InitIOList() Function?? I/O Name?? ???????? ???? ????
			Error?? ?????? Print???? Option ????
2005.11.16	Debug Mode Compile?? ???? Code?????? Channel I/O Error
			?????? Console?? Print ?????? ????.
2005.11.19	<cskim> I/O?? ???????? ?? Console ?????? Print???? ???? ????.
			InitIOList() Function?? BOOL Type Parameter?? bool Type????
			????.
2005.11.22	InitIOList() ???? I/O Valid Check???? Check?????? I/O
			?????? ???? ?????? ???? ????.
2005.11.25	Init IO Fail ???? Console ?????? Print ???? ???? ????.
2005.12.07	Sample?? ???? ?????? ???? ????(m_pIOList => g_pIOList).
--------------------------------------------------------------------*/
