// PortInfo.cpp: implementation of the CPortInfo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PortInfo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPortInfo::CPortInfo()
{
	memset(m_szModuleName , 0 , sizeof(m_szModuleName));
	m_usPortNum = 0;
}

CPortInfo::~CPortInfo()
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Function     : SetModuleName
//Date         : 2007.03.13
//Description  : 
//Arguments    :
//Return Value : bool
//////////////////////////////////////////////////////////////////////////////////////////////////////
bool CPortInfo::SetModuleName  (char* szModuleName)
{
	bool bRet = true;

	if (NULL == szModuleName) return false;
	else if (0 == strcmp(szModuleName , "PM1")
		  || 0 == strcmp(szModuleName , "PM2")
		  || 0 == strcmp(szModuleName , "PM3")
		  || 0 == strcmp(szModuleName , "PM4")
		  || 0 == strcmp(szModuleName , "PM5")
		  || 0 == strcmp(szModuleName , "PM6")) {
		strcpy(m_szModuleName , szModuleName);
	} else return false;

	return bRet;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Function     : GetModuleName
//Date         : 2007.03.13
//Description  : 
//Arguments    :
//Return Value : char*
//////////////////////////////////////////////////////////////////////////////////////////////////////
char* CPortInfo::GetModuleName()
{
	return m_szModuleName;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Function     : SetPortNum
//Date         : 2007.03.13
//Description  : 
//Arguments    :
//Return Value : bool
//////////////////////////////////////////////////////////////////////////////////////////////////////
bool  CPortInfo::SetPortNum  (unsigned short usPortNum)
{
	bool bRet = true;

	if (usPortNum >= 6000 && usPortNum <= 9000)
		m_usPortNum = usPortNum;
	else return false;

	return bRet;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//Function     : GetPortNum
//Date         : 2007.03.13
//Description  : 
//Arguments    :
//Return Value : unsigned short
//////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned short CPortInfo::GetPortNum()
{
	return m_usPortNum;
}

