#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person() {
		m_A = 0;
		m_B = 0;
	}
	void ShowPerson() const {
		this->m_B = 100;
	}
	void MyFunc() const {
		//this->m_A = 10000;
	}
public:
	int m_A;
	mutable int m_B;
};

void test01() {
	//const 修饰常对象，必须是可修改的左值
	const Person person;
	cout << person.m_A << endl;
	//person.m_A = 100;
	person.m_B = 100;
	person.MyFunc();
}

int main() {
	test01();
	system("pause");
	return 0;
}
