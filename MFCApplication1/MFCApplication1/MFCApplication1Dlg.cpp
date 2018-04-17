
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCApplication1Dlg �Ի���



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


// CMFCApplication1Dlg ��Ϣ�������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];

	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 12);
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 12);

	num1 = _ttoi(ch1); //	���ַ������е�ֵת��int��
	num2 = _ttoi(ch2); //	���ַ������е�ֵת��int��

	num3 = num1 + num2;

	_itot_s(num3, ch3, 10);	//	��int��ֵ�浽�ַ�������
	GetDlgItem(IDC_EDIT3)->SetWindowText(ch3);

}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];

	GetDlgItemText(IDC_EDIT1,ch1, 12);
	GetDlgItemText(IDC_EDIT2,ch2, 12);

	num1 = _ttoi(ch1);	//	���ַ������е�ֵת��int��
	num2 = _ttoi(ch2);	//	���ַ������е�ֵת��int��

	num3 = num1 + num2;

	_itot_s(num3, ch3, 10);	//	��int��ֵ�浽�ַ�������

	SetDlgItemText(IDC_EDIT3,ch3);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	int num1, num2, num3;

	num1 = GetDlgItemInt(IDC_EDIT1);
	num2 = GetDlgItemInt(IDC_EDIT2);
	num3 = num1 + num2;
	SetDlgItemInt(IDC_EDIT3, num3);
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	/*ǰ�����ڽ����Ͻ����˿ؼ������ͱ���������Ĳ���
		ѡ���һ��༭���ؼ���ѡ����ӱ���
		�ؼ����ѡ�� value ��ѡ��Ҫת���ı������ͣ�����һ���������֣���ͷ�ļ������л��Զ�����˽�б�����
		���ڹ��캯���н��и���ֵ��  Ҳ���Զ���Сֵ�����ֵ�����趨
		���Զ�����һ�� DoDataExchange�����������Ա����Ϳؼ�֮����й�����Ҳ�����Լ�д

		����������������ֽ��м�飬�����������������������ͣ�
	*/
	UpdateData(TRUE);//��Ϊtrueʱ����ִ�пؼ��������������ؼ��ϵ�ֵ�ֱ�ת���� m_num2 , m_num1 �ϣ�

	m_num3 = m_num2 + m_num1;

	UpdateData(FALSE);//��Ϊfalseʱ����ִ�н������������ؼ��ϣ���m_num3��ֵ���ؼ������������
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	/*ǰ�����ڽ����Ͻ����˿ؼ������ͱ���������Ĳ���
	ѡ���һ��༭���ؼ���ѡ����ӱ���
	�ؼ����ѡ�� Control ���������͸�����Ҫѡ�񣬲���һ���������֣�
	��ͷ�ļ������л��Զ�����˽�б�����
	���Զ�����һ�� DoDataExchange�����������Ա����Ϳؼ�֮����й�����Ҳ�����Լ�д

	����������������ֽ��м�飬�����������������������ͣ�
	*/
	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];
	
	m_edit1.GetWindowTextW(ch1, 12);
	m_edit2.GetWindowTextW(ch2, 12);

	num1 = _ttoi(ch1);	//	���ַ������е�ֵת��int��
	num2 = _ttoi(ch2);	//	���ַ������е�ֵת��int��

	num3 = num1 + num2;

	_itot_s(num3, ch3, 10);	//	��int��ֵ�浽�ַ�������

	m_edit3.SetWindowTextW(ch3);
}

void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];

	::SendMessage(GetDlgItem(IDC_EDIT1)->m_hWnd, WM_GETTEXT, 12,LPARAM(ch1));
	::SendMessage(GetDlgItem(IDC_EDIT2)->m_hWnd, WM_GETTEXT, 12, LPARAM(ch2));\
		/*
		����ԭ�ͱ༭		LRESULT SendMessage��HWND hWnd��UINT Msg��WPARAM wParam��LPARAM IParam��
		����
			hWnd���䴰�ڳ��򽫽�����Ϣ�Ĵ��ڵľ��������˲���ΪHWND_BROADCAST������Ϣ�������͵�ϵͳ�����ж��㴰�ڣ�������Ч�򲻿ɼ��ķ�����ӵ�еĴ��ڡ������ǵĴ��ں͵���ʽ���ڣ�����Ϣ�������͵��Ӵ��ڡ�
			Msg��ָ�������͵���Ϣ��
			wParam��ָ�����ӵ���Ϣ�ض���Ϣ��
			IParam��ָ�����ӵ���Ϣ�ض���Ϣ��
		����ֵ������ֵָ����Ϣ����Ľ���������������͵���Ϣ��
		��ע����Ҫ��HWND_BROADCASTͨ�ŵ�Ӧ�ó���Ӧ��ʹ�ú���RegisterWindowMessage��ΪӦ�ó�����ͨ��ȡ��һ��Ψһ����Ϣ��*/

	num1 = _ttoi(ch1);
	num2 = _ttoi(ch2);
	num3 = num1 + num2;
	_itot_s(num3, ch3, 10);

	::SendMessage(GetDlgItem(IDC_EDIT3)->m_hWnd, WM_SETTEXT, 0, LPARAM(ch3));
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int num1, num2, num3;
	TCHAR ch1[12], ch2[12], ch3[12];

	SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 12, (LPARAM)ch1);
	SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 12, (LPARAM)ch2);
	/*�Է������ĺ������м�*/

	num1 = _ttoi(ch1);
	num2 = _ttoi(ch2);
	num3 = num1 + num2;
	_itot_s(num3, ch3, 10);

	SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 0, (LPARAM)ch3);
}
