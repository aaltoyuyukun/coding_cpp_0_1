#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person {
public:
	char m_Name[64];
	int m_Age;
};

void test01() {
	//-����ͷ�ļ�
	//-�������������
	ofstream ofs("Person.txt", ios::out | ios::binary);
	//-���ļ�
	Person p = {"zhangsan", 18};
	//-д�ļ�
	ofs.write((const char*)&p, sizeof(p));
	//-�ر��ļ�
	ofs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}