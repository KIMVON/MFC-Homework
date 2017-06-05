#if !defined(AFX_AFFIRMDEL_H__023B79B6_EE27_414A_A5E6_93B7BEC86EEA__INCLUDED_)
#define AFX_AFFIRMDEL_H__023B79B6_EE27_414A_A5E6_93B7BEC86EEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AffirmDel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAffirmDel dialog

class CAffirmDel : public CDialog
{
// Construction
public:
	CAffirmDel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAffirmDel)
	enum { IDD = IDD_DIALOG5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAffirmDel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAffirmDel)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AFFIRMDEL_H__023B79B6_EE27_414A_A5E6_93B7BEC86EEA__INCLUDED_)
