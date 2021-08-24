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
	//-头文件
	//-打开文件
	ifstream ifs;
	ifs.open("Person.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "打开文件失败" << endl;
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