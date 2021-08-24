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
	//-包含头文件
	//-创建输出流对象
	ofstream ofs("Person.txt", ios::out | ios::binary);
	//-打开文件
	Person p = {"zhangsan", 18};
	//-写文件
	ofs.write((const char*)&p, sizeof(p));
	//-关闭文件
	ofs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}