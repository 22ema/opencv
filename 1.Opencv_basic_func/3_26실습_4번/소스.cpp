#include <opencv2/opencv.hpp>
#include<iostream>
#include<conio.h>
using namespace cv;
using namespace std;


int main() {
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("Ű���� �̺�Ʈ", WINDOW_AUTOSIZE);
	while (true) {
		
		/*int key = waitKey(100);
		if (key == 27) break;
		if(key==224){
			key = waitKey(100);
			switch (key)
			{
			case 72 : cout << "����Ű�Է�" << endl; break;
			case 75: cout << "������Ű�Է�" << endl; break;
			case 77: cout << "����Ű�Է�" << endl; break;
			case 80: cout << "�Ʒ���Ű�Է�" << endl; break;

			}

		}
		else {
			switch (key)
			{
			case 'a': cout << "aŰ�Է�" << endl; break;
			case 'b': cout << "bŰ�Է�" << endl; break;
			case 0x41: cout << "AŰ�Է�" << endl; break;
			case 66: cout << "BŰ�Է�" << endl; break;

			}
		}*/
		int ninput = waitKeyEx();
		cout << "����:" << (char)ninput << ",�ƽ�Ű�ڵ�" << ninput << endl;
	}
	return 0;
}