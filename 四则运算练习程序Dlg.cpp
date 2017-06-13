// 四则运算练习程序Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "四则运算练习程序.h"
#include "四则运算练习程序Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
float result=-1;
int 	m_zhengshu=0,m_cuoshu=0;
class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
	m_shizi = _T("");
	m_daan = 0;
	m_jieguo = _T("");
	m_zhengshu = 0;
	m_cuoshu = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Text(pDX, IDC_EDIT1, m_shizi);
	DDX_Text(pDX, IDC_EDIT2, m_daan);
	DDX_Text(pDX, IDC_EDIT3, m_jieguo);
	DDX_Text(pDX, IDC_EDIT4, m_zhengshu);
	DDX_Text(pDX, IDC_EDIT5, m_cuoshu);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	while(1){
	srand(time(0));
	result=-1;
	int n,num[7],j=0,i=0;
	char operation[5],s[50];
	int flag=0;
	char exp[50];					//做栈使用
	char postexp[50];			//后缀表达式
	float st[50];					//数值栈
	char ch;
	int top=-1;
	for(j=1;j<=4;j++)
	{
		n=rand()%10;
		num[j]=n;
	}
	for(j=1;j<=3;j++)
	{
		n=rand()%3;
    	switch(n)
		{
          	case 0:operation[j]='+';break;
        	case 1:operation[j]='-';break;
			case 2:operation[j]='*';break;
			default:operation[j]='/';
		}
	}
	n=rand()%6;
	switch(n)						//生产成随机式子部分 
	{
	case 0:
		s[0]=char(num[1]+'0');
		s[1]=operation[1];
		s[2]=char(num[2]+'0');
		s[3]=operation[2];
		s[4]=char(num[3]+'0');
		s[5]=operation[3];
		s[6]=char(num[4]+'0');
		s[7]='\0';
		break;
	case 1:
		s[0]='(';
		s[1]=char(num[1]+'0');
		s[2]=operation[1];
		s[3]=char(num[2]+'0');
		s[4]=operation[2];
		s[5]=char(num[3]+'0');
		s[6]=')';
		s[7]=operation[3];
		s[8]=char(num[4]+'0');
		s[9]='\0';
		break;
	case 2:
		s[0]=char(num[1]+'0');
		s[1]=operation[1];
		s[2]='(';
		s[3]=char(num[2]+'0');
		s[4]=operation[2];
		s[5]=char(num[3]+'0');
		s[6]=operation[3];
		s[7]=char(num[4]+'0');
		s[8]=')';
		s[9]='\0';
		break;
	case 3:
		s[0]='(';
		s[1]=char(num[1]+'0');
		s[2]=operation[1];
		s[3]=char(num[2]+'0');
		s[4]=')';
		s[5]=operation[2];
		s[6]=char(num[3]+'0');
		s[7]=operation[3];
		s[8]=char(num[4]+'0');
		s[9]='\0';
		break;
	case 4:
		s[0]=char(num[1]+'0');
		s[1]=operation[1];
		s[2]=char(num[2]+'0');
		s[3]=operation[2];
		s[4]='(';
		s[5]=char(num[3]+'0');
		s[6]=operation[3];
		s[7]=char(num[4]+'0');
		s[8]=')';
		s[9]='\0';
		break;
	default:
		s[0]='(';
		s[1]=char(num[1]+'0');
		s[2]=operation[1];
		s[3]=char(num[2]+'0');
		s[4]=')';
		s[5]=operation[2];
		s[6]='(';
		s[7]=char(num[3]+'0');
		s[8]=operation[3];
		s[9]=char(num[4]+'0');
		s[10]=')';
		s[11]='\0';
		break;
	}
	for(i=0;i<strlen(s);i++)			//将中缀表达式转化为后缀表达式
	{
		ch=s[i];
		if(ch=='(')						//左括号
		{
			top++;
			exp[top]=ch;
			continue;
			
		}
		else if(ch==')')				//若遇到右括弧“）”，则连续出栈输出，直到遇到左括弧“（”为止。其中，左括弧出栈但是并不输出 
		{
			while(exp[top]!='(')
			{
				postexp[j]=exp[top];
				top--;
				j++;
			}
			top--;
			continue;
		}
		else if(ch=='+'||ch=='-')		//为'+'或'-'时，其优先级不大于栈顶任何运算符的优先级，直到')' 
		{
			while(top!=-1&&exp[top]!='(')
			{
				postexp[j]=exp[top];
				top--;
				j++;
			}
			top++;
			exp[top]=ch;
			continue;
		}
		else if(ch=='*'||ch=='/')		//为'*'或'/'时，其优先级不大于栈顶为'*'或'/'的优先级，直到')'  
		{
			while(top!=-1&&exp[top]!='('&&(exp[top]=='*'||exp[top]=='/'))
			{
				postexp[j]=exp[top];
				j++;
				top--;
			}
			top++;
			exp[top]=ch;
			continue;
		}
		else if(ch>='0'&&ch<='9')		//为数字，直接存入
		{
			postexp[j]=ch;
			j++;
			continue;
		}
		else
		{
			continue;
		}
	}
	while(top!=-1)
	{
		postexp[j]=exp[top];
		j++;
		top--;
	}
	postexp[j]='\0';
	top=-1;
	for(i=0;i<strlen(postexp);i++)			//计算后缀表达式 
	{
		ch=postexp[i];
		if(ch=='+')							//遇到操作符就弹出两个数 并将结果进栈   
		{
			st[top-1]=st[top-1]+st[top];
			top--;
		}
		if(ch=='-')
		{
			st[top-1]=st[top-1]-st[top];
			top--;
		}
		if(ch=='*')
		{
			st[top-1]=st[top-1]*st[top];
			top--;
		}
		if(ch=='/')
		{
			if(st[top]==0)			//防止出现除数为0的情况
			{
				flag=1;
				break;
			}
			else
			{
				st[top-1]=st[top-1]/st[top];
				top--;
			}
		}
		if(ch>='0'&&ch<='9')
		{
			top++;
			st[top]=ch-'0';	
		}
	}
	if(flag==0)
	{
		result=st[top];			//若未出现除数为0的情况，则栈顶元素即为式子结果
		int test;
		test=result;
		if(test==result&&result>=0)
		{
			i=strlen(s);
			s[i]='=';
			s[i+1]='\0';
			m_shizi=s;
			break;
		}
	}
	else
	{
		result=-1;
	}
	}
	UpdateData(FALSE);
}

void CMyDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	char r[10];
	char temp[50]="答案错误！正确答案是：";
	if(m_daan==result)
	{
		m_zhengshu++;
		m_jieguo="答案正确！";
	}
	else
	{
		m_cuoshu++;
		sprintf(r,"%.0f",result);
		strcat(temp,r);
		m_jieguo=temp;

	}
	UpdateData(FALSE);
}
