
// PVZCheaterDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "PVZCheater.h"
#include "PVZCheaterDlg.h"
#include "afxdialogex.h"

#define log(fmt, ...) \
CString str; \
str.Format(CString(fmt), __VA_ARGS__); \
AfxMessageBox(str);

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static CPVZCheaterDlg* g_dlg;
static HANDLE g_processHandle;

// 将某个值写入植物大战僵尸内存（后面的可变参数是地址链，要以-1结尾）
void WriteMemory(void* value, DWORD valueSize, ...) {
	if (value == NULL || valueSize == 0 || g_processHandle == NULL) return;

	DWORD tempValue = 0;

	va_list addresses;
	va_start(addresses, valueSize);
	DWORD offset = 0;
	DWORD lastAddress = 0;
	while ((offset = va_arg(addresses, DWORD)) != -1) {
		lastAddress = tempValue + offset;
		::ReadProcessMemory(g_processHandle, (LPCVOID)lastAddress, &tempValue, sizeof(DWORD), NULL);
	}
	va_end(addresses);

	::WriteProcessMemory(g_processHandle, (LPVOID)lastAddress, value, valueSize, NULL);
}

/*
* value: 数据
* valueSize： 数据大小
* address： 内存地址
*/
void WriteMemory(void* value, DWORD valueSize, DWORD address) {
	WriteMemory(value, valueSize, address, -1);
}

// 用来监控游戏的线程
DWORD monitorThreadFunc(LPVOID lpThreadParameter) {
	while (1) {
		// 获取植物大战僵尸窗口的句柄
		HWND windowHandle = FindWindow(CString("MainWindow"), CString("Plants vs. Zombies"));

		if (windowHandle == NULL) {
			g_dlg->m_bnKill.SetCheck(FALSE);
			g_dlg->m_bnSun.SetCheck(FALSE);
			g_dlg->m_bnKill.EnableWindow(FALSE);
			g_dlg->m_bnSun.EnableWindow(FALSE);

			g_processHandle = NULL;
		} else if (g_processHandle == NULL) {
			g_dlg->m_bnKill.EnableWindow(TRUE);
			g_dlg->m_bnSun.EnableWindow(TRUE);

			// 获得植物大战僵尸的进程ID
			DWORD processPid;
			GetWindowThreadProcessId(windowHandle, &processPid);
			// 获得植物大战僵尸的进程句柄
			g_processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processPid);
		}

		// 休息睡眠
		Sleep(1000);
	}
	return NULL;
}


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx {
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX) {}

void CAboutDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPVZCheaterDlg 对话框



CPVZCheaterDlg::CPVZCheaterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PVZCHEATER_DIALOG, pParent) {
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPVZCheaterDlg::DoDataExchange(CDataExchange* pDX) {
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_KILL, m_bnKill);
	DDX_Control(pDX, IDC_SUN, m_bnSun);
}

BEGIN_MESSAGE_MAP(CPVZCheaterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COURSE, &CPVZCheaterDlg::OnBnClickedCourse)
	ON_BN_CLICKED(IDC_KILL, &CPVZCheaterDlg::OnBnClickedKill)
	ON_BN_CLICKED(IDC_SUN, &CPVZCheaterDlg::OnBnClickedSun)
END_MESSAGE_MAP()


// CPVZCheaterDlg 消息处理程序

BOOL CPVZCheaterDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr) {
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty()) {
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	// 创建一条子线程，监控游戏的打开或者关闭
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE) monitorThreadFunc, NULL, NULL, NULL);

	// 保存对话框
	g_dlg = this;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CPVZCheaterDlg::OnSysCommand(UINT nID, LPARAM lParam) {
	if ((nID & 0xFFF0) == IDM_ABOUTBOX) {
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	} else {
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CPVZCheaterDlg::OnPaint() {
	if (IsIconic()) {
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	} else {
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CPVZCheaterDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}

void CPVZCheaterDlg::OnBnClickedCourse() {
	//int age = 20;
	//TRACE("age is %d\n", age); //age is 20

	ShellExecute(NULL,
		CString("open"),
		CString("https://ke.qq.com/course/336509"), NULL, NULL,
		SW_SHOWNORMAL);

	/*ShellExecuteW(
		_In_opt_ HWND hwnd,
		_In_opt_ LPCWSTR lpOperation,
		_In_ LPCWSTR lpFile,
		_In_opt_ LPCWSTR lpParameters,
		_In_opt_ LPCWSTR lpDirectory,
		_In_ INT nShowCmd);*/

		/*int age = 10;
		log("my age is %d", age);*/

		/*int age = 10;
		CString str;
		str.Format(CString("age is %d"), age);
		AfxMessageBox(str);*/

		/*int age = 10;
		CString str;
		str.Format(CString("age is %d"), age);
		MessageBox(str, CString("警告"), MB_YESNOCANCEL | MB_ICONWARNING);*/
}

void CPVZCheaterDlg::OnBnClickedKill() {
	//CButton* button = (CButton*)GetDlgItem(IDC_KILL);
	//bool checked = IsDlgButtonChecked(IDC_KILL);
	if (m_bnKill.GetCheck()) {
		BYTE data[] = { 0x29, 0xED, 0x90, 0x90 };
		WriteMemory(data, sizeof(data), 0x0054D0BA);

		//BYTE data2[] = { 0x29, 0xC9 };
		//WriteMemory(data2, sizeof(data2), 0x0054CDD4);

	} else {
		BYTE data[] = { 0x2B, 0x6C, 0x24, 0x20 };
		WriteMemory(data, sizeof(data), 0x0054D0BA);
	}
}


void CPVZCheaterDlg::OnBnClickedSun() {
	if (m_bnSun.GetCheck()) {
		log("check");
	} else {
		log("uncheck");
	}
}
