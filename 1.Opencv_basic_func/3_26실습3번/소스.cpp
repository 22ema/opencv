#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img8 = imread("C:/Users/ima_com/Desktop/image/1.jpg",IMREAD_COLOR);//이미지 불러오기
	CV_Assert(img8.data);//예외처리
	Mat img16, img32; // 선언
	img8.convertTo(img16, CV_16U, 65535 / 255.0);// 이미지를 float형으로 변환한다.
	img8.convertTo(img32, CV_32F, 1 / 255.0f);//uchar형인 화소값의 범위를 float형에 맞게 0~1사이의 값으로 변경한다.

	Rect roi(10, 10, 3, 3);//관심영역 추출
	cout << "img8 행렬의 일부" << endl << img8(roi) << endl << endl;
	cout << "img16 행렬의 일부" << endl << img16(roi) << endl << endl;
	cout << "img32 행렬의 일부" << endl << img32(roi) << endl << endl;

	imwrite("C:/Users/ima_com/Desktop/image/12.tif", img16);//이미지 저장
	imwrite("C:/Users/ima_com/Desktop/image/123.tif", img32);
	imshow("img16", img16);// 이미지 보여주기
	imshow("img32", img32);
	waitKey();
	return 0;



}