#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void test01() {
	//-包含头文件
	//-定义输入/输出对象
	ifstream ifs;
	//-打开文件，并判断文件是否真实打开
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "打开文件失败" << endl;
		return;
	}
	//读取文件
	char c;
	while ((c = ifs.get()) != EOF) {  //EOF end of file
		cout << c;
	}
	//关闭文件
	ifs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}