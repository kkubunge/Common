; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAWCAnalysisDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "AWCAnalysis.h"

ClassCount=4
Class1=CAWCAnalysisApp
Class2=CAWCAnalysisDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_AWCANALYSIS_DIALOG
Resource4=IDD_DATE_DIALOG
Class4=CDateDialog
Resource5=IDD_ABOUTBOX (English (U.S.))

[CLS:CAWCAnalysisApp]
Type=0
HeaderFile=AWCAnalysis.h
ImplementationFile=AWCAnalysis.cpp
Filter=N

[CLS:CAWCAnalysisDlg]
Type=0
HeaderFile=AWCAnalysisDlg.h
ImplementationFile=AWCAnalysisDlg.cpp
Filter=D
LastObject=CAWCAnalysisDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=AWCAnalysisDlg.h
ImplementationFile=AWCAnalysisDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_AWCANALYSIS_DIALOG]
Type=1
Class=CAWCAnalysisDlg
ControlCount=18
Control1=IDC_STATIC_GRAPH,static,1208094720
Control2=IDC_BUTTON_PLUS_YMAX,button,1342242816
Control3=IDC_BUTTON_MINUS_YMAX,button,1342242816
Control4=IDC_BUTTON_MINUS_XMAX,button,1342242816
Control5=IDC_BUTTON_PLUS_XMAX,button,1342242816
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1208025088
Control8=IDC_STATIC,static,1350569991
Control9=IDC_BUTTON_DIRECTORY,button,1342242816
Control10=IDC_STATIC_PATH,static,1342312960
Control11=IDC_BUTTON_LOAD,button,1342242816
Control12=IDC_LIST_AWC,listbox,1352728835
Control13=IDC_STATIC,static,1342308352
Control14=IDC_COMBO_MODULE,combobox,1344339970
Control15=IDC_STATIC,static,1342308352
Control16=IDC_COMBO_ARM,combobox,1344339970
Control17=IDC_STATIC,static,1342308352
Control18=IDC_COMBO_TYPE,combobox,1344339970

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DATE_DIALOG]
Type=1
Class=CDateDialog
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_MONTHCALENDAR1,SysMonthCal32,1342242832

[CLS:CDateDialog]
Type=0
HeaderFile=DateDialog.h
ImplementationFile=DateDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDateDialog

