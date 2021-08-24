#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person() {
		cout << "无参构造函数！" << endl;
		mAge = 0;
	}

	Person(int age) {
		cout << "有参构造函数！" << endl;
	}

	Person(const Person& p) {
		cout << "拷贝构造函数！" << endl;
		mAge = p.mAge;
	}

	~Person() {
		cout << "析构函数" << endl;
	}

public:
	int mAge;
};

void test01() {
	Person man(100);
	Person newman(man);
	Person newman2 = man;
}

void doWork(Person p1) {};
void test02() {
	Person p;
	doWork(p);
}

Person doWork2() {
	Person p1;
	// &p与((int *)&p)区别
	//&是取地址而(int*)p1只是把整数p1转换成指针类型，
	//而输出整型指针类型就是输出这个指针指向的地址的16进制表示
	cout << (int*) &p1 << endl;
	return p1;
}

void test03()
{
	Person p = doWork2();
	cout << (int*)&p << endl;
}

int main() {
	//test01();
	//test02();
	test03();

	system("pause");
	return 0;
}