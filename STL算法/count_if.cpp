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
	cout << "大于4的个数为：" << num << endl;
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
	Person p1("刘备", 35);
	Person p2("关羽", 35);
	Person p3("张飞", 35);
	Person p4("赵云", 30);
	Person p5("曹操", 25);

	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);

	int num = count_if(vp.begin(), vp.end(), Ageless35());
	cout << "小于35的人数是：" << num << endl;
}

int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}