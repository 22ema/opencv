#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	VideoCapture capture(0);//카메라 설정
	CV_Assert(capture.isOpened());// 예외처리

	double fps = 15.97;// fps설정
	int delay = cvRound(500.0 / fps);//딜레이 설정
	Size size(640, 480);// 화면 해상도
	int fourcc = VideoWriter::fourcc('D', 'X', '5', '0');//코덱

	capture.set(CAP_PROP_FRAME_WIDTH, size.width);//해상도 설정하기
	capture.set(CAP_PROP_FRAME_HEIGHT, size.height);//

	cout << "widht x height" << size << endl;
	cout << " VideoWriter::fourcc :" << fourcc << endl;
	cout << "delay" << delay << endl;
	cout << "fps : " << fps << endl;
	
	VideoWriter writer;//파일 쓰기
	writer.open("C:/image/video_file.avi", fourcc, fps, size);//파일작성
	CV_Assert(writer.isOpened());

	for (;;) {
		Mat frame;// 보여줄 영상
		Mat result;//저장할 영상
		capture >> frame;// capture는 frame으로 보여준다
		flip(frame, result, 1);//좌우반전
		writer << result;// writer는 좌우 반전해서 보여준다
		
		imshow("카메라 영상보기", frame);//frame으로 보여준다
		if (waitKey(delay) >= 0)
			break;
	}
	return 0;
}
