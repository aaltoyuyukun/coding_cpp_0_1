#include<iostream>
#include<string>
using namespace std;

void test01() {
	/*string s1 = "hello";
	string s2 = "aello";

	int ret = s1.compare(s2);
	if (ret == 0) {
		cout << "s1等于s2" << endl;
	}
	else if (ret > 0) {
		cout << "s1大于s2" << endl;
	}
	else {
		cout << "s2小于s2" << endl;
	}*/

	//1、通过 []访问单个字符
	string str = "hello";
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	}
	cout << endl;

	//2、通过at方式访问单个字符
	string str1 = "hellostr1";
	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	}
	cout << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}