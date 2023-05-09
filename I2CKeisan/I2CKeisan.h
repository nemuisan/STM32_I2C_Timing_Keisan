
// I2CKeisan.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// メイン シンボル


// CI2CKeisanApp:
// このクラスの実装については、I2CKeisan.cpp を参照してください
//

class CI2CKeisanApp : public CWinApp
{
public:
	CI2CKeisanApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CI2CKeisanApp theApp;
