
// DlgProxy.h: header file
//

#include "mfcdual.h"
#include "MFCComServerBGColorTest_h.h"

#pragma once

class CMFCComServerBGColorTestDlg;


// CMFCComServerBGColorTestDlgAutoProxy command target

class CMFCComServerBGColorTestDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CMFCComServerBGColorTestDlgAutoProxy)

	CMFCComServerBGColorTestDlgAutoProxy();

// Attributes
public:
	CMFCComServerBGColorTestDlg* m_pDialog;

// Operations
public:

// Overrides
	public:
	virtual void OnFinalRelease();

	CString m_str;
	afx_msg void ShowWindow();
	afx_msg void TestErrorHandler(short wCode);

protected:
	virtual ~CMFCComServerBGColorTestDlgAutoProxy();

	// Generated message map functions

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CMFCComServerBGColorTestDlgAutoProxy)

	// Generated OLE dispatch map functions

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()


	BEGIN_DUAL_INTERFACE_PART(DualMFCComServerBGColorTest, IDualMFCComServerBGColorTest)
		STDMETHOD(put_color)(THIS_ BSTR newText);
		STDMETHOD(get_color)(THIS_ BSTR FAR* retval);
		STDMETHOD(TestError)(THIS_ short wCode);
	END_DUAL_INTERFACE_PART(DualMFCComServerBGColorTest)

		//     add declaration of ISupportErrorInfo implementation
		//     to indicate we support the OLE Automation error object
		DECLARE_DUAL_ERRORINFO()
};

