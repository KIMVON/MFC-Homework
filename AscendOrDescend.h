#if !defined(AFX_ASCENDORDESCEND_H__BA3782F0_54CA_4328_AC26_AAAE5B3518C4__INCLUDED_)
#define AFX_ASCENDORDESCEND_H__BA3782F0_54CA_4328_AC26_AAAE5B3518C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AscendOrDescend.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAscendOrDescend dialog

class CAscendOrDescend : public CDialog
{
// Construction
public:
	CAscendOrDescend(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAscendOrDescend)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAscendOrDescend)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAscendOrDescend)
	afx_msg void OnDescendingOrder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASCENDORDESCEND_H__BA3782F0_54CA_4328_AC26_AAAE5B3518C4__INCLUDED_)
