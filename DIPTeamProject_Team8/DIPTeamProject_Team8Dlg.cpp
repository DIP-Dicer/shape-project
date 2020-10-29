
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

Mat CDIPTeamProjectTeam8Dlg::BlackWhite(Mat m_matImage) { //도형 부분을 검정색으로 바꾼 mat 이미지를 반환
	int width = m_matImage.cols;
	int height = m_matImage.rows;
	int color, blue, green, red;
	Mat m_matImg = Mat::zeros(height, width, m_matImage.type());

	for (int y = 0; y < width; y++) {
		for (int x = 0; x < height; x++) {
			blue = m_matImage.at<Vec3b>(x, y)[0];
			green = m_matImage.at<Vec3b>(x, y)[1];
			red = m_matImage.at<Vec3b>(x, y)[2];
			color = (blue + green + red) / 3;
				
			if (color > 180)
				m_matImg.at<Vec3b>(x, y) = Vec3b(255, 255, 255);
			else
				m_matImg.at<Vec3b>(x, y) = Vec3b(0, 0, 0);
		}
	}
	return m_matImg;
}

void CDIPTeamProjectTeam8Dlg::OnBnClickedButton1() { //첫번째 버튼 클릭하면 picture control에 이미지 출력
	m_matImage1 = imread("C:\\input\\1.jpg", -1);
	resize(m_matImage1, imgtemp1, Size(100, 100), 0, 0, 1);
	CreateBitmapInfo(imgtemp1.cols, imgtemp1.rows, imgtemp1.channels() * 8);
	DrawImage(IDC_PIC_VIEW1, imgtemp1);

	m_matImage2 = imread("C:\\input\\2.jpg", -1);
	resize(m_matImage2, imgtemp2, Size(100, 100), 0, 0, 1);
	CreateBitmapInfo(imgtemp2.cols, imgtemp2.rows, imgtemp2.channels() * 8);
	DrawImage(IDC_PIC_VIEW2, imgtemp2);

	m_matImage3 = imread("C:\\input\\3.jpg", -1);
	resize(m_matImage3, imgtemp3, Size(100, 100), 0, 0, 1);
	CreateBitmapInfo(imgtemp3.cols, imgtemp3.rows, imgtemp3.channels() * 8);
	DrawImage(IDC_PIC_VIEW3, imgtemp3);

	m_matImage4 = imread("C:\\input\\4.jpg", -1);
	resize(m_matImage4, imgtemp4, Size(100, 100), 0, 0, 1);
	CreateBitmapInfo(imgtemp4.cols, imgtemp4.rows, imgtemp4.channels() * 8);
	DrawImage(IDC_PIC_VIEW4, imgtemp4);
}

void CDIPTeamProjectTeam8Dlg::CreateBitmapInfo(int width, int height, int bpp) { //mat 이미지 별로 BITMAPINFO 구조체 생성
	if (m_pBitmapInfo != NULL) {
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	//bpp는 이미지 channel 말하는건데 1이면 컬러 채널이 1개(흑백)이구 3이면 컬러 채널 3개(RGB 값 다 있음)
	//사진 속성 보니까 대부분 채널이 3개인 것 같아서 처음에는 이 bpp를 아예 안썼었는데 혹시 이것때문에 오류인건가 싶어서 넣어봤어
	//근데 넣어도 사진 이상하게 출력되는건 똑같이 이상하게 출력되더라공??! 써볼거면 주석 풀어서 써방._.

	/*if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit*/
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)]; //이 변수는 DrawImage 함수에서 picture control에 이미지 로드할 때 사용됨

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biWidth = width;
	m_pBitmapInfo->bmiHeader.biHeight = -height; //Height가 양수면 왼쪽 아래 코너부터 시작, 음수면 왼쪽 위 코너부터 시작
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	/*if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}*/
}

void CDIPTeamProjectTeam8Dlg::DrawImage(int id, Mat m_matImage) { //각 Picture control에 이미지 띄움

	CClientDC dc(GetDlgItem(id));
	CRect rect;
	GetDlgItem(id)->GetClientRect(&rect);

	//SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	dc.SetStretchBltMode(COLORONCOLOR);

	for (int x = 0; x < 20; x++) { //이건 이미지 출력할 때 처음 좌표 볼라구 넣어놓은 거. 자꾸 오류나서!!ㅠ힝구
		for (int y = 0; y < 20; y++) {
			if (y<5)
				m_matImage.at<Vec3b>(x, y) = Vec3b(0, 0, 255); //빨강
			else
				m_matImage.at<Vec3b>(x, y) = Vec3b(255, 0, 0); //파랑
		}
	}

	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage.cols, m_matImage.rows, m_matImage.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	//Picture control의 왼쪽 아래 좌표가 (0, 0)이고 가로, 세로 길이가 각각 rect.Width()와 rect.Height()
	//Mat 이미지의 왼쪽 아래 좌표가 (0, 0)이고 가로, 세로 길이가 각각 m_matImage.cols, m_matImage.rows
}

void CDIPTeamProjectTeam8Dlg::OnBnClickedButton2() { //두번째 버튼 클릭하면 (색상값으로 0이나 255만 갖고 있는 Mat 이미지랑 text box를 파라미터로) Distinguish 함수 호출
	Distinguish(BlackWhite(m_matImage1), IDC_STATIC1);
	Distinguish(BlackWhite(m_matImage2), IDC_STATIC2);
	Distinguish(BlackWhite(m_matImage3), IDC_STATIC3);
	Distinguish(BlackWhite(m_matImage4), IDC_STATIC4);
}

void CDIPTeamProjectTeam8Dlg::Distinguish(Mat m_matImage, int text) { //삼각형 사각형 판별하기
	int width = m_matImage.cols;
	int height = m_matImage.rows;
	int color;

	//민지가 짠 코드 넣을 곳

	SetDlgItemText(text, _T("삼각형인가 사각형인가")); //삼각형/사각형 판별되면 static text box 텍스트 바꿈
}