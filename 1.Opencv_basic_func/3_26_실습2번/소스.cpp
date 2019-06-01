#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

string title = "�̺�Ʈ �׸���";// title ����
Mat image;

void onMouse(int event, int x, int y, int flags, void *param) {
	static Point pt(-1, -1);
	if (event == EVENT_LBUTTONDOWN) {// ��Ŭ���� ������ �̺�Ʈ �߻�
		if (pt.x < 0) pt = Point(x, y);// ó�� ��ǥ�� �������
		else {// �ι�° ��ǥ�� ������� �б�ȴ�
			rectangle(image, pt, Point(x, y), Scalar(50), 2);// ó�� ���� ���� �ι�° ���� �������� �簢�� �����
			imshow(title, image);// �̹����� �����ش�
			pt = Point(-1, -1);//�ʱ�ȭ
		}
	}
	else if (event == EVENT_RBUTTONDOWN) {
		if (pt.x < 0) pt = Point(x, y);//ó�� ��Ŭ���� ������ ���� �߰�������
		else {// �ι�° ��ǥ�� ������� 
			Point2d pt2 = pt - Point(x, y);//ó�� ���� ��ǥ�� �������� ��ǥ������ ���� �������� ���Ѵ�.
			int radius = (int)sqrt(pt2.x *pt2.x + pt2.y*pt2.y);// ��Ÿ��� ����
			circle(image, pt, radius, Scalar(150), 2);// ���� ���� ���� ���� �׸���

			imshow(title, image);// �̹����� ����Ѵ�
			pt = Point(-1, -1);// ��ǥ �ʱ�ȭ
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