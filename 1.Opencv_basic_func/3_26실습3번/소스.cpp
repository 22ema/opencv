#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat img8 = imread("C:/Users/ima_com/Desktop/image/1.jpg",IMREAD_COLOR);//�̹��� �ҷ�����
	CV_Assert(img8.data);//����ó��
	Mat img16, img32; // ����
	img8.convertTo(img16, CV_16U, 65535 / 255.0);// �̹����� float������ ��ȯ�Ѵ�.
	img8.convertTo(img32, CV_32F, 1 / 255.0f);//uchar���� ȭ�Ұ��� ������ float���� �°� 0~1������ ������ �����Ѵ�.

	Rect roi(10, 10, 3, 3);//���ɿ��� ����
	cout << "img8 ����� �Ϻ�" << endl << img8(roi) << endl << endl;
	cout << "img16 ����� �Ϻ�" << endl << img16(roi) << endl << endl;
	cout << "img32 ����� �Ϻ�" << endl << img32(roi) << endl << endl;

	imwrite("C:/Users/ima_com/Desktop/image/12.tif", img16);//�̹��� ����
	imwrite("C:/Users/ima_com/Desktop/image/123.tif", img32);
	imshow("img16", img16);// �̹��� �����ֱ�
	imshow("img32", img32);
	waitKey();
	return 0;



}