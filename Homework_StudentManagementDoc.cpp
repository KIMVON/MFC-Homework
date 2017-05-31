// Homework_StudentManagementDoc.cpp : implementation of the CHomework_StudentManagementDoc class
//

#include "stdafx.h"
#include "Homework_StudentManagement.h"

#include "Homework_StudentManagementDoc.h"

#include "AddStudentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc

IMPLEMENT_DYNCREATE(CHomework_StudentManagementDoc, CDocument)

BEGIN_MESSAGE_MAP(CHomework_StudentManagementDoc, CDocument)
	//{{AFX_MSG_MAP(CHomework_StudentManagementDoc)
	ON_COMMAND(ID_STUDENT_ADD, OnStudentAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc construction/destruction

CHomework_StudentManagementDoc::CHomework_StudentManagementDoc()
{
	// TODO: add one-time construction code here

}

CHomework_StudentManagementDoc::~CHomework_StudentManagementDoc()
{
}

BOOL CHomework_StudentManagementDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc serialization

void CHomework_StudentManagementDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc diagnostics

#ifdef _DEBUG
void CHomework_StudentManagementDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHomework_StudentManagementDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CHomework_StudentManagementDoc commands




/************************************************************************/
/*    student类函数的实现                                               */
/************************************************************************/
CStudent::CStudent(CString name , CString no , CString sex , CString birth , CString country , CString nation , CString address , float chinese , float math , float english , float physics , float chemistry , float biology)
{
	strName = name;
	strNo = no;
	strSex = sex;
	strBirth = birth;
	strCountry = country;
	strNation = nation;
	strAddress = address;

	fScoreChinese = chinese;
	fScoreMath = math;
	fScoreEnglish = english;
	fScorePhysics = physics;
	fScoreChemistry = chemistry;
	fScoreBiology = biology;

	fScoreAverage = (float)((fScoreChinese+fScoreMath+fScoreEnglish+fScorePhysics+fScoreChemistry+fScoreBiology)/6.0);

}

//序列化
IMPLEMENT_SERIAL(CStudent , CObject , 1);


/************************************************************************/
/*      get set 方法实现                                                */
/************************************************************************/
CString CStudent::getName(){
	return strName;
}
void CStudent::setName(CString name){
	strName = name;
}


CString CStudent::getNo(){
	return strNo;
}
void CStudent::setNo(CString no){
	strNo = no;
}


CString CStudent::getSex(){
	return strSex;
}
void CStudent::setSex(CString sex){
	strSex = sex;
}


CString CStudent::getBirth(){
	return strBirth;
}
void CStudent::setBirth(CString birth){
	strBirth = birth;
}


CString CStudent::getCountry(){
	return strCountry;
}
void CStudent::setCountry(CString country){
	strCountry = country;
}



CString CStudent::getNation(){
	return strNation;
}
void CStudent::setNation(CString nation){
	strNation = nation;
}
	

CString CStudent::getAddress(){
	return strAddress;
}
void CStudent::setAddress(CString address){
	strAddress = address;
}

//成绩
float CStudent::getChineseScore(){
	return fScoreChinese;
}
void CStudent::setChineseScore(float chineseScore){
	fScoreChinese = chineseScore;
}

float CStudent::getMathScore(){
	return fScoreMath;
}
void CStudent::setMathScore(float mathScore){
	fScoreMath = mathScore;
}

float CStudent::getEnglishScore(){
	return fScoreEnglish;
}
void CStudent::setEnglishScore(float englishScore){
	fScoreEnglish = englishScore;
}

float CStudent::getPhysicsScore(){
	return fScorePhysics;
}
void CStudent::setPhysicsScore(float physicsScore){
	fScorePhysics = physicsScore;
}

float CStudent::getChemistryScore(){
	return fScoreChemistry;
}
void CStudent::setChemistryScore(float chemistryScore){
	fScoreChemistry = chemistryScore;
}

float CStudent::getBiologyScore(){
	return fScoreBiology;
}
void CStudent::setBiologyScore(float biologyScore){
	fScoreBiology = biologyScore;
}

//获得平均成绩
float CStudent::getAverageScore(){
	return fScoreAverage;
}



void CHomework_StudentManagementDoc::OnStudentAdd() 
{
	// TODO: Add your command handler code here
	CAddStudentDlg dlg;

	if (IDOK == dlg.DoModal()) {
		//添加学生信息
		CStudent *pStudent = new CStudent(dlg.m_strName , dlg.m_strNo , dlg.m_strSex , dlg.m_strBirth , dlg.m_strCountry , dlg.m_strNation , dlg.m_strAddress , 
			dlg.m_fScoreChinese , dlg.m_fScoreMath , dlg.m_fScoreEnglish , dlg.m_fScorePhysics , dlg.m_fScoreChemistry , dlg.m_fScoreBiology);
		
		m_stuObList.AddTail(pStudent);

		
		SetModifiedFlag();

		UpdateAllViews(NULL);

	}
}
