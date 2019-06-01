#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;
int main()
{
	FileStorage fs_r("test.xml", FileStorage::READ);// xml �̹��� �ҷ�����
	CV_Assert(fs_r.isOpened());// xml ������ ��������? �ִ���? ����ó���ϴ� �κ�
	FileNode node_pic = fs_r["picture"];//������ picture ��� �ҷ�����

	vector<Mat> images; // images ��� ���� �迭 �����
	for (int i = 0; i < node_pic.size(); i++)// node_pic�� ���� ��ŭ �ݺ�
	{
		Mat tmp = imread("C:/image/" + (string)node_pic[i], IMREAD_UNCHANGED);// �̹��� �ҷ����� IMREAD_UNCHANGED�� ������ �״�� �ҷ�����
		CV_Assert(tmp.data);// ������ �������� �ִ��� ����ó�� �ϴ� �κ�
		images.push_back(tmp);// images�� tmp �߰� ��Ű��
		imshow(node_pic[i], images[i]);// �̹��� ���̱�
	}

	FileStorage fs_w("result.xml", FileStorage::WRITE);// ���� ���丮�� xml ���� �ۼ� 
	CV_Assert(fs_w.isOpened());//����ó�� �κ� ������� ������ false ���°� ��

	vector<double> mean, dev;//vector mean�� dev ����
	for (int i = 0; i < images.size(); i++) {//images�� �������� 3�� ��ŭ �ݺ�
		string pic_name = ((string)node_pic[i]).substr(0, 5);//mine1���� ������ (Ȯ���ڸ� ����)
		cout << pic_name << endl;// Ȯ���ϴ°� �� �ڵ�

		meanStdDev(images[i], mean, dev);//ǥ�������� ����� ���ϴ� ����
		fs_w << pic_name + "_mean" << "[";// ���������� ����� ��

		for (int j = 0; j < (int)mean.size(); j++) {
			fs_w << mean[i];
		}
		fs_w << "]";
		fs_w << pic_name + "_dev" << dev;
	}
	waitKey();
	fs_r.release();// �޸� �Ҵ� ����
	fs_w.release();//���� ����
	return 0;
}