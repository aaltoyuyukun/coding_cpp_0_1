#include<iostream>
#include<string>
using namespace std;

class Base {
public:
	virtual void func() = 0;
};

class Son :public Base {
public:
	virtual void func() {
		cout << "func调用" << endl;
	}
};

void test01() {
	Base* base = NULL;	//创建base堆区，大小为1
	//base = new Base;
	base = new Son;
	base->func();
	delete base;
}

int main() {
	test01();
	system("pause");
	return 0;
}