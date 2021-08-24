#include<iostream>
#include<string>
using namespace std;

class Base {
public:
	static int m_A;
	static void func() {
		cout << "Base - static void func()" << endl;
	}
	static void func(int a) {
		cout << "Base - static void func(int a)" << endl;
	}
};

int Base::m_A = 100;

class Son: public Base {
public:
	static int m_A;
	static void func() {
		cout << "Son - static void func()" << endl;
	}
};

int Son::m_A = 200;

void test01() {
	cout << "通过对象访问:" << endl;
	Son s;
	cout << "子类 m_A," << s.m_A << endl;
	cout << "父类 m_A," << s.Base::m_A << endl;

	cout << "通过类名访问" << endl;
	cout << "Son下m_A = " << Son::m_A << endl;
	cout << "Base下m_A = " << Son::Base::m_A << endl;
}

void test02() {
	cout << "通过对象访问" << endl;
	Son s;
	s.func();
	s.Base::func();

	cout << "通过类名访问" << endl;
	Son::func();
	Son::Base::func();
	Son::Base::func(100);
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}