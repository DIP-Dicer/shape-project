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

public:
	CDIPTeamProjectTeam8Dlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIPTEAMPROJECT_TEAM8_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);

public:
	Mat m_matImage1, m_matImage2, m_matImage3, m_matImage4;
	Mat m_matImageTemp1, m_matImageTemp2, m_matImageTemp3, m_matImageTemp4;
	BITMAPINFO* m_pBitmapInfo;

	Mat BlackWhite(Mat m_matImage);
	void CreateBitmapInfo(int w, int h);
	void DrawImage(int id, Mat m_matImage);
	void Distinguish(Mat m_matImage, int text);

protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CStatic mText1, mText2, mText3, mText4;
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};
