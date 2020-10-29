
// DIPTeamProject_Team8Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DIPTeamProject_Team8.h"
#include "DIPTeamProject_Team8Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDIPTeamProjectTeam8Dlg 대화 상자



CDIPTeamProjectTeam8Dlg::CDIPTeamProjectTeam8Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIPTEAMPROJECT_TEAM8_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDIPTeamProjectTeam8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, mText1);
	DDX_Control(pDX, IDC_STATIC2, mText2);
	DDX_Control(pDX, IDC_STATIC3, mText3);
	DDX_Control(pDX, IDC_STATIC4, mText4);
}

BEGIN_MESSAGE_MAP(CDIPTeamProjectTeam8Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDIPTeamProjectTeam8Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDIPTeamProjectTeam8Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDIPTeamProjectTeam8Dlg 메시지 처리기

BOOL CDIPTeamProjectTeam8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDIPTeamProjectTeam8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDIPTeamProjectTeam8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

Mat CDIPTeamProjectTeam8Dlg::BlackWhite(Mat m_matImage) {
	int width = m_matImage.cols;
	int height = m_matImage.rows;
	int color, blue, green, red;
	Mat m_matImg = Mat::zeros(width, height, m_matImage.type());

	try {
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				blue = m_matImage.at<Vec3b>(x, y)[0];
				green = m_matImage.at<Vec3b>(x, y)[1];
				red = m_matImage.at<Vec3b>(x, y)[2];
				color = (blue + green + red) / 3;

				if (color > 90)
					m_matImg.at<Vec3b>(x, y) = Vec3b(255, 255, 255);
				
				else
					m_matImg.at<Vec3b>(x, y) = Vec3b(0, 0, 0);
				
			}
		}

	}
	
	catch (Exception ex) {
		printf("%s", ex.msg);
	}

	return m_matImg;
}

void CDIPTeamProjectTeam8Dlg::OnBnClickedButton1() {
	m_matImage1 = imread("C:\\input\\1.jpg", -1);
	CreateBitmapInfo(m_matImage1.cols, m_matImage1.rows);
	DrawImage(IDC_PIC_VIEW1);

	m_matImage2 = imread("C:\\input\\2.jpg", -1);
	CreateBitmapInfo(m_matImage2.cols, m_matImage2.rows);
	DrawImage(IDC_PIC_VIEW2);

	m_matImage3 = imread("C:\\input\\3.jpg", -1);
	CreateBitmapInfo(m_matImage3.cols, m_matImage3.rows);
	DrawImage(IDC_PIC_VIEW3);

	m_matImage4 = imread("C:\\input\\4.jpg", -1);
	CreateBitmapInfo(m_matImage4.cols, m_matImage4.rows);
	DrawImage(IDC_PIC_VIEW4);
}

void CDIPTeamProjectTeam8Dlg::CreateBitmapInfo(int w, int h) {
	if (m_pBitmapInfo != NULL) {
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
	//Height가 양수면 왼쪽 아래 코너부터 시작, 음수면 왼쪽 위 코너부터 시작
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = 24;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;
}

void CDIPTeamProjectTeam8Dlg::DrawImage(int id) {

	CClientDC dc(GetDlgItem(id));
	CRect rect;
	GetDlgItem(id)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);

	switch (id) {
	case IDC_PIC_VIEW1:
		StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage1.cols, m_matImage1.rows, m_matImage1.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
		break;
	case IDC_PIC_VIEW2:
		StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage2.cols, m_matImage2.rows, m_matImage2.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
		break;
	case IDC_PIC_VIEW3:
		StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage3.cols, m_matImage3.rows, m_matImage3.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
		break;
	case IDC_PIC_VIEW4:
		StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage4.cols, m_matImage4.rows, m_matImage4.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
		break;
	}
}

void CDIPTeamProjectTeam8Dlg::OnBnClickedButton2() {
	Distinguish(BlackWhite(m_matImage1), IDC_STATIC1);
	Distinguish(BlackWhite(m_matImage2), IDC_STATIC2);
	Distinguish(BlackWhite(m_matImage3), IDC_STATIC3);
	Distinguish(BlackWhite(m_matImage4), IDC_STATIC4);

	waitKey(0);
}

void CDIPTeamProjectTeam8Dlg::Distinguish(Mat m_matImage, int text) {
	int width = m_matImage.cols;
	int height = m_matImage.rows;
	int color;

	SetDlgItemText(text, _T("삼각형인가 사각형인가"));
}