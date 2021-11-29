
// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "MFCComServerBGColorTest.h"
#include "DlgProxy.h"
#include "MFCComServerBGColorTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCComServerBGColorTestDlgAutoProxy

IMPLEMENT_DYNCREATE(CMFCComServerBGColorTestDlgAutoProxy, CCmdTarget)

CMFCComServerBGColorTestDlgAutoProxy::CMFCComServerBGColorTestDlgAutoProxy()
{
	EnableAutomation();

	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT_VALID(AfxGetApp()->m_pMainWnd);
	if (AfxGetApp()->m_pMainWnd)
	{
		ASSERT_KINDOF(CMFCComServerBGColorTestDlg, AfxGetApp()->m_pMainWnd);
		if (AfxGetApp()->m_pMainWnd->IsKindOf(RUNTIME_CLASS(CMFCComServerBGColorTestDlg)))
		{
			m_pDialog = reinterpret_cast<CMFCComServerBGColorTestDlg*>(AfxGetApp()->m_pMainWnd);
			m_pDialog->m_pAutoProxy = this;
		}
	}
}

CMFCComServerBGColorTestDlgAutoProxy::~CMFCComServerBGColorTestDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CMFCComServerBGColorTestDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CMFCComServerBGColorTestDlgAutoProxy, CCmdTarget)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCComServerBGColorTestDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CMFCComServerBGColorTestDlgAutoProxy)
	DISP_PROPERTY(CMFCComServerBGColorTestDlgAutoProxy, "color", m_str, VT_BSTR)
	DISP_FUNCTION(CMFCComServerBGColorTestDlgAutoProxy, "TestError", TestErrorHandler, VT_EMPTY, VTS_I2)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

BEGIN_INTERFACE_MAP(CMFCComServerBGColorTestDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CMFCComServerBGColorTestDlgAutoProxy, DIID_IMFCComServerBGColorTest, Dispatch)
	INTERFACE_PART(CMFCComServerBGColorTestDlgAutoProxy, IID_IDualMFCComServerBGColorTest, DualMFCComServerBGColorTest)
	DUAL_ERRORINFO_PART(CMFCComServerBGColorTestDlgAutoProxy)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {FA796308-1FB5-4289-B5DD-504D8499088E}
IMPLEMENT_OLECREATE2(CMFCComServerBGColorTestDlgAutoProxy, "MFCComServerBGColorTest.Application", 0xfa796308, 0x1fb5, 0x4289, 0xb5, 0xdd, 0x50, 0x4d, 0x84, 0x99, 0x8, 0x8e)


void CMFCComServerBGColorTestDlgAutoProxy::ShowWindow()
{
	this->m_pDialog->ShowWindow(SW_SHOW);
}

// CMFCComServerBGColorTestDlgAutoProxy message handlers

void CMFCComServerBGColorTestDlgAutoProxy::TestErrorHandler(short wCode)
{
	CString strError;
	strError.Format(200, wCode); 
	AfxThrowOleDispatchException((WORD)wCode,
		strError,
		(UINT)wCode);
}

// DUAL_SUPPORT_START

// delegate standard IDispatch methods to MFC IDispatch implementation
DELEGATE_DUAL_INTERFACE(CMFCComServerBGColorTestDlgAutoProxy, DualMFCComServerBGColorTest)

// Our method and property functions can generally just
// delegate back to the methods we generated using
// ClassWizard. However, if we set up properties to
// access variables directly, we will need to write the
//  code to get/put the value into the variable.

STDMETHODIMP CMFCComServerBGColorTestDlgAutoProxy::XDualMFCComServerBGColorTest::put_color(BSTR newText)
{	
	METHOD_PROLOGUE(CMFCComServerBGColorTestDlgAutoProxy, DualMFCComServerBGColorTest)

		TRY_DUAL(IID_IDualMFCComServerBGColorTest)
	{
		pThis->m_pDialog->put_color(newText);
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CMFCComServerBGColorTestDlgAutoProxy::XDualMFCComServerBGColorTest::get_color(BSTR* retval)
{
	METHOD_PROLOGUE(CMFCComServerBGColorTestDlgAutoProxy, DualMFCComServerBGColorTest)

		TRY_DUAL(IID_IDualMFCComServerBGColorTest)
	{
		pThis->m_pDialog->get_color(retval);
		return NOERROR;
	}
	CATCH_ALL_DUAL
}

STDMETHODIMP CMFCComServerBGColorTestDlgAutoProxy::XDualMFCComServerBGColorTest::TestError(short wCode)
{
	METHOD_PROLOGUE(CMFCComServerBGColorTestDlgAutoProxy, DualMFCComServerBGColorTest)

		TRY_DUAL(IID_IDualMFCComServerBGColorTest)
	{
		pThis->TestErrorHandler(wCode);
		return NOERROR;
	}
	CATCH_ALL_DUAL
}


// Implement ISupportErrorInfo to indicate we support the
// OLE Automation error handler.
IMPLEMENT_DUAL_ERRORINFO(CMFCComServerBGColorTestDlgAutoProxy, IID_IDualMFCComServerBGColorTest)