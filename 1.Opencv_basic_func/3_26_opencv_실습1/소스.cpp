#include <opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

string title = "��� ����", bar_name = "��Ⱚ";// ������������
Mat image;//��ķ� image ��ļ���

void onChange(int value, void* userdata) {//Ʈ���ٸ� ������ ����� �����Լ� �ݹ��Լ� ���� 
	int add_value = value - 130;//��Ŀ� �߰��� ���� add_value�� �����ϰ� , Ʈ������ ������ �߰����� 130������.
	                            //Ʈ���ٰ� 0~255�� ������ �����⶧���� add_value�� -126~129�� ������ ������ �ȴ�.
	cout << "�߰� ȭ�Ұ�" << add_value << endl;//�߰� ȭ�Ұ� ���

	Mat tmp = image + add_value;// image ��Ŀ� add_value���� ���Ѵ�. ����� �����Ұ� Ʈ������ ���� ���� ���� ��������.
	                            //�������� ��� ���̷� ��ȭ�Ѵ�.
	imshow(title, tmp);         //�̹����� titleâ�� ����Ѵ�.


}
void onMouse(int event, int x, int y, int flags, void *param) {
	if (event == EVENT_RBUTTONDOWN) {//��Ŭ���� �������� �Ͼ�� �̺�Ʈ
		add(image, 10, image);//image �� ȭ�Ұ��� 10�� ���Ѵ�.
		setTrackbarPos(bar_name, title, image.at<uchar>(0));//Ʈ������ ��ġ�� �����Ѵ�.
		imshow(title, image);//�̹��� title â�� ����ϱ�
	}
	else if (event == EVENT_LBUTTONDOWN) {//��Ŭ���� �������� �Ͼ�� �̺�Ʈ
		subtract(image, 10, image);//image �� ȭ�Ұ��� 10�� ����.
		setTrackbarPos(bar_name, title, image.at<uchar>(0));// Ʈ������ ��ġ�� �����Ѵ�.
		imshow(title, image);// �̹���  title â�� ����ϱ�

	}
}

	int main()
	{
		int value = 130;//130���� ��������
		image = Mat(300, 500, CV_8UC1, Scalar(120));// image�� 300,500 ��ķ� ����

		namedWindow(title, WINDOW_AUTOSIZE);//â�� �̸��� ����� ����� �������� ���ϰ� ����
		createTrackbar(bar_name, title, &value, 255, onChange);//Ʈ���ٸ� �����ϰ�, �װ��� ������ ������â�� �߰��ϴ� �Լ��̴�.
		setMouseCallback(title, onMouse, 0);//����ڰ� ������ ���콺 �ݹ��Լ��� �ý��ۿ� �����ϴ� �Լ��̴�.
		
		imshow(title, image);//�̹��� ���
		waitKey(0);//�ƹ� Ű�� �Էµɶ����� �����ִ´�.
		return 0;
	}
 