#include<iostream>
#include<string>
using namespace std;

class Person {
	friend ostream& operator<<(ostream& out, Person& p);
public:
	Person(int a, int b) {
		this->m_A = a;
		this->m_B = b;
	}

private:
	int m_A;
	int m_B;
};

//ostream& operator<<(ostream& out, Person& p) {
//	cout << "a:" << p.m_A << " b:" << p.m_B << endl;
//	return cout;
//}

void test() {
	Person p1(10, 20);
	cout << p1 << "hello world " << "aaaa " << "bbbb" << endl;
}

int main() {
	test();
	system("pause");
	return 0;
}