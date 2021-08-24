#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	//静态成员特点，类内声明，类外初始化
	static int m_A;

private:
	static int m_B;
};

//类内没有声明变量，只能用::这种方式
int Person::m_A = 10;
int Person::m_B = 10;

void test01(){
	Person p1;
	p1.m_A = 100;
	cout << "p1.m_A = " << p1.m_A << endl;

	Person p2;
	p2.m_A = 200;
	cout << "p1.m_A = " << p1.m_A << endl;
	cout << "p2.m_A = " << p2.m_A << endl;
}

int main() {
	test01();
	system("pause");
	return 0;
}