#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Person {
public:
	char m_Name[64];
	int age;
};

void test01() {
	//-ͷ�ļ�
	//-���ļ�
	ifstream ifs;
	ifs.open("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
}

int main() {
	test01();
	system("pause");
	return 0;
}