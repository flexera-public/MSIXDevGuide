
// MFCComServerBGColorTestDlg.h : header file
//

#pragma once

class CMFCComServerBGColorTestDlgAutoProxy;


// CMFCComServerBGColorTestDlg dialog
class CMFCComServerBGColorTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMFCComServerBGColorTestDlg);
	friend class CMFCComServerBGColorTestDlgAutoProxy;

// Construction
public:
	CMFCComServerBGColorTestDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CMFCComServerBGColorTestDlg();
	void put_color(BSTR newText);
	void get_color(BSTR* retval);


// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCComServerBGColorTest_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);


// Implementation
protected:
	CMFCComServerBGColorTestDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;
	CBrush m_Brush;

	BOOL CanExit();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	DECLARE_MESSAGE_MAP()
};
