#include<iostream>
using namespace std;
#include<string>

void test01(){
	string s1 = "ooo";
	cout << "str1 = " << s1 << endl;

	const char* str = "hello world";
	string s2(str);

	cout << "str2 = " << s2 << endl;

	string s3(s2);
	cout << "str3 = " << s3 << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}