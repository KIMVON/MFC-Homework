// AscendOrDescendDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"
#include "AscendOrDescendDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAscendOrDescendDlg dialog


CAscendOrDescendDlg::CAscendOrDescendDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAscendOrDescendDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAscendOrDescendDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAscendOrDescendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAscendOrDescendDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAscendOrDescendDlg, CDialog)
	//{{AFX_MSG_MAP(CAscendOrDescendDlg)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAscendOrDescendDlg message handlers

//重新设置对话框右上角的X
void CAscendOrDescendDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	int nRet=5;  
	//自定义关闭方式
    EndDialog(nRet);  
	CDialog::OnClose();
}
