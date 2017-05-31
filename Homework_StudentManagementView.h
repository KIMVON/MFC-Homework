// Homework_StudentManagementView.h : interface of the CHomework_StudentManagementView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOMEWORK_STUDENTMANAGEMENTVIEW_H__6C03FF94_1E3E_4A34_9AA0_15CB194D3CFF__INCLUDED_)
#define AFX_HOMEWORK_STUDENTMANAGEMENTVIEW_H__6C03FF94_1E3E_4A34_9AA0_15CB194D3CFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHomework_StudentManagementView : public CListView
{
protected: // create from serialization only
	CHomework_StudentManagementView();
	DECLARE_DYNCREATE(CHomework_StudentManagementView)

// Attributes
public:
	CHomework_StudentManagementDoc* GetDocument();

// Operations
public:

	void SetCtrlStyle(HWND hWnd, DWORD dwNewStyle)
	{
		DWORD	dwOldStyle;
		dwOldStyle = GetWindowLong(hWnd, GWL_STYLE);		// 获取当前风格
		if ((dwOldStyle&LVS_TYPEMASK) != dwNewStyle){
			dwOldStyle &= ~LVS_TYPEMASK;
			dwNewStyle |= dwOldStyle;
			SetWindowLong(hWnd, GWL_STYLE, dwNewStyle);	// 设置新风格
		}
	}

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHomework_StudentManagementView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void UpdateListItemData();
	virtual ~CHomework_StudentManagementView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHomework_StudentManagementView)
	afx_msg void OnStudentAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Homework_StudentManagementView.cpp
inline CHomework_StudentManagementDoc* CHomework_StudentManagementView::GetDocument()
   { return (CHomework_StudentManagementDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOMEWORK_STUDENTMANAGEMENTVIEW_H__6C03FF94_1E3E_4A34_9AA0_15CB194D3CFF__INCLUDED_)
