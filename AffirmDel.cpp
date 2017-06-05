// AffirmDel.cpp : implementation file
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"
#include "AffirmDel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAffirmDel dialog


CAffirmDel::CAffirmDel(CWnd* pParent /*=NULL*/)
	: CDialog(CAffirmDel::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAffirmDel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAffirmDel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAffirmDel)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAffirmDel, CDialog)
	//{{AFX_MSG_MAP(CAffirmDel)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAffirmDel message handlers
