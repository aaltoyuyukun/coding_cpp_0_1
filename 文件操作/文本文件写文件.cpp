#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void test01() {
	//-����ͷ�ļ� fstream

	//-����������/���������
	ofstream ofs;
	//-���ļ�
	ofs.open("test.txt", ios::out);
	//-д/���ļ�
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	//-�ر��ļ�
	ofs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}