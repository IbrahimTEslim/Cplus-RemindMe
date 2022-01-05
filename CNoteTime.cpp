// CNoteTime.cpp : implementation file
//

#include "pch.h"
#include "Remind_Me.h"
#include "CNoteTime.h"
#include "afxdialogex.h"

#include "Remind_MeDlg.h"

#include <atltime.h>

// CNoteTime dialog

CTimeSpan Note_Old;

IMPLEMENT_DYNAMIC(CNoteTime, CDialogEx)

CNoteTime::CNoteTime(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NOTE_TIME, pParent)
{

}

CNoteTime::~CNoteTime()
{
}

void CNoteTime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNoteTime, CDialogEx)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON1, &CNoteTime::OnBnClickedButton1)
	ON_WM_NCHITTEST()
END_MESSAGE_MAP()


// CNoteTime message handlers


BOOL CNoteTime::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	CFont* Note_Time = new CFont();
	Note_Time->CreatePointFont(100, _T("Arial"));

	GetDlgItem(IDC_STATIC_NOTE_TIME)->SetFont(Note_Time);
	GetDlgItem(IDC_STATIC_NOTE_TIME)->SetWindowText(L"Created in: "+CS_Time);

	CString CS_Note_Old = Note_Old.Format(L"%D:%H:%M:%S");

	GetDlgItem(IDC_STATIC_NOTE_OLD)->SetFont(Note_Time);
	GetDlgItem(IDC_STATIC_NOTE_OLD)->SetWindowText(L"This Note Existent from: "+CS_Note_Old);


		return TRUE;  // return TRUE unless you set the focus to a control
					  // EXCEPTION: OCX Property Pages should return FALSE
}


int CNoteTime::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CTime Now_Time = CTime::GetCurrentTime();

	Note_Old = Now_Time - Time;

	return 0;
}


void CNoteTime::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CNoteTime::OnOK();
}


LRESULT CNoteTime::OnNcHitTest(CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	ScreenToClient(&point);

	CRect rc;
	GetClientRect(&rc);

	//rc.bottom = rc.top + 100; 

	if (rc.PtInRect(point))
		return HTCAPTION;

	return CDialog::OnNcHitTest(point);
}
