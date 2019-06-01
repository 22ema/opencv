#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

string title = "이벤트 그리기";// title 지정
Mat image;

void onMouse(int event, int x, int y, int flags, void *param) {
	static Point pt(-1, -1);
	if (event == EVENT_LBUTTONDOWN) {// 좌클릭을 누르면 이벤트 발생
		if (pt.x < 0) pt = Point(x, y);// 처음 좌표를 찍었을때
		else {// 두번째 좌표를 찍었을때 분기된다
			rectangle(image, pt, Point(x, y), Scalar(50), 2);// 처음 찍은 지점 두번째 찍은 지점으로 사각형 만들기
			imshow(title, image);// 이미지를 보여준다
			pt = Point(-1, -1);//초기화
		}
	}
	else if (event == EVENT_RBUTTONDOWN) {
		if (pt.x < 0) pt = Point(x, y);//처음 우클릭을 했을때 원의 중간을찍음
		else {// 두번째 좌표를 찍었을때 
			Point2d pt2 = pt - Point(x, y);//처음 찍은 좌표와 나중찍은 좌표를빼서 원의 반지름을 구한다.
			int radius = (int)sqrt(pt2.x *pt2.x + pt2.y*pt2.y);// 피타고라스 정리
			circle(image, pt, radius, Scalar(150), 2);// 위의 값을 통해 원을 그린다

			imshow(title, image);// 이미지를 출력한다
			pt = Point(-1, -1);// 좌표 초기화
		}
	}
}

int main() {
	image = Mat(300, 500, CV_8UC1, Scalar(255));
	imshow(title, image);
	setMouseCallback(title, onMouse, 0);

	waitKey(0);
	return 0;
}