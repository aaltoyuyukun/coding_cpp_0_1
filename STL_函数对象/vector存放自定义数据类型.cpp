#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

class Person {
public:
	Person(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};

//存放对象
void test01() {
	vector<Person> v;
	Person p1("A", 20);
	Person p2("B", 30);
	Person p3("C", 40);
	Person p4("D", 50);
	Person p5("E", 60);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "Name: " << (*it).mName << ",Age: " << (*it).mAge << endl;
	}
}

//存放对象指针
void test02() {
	vector<Person*> v;
	Person p1("a", 111);
	Person p2("b", 222);
	Person p3("c", 333);
	Person p4("d", 444);
	Person p5("e", 555);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		Person* p = (*it);
		cout << "mName:" << p->mName << ",mAge" << p->mAge << endl;
	}
}

int main() {
	//test01();
	test02();
	system("pause");
	return 0;
}