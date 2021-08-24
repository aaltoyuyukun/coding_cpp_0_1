#include<string>
#include<iostream>
using namespace std;

class MyInteger {
	friend ostream& operator<<(ostream& out, MyInteger myint);
public:
	MyInteger() {
		m_Num = 10;
	}
	//前置--，返回值
	MyInteger& operator--() {
		--m_Num;
		return *this;
	}

	//后置--，返回引用
	MyInteger operator--(int) {
		MyInteger temp = *this;
		m_Num--;
		return temp;
	}

private:
	int m_Num;
};

ostream& operator<<(ostream& out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}

void test01() {
	MyInteger myint;
	cout << --myint << endl;
	cout << myint << endl;
}

void test02() {
	MyInteger myint;
	cout << myint-- << endl;
	cout << myint << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}