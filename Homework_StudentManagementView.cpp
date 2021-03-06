// Homework_StudentManagementView.cpp : implementation of the CHomework_StudentManagementView class
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"

#include "Homework_StudentManagementDoc.h"
#include "Homework_StudentManagementView.h"

#include "AddStudentDlg.h"
#include "SearchStudentByNo.h"
#include "SearchStudentByName.h"
#include "AscendOrDescendDlg.h"
#include "AffirmDel.h"

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
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_COMMAND(ID_STUDENT_DEL, OnStudentDel)
	ON_COMMAND(ID_STUDENT_AMEND, OnStudentAmend)
	ON_COMMAND(ID_STUDENT_SEARCH_ALL, OnStudentSearchAll)
	ON_COMMAND(ID_STUDENT_SEARCH_BY_NO, OnStudentSearchByNo)
	ON_COMMAND(ID_STUDENT_SEARCH_BY_NAME, OnStudentSearchByName)
	ON_COMMAND(ID_STUDENT_SORT_AVERAGE, OnStudentSortAverage)
	ON_COMMAND(ID_STUDENT_SORT_BIOLOGY, OnStudentSortBiology)
	ON_COMMAND(ID_STUDENT_SORT_CHEMISTRY, OnStudentSortChemistry)
	ON_COMMAND(ID_STUDENT_SORT_CHINESE, OnStudentSortChinese)
	ON_COMMAND(ID_STUDENT_SORT_ENGLISH, OnStudentSortEnglish)
	ON_COMMAND(ID_STUDENT_SORT_MATH, OnStudentSortMath)
	ON_COMMAND(ID_STUDENT_SORT_ORIGINAL, OnStudentSortOriginal)
	ON_COMMAND(ID_STUDENT_SORT_PHYSICS, OnStudentSortPhysics)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_COMMAND(ID_AVERAGE_ALL, OnAverageAll)
	ON_COMMAND(ID_AVERAGE_BIOLOGY, OnAverageBiology)
	ON_COMMAND(ID_AVERAGE_CHEMISTRY, OnAverageChemistry)
	ON_COMMAND(ID_AVERAGE_CHINESE, OnAverageChinese)
	ON_COMMAND(ID_AVERAGE_ENGLISH, OnAverageEnglish)
	ON_COMMAND(ID_AVERAGE_MATH, OnAverageMath)
	ON_COMMAND(ID_AVERAGE_PHYSICS, OnAveragePhysics)
	ON_COMMAND(ID_PASS_ALL, OnPassAll)
	ON_COMMAND(ID_PASS_BIOLOGY, OnPassBiology)
	ON_COMMAND(ID_PASS_CHEMISTRY, OnPassChemistry)
	ON_COMMAND(ID_PASS_CHINESE, OnPassChinese)
	ON_COMMAND(ID_PASS_ENGLISH, OnPassEnglish)
	ON_COMMAND(ID_PASS_MATH, OnPassMath)
	ON_COMMAND(ID_PASS_PHYSICS, OnPassPhysics)
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

	//初始化nIndex;
	nIndex = -1;

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



	
	//删除多余的列
	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum!=14) {
		 
		for (int i=13; i>=0; i--){
			m_ListCtrl.DeleteColumn (i);	  
		}
		
		//如果有排序那一列
		if (nHeadNum==29) {
			m_ListCtrl.DeleteColumn(14);
		}

		UpdateListItemData();
		
	}


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

	
	int nIndex;

	//while (pos!=NULL) {
	for (int nItem = 0 ; nItem <doc->m_stuObList.GetCount() ; nItem++ ) {

		POSITION pos = doc->m_stuObList.FindIndex(nItem);
	
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
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

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
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}



	CAddStudentDlg *pDlg = new CAddStudentDlg;

	CHomework_StudentManagementDoc* doc = GetDocument();
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
		
//		pDlg->Create(IDD_DIALOG1);
//		pDlg->ShowWindow(SW_NORMAL);
		//更新数据
		if(IDOK==pDlg->DoModal()){//pDlg->DoModal()实例化,如果点击了IDOK就执行
			
			POSITION pos = doc->m_stuObList.FindIndex(nIndex);
			
			CStudent *pStu = new CStudent(pDlg->m_strName , pDlg->m_strNo , pDlg->m_strSex ,pDlg->m_strBirth , pDlg->m_strCountry , pDlg->m_strNation , pDlg->m_strAddress , 
			pDlg->m_fScoreChinese , pDlg->m_fScoreMath , pDlg->m_fScoreEnglish , pDlg->m_fScorePhysics , pDlg->m_fScoreChemistry , pDlg->m_fScoreBiology);
		
			doc->m_stuObList.SetAt(pos , pStu);
			

			UpdateListItemData();
		}

		UpdateData(FALSE);

	}

	
	*pResult = 0;
}

void CHomework_StudentManagementView::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	LPNMITEMACTIVATE lpItem = (LPNMITEMACTIVATE)pNMHDR;
	nIndex = lpItem->iItem;
	
	*pResult = 0;
}


void CHomework_StudentManagementView::OnStudentDel() 
{
	// TODO: Add your command handler code here
	CAffirmDel dlg;
	
	if (nIndex == -1) {
		MessageBox("不能删除，没有选定！！");		
	}else{

		
		if (IDOK == dlg.DoModal()) {
			CListCtrl& m_ListCtrl = GetListCtrl();

			int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
			if (nHeadNum==15) {
				m_ListCtrl.DeleteColumn (14);
			}


			CHomework_StudentManagementDoc* doc = GetDocument();


			if (nIndex>=0) {
				POSITION pos = doc->m_stuObList.FindIndex(nIndex);

				doc->m_stuObList.RemoveAt(pos);

				UpdateListItemData();

				//没有选定，设置为-1
				nIndex=-1;
			}

		}




	}




}

void CHomework_StudentManagementView::OnStudentAmend() 
{
	// TODO: Add your command handler code here
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}


	CAddStudentDlg *pDlg = new CAddStudentDlg;

	CHomework_StudentManagementDoc* doc = GetDocument();

	if (nIndex == -1) {
		MessageBox("失败，没有选定！！");
	}


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
		
		//更新数据
		if(IDOK==pDlg->DoModal()){//pDlg->DoModal()实例化,如果点击了IDOK就执行
			
			POSITION pos = doc->m_stuObList.FindIndex(nIndex);
			
			CStudent *pStu = new CStudent(pDlg->m_strName , pDlg->m_strNo , pDlg->m_strSex ,pDlg->m_strBirth , pDlg->m_strCountry , pDlg->m_strNation , pDlg->m_strAddress , 
			pDlg->m_fScoreChinese , pDlg->m_fScoreMath , pDlg->m_fScoreEnglish , pDlg->m_fScorePhysics , pDlg->m_fScoreChemistry , pDlg->m_fScoreBiology);
		
			doc->m_stuObList.SetAt(pos , pStu);
			

			UpdateListItemData();
		}

		UpdateData(FALSE);

		nIndex = -1;
	}

	
}


/************************************************************************/
void CHomework_StudentManagementView::OnStudentSearchAll() 
{
	// TODO: Add your command handler code here
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}


	UpdateListItemData();
}


/************************************************************************/
void CHomework_StudentManagementView::OnStudentSearchByNo() 
{
	// TODO: Add your command handler code here
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}




	CSearchStudentByNo dlg;

	CHomework_StudentManagementDoc* doc = GetDocument();

	if(IDOK==dlg.DoModal()){
		CObList list;

		for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
			POSITION pos = doc->m_stuObList.FindIndex(i);
			
			CStudent *stu = (CStudent*)doc->m_stuObList.GetAt(pos);

			if (dlg.m_strStudentNo == stu->getNo()) {
				list.AddTail(stu);	
			}

		}
		if (list.GetCount()==0) {
			MessageBox("该学号的学生不存在，查询失败！！！");
		}else{
			UpdateListItemData(list);
		}
		
	}
	
}


/************************************************************************/
void CHomework_StudentManagementView::OnStudentSearchByName() 
{
	// TODO: Add your command handler code here
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}



	CSearchStudentByName dlg;

	CHomework_StudentManagementDoc* doc = GetDocument();

	if(IDOK==dlg.DoModal()){
		CObList list;

		for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
			POSITION pos = doc->m_stuObList.FindIndex(i);
			
			CStudent *stu = (CStudent*)doc->m_stuObList.GetAt(pos);

			if (dlg.m_strStudentName == stu->getName()) {
				list.AddTail(stu);	
			}

		}
		
		if (list.GetCount()==0) {
			MessageBox("该姓名的学生不存在，查询失败！！！");
		}else{
			UpdateListItemData(list);
		}
	}
}


/************************************************************************/
void CHomework_StudentManagementView::UpdateListItemData(CObList& list)
{
	CListCtrl& m_ListCtrl = GetListCtrl();
	m_ListCtrl.DeleteAllItems();
	CHomework_StudentManagementDoc* doc = GetDocument();

	
	int nIndex;

	//while (pos!=NULL) {
	for (int nItem = 0 ; nItem <list.GetCount() ; nItem++ ) {

		POSITION pos = list.FindIndex(nItem);
	
		CStudent* stu =(CStudent*)list.GetAt(pos);
		
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
/************************************************************************/
//平均成绩排序
void CHomework_StudentManagementView::OnStudentSortAverage() 
{
	// TODO: Add your command handler code here

	//新增排序列
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "平均成绩排名" , LVCFMT_LEFT , 100);

/***********************************************************/

	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//复制List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//升序
	if (IDOK == nResponse) {
		
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getAverageScore() > ((CStudent*)list.GetAt(posJ))->getAverageScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);

		//添加排名列
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getAverageScore() == ((CStudent*)list.GetAt(pos2))->getAverageScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}
		

		
	}
	
	//降序
	if (IDCANCEL == nResponse) {
	
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getAverageScore() < ((CStudent*)list.GetAt(posJ))->getAverageScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);


		//添加排名列--------降序
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getAverageScore() == ((CStudent*)list.GetAt(pos2))->getAverageScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}






	}


	
	
}
/************************************************************************/


//生物排序
void CHomework_StudentManagementView::OnStudentSortBiology() 
{
	// TODO: Add your command handler code here

	//新增排序列
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "生物成绩排名" , LVCFMT_LEFT , 100);




	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//复制List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//升序
	if (IDOK == nResponse) {
		
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getBiologyScore() > ((CStudent*)list.GetAt(posJ))->getBiologyScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);


		//添加排名列
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getBiologyScore() == ((CStudent*)list.GetAt(pos2))->getBiologyScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}

		


		
	}
	
	//降序
	if (IDCANCEL == nResponse) {
	
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getBiologyScore() < ((CStudent*)list.GetAt(posJ))->getBiologyScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);



		//添加排名列--------降序
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getBiologyScore() == ((CStudent*)list.GetAt(pos2))->getBiologyScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}









	}
	
}

/************************************************************************/
//化学排序
void CHomework_StudentManagementView::OnStudentSortChemistry() 
{
	// TODO: Add your command handler code here

	//新增排序列
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "化学成绩排名" , LVCFMT_LEFT , 100);



	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//复制List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//升序
	if (IDOK == nResponse) {
		
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getChemistryScore() > ((CStudent*)list.GetAt(posJ))->getChemistryScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);


		//添加排名列
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getChemistryScore() == ((CStudent*)list.GetAt(pos2))->getChemistryScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}



		
		
	}
	
	//降序
	if (IDCANCEL == nResponse) {
	
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getChemistryScore() < ((CStudent*)list.GetAt(posJ))->getChemistryScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);




		//添加排名列--------降序
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getChemistryScore() == ((CStudent*)list.GetAt(pos2))->getChemistryScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}









	}
}

/************************************************************************/

//语文排序
void CHomework_StudentManagementView::OnStudentSortChinese() 
{
	// TODO: Add your command handler code here

	//新增排序列
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "语文成绩排名" , LVCFMT_LEFT , 100);




	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//复制List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//升序
	if (IDOK == nResponse) {
		
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getChineseScore() > ((CStudent*)list.GetAt(posJ))->getChineseScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);

		//添加排名列
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getChineseScore() == ((CStudent*)list.GetAt(pos2))->getChineseScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}





		
	}
	
	//降序
	if (IDCANCEL == nResponse) {
	
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getChineseScore() < ((CStudent*)list.GetAt(posJ))->getChineseScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);



		//添加排名列--------降序
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getChineseScore() == ((CStudent*)list.GetAt(pos2))->getChineseScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}







	}
}

/************************************************************************/

//英语排序
void CHomework_StudentManagementView::OnStudentSortEnglish() 
{
	// TODO: Add your command handler code here

	//新增排序列
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "英语成绩排名" , LVCFMT_LEFT , 100);






	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//复制List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//升序
	if (IDOK == nResponse) {
		
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getEnglishScore() > ((CStudent*)list.GetAt(posJ))->getEnglishScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);



		//添加排名列
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getEnglishScore() == ((CStudent*)list.GetAt(pos2))->getEnglishScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}




		
	}
	
	//降序
	if (IDCANCEL == nResponse) {
	
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getEnglishScore() < ((CStudent*)list.GetAt(posJ))->getEnglishScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);
		

		
		//添加排名列--------降序
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getEnglishScore() == ((CStudent*)list.GetAt(pos2))->getEnglishScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}







	}

}

/************************************************************************/

//数学排序
void CHomework_StudentManagementView::OnStudentSortMath() 
{
	// TODO: Add your command handler code here

	//新增排序列
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "数学成绩排名" , LVCFMT_LEFT , 100);






	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//复制List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//升序
	if (IDOK == nResponse) {
		
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getMathScore() > ((CStudent*)list.GetAt(posJ))->getMathScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);


		//添加排名列
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getMathScore() == ((CStudent*)list.GetAt(pos2))->getMathScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}




		
	}
	
	//降序
	if (IDCANCEL == nResponse) {
	
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getMathScore() < ((CStudent*)list.GetAt(posJ))->getMathScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);



		//添加排名列--------降序
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getMathScore() == ((CStudent*)list.GetAt(pos2))->getMathScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}






	}
}


/************************************************************************/


//原始排序
void CHomework_StudentManagementView::OnStudentSortOriginal() 
{
	// TODO: Add your command handler code here

	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}



	UpdateListItemData();
}


/************************************************************************/
 


//物理排序
void CHomework_StudentManagementView::OnStudentSortPhysics() 
{
	// TODO: Add your command handler code here

	//新增排序列
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "物理成绩排名" , LVCFMT_LEFT , 100);




	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//复制List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//升序
	if (IDOK == nResponse) {
		
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getPhysicsScore() > ((CStudent*)list.GetAt(posJ))->getPhysicsScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);

		//添加排名列
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getPhysicsScore() == ((CStudent*)list.GetAt(pos2))->getPhysicsScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}


		
	}
	
	//降序
	if (IDCANCEL == nResponse) {
	
		for (int i=0 ; i < list.GetCount() ; i++) {
			POSITION posI = list.FindIndex(i);
			for (int j = i+1 ; j < list.GetCount() ; j++) {
				POSITION posJ = list.FindIndex(j);
				
				if (((CStudent*)list.GetAt(posI))->getPhysicsScore() < ((CStudent*)list.GetAt(posJ))->getPhysicsScore()) {
					CStudent *stuI = (CStudent*)list.GetAt(posI);
					CStudent *stuJ = (CStudent*)list.GetAt(posJ);
					
					list.SetAt(posI , stuJ);
					list.SetAt(posJ , stuI);
				}
			}
		}

		UpdateListItemData(list);



		//添加排名列--------降序
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//如果两个分数相同，排名一样
				if (((CStudent*)list.GetAt(pos1))->getPhysicsScore() == ((CStudent*)list.GetAt(pos2))->getPhysicsScore()) {
					//分数相同，排名大的跟小的一样
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//浮点数转字符串
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//浮点数转字符串
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}


		





	}
}



void CHomework_StudentManagementView::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	
	LPNMITEMACTIVATE lpItem = (LPNMITEMACTIVATE)pNMHDR;
	nIndex = lpItem->iItem;

	if (nIndex>=0) {


		CMenu menu;

		menu.CreatePopupMenu();
		menu.InsertMenu(0, MF_BYCOMMAND, ID_STUDENT_AMEND, "修改信息");
		menu.InsertMenu(1, MF_SEPARATOR);
		menu.InsertMenu(2, MF_BYCOMMAND, ID_STUDENT_DEL, "删除信息");

		CPoint point;//定义一个用于确定光标位置的位置  
		GetCursorPos(&point);//获取当前光标的位置，以便使得菜单可以跟随光标  
		//创建快捷菜单
		menu.TrackPopupMenu( TPM_RIGHTBUTTON, point.x, point.y, this);


		menu.DestroyMenu();

	}

	
	*pResult = 0;
}

void CHomework_StudentManagementView::OnAverageAll() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumChinese=0;
	float sumMath=0;
	float sumEnglish=0;
	float sumPhysics=0;
	float sumChemistry=0;
	float sumBiology=0;

	CString strAverageChinese;
	CString strAverageMath;
	CString strAverageEnglish;
	CString strAveragePhysics;
	CString strAverageChemistry;
	CString strAverageBiology;
	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);

		sumChinese	+= stu->getChineseScore();
		sumMath		+= stu->getMathScore();
		sumEnglish	+= stu->getEnglishScore();
		sumPhysics  += stu->getPhysicsScore();
		sumChemistry+= stu->getChemistryScore();
		sumBiology	+= stu->getBiologyScore();
	}


	strAverageChinese.Format("%.1f" , sumChinese *1.0/doc->m_stuObList.GetCount());
	strAverageMath.Format("%.1f" ,	  sumMath *1.0/doc->m_stuObList.GetCount());
	strAverageEnglish.Format("%.1f" , sumEnglish *1.0/doc->m_stuObList.GetCount());
	strAveragePhysics.Format("%.1f" , sumPhysics *1.0/doc->m_stuObList.GetCount());
	strAverageChemistry.Format("%.1f",sumChemistry *1.0/doc->m_stuObList.GetCount());
	strAverageBiology.Format("%.1f" , sumBiology *1.0/doc->m_stuObList.GetCount());


	MessageBox("语文科目平均成绩："+strAverageChinese+"\n"
		+"数学科目平均成绩："+strAverageMath+"\n"
		+"英语科目平均成绩："+strAverageEnglish+"\n"
		+"物理科目平均成绩："+strAveragePhysics+"\n"
		+"化学科目平均成绩："+strAverageChemistry+"\n"
		+"生物科目平均成绩："+strAverageBiology+"\n");
	
}

void CHomework_StudentManagementView::OnAverageBiology() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;


	float sumBiology=0;

	CString strAverageBiology;

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);

		sumBiology	+= stu->getBiologyScore();
	}

	strAverageBiology.Format("%.1f" , sumBiology *1.0/doc->m_stuObList.GetCount());


	MessageBox("生物科目平均成绩："+strAverageBiology);
	
}

void CHomework_StudentManagementView::OnAverageChemistry() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumChemistry=0;

	CString strAverageChemistry;


	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);

		sumChemistry+= stu->getChemistryScore();

	}


	strAverageChemistry.Format("%.1f",sumChemistry *1.0/doc->m_stuObList.GetCount());



	MessageBox("化学科目平均成绩："+strAverageChemistry);
	
}

void CHomework_StudentManagementView::OnAverageChinese() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumChinese=0;


	CString strAverageChinese;
	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);

		sumChinese	+= stu->getChineseScore();

	}


	strAverageChinese.Format("%.1f" , sumChinese *1.0/doc->m_stuObList.GetCount());



	MessageBox("语文科目平均成绩："+strAverageChinese);
	
}

void CHomework_StudentManagementView::OnAverageEnglish() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumEnglish=0;

	CString strAverageEnglish;

	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);

		sumEnglish	+= stu->getEnglishScore();
	}


	strAverageEnglish.Format("%.1f" , sumEnglish *1.0/doc->m_stuObList.GetCount());



	MessageBox("英语科目平均成绩："+strAverageEnglish);
	
}

void CHomework_StudentManagementView::OnAverageMath() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumMath=0;

	CString strAverageMath;

	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);

		sumMath		+= stu->getMathScore();

	}

	strAverageMath.Format("%.1f" ,	  sumMath *1.0/doc->m_stuObList.GetCount());



	MessageBox("数学科目平均成绩："+strAverageMath);
	
}

void CHomework_StudentManagementView::OnAveragePhysics() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumPhysics=0;

	CString strAveragePhysics;

	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);

		sumPhysics  += stu->getPhysicsScore();

	}


	strAveragePhysics.Format("%.1f" , sumPhysics *1.0/doc->m_stuObList.GetCount());



	MessageBox("物理科目平均成绩："+strAveragePhysics);
	
}



void CHomework_StudentManagementView::OnPassAll() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumChinese=0;
	float sumMath=0;
	float sumEnglish=0;
	float sumPhysics=0;
	float sumChemistry=0;
	float sumBiology=0;

	CString strPassChinese;
	CString strPassMath;
	CString strPassEnglish;
	CString strPassPhysics;
	CString strPassChemistry;
	CString strPassBiology;
	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);
		
		if (stu->getChineseScore() >= 60 ) {
			sumChinese++;
		}
		if (stu->getMathScore() >= 60 ) {
			sumMath++;
		}
		if (stu->getEnglishScore() >= 60 ) {
			sumEnglish++;
		}
		if (stu->getPhysicsScore() >= 60 ) {
			sumPhysics++;
		}
		if (stu->getChemistryScore() >= 60 ) {
			sumChemistry++;
		}
		if (stu->getBiologyScore() >= 60 ) {
			sumBiology++;
		}
	 
	}


	strPassChinese.Format("%.1f" , 100*sumChinese *1.0/doc->m_stuObList.GetCount());
	strPassMath.Format("%.1f" ,	  100*sumMath *1.0/doc->m_stuObList.GetCount());
	strPassEnglish.Format("%.1f" , 100*sumEnglish *1.0/doc->m_stuObList.GetCount());
	strPassPhysics.Format("%.1f" , 100*sumPhysics *1.0/doc->m_stuObList.GetCount());
	strPassChemistry.Format("%.1f",100*sumChemistry *1.0/doc->m_stuObList.GetCount());
	strPassBiology.Format("%.1f" , 100*sumBiology *1.0/doc->m_stuObList.GetCount());


	MessageBox("语文科目及格率："+strPassChinese+"%"+"\n"
		+"数学科目及格率："+strPassMath+"%"+"\n"
		+"英语科目及格率："+strPassEnglish+"%"+"\n"
		+"物理科目及格率："+strPassPhysics+"%"+"\n"
		+"化学科目及格率："+strPassChemistry+"%"+"\n"
		+"生物科目及格率："+strPassBiology+"%"+"\n");
}



void CHomework_StudentManagementView::OnPassBiology() 
{
	// TODO: Add your command handler code here
	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumBiology=0;

	CString strPassBiology;
	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);
		
		if (stu->getBiologyScore() >= 60 ) {
			sumBiology++;
		}
	 
	}

	strPassBiology.Format("%.1f" , 100*sumBiology *1.0/doc->m_stuObList.GetCount());


	MessageBox("生物科目及格率："+strPassBiology+"%");
	

}



void CHomework_StudentManagementView::OnPassChemistry() 
{
	// TODO: Add your command handler code here

	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumChemistry=0;
	

	CString strPassChemistry;


	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);
		
		if (stu->getChemistryScore() >= 60 ) {
			sumChemistry++;
		}
	 
	}


	strPassChemistry.Format("%.1f",100*sumChemistry *1.0/doc->m_stuObList.GetCount());


	MessageBox("化学科目及格率："+strPassChemistry+"%");
	
}

void CHomework_StudentManagementView::OnPassChinese() 
{
	// TODO: Add your command handler code here

	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumChinese=0;

	CString strPassChinese;
	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);
		
		if (stu->getChineseScore() >= 60 ) {
			sumChinese++;
		}
	 
	}


	strPassChinese.Format("%.1f" , 100*sumChinese *1.0/doc->m_stuObList.GetCount());


	MessageBox("语文科目及格率："+strPassChinese+"%");
	
}

void CHomework_StudentManagementView::OnPassEnglish() 
{
	// TODO: Add your command handler code here

	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	float sumEnglish=0;

	CString strPassEnglish;
	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);
		
		if (stu->getEnglishScore() >= 60 ) {
			sumEnglish++;
		}

	 
	}


	strPassEnglish.Format("%.1f" , 100*sumEnglish *1.0/doc->m_stuObList.GetCount());


	MessageBox("英语科目及格率："+strPassEnglish+"%");
	
}

void CHomework_StudentManagementView::OnPassMath() 
{
	// TODO: Add your command handler code here

	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;

	
	float sumMath=0;

	CString strPassMath;

	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);
		
		if (stu->getMathScore() >= 60 ) {
			sumMath++;
		}
		
	 
	}


	strPassMath.Format("%.1f" ,	  100*sumMath *1.0/doc->m_stuObList.GetCount());


	MessageBox("数学科目及格率："+strPassMath+"%");
	
}

void CHomework_StudentManagementView::OnPassPhysics() 
{
	// TODO: Add your command handler code here

	CHomework_StudentManagementDoc* doc = GetDocument();
	
	CStudent *stu;
	POSITION pos;


	float sumPhysics=0;


	CString strPassPhysics;

	

	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		pos = doc->m_stuObList.FindIndex(i);
	
		stu = (CStudent*)doc->m_stuObList.GetAt(pos);
		
		if (stu->getPhysicsScore() >= 60 ) {
			sumPhysics++;
		}
	 
	}


	strPassPhysics.Format("%.1f" , 100*sumPhysics *1.0/doc->m_stuObList.GetCount());


	MessageBox("物理科目及格率："+strPassPhysics+"%");
	
}
