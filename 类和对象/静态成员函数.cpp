#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	static void func() {
		cout << "func调用" << endl;
		cout << "m_A:" << m_A << endl;
		m_A = 100;
	}

	static int m_A;
	//int m_B;

private:
	static void func2() {
		cout << "func2调用" << endl;
	}
};
int Person::m_A = 10;

void test01() {
	Person p1;
	p1.func();

	Person::func();
}

int main() {
	test01();
	system("pause");
	return 0;
}