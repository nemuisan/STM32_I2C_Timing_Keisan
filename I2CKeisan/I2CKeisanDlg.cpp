
// I2CKeisanDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "I2CKeisan.h"
#include "I2CKeisanDlg.h"
#include "afxdialogex.h"

#include "i2c_timing_utility.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CI2CKeisanDlg ダイアログ



CI2CKeisanDlg::CI2CKeisanDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_I2CKEISAN_DIALOG, pParent)
	, I2CFREQ(_T("100"))
	, KERNELFREQ(_T("48"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CI2CKeisanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, I2CFREQ);
	DDV_MaxChars(pDX, I2CFREQ, 4);
	DDX_Text(pDX, IDC_EDIT1, KERNELFREQ);
	DDV_MaxChars(pDX, KERNELFREQ, 4);
}

BEGIN_MESSAGE_MAP(CI2CKeisanDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CI2CKeisanDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CI2CKeisanDlg メッセージ ハンドラー

BOOL CI2CKeisanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CI2CKeisanDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CI2CKeisanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CI2CKeisanDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	CString textval;

	UpdateData(true);

	uint32_t ukfreq = _ttoi(KERNELFREQ);
	uint32_t i2cfreq = _ttoi(I2CFREQ);

	if (ukfreq > 300) {
		AfxMessageBox(_T("Kernel-Freq value must be below 300(MHz)!"));
		return;
	}
	if (!((i2cfreq <= 1000) && (i2cfreq >= 100)) ) {
		AfxMessageBox(_T("I2C-Clock value must be 100,400,1000(kHz)!"));
		return;
	}

	ukfreq *= 1000 * 1000UL;
	i2cfreq *= 1000UL;

	uint32_t setval = I2C_GetTiming(ukfreq, i2cfreq);

	textval.Format(_T("0x%X"), setval);

	GetDlgItem(IDC_EDIT3)->SetWindowText(textval);
	UpdateData(false);

}
