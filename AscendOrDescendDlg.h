#if !defined(AFX_ASCENDORDESCENDDLG_H__1FD1E012_EAE0_4622_BBC0_05AA91BAA87B__INCLUDED_)
#define AFX_ASCENDORDESCENDDLG_H__1FD1E012_EAE0_4622_BBC0_05AA91BAA87B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AscendOrDescendDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAscendOrDescendDlg dialog

class CAscendOrDescendDlg : public CDialog
{
// Construction
public:
	CAscendOrDescendDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAscendOrDescendDlg)
	enum { IDD = IDD_DIALOG4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAscendOrDescendDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAscendOrDescendDlg)
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASCENDORDESCENDDLG_H__1FD1E012_EAE0_4622_BBC0_05AA91BAA87B__INCLUDED_)
