// DynamicIO.cpp: implementation of the CDynamicIO class.
//
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include <string.h>
//====================================================================
extern "C"
{
#include <Kutlstr.h>
#include <Kutltime.h>
#include "cimseqnc.h"
#include "iodefine.h"
} // End of [extern "C"]
//====================================================================

#include "DynamicIO.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDynamicIO::CDynamicIO()
{
	m_bIOValidErrCheck = TRUE;
	m_nIOCount = 0;
	m_pIOList = NULL;
}

CDynamicIO::~CDynamicIO()
{

}

//////////////////////////////////////////////////////////////////////
// Member Function


BOOL CDynamicIO::InitIOList(IO_LIST pIOList[], bool bIOValidErrCheck, int nIOValidCheckIdx, int nModuleNumber)
{
	BOOL bRet = TRUE;
	int i;
	m_pIOList = pIOList;
	m_bIOValidErrCheck = bIOValidErrCheck;
	for(i=0; m_pIOList[i].szIOName[0] != 0; i++)
	{
		if(strncmp("NotDefined", m_pIOList[i].szIOName, 10) == 0)
		{
			m_pIOList[i].nIOPoint = -1;
			continue;
		}
		
		if(nModuleNumber>0 && nModuleNumber<10) ChangeChar(m_pIOList[i].szIOName, '#', '0'+nModuleNumber);	// 2006.02.22
		m_pIOList[i].nIOPoint = _FIND_FROM_STRING(m_pIOList[i].nIOType, m_pIOList[i].szIOName);
		if(m_pIOList[i].nIOPoint == -1)
		{
			if(bIOValidErrCheck && i>=nIOValidCheckIdx)
			{
				printf("-----> Init IO failed ![Name:%s,Type:%d]\n",m_pIOList[i].szIOName, m_pIOList[i].nIOType);
				bRet = FALSE;
			}
		}
	}
	m_nIOCount = i;
	return bRet;
}

BOOL CDynamicIO::IOValid(int nIoIdxEnum)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); return FALSE; }
	if(nIoIdxEnum >= m_nIOCount) return FALSE;
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1) return FALSE;
	else return TRUE;
}

void CDynamicIO::dWRITE_DIGITAL(int nIoIdxEnum, int nValue, BOOL *pResult)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); *pResult = FALSE; return; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_D_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dWRITE_DIGITAL\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		*pResult = FALSE;
		return;
	}
	_dWRITE_DIGITAL(m_pIOList[nIoIdxEnum].nIOPoint, nValue, pResult);
}

int CDynamicIO::dREAD_DIGITAL(int nIoIdxEnum, BOOL *pResult)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); *pResult = FALSE; return 0; }
	int nValue = 0;
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_D_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dREAD_DIGITAL\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		*pResult = FALSE;
		return 0;
	}
	nValue = _dREAD_DIGITAL(m_pIOList[nIoIdxEnum].nIOPoint, pResult);
	return nValue;
}

void CDynamicIO::dWRITE_ANALOG(int nIoIdxEnum, double dbValue, BOOL *pResult)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); *pResult = FALSE; return; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_A_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dWRITE_ANALOG\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		*pResult = FALSE;
		return;
	}
	_dWRITE_ANALOG(m_pIOList[nIoIdxEnum].nIOPoint, dbValue, pResult);
}

double CDynamicIO::dREAD_ANALOG(int nIoIdxEnum, BOOL *pResult)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); *pResult = FALSE; return 0; }
	double dbValue = 0;
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_A_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dREAD_ANALOG\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		*pResult = FALSE;
		return 0;
	}
	dbValue = _dREAD_ANALOG(m_pIOList[nIoIdxEnum].nIOPoint, pResult);
	return dbValue;
}

void CDynamicIO::dWRITE_STRING(int nIoIdxEnum, char *pValue, BOOL *pResult)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); *pResult = FALSE; return; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_S_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dWRITE_STRING\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		*pResult = FALSE;
		return;
	}
	_dWRITE_STRING(m_pIOList[nIoIdxEnum].nIOPoint, pValue, pResult);
}

char* CDynamicIO::dREAD_STRING(int nIoIdxEnum, char *pValue, BOOL *pResult)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); *pResult = FALSE; return 0; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_S_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dREAD_STRING\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		*pResult = FALSE;
		return 0;
	}
	_dREAD_STRING(m_pIOList[nIoIdxEnum].nIOPoint, pValue, pResult);
	return pValue;
}

int CDynamicIO::dRUN_FUNCTION(int nIoIdxEnum, char *szParam)
{
	int nRet = SYS_ABORTED;
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); return nRet; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_F_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dRUN_FUNCTION\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		return nRet;
	}
	nRet = _dRUN_FUNCTION(m_pIOList[nIoIdxEnum].nIOPoint, szParam);
	return nRet;
}

int CDynamicIO::dRUN_WAIT_FUNCTION(int nIoIdxEnum)
{
	int nRet = SYS_ABORTED;
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); return nRet; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_F_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dRUN_FUNCTION\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		return nRet;
	}
	nRet = _dRUN_WAIT_FUNCTION(m_pIOList[nIoIdxEnum].nIOPoint);
	return nRet;
}

BOOL CDynamicIO::dRUN_FUNCTION_FREE(int nIoIdxEnum, char *szParam)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); return FALSE; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_F_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dRUN_FUNCTION_FREE\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		return FALSE;
	}
	_dRUN_FUNCTION_FREE(m_pIOList[nIoIdxEnum].nIOPoint, szParam);
	return TRUE;
}

BOOL CDynamicIO::dRUN_FUNCTION_ABORT(int nIoIdxEnum)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); return FALSE; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_F_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dRUN_FUNCTION_ABORT\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		return FALSE;
	}
	_dRUN_FUNCTION_ABORT(m_pIOList[nIoIdxEnum].nIOPoint);
	return TRUE;
}

BOOL CDynamicIO::dRUN_SET_FUNCTION(int nIoIdxEnum, char *szParam)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); return FALSE; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_F_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dRUN_SET_FUNCTION\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		return FALSE;
	}
	_dRUN_SET_FUNCTION(m_pIOList[nIoIdxEnum].nIOPoint, szParam);
	return TRUE;
}

int CDynamicIO::dREAD_FUNCTION(int nIoIdxEnum)
{
	int nRet = SYS_ABORTED;
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); return nRet; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_F_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dREAD_FUNCTION\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		return nRet;
	}
	nRet = _dREAD_FUNCTION(m_pIOList[nIoIdxEnum].nIOPoint);
	return nRet;
}

BOOL CDynamicIO::dWRITE_FUNCTION_EVENT(int nIoIdxEnum, char *szParam)
{
	if(m_pIOList == NULL) { printf("-----> IO List is not initialized !\n"); return FALSE; }
	if(m_pIOList[nIoIdxEnum].nIOPoint == -1 || m_pIOList[nIoIdxEnum].nIOType != _K_F_IO)
	{
		#ifdef _DEBUG
		printf("-----> Invalid IO [Name:%s,Type:%d,Point:%d] in dWRITE_FUNCTION_EVENT\n",
				m_pIOList[nIoIdxEnum].szIOName, m_pIOList[nIoIdxEnum].nIOType, m_pIOList[nIoIdxEnum].nIOPoint);
		#endif
		return FALSE;
	}
	_dWRITE_FUNCTION_EVENT(m_pIOList[nIoIdxEnum].nIOPoint, szParam);
	return TRUE;
}

void CDynamicIO::ChangeChar(char* szString, char cCur, char cNew)	// 2006.02.22
{
	int i;
	for(i=0; *(szString+i) != NULL; i++)
	{
		if(*(szString+i) == cCur) *(szString+i) = cNew;
	}
}