// Homework_StudentManagement.h : main header file for the HOMEWORK_STUDENTMANAGEMENT application
//

#if !defined(AFX_HOMEWORK_STUDENTMANAGEMENT_H__8B5457C8_72EB_48A0_979F_BF738D1DCF55__INCLUDED_)
#define AFX_HOMEWORK_STUDENTMANAGEMENT_H__8B5457C8_72EB_48A0_979F_BF738D1DCF55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementApp:
// See Homework_StudentManagement.cpp for the implementation of this class
//

class CHomework_StudentManagementApp : public CWinApp
{
public:
	CHomework_StudentManagementApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHomework_StudentManagementApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CHomework_StudentManagementApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOMEWORK_STUDENTMANAGEMENT_H__8B5457C8_72EB_48A0_979F_BF738D1DCF55__INCLUDED_)
