// AscendOrDescend.cpp : implementation file
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"
#include "AscendOrDescend.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAscendOrDescend dialog


CAscendOrDescend::CAscendOrDescend(CWnd* pParent /*=NULL*/)
	: CDialog(CAscendOrDescend::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAscendOrDescend)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAscendOrDescend::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAscendOrDescend)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAscendOrDescend, CDialog)
	//{{AFX_MSG_MAP(CAscendOrDescend)
	ON_BN_CLICKED(IDCANCEL, OnDescendingOrder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAscendOrDescend message handlers

void CAscendOrDescend::OnDescendingOrder() 
{
	// TODO: Add your control notification handler code here
	
}
