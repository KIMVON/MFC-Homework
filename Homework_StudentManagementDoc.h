// Homework_StudentManagementDoc.h : interface of the CHomework_StudentManagementDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOMEWORK_STUDENTMANAGEMENTDOC_H__CE953165_116C_49E5_8C1C_9E0C0B8164AC__INCLUDED_)
#define AFX_HOMEWORK_STUDENTMANAGEMENTDOC_H__CE953165_116C_49E5_8C1C_9E0C0B8164AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHomework_StudentManagementDoc : public CDocument
{
protected: // create from serialization only
	CHomework_StudentManagementDoc();
	DECLARE_DYNCREATE(CHomework_StudentManagementDoc)

// Attributes
public:
	CObList m_stuObList;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHomework_StudentManagementDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHomework_StudentManagementDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHomework_StudentManagementDoc)
	afx_msg void OnStudentAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////


/************************************************************************/
/*   student类                                                          */
/************************************************************************/

class CStudent:public CObject
{

	//序列化
	DECLARE_SERIAL(CStudent);

//构造函数
public:
	CStudent(){

	};

	CStudent(CString name , CString no , CString sex , CString birth , CString country , CString nation , CString address , float chinese , float math , float english , float physics , float chemistry , float biology);


//操作函数
public:
	void Display();


//获取成员变量的方法
public:
	CString getName();
	void setName(CString name);

	CString getNo();
	void setNo(CString no);

	CString getSex();
	void setSex(CString sex);

	CString getBirth();
	void setBirth(CString birth);

	CString getCountry();
	void setCountry(CString country);

	CString getNation();
	void setNation(CString nation);
	
	CString getAddress();
	void setAddress(CString address);

	//成绩
	float getChineseScore();
	void setChineseScore(float chineseScore);

	float getMathScore();
	void setMathScore(float mathScore);

	float getEnglishScore();
	void setEnglishScore(float englishScore);

	float getPhysicsScore();
	void setPhysicsScore(float physicsScore);

	float getChemistryScore();
	void setChemistryScore(float chemistryScore);

	float getBiologyScore();
	void setBiologyScore(float biologyScore);

	//获得平均成绩
	float getAverageScore();
protected:

//成员变量
private:
	CString strName;
	CString strNo;
	CString strSex;
	CString strBirth;
	CString strCountry;
	CString strNation;
	CString strAddress;
	
	float fScoreChinese;
	float fScoreMath;
	float fScoreEnglish;
	float fScorePhysics;
	float fScoreChemistry;
	float fScoreBiology;
	
	float fScoreAverage;

};





//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOMEWORK_STUDENTMANAGEMENTDOC_H__CE953165_116C_49E5_8C1C_9E0C0B8164AC__INCLUDED_)
