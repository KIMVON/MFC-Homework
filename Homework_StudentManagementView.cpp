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

	//��ʼ��nIndex;
	nIndex = -1;

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



	
	//ɾ���������
	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum!=14) {
		 
		for (int i=13; i>=0; i--){
			m_ListCtrl.DeleteColumn (i);	  
		}
		
		//�����������һ��
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
		//������ת�ַ���
		str.Format("%.1f" , stu->getChineseScore());
		m_ListCtrl.SetItemText(nIndex , 7 , str);
		
		//������ת�ַ���
		str.Format("%.1f" , stu->getMathScore());
		m_ListCtrl.SetItemText(nIndex , 8 , str);

		//������ת�ַ���
		str.Format("%.1f" , stu->getEnglishScore());
		m_ListCtrl.SetItemText(nIndex , 9 , str);

		//������ת�ַ���
		str.Format("%.1f" , stu->getPhysicsScore());
		m_ListCtrl.SetItemText(nIndex , 10 , str);

		//������ת�ַ���
		str.Format("%.1f" , stu->getChemistryScore());
		m_ListCtrl.SetItemText(nIndex , 11 , str);
		
		//������ת�ַ���
		str.Format("%.1f" , stu->getBiologyScore());
		m_ListCtrl.SetItemText(nIndex , 12 , str);
		
		//������ת�ַ���
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
		//���ѧ����Ϣ
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

		//˫����ʾ���ݵ��Ի���
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
		//��������
		if(IDOK==pDlg->DoModal()){//pDlg->DoModal()ʵ����,��������IDOK��ִ��
			
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
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}


	CHomework_StudentManagementDoc* doc = GetDocument();

	if (nIndex == -1) {
		MessageBox("����ɾ����û��ѡ������");
	}


	if (nIndex>=0) {
		POSITION pos = doc->m_stuObList.FindIndex(nIndex);

		doc->m_stuObList.RemoveAt(pos);

		UpdateListItemData();

		//û��ѡ��������Ϊ-1
		nIndex=-1;
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
		MessageBox("ʧ�ܣ�û��ѡ������");
	}


	if (nIndex>=0) {
		CListCtrl& m_ListCtrl = GetListCtrl();

		//˫����ʾ���ݵ��Ի���
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
		
		//��������
		if(IDOK==pDlg->DoModal()){//pDlg->DoModal()ʵ����,��������IDOK��ִ��
			
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
			MessageBox("��ѧ�ŵ�ѧ�������ڣ���ѯʧ�ܣ�����");
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
			MessageBox("��������ѧ�������ڣ���ѯʧ�ܣ�����");
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
		//������ת�ַ���
		str.Format("%.1f" , stu->getChineseScore());
		m_ListCtrl.SetItemText(nIndex , 7 , str);
		
		//������ת�ַ���
		str.Format("%.1f" , stu->getMathScore());
		m_ListCtrl.SetItemText(nIndex , 8 , str);

		//������ת�ַ���
		str.Format("%.1f" , stu->getEnglishScore());
		m_ListCtrl.SetItemText(nIndex , 9 , str);

		//������ת�ַ���
		str.Format("%.1f" , stu->getPhysicsScore());
		m_ListCtrl.SetItemText(nIndex , 10 , str);

		//������ת�ַ���
		str.Format("%.1f" , stu->getChemistryScore());
		m_ListCtrl.SetItemText(nIndex , 11 , str);
		
		//������ת�ַ���
		str.Format("%.1f" , stu->getBiologyScore());
		m_ListCtrl.SetItemText(nIndex , 12 , str);
		
		//������ת�ַ���
		str.Format("%.1f" , stu->getAverageScore());
		m_ListCtrl.SetItemText(nIndex , 13 , str);
	
	}
}
/************************************************************************/
//ƽ���ɼ�����
void CHomework_StudentManagementView::OnStudentSortAverage() 
{
	// TODO: Add your command handler code here

	//����������
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "ƽ���ɼ�����" , LVCFMT_LEFT , 100);

/***********************************************************/

	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//����List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//����
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

		//���������
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getAverageScore() == ((CStudent*)list.GetAt(pos2))->getAverageScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}
		

		
	}
	
	//����
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


		//���������--------����
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getAverageScore() == ((CStudent*)list.GetAt(pos2))->getAverageScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}






	}


	
	
}
/************************************************************************/


//��������
void CHomework_StudentManagementView::OnStudentSortBiology() 
{
	// TODO: Add your command handler code here

	//����������
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "����ɼ�����" , LVCFMT_LEFT , 100);




	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//����List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//����
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


		//���������
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getBiologyScore() == ((CStudent*)list.GetAt(pos2))->getBiologyScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}

		


		
	}
	
	//����
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



		//���������--------����
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getBiologyScore() == ((CStudent*)list.GetAt(pos2))->getBiologyScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}









	}
	
}

/************************************************************************/
//��ѧ����
void CHomework_StudentManagementView::OnStudentSortChemistry() 
{
	// TODO: Add your command handler code here

	//����������
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "��ѧ�ɼ�����" , LVCFMT_LEFT , 100);



	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//����List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//����
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


		//���������
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getChemistryScore() == ((CStudent*)list.GetAt(pos2))->getChemistryScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}



		
		
	}
	
	//����
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




		//���������--------����
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getChemistryScore() == ((CStudent*)list.GetAt(pos2))->getChemistryScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}









	}
}

/************************************************************************/

//��������
void CHomework_StudentManagementView::OnStudentSortChinese() 
{
	// TODO: Add your command handler code here

	//����������
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "���ĳɼ�����" , LVCFMT_LEFT , 100);




	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//����List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//����
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

		//���������
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getChineseScore() == ((CStudent*)list.GetAt(pos2))->getChineseScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}





		
	}
	
	//����
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



		//���������--------����
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getChineseScore() == ((CStudent*)list.GetAt(pos2))->getChineseScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}







	}
}

/************************************************************************/

//Ӣ������
void CHomework_StudentManagementView::OnStudentSortEnglish() 
{
	// TODO: Add your command handler code here

	//����������
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "Ӣ��ɼ�����" , LVCFMT_LEFT , 100);






	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//����List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//����
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



		//���������
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getEnglishScore() == ((CStudent*)list.GetAt(pos2))->getEnglishScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}




		
	}
	
	//����
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
		

		
		//���������--------����
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getEnglishScore() == ((CStudent*)list.GetAt(pos2))->getEnglishScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}







	}

}

/************************************************************************/

//��ѧ����
void CHomework_StudentManagementView::OnStudentSortMath() 
{
	// TODO: Add your command handler code here

	//����������
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "��ѧ�ɼ�����" , LVCFMT_LEFT , 100);






	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//����List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//����
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


		//���������
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getMathScore() == ((CStudent*)list.GetAt(pos2))->getMathScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}




		
	}
	
	//����
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



		//���������--------����
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getMathScore() == ((CStudent*)list.GetAt(pos2))->getMathScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}






	}
}


/************************************************************************/


//ԭʼ����
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
 


//��������
void CHomework_StudentManagementView::OnStudentSortPhysics() 
{
	// TODO: Add your command handler code here

	//����������
	CListCtrl& m_ListCtrl = GetListCtrl();

	int nHeadNum = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	if (nHeadNum==15) {
		m_ListCtrl.DeleteColumn (14);
	}

	m_ListCtrl.InsertColumn(14 , "����ɼ�����" , LVCFMT_LEFT , 100);




	CAscendOrDescendDlg dlg;
	CHomework_StudentManagementDoc* doc = GetDocument();

	int nResponse = dlg.DoModal();
	
	CObList list;
	//����List
	for (int i=0 ; i < doc->m_stuObList.GetCount() ; i++) {
		POSITION pos = doc->m_stuObList.FindIndex(i);
		
		list.AddTail(doc->m_stuObList.GetAt(pos));
	}

	//����
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

		//���������
		CString str;
		int order = 1;
		int total=0;
		for ( int count = list.GetCount()-1  ; count >=0 ; count--,order++) {
			if (count <= list.GetCount()-2) {
				POSITION pos1 = list.FindIndex(count);
				POSITION pos2 = list.FindIndex(count+1);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getPhysicsScore() == ((CStudent*)list.GetAt(pos2))->getPhysicsScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
				str.Format("%d" , order);
				m_ListCtrl.SetItemText(count , 14 ,  str);
			}
		}


		
	}
	
	//����
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



		//���������--------����
		CString str;
		int order = 1;
		int total=0;
		for ( int count = 0  ; count < list.GetCount() ; count++ , order++) {
			if (count > 0) {
				POSITION pos1 = list.FindIndex(count-1);
				POSITION pos2 = list.FindIndex(count);
				
				//�������������ͬ������һ��
				if (((CStudent*)list.GetAt(pos1))->getPhysicsScore() == ((CStudent*)list.GetAt(pos2))->getPhysicsScore()) {
					//������ͬ��������ĸ�С��һ��
					total++;
					str.Format("%d" , order - total);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}else{
					//������ת�ַ���
					total=0;
					str.Format("%d" , order);
					m_ListCtrl.SetItemText(count , 14 ,  str);
				}

			}else{
	 			//������ת�ַ���
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
		menu.InsertMenu(0, MF_BYCOMMAND, ID_STUDENT_AMEND, "�޸���Ϣ");
		menu.InsertMenu(1, MF_SEPARATOR);
		menu.InsertMenu(2, MF_BYCOMMAND, ID_STUDENT_DEL, "ɾ����Ϣ");

		CPoint point;//����һ������ȷ�����λ�õ�λ��  
		GetCursorPos(&point);//��ȡ��ǰ����λ�ã��Ա�ʹ�ò˵����Ը�����  
		//������ݲ˵�
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


	MessageBox("���Ŀ�Ŀƽ���ɼ���"+strAverageChinese+"\n"
		+"��ѧ��Ŀƽ���ɼ���"+strAverageMath+"\n"
		+"Ӣ���Ŀƽ���ɼ���"+strAverageEnglish+"\n"
		+"�����Ŀƽ���ɼ���"+strAveragePhysics+"\n"
		+"��ѧ��Ŀƽ���ɼ���"+strAverageChemistry+"\n"
		+"�����Ŀƽ���ɼ���"+strAverageBiology+"\n");
	
}
