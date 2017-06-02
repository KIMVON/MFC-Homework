// SearchStudentByName.cpp : implementation file
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"
#include "SearchStudentByName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchStudentByName dialog


CSearchStudentByName::CSearchStudentByName(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchStudentByName::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchStudentByName)
	m_strStudentName = _T("");
	//}}AFX_DATA_INIT
}


void CSearchStudentByName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchStudentByName)
	DDX_Text(pDX, IDC_EDIT1, m_strStudentName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchStudentByName, CDialog)
	//{{AFX_MSG_MAP(CSearchStudentByName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchStudentByName message handlers

void CSearchStudentByName::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	CDialog::OnOK();
}
