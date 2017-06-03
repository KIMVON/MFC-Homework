; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAscendOrDescendDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Homework_StudentManagement.h"
LastPage=0

ClassCount=9
Class1=CHomework_StudentManagementApp
Class2=CHomework_StudentManagementDoc
Class3=CHomework_StudentManagementView
Class4=CMainFrame

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CAddStudentDlg
Resource3=IDD_DIALOG2
Class7=CSearchStudentByNo
Resource4=IDD_DIALOG3
Class8=CSearchStudentByName
Resource5=IDD_DIALOG1
Class9=CAscendOrDescendDlg
Resource6=IDD_DIALOG4

[CLS:CHomework_StudentManagementApp]
Type=0
HeaderFile=Homework_StudentManagement.h
ImplementationFile=Homework_StudentManagement.cpp
Filter=N

[CLS:CHomework_StudentManagementDoc]
Type=0
HeaderFile=Homework_StudentManagementDoc.h
ImplementationFile=Homework_StudentManagementDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CHomework_StudentManagementDoc

[CLS:CHomework_StudentManagementView]
Type=0
HeaderFile=Homework_StudentManagementView.h
ImplementationFile=Homework_StudentManagementView.cpp
Filter=C
BaseClass=CListView
VirtualFilter=VWC
LastObject=ID_STUDENT_SORT_AVERAGE


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Homework_StudentManagement.cpp
ImplementationFile=Homework_StudentManagement.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_VIEW_TOOLBAR
Command11=ID_VIEW_STATUS_BAR
Command12=ID_STUDENT_ADD
Command13=ID_STUDENT_AMEND
Command14=ID_STUDENT_DEL
Command15=ID_STUDENT_SEARCH_ALL
Command16=ID_STUDENT_SEARCH_BY_NO
Command17=ID_STUDENT_SEARCH_BY_NAME
Command18=ID_STUDENT_SORT_ORIGINAL
Command19=ID_STUDENT_SORT_CHINESE
Command20=ID_STUDENT_SORT_ENGLISH
Command21=ID_STUDENT_SORT_MATH
Command22=ID_STUDENT_SORT_PHYSICS
Command23=ID_STUDENT_SORT_CHEMISTRY
Command24=ID_STUDENT_SORT_BIOLOGY
Command25=ID_STUDENT_SORT_AVERAGE
Command26=ID_APP_ABOUT
CommandCount=26

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_DIALOG1]
Type=1
Class=CAddStudentDlg
ControlCount=36
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177296
Control4=IDC_EDIT_NO,edit,1350631552
Control5=IDC_STATIC,static,1342308865
Control6=IDC_EDIT_NAME,edit,1350631552
Control7=IDC_EDIT_BIRTH,edit,1350631552
Control8=IDC_STATIC,static,1342308865
Control9=IDC_EDIT_SEX,edit,1350631552
Control10=IDC_EDIT_COUNTRY,edit,1350631552
Control11=IDC_EDIT_NATION,edit,1350631552
Control12=IDC_EDIT_ADDRESS,edit,1350631428
Control13=IDC_STATIC,static,1342177296
Control14=IDC_EDIT_SCORE_CHINESE,edit,1350631552
Control15=IDC_EDIT_SCORE_MATH,edit,1350631552
Control16=IDC_EDIT_SCORE_PHYSICS,edit,1350631552
Control17=IDC_EDIT_SCORE_ENGLISH,edit,1350631552
Control18=IDC_EDIT_SCORE_CHEMISTRY,edit,1350631552
Control19=IDC_EDIT_SCORE_BIOLOGY,edit,1350631552
Control20=IDC_STATIC,static,1342308865
Control21=IDC_STATIC,static,1342308865
Control22=IDC_STATIC,static,1342308865
Control23=IDC_STATIC,static,1342308865
Control24=IDC_STATIC,static,1342308865
Control25=IDC_STATIC,static,1342308865
Control26=IDC_STATIC,static,1342308865
Control27=IDC_STATIC,static,1342308865
Control28=IDC_STATIC,static,1342308865
Control29=IDC_STATIC,static,1342308865
Control30=IDC_STATIC,static,1342308865
Control31=IDC_SPIN1,msctls_updown32,1342177328
Control32=IDC_SPIN2,msctls_updown32,1342177328
Control33=IDC_SPIN3,msctls_updown32,1342177328
Control34=IDC_SPIN4,msctls_updown32,1342177328
Control35=IDC_SPIN5,msctls_updown32,1342177328
Control36=IDC_SPIN6,msctls_updown32,1342177328

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[CLS:CAddStudentDlg]
Type=0
HeaderFile=AddStudentDlg.h
ImplementationFile=AddStudentDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAddStudentDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG2]
Type=1
Class=CSearchStudentByNo
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177296
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308865

[CLS:CSearchStudentByNo]
Type=0
HeaderFile=SearchStudentByNo.h
ImplementationFile=SearchStudentByNo.cpp
BaseClass=CDialog
Filter=D
LastObject=CSearchStudentByNo
VirtualFilter=dWC

[DLG:IDD_DIALOG3]
Type=1
Class=CSearchStudentByName
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_STATIC,static,1342308865
Control5=IDC_STATIC,static,1342177296

[CLS:CSearchStudentByName]
Type=0
HeaderFile=SearchStudentByName.h
ImplementationFile=SearchStudentByName.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_DIALOG4]
Type=1
Class=CAscendOrDescendDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:CAscendOrDescendDlg]
Type=0
HeaderFile=AscendOrDescendDlg.h
ImplementationFile=AscendOrDescendDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAscendOrDescendDlg
VirtualFilter=dWC

