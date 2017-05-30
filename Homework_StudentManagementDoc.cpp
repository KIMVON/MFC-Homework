// Homework_StudentManagementDoc.cpp : implementation of the CHomework_StudentManagementDoc class
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"

#include "Homework_StudentManagementDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc

IMPLEMENT_DYNCREATE(CHomework_StudentManagementDoc, CDocument)

BEGIN_MESSAGE_MAP(CHomework_StudentManagementDoc, CDocument)
	//{{AFX_MSG_MAP(CHomework_StudentManagementDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc construction/destruction

CHomework_StudentManagementDoc::CHomework_StudentManagementDoc()
{
	// TODO: add one-time construction code here

}

CHomework_StudentManagementDoc::~CHomework_StudentManagementDoc()
{
}

BOOL CHomework_StudentManagementDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc serialization

void CHomework_StudentManagementDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc diagnostics

#ifdef _DEBUG
void CHomework_StudentManagementDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHomework_StudentManagementDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc commands
