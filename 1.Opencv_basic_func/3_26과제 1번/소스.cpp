#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	FileStorage fs_r("test.xml", FileStorage::READ);// xml 이미지 불러오기
	CV_Assert(fs_r.isOpened());// xml 파일이 열리는지? 있는지? 예외처리하는 부분
	FileNode node_pic = fs_r["picture"];//시퀀스 picture 노드 불러오기

	vector<Mat> images; // images 라는 백터 배열 만들기
	for (int i = 0; i < node_pic.size(); i++)// node_pic의 개수 만큼 반복
	{
		Mat tmp = imread("C:/image/" + (string)node_pic[i], IMREAD_UNCHANGED);// 이미지 불러오기 IMREAD_UNCHANGED는 그파일 그대로 불러오기
		CV_Assert(tmp.data);// 파일이 열리는지 있는지 예외처리 하는 부분
		images.push_back(tmp);// images에 tmp 추가 시키기
		imshow(node_pic[i], images[i]);// 이미지 보이기
	}

	FileStorage fs_w("result.xml", FileStorage::WRITE);// 파일 스토리지 xml 파일 작성 
	CV_Assert(fs_w.isOpened());//예외처리 부분 실행되지 않으면 false 상태가 됨

	vector<double> mean, dev;//vector mean과 dev 선언
	for (int i = 0; i < images.size(); i++) {//images의 사이즈인 3번 만큼 반복
		string pic_name = ((string)node_pic[i]).substr(0, 5);//mine1까지 들고오기 (확장자명 제거)
		cout << pic_name << endl;// 확인하는겸 쓴 코딩

		meanStdDev(images[i], mean, dev);//표준편차와 평균을 구하는 공식
		fs_w << pic_name + "_mean" << "[";// 시퀀스노드로 만드는 것

		for (int j = 0; j < (int)mean.size(); j++) {
			fs_w << mean[i];
		}
		fs_w << "]";
		fs_w << pic_name + "_dev" << dev;
	}
	waitKey();
	fs_r.release();// 메모리 할당 제거
	fs_w.release();//이하 동문
	return 0;
}