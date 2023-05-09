
// I2CKeisanDlg.h : ヘッダー ファイル
//

#pragma once


// CI2CKeisanDlg ダイアログ
class CI2CKeisanDlg : public CDialogEx
{
// コンストラクション
public:
	CI2CKeisanDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_I2CKEISAN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString I2CFREQ;
	CString KERNELFREQ;
	afx_msg void OnBnClickedButton1();
};
