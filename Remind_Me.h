
// Remind_Me.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CRemindMeApp:
// See Remind_Me.cpp for the implementation of this class
//

class CRemindMeApp : public CWinApp
{
public:
	CRemindMeApp();
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CRemindMeApp theApp;
