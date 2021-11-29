
// MFCComServerBGColorTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCComServerBGColorTest.h"
#include "MFCComServerBGColorTestDlg.h"
#include "DlgProxy.h"
#include "afxdialogex.h"
#include <appmodel.h>
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CMFCComServerBGColorTestDlg dialog

bool IsRunningFromUWPContaner()
{
	UINT32 length = 0;
	LONG rc = GetCurrentPackageFamilyName(&length, NULL);
	if (rc != ERROR_INSUFFICIENT_BUFFER)
	{
		if (rc == APPMODEL_ERROR_NO_PACKAGE)
			return false;
		else
			return true;
	}

	PWSTR familyName = (PWSTR)malloc(length * sizeof(*familyName));

	rc = GetCurrentPackageFamilyName(&length, familyName);
	if (rc == APPMODEL_ERROR_NO_PACKAGE)
		return false;

	free(familyName);

	return true;
}

IMPLEMENT_DYNAMIC(CMFCComServerBGColorTestDlg, CDialogEx);

CMFCComServerBGColorTestDlg::CMFCComServerBGColorTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCComServerBGColorTest_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pAutoProxy = NULL;
}

CMFCComServerBGColorTestDlg::~CMFCComServerBGColorTestDlg()
{
	// If there is an automation proxy for this dialog, set
	//  its back pointer to this dialog to NULL, so it knows
	//  the dialog has been deleted.
	if (m_pAutoProxy != NULL)
		m_pAutoProxy->m_pDialog = NULL;

	//AfxOleUnlockApp();
}

void CMFCComServerBGColorTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCComServerBGColorTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CMFCComServerBGColorTestDlg message handlers

HBRUSH CMFCComServerBGColorTestDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd->GetDlgCtrlID() == IDC_PICTURECTRL)
	{
		pDC->SetBkMode(TRANSPARENT);
		m_Brush.DeleteObject();
		int rgb;
		BSTR color;
		get_color(&color);
		StrToIntEx(color, STIF_SUPPORT_HEX, &rgb);
		COLORREF clr = (((rgb & 0x000000FF) << 16) | (rgb & 0x0000FF00) | ((rgb & 0x00FF0000) >> 16));
		m_Brush.CreateSolidBrush(clr);
		//pDC->SetBkColor(RGB(255, 255, 255));		
		return (HBRUSH)m_Brush.GetSafeHandle();
	}
	return hbr;
}

BOOL CMFCComServerBGColorTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Brush.CreateSolidBrush(RGB(255, 0, 0));

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	if (IsRunningFromUWPContaner())
		GetDlgItem(ID_STATIC3)->SetWindowText(_T("I'm running inside a UWP container"));
	else
		GetDlgItem(ID_STATIC3)->SetWindowText(_T("I'm running as a native desktop app"));

	// TODO: Add extra initialization here

	//m_pAutoProxy = new CMFCComServerBGColorTestDlgAutoProxy();
	//m_pUnk = m_pAutoProxy->GetIDispatch(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCComServerBGColorTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCComServerBGColorTestDlg::OnPaint()
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
HCURSOR CMFCComServerBGColorTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CMFCComServerBGColorTestDlg::OnClose()
{
	if (CanExit())
		CDialogEx::OnClose();
}

void CMFCComServerBGColorTestDlg::OnOK()
{
	if (CanExit())
		CDialogEx::OnOK();
}

void CMFCComServerBGColorTestDlg::OnCancel()
{
	if (CanExit())
		CDialogEx::OnCancel();
}

BOOL CMFCComServerBGColorTestDlg::CanExit()
{
	//// If the proxy object is still around, then the automation
	////  controller is still holding on to this application.  Leave
	////  the dialog around, but hide its UI.
	//if (m_pAutoProxy != NULL)
	//{
	//	ShowWindow(SW_HIDE);
	//	return FALSE;
	//}

	return TRUE;
}

void CMFCComServerBGColorTestDlg::put_color(BSTR newText)
{
	GetDlgItem(ID_STATIC5)->SetWindowText(newText);
	InvalidateRect(NULL, TRUE);
	UpdateWindow();
}

void CMFCComServerBGColorTestDlg::get_color(BSTR* retval)
{
	TCHAR text[MAX_PATH] = { 0 };
	GetDlgItem(ID_STATIC5)->GetWindowText(text, MAX_PATH);
	*retval = text;
}

