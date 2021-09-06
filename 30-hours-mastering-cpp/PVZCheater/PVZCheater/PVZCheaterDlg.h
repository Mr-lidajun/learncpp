
// PVZCheaterDlg.h: 头文件
//

#pragma once


// CPVZCheaterDlg 对话框
class CPVZCheaterDlg : public CDialogEx
{
// 构造
public:
	CPVZCheaterDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PVZCHEATER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedCourse();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedKill();
	afx_msg void OnBnClickedSun();
private:
	/* 友元函数 */
	friend DWORD monitorThreadFunc(LPVOID);
	/* 秒杀僵尸 */
	CButton m_bnKill;
	/* 无限阳光 */
	CButton m_bnSun;
	/* 子线程句柄 */
	HANDLE m_monitorThread;
};
