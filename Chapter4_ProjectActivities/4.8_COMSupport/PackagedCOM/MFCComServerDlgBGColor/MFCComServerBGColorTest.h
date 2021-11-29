
// MFCComServerBGColorTest.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCComServerBGColorTestApp:
// See MFCComServerBGColorTest.cpp for the implementation of this class
//

class CMFCComServerBGColorTestApp : public CWinApp
{
public:
	CMFCComServerBGColorTestApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	COleTemplateServer m_server;

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCComServerBGColorTestApp theApp;