#include<iostream>
#include<string>
using namespace std;

class Base {
public:
	Base() {
		m_A = 100;
	}
	void func() {
		cout << "Base - func()调用" << endl;
	}
	void func(int a) {
		cout << "Base - func(int a)调用" << endl;
	}

public:
	int m_A;
};

class Son : public Base {
public:
	Son() {
		m_A = 200;
	}
	void func() {
		cout << "Son - func()调用" << endl;
	}
public:
	int m_A;
};

void test01() {
	Son s;
	cout << "Son下的m_A = " << s.m_A << endl;
	cout << "Base下的m_A = " << s.Base::m_A << endl;
	s.func();
	s.Base::func();
	s.Base::func(10);
}

int main() {
	test01();
	system("pause");
	return 0;
	return EXIT_SUCCESS;
}