#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

class Greater4 {
public:
	bool operator()(const int val) {
		return val > 4;
	}
};

void test01() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	int num = count_if(v.begin(), v.end(), Greater4());
	cout << "����4�ĸ���Ϊ��" << num << endl;
}

class Person {
public:
	Person(string name, int age) {
		this->m_Name = name;
		this->age = age;
	}

	string m_Name;
	int age;
};

class Ageless35 {
public:
	bool operator()(const Person& p) {
		return p.age < 35;
	}
};

void test02() {
	vector<Person> vp;
	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 30);
	Person p5("�ܲ�", 25);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);

	int num = count_if(vp.begin(), vp.end(), Ageless35());
	cout << "С��35�������ǣ�" << num << endl;
}

int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}