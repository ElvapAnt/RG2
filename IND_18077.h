
// IND_18077.h : main header file for the IND_18077 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CIND18077App:
// See IND_18077.cpp for the implementation of this class
//

class CIND18077App : public CWinApp
{
public:
	CIND18077App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CIND18077App theApp;
