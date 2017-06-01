// Homework_StudentManagementView.cpp : implementation of the CHomework_StudentManagementView class
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"

#include "Homework_StudentManagementDoc.h"
#include "Homework_StudentManagementView.h"

#include "AddStudentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementView

IMPLEMENT_DYNCREATE(CHomework_StudentManagementView, CListView)

BEGIN_MESSAGE_MAP(CHomework_StudentManagementView, CListView)
	//{{AFX_MSG_MAP(CHomework_StudentManagementView)
	ON_COMMAND(ID_STUDENT_ADD, OnStudentAdd)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementView construction/destruction

CHomework_StudentManagementView::CHomework_StudentManagementView()
{
	// TODO: add construction code here

}

CHomework_StudentManagementView::~CHomework_StudentManagementView()
{
}

BOOL CHomework_StudentManagementView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementView drawing

void CHomework_StudentManagementView::OnDraw(CDC* pDC)
{
	CHomework_StudentManagementDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CHomework_StudentManagementView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: You may populate your ListView with items by directly accessing
	//  its list control through a call to GetListCtrl().
	CListCtrl& m_ListCtrl = GetListCtrl();
	LV_COLUMN listCol;
	char* arCols[14]={"学号", "姓名", "性别", "出生日期" , "国籍" , "民族" , "地址" , "语文" , "数学" , "英语" , "物理" , "化学" , "生物" , "平均成绩"};
	listCol.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;

	// 添加列表头
	for (int nCol=0; nCol<14; nCol++)	{
		listCol.iSubItem = nCol;
		listCol.pszText = arCols[nCol];	
		listCol.fmt = LVCFMT_LEFT;
		m_ListCtrl.InsertColumn(nCol,&listCol);
	}



	SetCtrlStyle(m_ListCtrl.GetSafeHwnd(), LVS_REPORT);	// 设置为报表方式
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	// 设置扩展风格，使得列表项一行全项选择且显示出网格线
	
	// 设置列宽
	m_ListCtrl.SetColumnWidth(0, 100);	// 学号列宽
	m_ListCtrl.SetColumnWidth(1, 100);	// 姓名列宽
	m_ListCtrl.SetColumnWidth(2, 100);	// 性别列宽
	m_ListCtrl.SetColumnWidth(3, 100);	// 出生日期列宽
	m_ListCtrl.SetColumnWidth(4, 100);	// 国籍列宽
	m_ListCtrl.SetColumnWidth(5, 100);	// 民族列宽
	m_ListCtrl.SetColumnWidth(6, 200);	// 地址列宽
	m_ListCtrl.SetColumnWidth(7, 100);	// 语文列宽
	m_ListCtrl.SetColumnWidth(8, 100);	// 数学列宽
	m_ListCtrl.SetColumnWidth(9, 100);	// 英语列宽
	m_ListCtrl.SetColumnWidth(10, 100);	// 物理列宽
	m_ListCtrl.SetColumnWidth(11, 100);	// 化学列宽 
	m_ListCtrl.SetColumnWidth(12, 100);	// 生物列宽
	m_ListCtrl.SetColumnWidth(13, 100);	// 平均成绩列宽

}

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementView printing

BOOL CHomework_StudentManagementView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHomework_StudentManagementView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHomework_StudentManagementView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementView diagnostics

#ifdef _DEBUG
void CHomework_StudentManagementView::AssertValid() const
{
	CListView::AssertValid();
}

void CHomework_StudentManagementView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CHomework_StudentManagementDoc* CHomework_StudentManagementView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHomework_StudentManagementDoc)));
	return (CHomework_StudentManagementDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementView message handlers

void CHomework_StudentManagementView::UpdateListItemData()
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();
	CHomework_StudentManagementDoc* doc = GetDocument();

	POSITION pos = doc->m_stuObList.GetHeadPosition();
	int nIndex;

	//while (pos!=NULL) {
	for (int nItem = 0 ; nItem <doc->m_stuObList.GetCount() ; nItem++ ) {
	
		CStudent* stu =(CStudent*)(doc->m_stuObList).GetAt(pos);
		
		nIndex = m_ListCtrl.InsertItem(nItem , stu->getNo());

		CString str;
		

//		m_ListCtrl.SetItemText(nIndex , 1 , stu->getNo());
		m_ListCtrl.SetItemText(nIndex , 1 , stu->getName());
		m_ListCtrl.SetItemText(nIndex , 2 , stu->getSex());
		m_ListCtrl.SetItemText(nIndex , 3 , stu->getBirth());
		m_ListCtrl.SetItemText(nIndex , 4 , stu->getCountry());
		m_ListCtrl.SetItemText(nIndex , 5 , stu->getNation());
		m_ListCtrl.SetItemText(nIndex , 6 , stu->getAddress());
		//浮点数转字符串
		str.Format("%.1f" , stu->getChineseScore());
		m_ListCtrl.SetItemText(nIndex , 7 , str);
		
		//浮点数转字符串
		str.Format("%.1f" , stu->getMathScore());
		m_ListCtrl.SetItemText(nIndex , 8 , str);

		//浮点数转字符串
		str.Format("%.1f" , stu->getEnglishScore());
		m_ListCtrl.SetItemText(nIndex , 9 , str);

		//浮点数转字符串
		str.Format("%.1f" , stu->getPhysicsScore());
		m_ListCtrl.SetItemText(nIndex , 10 , str);

		//浮点数转字符串
		str.Format("%.1f" , stu->getChemistryScore());
		m_ListCtrl.SetItemText(nIndex , 11 , str);
		
		//浮点数转字符串
		str.Format("%.1f" , stu->getBiologyScore());
		m_ListCtrl.SetItemText(nIndex , 12 , str);
		
		//浮点数转字符串
		str.Format("%.1f" , stu->getAverageScore());
		m_ListCtrl.SetItemText(nIndex , 13 , str);
	
	}
}

void CHomework_StudentManagementView::OnStudentAdd() 
{
	// TODO: Add your command handler code here

	CAddStudentDlg dlg;

	CHomework_StudentManagementDoc* doc = GetDocument();
 
	if (IDOK == dlg.DoModal()) {
		//添加学生信息
		CStudent *pStudent = new CStudent(dlg.m_strName , dlg.m_strNo , dlg.m_strSex , dlg.m_strBirth , dlg.m_strCountry , dlg.m_strNation , dlg.m_strAddress , 
			dlg.m_fScoreChinese , dlg.m_fScoreMath , dlg.m_fScoreEnglish , dlg.m_fScorePhysics , dlg.m_fScoreChemistry , dlg.m_fScoreBiology);
		
		doc->m_stuObList.AddTail(pStudent);

		
//		SetModifiedFlag();

//		UpdateAllViews(NULL);


		UpdateListItemData();
	}
	
}

void CHomework_StudentManagementView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CAddStudentDlg *pDlg = new CAddStudentDlg;

//	CAddStudentDlg dlg;

	LPNMITEMACTIVATE lpItem = (LPNMITEMACTIVATE)pNMHDR;
	int nIndex = lpItem->iItem;

	if (nIndex>=0) {
		CListCtrl& m_ListCtrl = GetListCtrl();

		//双击显示数据到对话框
		pDlg->m_strNo		= m_ListCtrl.GetItemText(nIndex , 0);
		pDlg->m_strName		= m_ListCtrl.GetItemText(nIndex , 1);
		pDlg->m_strSex		= m_ListCtrl.GetItemText(nIndex , 2);
		pDlg->m_strBirth	= m_ListCtrl.GetItemText(nIndex , 3);
		pDlg->m_strCountry	= m_ListCtrl.GetItemText(nIndex , 4);
		pDlg->m_strNation	= m_ListCtrl.GetItemText(nIndex , 5);
		pDlg->m_strAddress	= m_ListCtrl.GetItemText(nIndex , 6);
		
		pDlg->m_fScoreChinese	= (float)atof(m_ListCtrl.GetItemText(nIndex , 7));
		pDlg->m_fScoreMath		= (float)atof(m_ListCtrl.GetItemText(nIndex , 8));
		pDlg->m_fScoreEnglish	= (float)atof(m_ListCtrl.GetItemText(nIndex , 9));
		pDlg->m_fScorePhysics	= (float)atof(m_ListCtrl.GetItemText(nIndex , 10));
		pDlg->m_fScoreChemistry	= (float)atof(m_ListCtrl.GetItemText(nIndex , 11));
		pDlg->m_fScoreBiology	= (float)atof(m_ListCtrl.GetItemText(nIndex , 12));
		
		pDlg->Create(IDD_DIALOG1);
		pDlg->ShowWindow(SW_NORMAL);

		UpdateData(FALSE);

	}

	
	*pResult = 0;
}
