#include <opencv2/opencv.hpp>
#include<iostream>
#include<conio.h>
using namespace cv;
using namespace std;


int main() {
	Mat image(200, 300, CV_8U, Scalar(255));
	namedWindow("키보드 이벤트", WINDOW_AUTOSIZE);
	while (true) {
		
		/*int key = waitKey(100);
		if (key == 27) break;
		if(key==224){
			key = waitKey(100);
			switch (key)
			{
			case 72 : cout << "왼쪽키입력" << endl; break;
			case 75: cout << "오른쪽키입력" << endl; break;
			case 77: cout << "위쪽키입력" << endl; break;
			case 80: cout << "아래쪽키입력" << endl; break;

			}

		}
		else {
			switch (key)
			{
			case 'a': cout << "a키입력" << endl; break;
			case 'b': cout << "b키입력" << endl; break;
			case 0x41: cout << "A키입력" << endl; break;
			case 66: cout << "B키입력" << endl; break;

			}
		}*/
		int ninput = waitKeyEx();
		cout << "문자:" << (char)ninput << ",아스키코드" << ninput << endl;
	}
	return 0;
}