#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	Mat image1;
	image1 = imread("c:/image/mine1.jpg",1);
	CV_Assert(image1.data);// 예외처리
	FileStorage fl_w("test1.xml", FileStorage::WRITE);



	fl_w << "image_size" << image1.size();
	fl_w << "depth" << image1.depth();
	fl_w << "image_data" << image1;
	fl_w.release();
	return 0;
	

}