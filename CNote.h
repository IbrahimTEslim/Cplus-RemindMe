#pragma once


// CNote dialog
#ifndef CNOTE.H




class CNote : public CDialogEx
{
	DECLARE_DYNAMIC(CNote)

public:
	CNote(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CNote();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButton1();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CButton m_close_B;
//	void Arranging_Note();
	afx_msg void OnEnChangeEdit1();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnOptionsShownotetime();
	afx_msg void OnOptionsShowparentwindow();
	afx_msg void OnOptionsCloseallthe();
//	afx_msg void OnMenu();
};

#endif // !CNOTE.H