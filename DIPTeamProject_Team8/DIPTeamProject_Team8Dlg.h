
// DIPTeamProject_Team8Dlg.h: 헤더 파일
//

#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>
using namespace cv;
using namespace std;


// CDIPTeamProjectTeam8Dlg 대화 상자
class CDIPTeamProjectTeam8Dlg : public CDialogEx
{
// 생성입니다.
public:
	CDIPTeamProjectTeam8Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIPTEAMPROJECT_TEAM8_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

public:
	Mat m_matImage1, m_matImage2, m_matImage3, m_matImage4; //이미지 정보를 담고 있는 객체
	Mat imgtemp1, imgtemp2, imgtemp3, imgtemp4;
	BITMAPINFO* m_pBitmapInfo; //Bitmap 정보를 담고 있는 구조체

	Mat BlackWhite(Mat m_matImage);
	void CreateBitmapInfo(int w, int h, int bpp); //Bitmap 정보를 생성하는 함수
	void DrawImage(int id, Mat m_matImage); //그리는 작업을 수행하는 함수
	void Distinguish(Mat m_matImage, int text);


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic mText1;
	CStatic mText2;
	CStatic mText3;
	CStatic mText4;
};
