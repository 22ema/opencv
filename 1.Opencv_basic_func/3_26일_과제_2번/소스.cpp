#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	VideoCapture capture(0);//ī�޶� ����
	CV_Assert(capture.isOpened());// ����ó��

	double fps = 15.97;// fps����
	int delay = cvRound(500.0 / fps);//������ ����
	Size size(640, 480);// ȭ�� �ػ�
	int fourcc = VideoWriter::fourcc('D', 'X', '5', '0');//�ڵ�

	capture.set(CAP_PROP_FRAME_WIDTH, size.width);//�ػ� �����ϱ�
	capture.set(CAP_PROP_FRAME_HEIGHT, size.height);//

	cout << "widht x height" << size << endl;
	cout << " VideoWriter::fourcc :" << fourcc << endl;
	cout << "delay" << delay << endl;
	cout << "fps : " << fps << endl;
	
	VideoWriter writer;//���� ����
	writer.open("C:/image/video_file.avi", fourcc, fps, size);//�����ۼ�
	CV_Assert(writer.isOpened());

	for (;;) {
		Mat frame;// ������ ����
		Mat result;//������ ����
		capture >> frame;// capture�� frame���� �����ش�
		flip(frame, result, 1);//�¿����
		writer << result;// writer�� �¿� �����ؼ� �����ش�
		
		imshow("ī�޶� ���󺸱�", frame);//frame���� �����ش�
		if (waitKey(delay) >= 0)
			break;
	}
	return 0;
}
