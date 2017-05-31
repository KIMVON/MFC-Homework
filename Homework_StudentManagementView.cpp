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
	char* arCols[14]={"ѧ��", "����", "�Ա�", "��������" , "����" , "����" , "��ַ" , "����" , "��ѧ" , "Ӣ��" , "����" , "��ѧ" , "����" , "ƽ���ɼ�"};
	listCol.mask = LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;

	// ����б�ͷ
	for (int nCol=0; nCol<14; nCol++)	{
		listCol.iSubItem = nCol;
		listCol.pszText = arCols[nCol];	
		listCol.fmt = LVCFMT_LEFT;
		m_ListCtrl.InsertColumn(nCol,&listCol);
	}



	SetCtrlStyle(m_ListCtrl.GetSafeHwnd(), LVS_REPORT);	// ����Ϊ����ʽ
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	// ������չ���ʹ���б���һ��ȫ��ѡ������ʾ��������
	
	// �����п�
	m_ListCtrl.SetColumnWidth(0, 100);	// ѧ���п�
	m_ListCtrl.SetColumnWidth(1, 100);	// �����п�
	m_ListCtrl.SetColumnWidth(2, 100);	// �Ա��п�
	m_ListCtrl.SetColumnWidth(3, 100);	// ���������п�
	m_ListCtrl.SetColumnWidth(4, 100);	// �����п�
	m_ListCtrl.SetColumnWidth(5, 100);	// �����п�
	m_ListCtrl.SetColumnWidth(6, 200);	// ��ַ�п�
	m_ListCtrl.SetColumnWidth(7, 100);	// �����п�
	m_ListCtrl.SetColumnWidth(8, 100);	// ��ѧ�п�
	m_ListCtrl.SetColumnWidth(9, 100);	// Ӣ���п�
	m_ListCtrl.SetColumnWidth(10, 100);	// �����п�
	m_ListCtrl.SetColumnWidth(11, 100);	// ��ѧ�п� 
	m_ListCtrl.SetColumnWidth(12, 100);	// �����п�
	m_ListCtrl.SetColumnWidth(13, 100);	// ƽ���ɼ��п�

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

//		m_ListCtrl.SetItemText(nIndex , 1 , stu->getNo());
		m_ListCtrl.SetItemText(nIndex , 1 , stu->getName());
		m_ListCtrl.SetItemText(nIndex , 2 , stu->getSex());
		m_ListCtrl.SetItemText(nIndex , 3 , stu->getBirth());
		m_ListCtrl.SetItemText(nIndex , 4 , stu->getCountry());
		m_ListCtrl.SetItemText(nIndex , 5 , stu->getNation());
		m_ListCtrl.SetItemText(nIndex , 6 , stu->getAddress());
		m_ListCtrl.SetItemText(nIndex , 7 , CString(stu->getChineseScore()));
		m_ListCtrl.SetItemText(nIndex , 8 , CString(stu->getMathScore()));
		m_ListCtrl.SetItemText(nIndex , 9 , CString(stu->getEnglishScore()));
		m_ListCtrl.SetItemText(nIndex , 10 , CString(stu->getPhysicsScore()));
		m_ListCtrl.SetItemText(nIndex , 11 , CString(stu->getChemistryScore()));
		m_ListCtrl.SetItemText(nIndex , 12 , CString(stu->getBiologyScore()));
		m_ListCtrl.SetItemText(nIndex , 13 , CString(stu->getAverageScore()));
	
	}
}

void CHomework_StudentManagementView::OnStudentAdd() 
{
	// TODO: Add your command handler code here

	CAddStudentDlg dlg;

	CHomework_StudentManagementDoc* doc = GetDocument();
 
	if (IDOK == dlg.DoModal()) {
		//���ѧ����Ϣ
		CStudent *pStudent = new CStudent(dlg.m_strName , dlg.m_strNo , dlg.m_strSex , dlg.m_strBirth , dlg.m_strCountry , dlg.m_strNation , dlg.m_strAddress , 
			dlg.m_fScoreChinese , dlg.m_fScoreMath , dlg.m_fScoreEnglish , dlg.m_fScorePhysics , dlg.m_fScoreChemistry , dlg.m_fScoreBiology);
		
		doc->m_stuObList.AddTail(pStudent);

		
//		SetModifiedFlag();

//		UpdateAllViews(NULL);


		UpdateListItemData();
	}
	
}
