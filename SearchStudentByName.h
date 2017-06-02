#if !defined(AFX_SEARCHSTUDENTBYNAME_H__6770FFC0_731C_49D0_B578_ED2EF2DCCC81__INCLUDED_)
#define AFX_SEARCHSTUDENTBYNAME_H__6770FFC0_731C_49D0_B578_ED2EF2DCCC81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchStudentByName.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchStudentByName dialog

class CSearchStudentByName : public CDialog
{
// Construction
public:
	CSearchStudentByName(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchStudentByName)
	enum { IDD = IDD_DIALOG3 };
	CString	m_strStudentName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchStudentByName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchStudentByName)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHSTUDENTBYNAME_H__6770FFC0_731C_49D0_B578_ED2EF2DCCC81__INCLUDED_)
