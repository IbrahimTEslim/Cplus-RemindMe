
// Remind_MeDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Remind_Me.h"
#include "Remind_MeDlg.h"
#include "afxdialogex.h"
#include "CNote.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CString Note;
CString CS_Time;

CTime Time;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:

//	afx_msg void OnMenu();
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CRemindMeDlg dialog



CRemindMeDlg::CRemindMeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_REMIND_ME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRemindMeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_Create);
}

BEGIN_MESSAGE_MAP(CRemindMeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CRemindMeDlg::OnBnClickedMfcbutton1)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CRemindMeDlg::OnBnClickedMfcbutton2)
	ON_WM_GETMINMAXINFO()
	ON_WM_CLOSE()
//	ON_WM_CREATE()
ON_WM_CREATE()
ON_COMMAND(ID_Menu, &CRemindMeDlg::OnMenu)
END_MESSAGE_MAP()


// CRemindMeDlg message handlers

BOOL CRemindMeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	SetWindowPos(&this->wndNoTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	CFont* Welcome_font = new CFont;
	Welcome_font->CreatePointFont(170, L"Arial");
	GetDlgItem(IDC_STATIC)->SetFont(Welcome_font);


	CFont* Write = new CFont();
	Write->CreatePointFont(120, _T("Arial"));
	GetDlgItem(IDC_STATIC_2)->SetFont(Write);


	CFont* Edit_font = new CFont();
	Edit_font->CreatePointFont(120, L"Arial");
	GetDlgItem(IDC_EDIT1)->SetFont(Edit_font);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRemindMeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRemindMeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRemindMeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CRemindMeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	if (pWnd->GetDlgCtrlID() == IDC_STATIC)
	{
		pDC->SetTextColor(RGB(30, 0, 255));
		pDC->SetBkColor(RGB(169, 204, 227));
	}

	if (pWnd->GetDlgCtrlID() == IDC_STATIC_2)
	{
		pDC->SetTextColor(RGB(30, 0, 255));
		pDC->SetBkColor(RGB(169, 204, 227));
	}

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}


BOOL CRemindMeDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	CRect rect;
	GetClientRect(&rect);

	CBrush myBrush(RGB(169, 204, 227)); 	// dialog background color
	pDC->SelectObject(myBrush);  // restore old brush

	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}

void CRemindMeDlg::OnBnClickedMfcbutton1()
{
	// TODO: Add your control notification handler code here
	CString edit;
	GetDlgItemText(IDC_EDIT1, Note);

	ShowWindow(SW_HIDE);

	CNote CNote;
	CNote.DoModal();

}


void CRemindMeDlg::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here

	exit(1);

}


void CRemindMeDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: Add your message handler code here and/or call default

	lpMMI->ptMinTrackSize.x = 525;
	lpMMI->ptMinTrackSize.y = 284;


	lpMMI->ptMaxTrackSize.x = 550;
	lpMMI->ptMaxTrackSize.y = 295;


	CDialogEx::OnGetMinMaxInfo(lpMMI);
}


void CRemindMeDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	exit(1);
}






int CRemindMeDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	CS_Time = CTime::GetCurrentTime().Format("%Y:%m:%d:%I:%M:%p");

	Time = CTime::GetCurrentTime();


	return 0;
}





void CRemindMeDlg::OnMenu()
{
	// TODO: Add your command handler code here

	CAboutDlg AboutDlg;
	AboutDlg.DoModal();
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	CFont* Write = new CFont();
	Write->CreatePointFont(120, _T("Arial"));
	GetDlgItem(IDC_STATIC_ABOUT)->SetFont(Write);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}



///// What I Was gonna do is putting a "Combo Box" to choose a time to remind user 
///// About his NOTE...