#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void test01() {
	//-����ͷ�ļ�
	//-��������/�������
	ifstream ifs;
	//-���ļ������ж��ļ��Ƿ���ʵ��
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	//��ȡ�ļ�
	char c;
	while ((c = ifs.get()) != EOF) {  //EOF end of file
		cout << c;
	}
	//�ر��ļ�
	ifs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}