// AWCAnalysis.h : main header file for the AWCANALYSIS application
//

#if !defined(AFX_AWCANALYSIS_H__1EEEB3BA_83EF_483F_9D02_C6D23423F10F__INCLUDED_)
#define AFX_AWCANALYSIS_H__1EEEB3BA_83EF_483F_9D02_C6D23423F10F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAWCAnalysisApp:
// See AWCAnalysis.cpp for the implementation of this class
//

class CAWCAnalysisApp : public CWinApp
{
public:
	CAWCAnalysisApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAWCAnalysisApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAWCAnalysisApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AWCANALYSIS_H__1EEEB3BA_83EF_483F_9D02_C6D23423F10F__INCLUDED_)
