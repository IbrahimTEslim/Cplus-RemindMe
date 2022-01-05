#pragma once


// CNoteTime dialog

class CNoteTime : public CDialogEx
{
	DECLARE_DYNAMIC(CNoteTime)

public:
	CNoteTime(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CNoteTime();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOTE_TIME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedButton1();
	afx_msg LRESULT OnNcHitTest(CPoint point);
};
