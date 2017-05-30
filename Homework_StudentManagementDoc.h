// Homework_StudentManagementDoc.h : interface of the CHomework_StudentManagementDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOMEWORK_STUDENTMANAGEMENTDOC_H__CE953165_116C_49E5_8C1C_9E0C0B8164AC__INCLUDED_)
#define AFX_HOMEWORK_STUDENTMANAGEMENTDOC_H__CE953165_116C_49E5_8C1C_9E0C0B8164AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHomework_StudentManagementDoc : public CDocument
{
protected: // create from serialization only
	CHomework_StudentManagementDoc();
	DECLARE_DYNCREATE(CHomework_StudentManagementDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHomework_StudentManagementDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHomework_StudentManagementDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHomework_StudentManagementDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOMEWORK_STUDENTMANAGEMENTDOC_H__CE953165_116C_49E5_8C1C_9E0C0B8164AC__INCLUDED_)
