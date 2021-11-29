
// MFCComServerBGColorTest.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "DlgProxy.h"
#include "MFCComServerBGColorTest.h"
#include "MFCComServerBGColorTestDlg.h"
#include "MFCComServerBGColorTest_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCComServerBGColorTestApp

BEGIN_MESSAGE_MAP(CMFCComServerBGColorTestApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCComServerBGColorTestApp construction

CMFCComServerBGColorTestApp::CMFCComServerBGColorTestApp()
{
	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CMFCComServerBGColorTestApp object

CMFCComServerBGColorTestApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x97E3C8AC, 0x67BE, 0x45E5, { 0x91, 0xEE, 0xE5, 0x63, 0xB6, 0x8D, 0x6B, 0x12 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CMFCComServerBGColorTestApp initialization

BOOL CMFCComServerBGColorTestApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	// Create the shell manager, in case the dialog contains
	// any shell tree view or shell list view controls.
	CShellManager *pShellManager = new CShellManager;

	// Activate "Windows Native" visual manager for enabling themes in MFC controls
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	// Parse command line for automation or reg/unreg switches.
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// App was launched with /Embedding or /Automation switch.
	// Run app as automation server.
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Register class factories via CoRegisterClassObject().
		COleTemplateServer::RegisterAll();
	}
	// App was launched with /Unregserver or /Unregister switch.  Remove
	// entries from the registry.
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		COleObjectFactory::UpdateRegistryAll(FALSE);
		AfxOleUnregisterTypeLib(LIBID_MFCComServerBGColorTest, _wVerMajor, _wVerMinor);
		return FALSE;
	}
	// App was launched standalone or with other switches (e.g. /Register
	// or /Regserver).  Update registry entries, including typelibrary.
	else
	{
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), LIBID_MFCComServerBGColorTest, _T("MFCComServerBGColorTest.TLB"));
		if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppRegister)
		{
			return FALSE;
		}
	}	

	//MessageBox(0, L"COleObjectFactory", L"COleObjectFactory", 0);

	//// Check to see if launched as OLE server
	//if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	//{
	//	// Application was run with /Embedding or /Automation.  Don't show the
	//	//  main window in this case.
	//	return TRUE;
	//}

		// When a server application is launched stand-alone, it is a good idea
	//  to update the system registry in case it has been damaged.
	//m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);
	//COleObjectFactory::UpdateRegistryAll();

	// DUAL_SUPPORT_START
	//    make sure the type library is registerd. Otherwise dual interface won't work!
	

	//MessageBox(0, L"Vara", L"Vara", 0);

	CMFCComServerBGColorTestDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "Warning: dialog creation failed, so application is terminating unexpectedly.\n");
		TRACE(traceAppMsg, 0, "Warning: if you are using MFC controls on the dialog, you cannot #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS.\n");
	}

	// Delete the shell manager created above.
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

#ifndef _AFXDLL
	ControlBarCleanUp();
#endif

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CMFCComServerBGColorTestApp::ExitInstance()
{
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}
