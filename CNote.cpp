// CNote.cpp : implementation file
//

#include "pch.h"
#include "Remind_Me.h"
#include "CNote.h"
#include "afxdialogex.h"
#include "Remind_MeDlg.h"

#include "CNoteTime.h"

CToolTipCtrl tp;


// CNote dialog

IMPLEMENT_DYNAMIC(CNote, CDialogEx)

CNote::CNote(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NOTE, pParent)
{

}

CNote::~CNote()
{

}




void CNote::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_close_B);
}


BEGIN_MESSAGE_MAP(CNote, CDialogEx)
	ON_WM_NCHITTEST()
	ON_WM_GETMINMAXINFO()
	//	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CNote::OnBnClickedButton1)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_EN_CHANGE(IDC_EDIT1, &CNote::OnEnChangeEdit1)
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_OPTIONS_SHOWNOTETIME, &CNote::OnOptionsShownotetime)
	ON_COMMAND(ID_OPTIONS_SHOWPARENTWINDOW, &CNote::OnOptionsShowparentwindow)
	ON_COMMAND(ID_OPTIONS_CLOSEALLTHE, &CNote::OnOptionsCloseallthe)
END_MESSAGE_MAP()


// CNote message handlers
void ChangeSize()
{
}

BOOL CNote::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	SetWindowPos(&this->wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);


	CFont* Note_font = new CFont();

	Note_font->CreateFont(24, 0, 0, 0, FW_BOLD,
		FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_ROMAN, L"Arial");


	Note = L"" + Note;

	GetDlgItem(IDC_EDIT_2)->SetFont(Note_font);
	GetDlgItem(IDC_EDIT_2)->SetWindowText(Note);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


LRESULT CNote::OnNcHitTest(CPoint point)
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


void CNote::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: Add your message handler code here and/or call default

	lpMMI->ptMinTrackSize.x = 160;
	lpMMI->ptMinTrackSize.y = 70;


	CDialogEx::OnGetMinMaxInfo(lpMMI);
}




void CNote::OnPaint()
{
	CPaintDC dc(this); // device context for painting
}


void CNote::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	PostMessage(WM_CLOSE, NULL, NULL);


	CRemindMeDlg R_me;
	R_me.DoModal();
}


BOOL CNote::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	CRect rect;
	GetClientRect(&rect);

	CBrush myBrush(RGB(255, 255, 255)); 	// dialog background color
	pDC->SelectObject(myBrush);  // restore old brush

	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}


void CNote::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

	if (!GetDlgItem(IDC_BUTTON1)) return;

	CRect rect;
	GetClientRect(rect);

	int width = rect.right - rect.left;

	UINT flags = SWP_NOSENDCHANGING | SWP_NOACTIVATE | SWP_NOZORDER;

	m_close_B.SetWindowPos(NULL, width - 17, 0, 17, 17, flags);

	m_close_B.SetWindowText(L"X");


	GetDlgItem(IDC_EDIT_2)->SetWindowPos(NULL, 0, 0, rect.right - 20, rect.bottom - 10, flags);
	////Rearranging the Text to fit the window every time it resize
	//int Letters_count = width / 7;
	//CString FirstLine = Note.GetBuffer(Letters_count);
}



void CNote::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


HBRUSH CNote::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here
	if (pWnd->GetDlgCtrlID() == IDC_EDIT_2)
	{
		pDC->SetTextColor(RGB(40, 0, 255));
	}
	// TODO:  Return a different brush if the default is not desired
	return hbr;
}




void CNote::OnOptionsShownotetime()
{
	// TODO: Add your command handler code here

	CNoteTime NoteTime;
	NoteTime.DoModal();
}


void CNote::OnOptionsShowparentwindow()
{
	// TODO: Add your control notification handler code here

	PostMessage(WM_CLOSE, NULL, NULL);


	CRemindMeDlg R_me;
	R_me.DoModal();

}


void CNote::OnOptionsCloseallthe()
{
	// TODO: Add your command handler code here

	exit(1);

}


