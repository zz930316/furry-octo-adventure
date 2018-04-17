
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
	, m_num1(0)
	, m_num2(0)
	, m_num3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_num1);
	DDX_Text(pDX, IDC_EDIT2, m_num2);
	DDX_Text(pDX, IDC_EDIT3, m_num3);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
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
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码

	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];

	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 12);
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 12);

	num1 = _ttoi(ch1); //	将字符数组中的值转成int型
	num2 = _ttoi(ch2); //	将字符数组中的值转成int型

	num3 = num1 + num2;

	_itot_s(num3, ch3, 10);	//	将int型值存到字符数组中
	GetDlgItem(IDC_EDIT3)->SetWindowText(ch3);

}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码

	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];

	GetDlgItemText(IDC_EDIT1,ch1, 12);
	GetDlgItemText(IDC_EDIT2,ch2, 12);

	num1 = _ttoi(ch1);	//	将字符数组中的值转成int型
	num2 = _ttoi(ch2);	//	将字符数组中的值转成int型

	num3 = num1 + num2;

	_itot_s(num3, ch3, 10);	//	将int型值存到字符数组中

	SetDlgItemText(IDC_EDIT3,ch3);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	
	int num1, num2, num3;

	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);
	num3 = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, num3);
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	/*前提是在界面上进行了控件和整型变量相关联的操作
		选中右击编辑栏控件，选择添加变量
		控件类别选择 value ，选择要转换的变量类型，并给一个变量名字，在头文件的类中会自动生成私有变量，
		并在构造函数中进行赋初值；  也可以对最小值和最大值进行设定
		会自动生成一个 DoDataExchange（）函数，对变量和控件之间进行关联，也可以自己写

		这个方法会对输入的字进行检查，不可以输入除整型以外的类型；
	*/
	UpdateData(TRUE);//当为true时，会执行控件关联变量，将控件上的值分别转换到 m_num2 , m_num1 上；

	m_num3 = m_num2 + m_num1;

	UpdateData(FALSE);//当为false时，会执行将变量关联到控件上，将m_num3的值给控件，进行输出；
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码

	/*前提是在界面上进行了控件和整型变量相关联的操作
	选中右击编辑栏控件，选择添加变量
	控件类别选择 Control ，变量类型根据需要选择，并给一个变量名字，
	在头文件的类中会自动生成私有变量，
	会自动生成一个 DoDataExchange（）函数，对变量和控件之间进行关联，也可以自己写

	这个方法会对输入的字进行检查，不可以输入除整型以外的类型；
	*/
	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];
	
	m_edit1.GetWindowTextW(ch1, 12);
	m_edit2.GetWindowTextW(ch2, 12);

	num1 = _ttoi(ch1);	//	将字符数组中的值转成int型
	num2 = _ttoi(ch2);	//	将字符数组中的值转成int型

	num3 = num1 + num2;

	_itot_s(num3, ch3, 10);	//	将int型值存到字符数组中

	m_edit3.SetWindowTextW(ch3);
}

void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO:  在此添加控件通知处理程序代码

	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];

	::SendMessage(GetDlgItem(IDC_EDIT1)->m_hWnd, WM_GETTEXT, 12,LPARAM(ch1));
	::SendMessage(GetDlgItem(IDC_EDIT2)->m_hWnd, WM_GETTEXT, 12, LPARAM(ch2));\
		/*
		函数原型编辑		LRESULT SendMessage（HWND hWnd，UINT Msg，WPARAM wParam，LPARAM IParam）
		参数
			hWnd：其窗口程序将接收消息的窗口的句柄。如果此参数为HWND_BROADCAST，则消息将被发送到系统中所有顶层窗口，包括无效或不可见的非自身拥有的窗口、被覆盖的窗口和弹出式窗口，但消息不被发送到子窗口。
			Msg：指定被发送的消息。
			wParam：指定附加的消息特定信息。
			IParam：指定附加的消息特定信息。
		返回值：返回值指定消息处理的结果，依赖于所发送的消息。
		备注：需要用HWND_BROADCAST通信的应用程序应当使用函数RegisterWindowMessage来为应用程序间的通信取得一个唯一的消息。*/

	num1 = _ttoi(ch1);
	num2 = _ttoi(ch2);
	num3 = num1 + num2;
	_itot_s(num3, ch3, 10);

	::SendMessage(GetDlgItem(IDC_EDIT3)->m_hWnd, WM_SETTEXT, 0, LPARAM(ch3));
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO:  在此添加控件通知处理程序代码
	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];

	SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 12, (LPARAM)ch1);
	SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 12, (LPARAM)ch2);
	/*对方法六的函数进行简化*/

	num1 = _ttoi(ch1);
	num2 = _ttoi(ch2);
	num3 = num1 + num2;
	_itot_s(num3, ch3, 10);

	SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3);
}
