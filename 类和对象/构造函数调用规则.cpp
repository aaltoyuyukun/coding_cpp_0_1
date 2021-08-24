#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person() {
		cout << "无参构造函数：" << endl;
	}

	Person(int a) {
		age = a;
		cout << "有参构造函数：" << endl;
	}

	Person(const Person& p) {
		age = p.age;
		cout << "拷贝构造函数" << endl;
	}

	~Person() {
		cout << "析构函数" << endl;
	}

public:
	int age;
};

void test01() {
	Person p1(18);
	Person p2(p1);
	cout << "p2的年龄为" << p2.age << endl;
}

void test02() {
	Person p1;
	Person p2(10);
	Person p3(p2);

	Person p4;
	Person p5(10);
	Person p6(p5);
}

int main() {
	//test01();
	test02();

	system("pause");
	return 0;
}
