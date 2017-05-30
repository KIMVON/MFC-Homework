#if !defined(AFX_ADDSTUDENTDLG_H__B8E82233_E0B2_4E7C_8C5B_11123E8C89B2__INCLUDED_)
#define AFX_ADDSTUDENTDLG_H__B8E82233_E0B2_4E7C_8C5B_11123E8C89B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddStudentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddStudentDlg dialog

class CAddStudentDlg : public CDialog
{
// Construction
public:
	CAddStudentDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddStudentDlg)
	enum { IDD = IDD_DIALOG1 };
	CSpinButtonCtrl	m_spinScore6;
	CSpinButtonCtrl	m_spinScore5;
	CSpinButtonCtrl	m_spinScore4;
	CSpinButtonCtrl	m_spinScore3;
	CSpinButtonCtrl	m_spinScore2;
	CSpinButtonCtrl	m_spinScore1;
	CString	m_strAddress;
	CString	m_strBirth;
	CString	m_strCountry;
	CString	m_strName;
	CString	m_strNation;
	CString	m_strNo;
	CString	m_strSex;
	float	m_fScoreBiology;
	float	m_fScoreChemistry;
	float	m_fScoreChinese;
	float	m_fScoreEnglish;
	float	m_fScoreMath;
	float	m_fScorePhysics;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddStudentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddStudentDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin3(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin4(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin5(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpin6(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSTUDENTDLG_H__B8E82233_E0B2_4E7C_8C5B_11123E8C89B2__INCLUDED_)
