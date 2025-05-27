
// MyHashSetApp.h: основной файл заголовка для приложения MyHashSetApp
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMyHashSetAppApp:
// Сведения о реализации этого класса: MyHashSetApp.cpp
//

class CMyHashSetAppApp : public CWinApp
{
public:
	CMyHashSetAppApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyHashSetAppApp theApp;
