// AddStudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"
#include "AddStudentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddStudentDlg dialog


CAddStudentDlg::CAddStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddStudentDlg)
	m_strAddress = _T("");
	m_strBirth = _T("");
	m_strCountry = _T("");
	m_strName = _T("");
	m_strNation = _T("");
	m_strNo = _T("");
	m_strSex = _T("");
	m_fScoreBiology = 0.0f;
	m_fScoreChemistry = 0.0f;
	m_fScoreChinese = 0.0f;
	m_fScoreEnglish = 0.0f;
	m_fScoreMath = 0.0f;
	m_fScorePhysics = 0.0f;
	//}}AFX_DATA_INIT
}


void CAddStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddStudentDlg)
	DDX_Control(pDX, IDC_SPIN6, m_spinScore6);
	DDX_Control(pDX, IDC_SPIN5, m_spinScore5);
	DDX_Control(pDX, IDC_SPIN4, m_spinScore4);
	DDX_Control(pDX, IDC_SPIN3, m_spinScore3);
	DDX_Control(pDX, IDC_SPIN2, m_spinScore2);
	DDX_Control(pDX, IDC_SPIN1, m_spinScore1);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_BIRTH, m_strBirth);
	DDX_Text(pDX, IDC_EDIT_COUNTRY, m_strCountry);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NATION, m_strNation);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNo);
	DDX_Text(pDX, IDC_EDIT_SEX, m_strSex);
	DDX_Text(pDX, IDC_EDIT_SCORE_BIOLOGY, m_fScoreBiology);
	DDV_MinMaxFloat(pDX, m_fScoreBiology, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_SCORE_CHEMISTRY, m_fScoreChemistry);
	DDV_MinMaxFloat(pDX, m_fScoreChemistry, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_SCORE_CHINESE, m_fScoreChinese);
	DDV_MinMaxFloat(pDX, m_fScoreChinese, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_SCORE_ENGLISH, m_fScoreEnglish);
	DDV_MinMaxFloat(pDX, m_fScoreEnglish, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_SCORE_MATH, m_fScoreMath);
	DDV_MinMaxFloat(pDX, m_fScoreMath, 0.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_SCORE_PHYSICS, m_fScorePhysics);
	DDV_MinMaxFloat(pDX, m_fScorePhysics, 0.f, 100.f);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CAddStudentDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, OnDeltaposSpin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN3, OnDeltaposSpin3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN4, OnDeltaposSpin4)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN5, OnDeltaposSpin5)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN6, OnDeltaposSpin6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddStudentDlg message handlers

BOOL CAddStudentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	//设置旋转按钮控件范围
	m_spinScore1.SetRange(0 , 100);
	m_spinScore2.SetRange(0 , 100);
	m_spinScore3.SetRange(0 , 100);
	m_spinScore4.SetRange(0 , 100);
	m_spinScore5.SetRange(0 , 100);
	m_spinScore6.SetRange(0 , 100);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


/************************************************************************/
/* 设置 旋转按钮控件1-6 的动作							                */
/************************************************************************/

void CAddStudentDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	m_fScoreChinese += (float)pNMUpDown->iDelta *0.5f;

	if (m_fScoreChinese < 0.0) {
		m_fScoreChinese = 0.0f;
	}

	if (m_fScoreChinese > 100.0) {
		m_fScoreChinese = 100.0f;
	}

	UpdateData(FALSE);
	
	*pResult = 0;
}

void CAddStudentDlg::OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	m_fScoreEnglish += (float)pNMUpDown->iDelta *0.5f;

	if (m_fScoreEnglish < 0.0) {
		m_fScoreEnglish = 0.0f;
	}

	if (m_fScoreEnglish > 100.0) {
		m_fScoreEnglish = 100.0f;
	}

	UpdateData(FALSE);
	
	*pResult = 0;
}

void CAddStudentDlg::OnDeltaposSpin3(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	m_fScoreChemistry += (float)pNMUpDown->iDelta *0.5f;

	if (m_fScoreChemistry < 0.0) {
		m_fScoreChemistry = 0.0f;
	}

	if (m_fScoreChemistry > 100.0) {
		m_fScoreChemistry = 100.0f;
	}

	UpdateData(FALSE);
	
	*pResult = 0;
}

void CAddStudentDlg::OnDeltaposSpin4(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	m_fScoreMath += (float)pNMUpDown->iDelta *0.5f;

	if (m_fScoreMath < 0.0) {
		m_fScoreMath = 0.0f;
	}

	if (m_fScoreMath > 100.0) {
		m_fScoreMath = 100.0f;
	}

	UpdateData(FALSE);
	
	*pResult = 0;
}

void CAddStudentDlg::OnDeltaposSpin5(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	m_fScorePhysics += (float)pNMUpDown->iDelta *0.5f;

	if (m_fScorePhysics < 0.0) {
		m_fScorePhysics = 0.0f;
	}

	if (m_fScorePhysics > 100.0) {
		m_fScorePhysics = 100.0f;
	}

	UpdateData(FALSE);

	*pResult = 0;
}

void CAddStudentDlg::OnDeltaposSpin6(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	m_fScoreBiology += (float)pNMUpDown->iDelta *0.5f;

	if (m_fScoreBiology < 0.0) {
		m_fScoreBiology = 0.0f;
	}

	if (m_fScoreBiology > 100.0) {
		m_fScoreBiology = 100.0f;
	}

	UpdateData(FALSE);
	
	*pResult = 0;
}

void CAddStudentDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);

	m_strNo.TrimLeft();
	m_strName.TrimLeft();
	m_strBirth.TrimLeft();
	m_strSex.TrimLeft();
	m_strCountry.TrimLeft();
	m_strNation.TrimLeft();
	m_strAddress.TrimLeft();

	//差错检测
	if (m_strNo.IsEmpty()
		|| m_strName.IsEmpty()
		|| m_strSex.IsEmpty()
		|| m_strBirth.IsEmpty()
		|| m_strCountry.IsEmpty()
		|| m_strNation.IsEmpty()
		|| m_strAddress.IsEmpty()) {

		if (m_strNo.IsEmpty()) {
			MessageBox("学号不能为空！！！");
		}else if (m_strName.IsEmpty()) {
			MessageBox("姓名不能为空！！！");
		}else if (m_strSex.IsEmpty()) {
			MessageBox("性别不能为空！！！");
		}else if (m_strBirth.IsEmpty()) {
			MessageBox("出生日期不能为空！！！");
		}else if (m_strCountry.IsEmpty()) {
			MessageBox("国家不能为空！！！");
		}else if (m_strNation.IsEmpty()) {
			MessageBox("民族不能为空！！！");
		}else if (m_strAddress.IsEmpty()) {
			MessageBox("家庭地址不能为空！！！");
		}
		
	}else{
		
		if (!(m_strSex=="男"||m_strSex=="女")) {
			MessageBox("性别输入的格式不对！！！");
		}else if (FALSE) {
		}else if (FALSE) {
		}else if (FALSE) {
		}else if (FALSE) {
		}else if (FALSE) {
		}else if (FALSE) {
		}else if (FALSE) {
		}else if (FALSE) {
		}else{
			CDialog::OnOK();
		}
	
	}
	 



}
