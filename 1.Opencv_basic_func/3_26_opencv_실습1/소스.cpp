#include <opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

string title = "밝기 변경", bar_name = "밝기값";// 전역변수지정
Mat image;//행렬로 image 행렬선언

void onChange(int value, void* userdata) {//트랙바를 제어할 사용자 정의함수 콜백함수 구현 
	int add_value = value - 130;//행렬에 추가할 값을 add_value로 선언하고 , 트랙바의 값에서 중간값인 130을뺀다.
	                            //트랙바가 0~255의 범위를 가지기때문에 add_value는 -126~129의 범위를 가지게 된다.
	cout << "추가 화소값" << add_value << endl;//추가 화소값 출력

	Mat tmp = image + add_value;// image 행렬에 add_value값을 더한다. 행렬의 모든원소가 트랙바의 값에 따라 값이 더해진다.
	                            //검은색과 흰색 사이로 변화한다.
	imshow(title, tmp);         //이미지를 title창에 출력한다.


}
void onMouse(int event, int x, int y, int flags, void *param) {
	if (event == EVENT_RBUTTONDOWN) {//우클릭을 눌렀을때 일어나는 이벤트
		add(image, 10, image);//image 의 화소값에 10을 더한다.
		setTrackbarPos(bar_name, title, image.at<uchar>(0));//트랙바의 위치를 변경한다.
		imshow(title, image);//이미지 title 창에 출력하기
	}
	else if (event == EVENT_LBUTTONDOWN) {//좌클릭을 눌렀을때 일어나는 이벤트
		subtract(image, 10, image);//image 의 화소값에 10을 뺀다.
		setTrackbarPos(bar_name, title, image.at<uchar>(0));// 트랙바의 위치를 변경한다.
		imshow(title, image);// 이미지  title 창에 출력하기

	}
}

	int main()
	{
		int value = 130;//130으로 변수지정
		image = Mat(300, 500, CV_8UC1, Scalar(120));// image를 300,500 행렬로 지정

		namedWindow(title, WINDOW_AUTOSIZE);//창의 이름을 만들되 사이즈를 변경하지 못하게 설정
		createTrackbar(bar_name, title, &value, 255, onChange);//트랙바를 생성하고, 그것을 지정된 윈도우창에 추가하는 함수이다.
		setMouseCallback(title, onMouse, 0);//사용자가 정의한 마우스 콜백함수를 시스템에 저장하는 함수이다.
		
		imshow(title, image);//이미지 출력
		waitKey(0);//아무 키나 입력될때까지 켜져있는다.
		return 0;
	}
 