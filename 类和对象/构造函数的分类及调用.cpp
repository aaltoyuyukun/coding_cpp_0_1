#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person() {
		cout << "无参构造函数" << endl;
	}
	Person(int a) {
		age = a;
		cout << "有参构造函数" << endl;
	}
	Person(const Person & p) {
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
	Person p; //无参构造
}

void test02() {
	//括号法
	//Person p1(10); //有参构造

	//显示法
	//Person p2 = Person(10); //有参构造
	//Person p3 = Person(p2); //拷贝构造

	//隐式转换法
	Person p4 = 10; //有参构造
	Person p5 = p4; //拷贝构造
}

int main() {

	//test01();
	test02();
	system("pause");
	return 0;
}
