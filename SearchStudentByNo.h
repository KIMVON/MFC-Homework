#if !defined(AFX_SEARCHSTUDENTBYNO_H__F7310B46_8B11_438D_A24F_8F07332684E2__INCLUDED_)
#define AFX_SEARCHSTUDENTBYNO_H__F7310B46_8B11_438D_A24F_8F07332684E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchStudentByNo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchStudentByNo dialog

class CSearchStudentByNo : public CDialog
{
// Construction
public:
	CSearchStudentByNo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSearchStudentByNo)
	enum { IDD = IDD_DIALOG2 };
	CString	m_strStudentNo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchStudentByNo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchStudentByNo)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHSTUDENTBYNO_H__F7310B46_8B11_438D_A24F_8F07332684E2__INCLUDED_)
