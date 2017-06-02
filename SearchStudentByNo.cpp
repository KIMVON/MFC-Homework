// SearchStudentByNo.cpp : implementation file
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"
#include "SearchStudentByNo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchStudentByNo dialog


CSearchStudentByNo::CSearchStudentByNo(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchStudentByNo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchStudentByNo)
	m_strStudentNo = _T("");
	//}}AFX_DATA_INIT
}


void CSearchStudentByNo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchStudentByNo)
	DDX_Text(pDX, IDC_EDIT1, m_strStudentNo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchStudentByNo, CDialog)
	//{{AFX_MSG_MAP(CSearchStudentByNo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchStudentByNo message handlers

void CSearchStudentByNo::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	CDialog::OnOK();
}
