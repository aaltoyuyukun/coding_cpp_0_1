#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void test01() {
	//-包含头文件 fstream

	//-创建输入流/输出流对象
	ofstream ofs;
	//-打开文件
	ofs.open("test.txt", ios::out);
	//-写/读文件
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	//-关闭文件
	ofs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}