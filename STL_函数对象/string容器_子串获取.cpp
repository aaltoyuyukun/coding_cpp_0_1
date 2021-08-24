#include<iostream>
#include<string>
using namespace std;

void test01() {
	string email = "yukun.yu@aalto.fi";
	int pos = email.find("@");
	string usrname = email.substr(0, pos);
	cout << "username: " << usrname << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}