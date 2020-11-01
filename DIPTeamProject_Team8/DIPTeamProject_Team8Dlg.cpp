#include "pch.h"
#include "framework.h"
#include "DIPTeamProject_Team8.h"
#include "DIPTeamProject_Team8Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

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
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

BOOL CDIPTeamProjectTeam8Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return TRUE;
}

void CDIPTeamProjectTeam8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);
		
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

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

void CDIPTeamProjectTeam8Dlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI) {
	lpMMI->ptMinTrackSize.x = 710;
	lpMMI->ptMinTrackSize.y = 635;
	lpMMI->ptMaxTrackSize.x = 745;
	lpMMI->ptMaxTrackSize.y = 666;
}

void CDIPTeamProjectTeam8Dlg::OnBnClickedButton1() { //첫번째 버튼 클릭하면 picture control에 이미지 출력
	int imgSize = 400;

	m_matImage1 = imread("C:\\input\\1.jpg", -1);
	resize(m_matImage1, m_matImageTemp1, Size(imgSize, imgSize), 0, 0, 1);
	CreateBitmapInfo(m_matImageTemp1.cols, m_matImageTemp1.rows);
	DrawImage(IDC_PIC_VIEW1, m_matImageTemp1);

	m_matImage2 = imread("C:\\input\\2.jpg", -1);
	resize(m_matImage2, m_matImageTemp2, Size(imgSize, imgSize), 0, 0, 1);
	CreateBitmapInfo(m_matImageTemp2.cols, m_matImageTemp2.rows);
	DrawImage(IDC_PIC_VIEW2, m_matImageTemp2);

	m_matImage3 = imread("C:\\input\\3.jpg", -1);
	resize(m_matImage3, m_matImageTemp3, Size(imgSize, imgSize), 0, 0, 1);
	CreateBitmapInfo(m_matImageTemp3.cols, m_matImageTemp3.rows);
	DrawImage(IDC_PIC_VIEW3, m_matImageTemp3);

	m_matImage4 = imread("C:\\input\\4.jpg", -1);
	resize(m_matImage4, m_matImageTemp4, Size(imgSize, imgSize), 0, 0, 1);
	CreateBitmapInfo(m_matImageTemp4.cols, m_matImageTemp4.rows);
	DrawImage(IDC_PIC_VIEW4, m_matImageTemp4);
}

void CDIPTeamProjectTeam8Dlg::CreateBitmapInfo(int width, int height) { //mat 이미지 별로 BITMAPINFO 구조체 생성
	if (m_pBitmapInfo != NULL) {
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)]; //이 변수는 DrawImage 함수에서 picture control에 이미지 로드할 때 사용됨

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biWidth = width;
	m_pBitmapInfo->bmiHeader.biHeight = -height;
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = 24;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;
}

void CDIPTeamProjectTeam8Dlg::DrawImage(int id, Mat m_matImage) { //각 Picture control에 이미지 띄움
	CClientDC dc(GetDlgItem(id));
	CRect rect;
	GetDlgItem(id)->GetClientRect(&rect);

	dc.SetStretchBltMode(COLORONCOLOR);

	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage.cols, m_matImage.rows, m_matImage.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}

void CDIPTeamProjectTeam8Dlg::OnBnClickedButton2() { //두번째 버튼 클릭하면 (색상값으로 0이나 255만 갖고 있는 Mat 이미지랑 text box를 파라미터로) Distinguish 함수 호출
	Distinguish(BlackWhite(m_matImageTemp1), IDC_STATIC1);
	Distinguish(BlackWhite(m_matImageTemp2), IDC_STATIC2);
	Distinguish(BlackWhite(m_matImageTemp3), IDC_STATIC3);
	Distinguish(BlackWhite(m_matImageTemp4), IDC_STATIC4);
}

void CDIPTeamProjectTeam8Dlg::Distinguish(Mat m_matImage, int text) { //삼각형 사각형 판별하기
	int width = m_matImage.cols;
	int height = m_matImage.rows;
	int color;

	int minX = width - 1;
	int minY = height - 1;
	int maxX = 0;
	int maxY = 0;

	//triangle, square를 구성하는 pixel중 x의 최소/최대, y의 최소/최대 찾음.
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			color = m_matImage.at<Vec3b>(x, y)[0];

			if (color == 0) {
				if (x < minX) {
					minX = x;
				}
				if (x > maxX) {
					maxX = x;
				}
				if (y < minY) {
					minY = y;
				}
				if (y > maxY) {
					maxY = y;
				}
			}
		}
	}

	//한 픽셀 정도는 뭉뚝할 수 있으므로, 그런 경우의 처리를 위해.
	int dx[] = { 0,0,0,1,-1,1,-1,1,-1 };
	int dy[] = { 0,1,-1,0,0,1,1,-1,-1 };

	vector<pair<int, int>> comb = { {minX, minY}, {minX, maxY}, {maxX, minY}, {maxX, maxY} };

	for (auto &p : comb) {
		int cx = p.first;
		int cy = p.second;
		for (int i = 0; i < 9; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			int temp;
			if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
				temp = m_matImage.at<Vec3b>(nx, ny)[0];
				if (temp == 0) {
					m_matImage.at<Vec3b>(cx, cy)[0] = 0;
					break;
				}
			}
		}
	}
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int color = m_matImage.at<Vec3b>(comb[i].first, comb[i].second)[0];
		if (color == 0) {
			cnt++;
		}
		else if (color == 255) {
			cnt--;
		}
	}

	if (cnt == 4 || cnt == -4) {
		SetDlgItemText(text, _T("square")); //삼각형/사각형 판별되면 static text box 텍스트 바꿈
	}
	else {
		SetDlgItemText(text, _T("triangle"));
	}
}