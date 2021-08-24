#include<iostream>
#include<string>
using namespace std;

class Person {
	//friend void test01();
public:
	Person(int age) {
		m_Age = new int(age);
	}

	Person& operator=(Person& p) {
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;
	}

	~Person() {
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}
	
	int* m_Age;
};

void test01() {
	Person p1(18);
	Person p2(20);
	Person p3(22);
	p3 = p2 = p1;

	cout << "p1������Ϊ��" << *p1.m_Age << endl;
	cout << "p2������Ϊ��" << *p2.m_Age << endl;
	cout << "p3������Ϊ��" << *p3.m_Age << endl;
}

int main() {
	test01();
	//���һ���࣬�����4������
	system("pause");
	return 0;
}
