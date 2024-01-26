
// bolls_drawer.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CbollsdrawerApp:
// Сведения о реализации этого класса: bolls_drawer.cpp
//

class CbollsdrawerApp : public CWinApp
{
public:
	CbollsdrawerApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CbollsdrawerApp theApp;
