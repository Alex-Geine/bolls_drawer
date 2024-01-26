
// bolls_drawerDlg.h: файл заголовка
//

#pragma once
#include "Drawer.h"
#include "BollsRow.h"


// Диалоговое окно CbollsdrawerDlg
class CbollsdrawerDlg : public CDialogEx
{
// Создание
public:
	CbollsdrawerDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOLLS_DRAWER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Drawer Graph;
	BollsRow* br = nullptr;
	afx_msg void OnBnClickedOk();
	float width;
	unsigned int size;
	float r;
};
