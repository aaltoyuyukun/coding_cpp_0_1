#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person(string name, int age) {
		m_Name = name;
		m_Age = age;
	}

	bool operator==(Person& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator!= (Person& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return false;
		}
		else {
			return true;
		}
	}

	string m_Name;
	int m_Age;
};

void test01() {
	Person p1("tom", 20);
	Person p2("tom", 20);
	if (p1 == p2) {
		cout << "p1和p2相等" << endl;
	}
	else {
		cout << "p1和p2不相等" << endl;
	}
}

void test02() {
	Person p3("amy", 30);
	Person p4("jari", 40);
	if (p3 == p4) {
		cout << "p3和p4相等" << endl;
	}
	else {
		cout << "p3和p4不相等" << endl;
	}
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}