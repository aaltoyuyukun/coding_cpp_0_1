#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person() {
		cout << "�޲ι��캯����" << endl;
		mAge = 0;
	}

	Person(int age) {
		cout << "�вι��캯����" << endl;
	}

	Person(const Person& p) {
		cout << "�������캯����" << endl;
		mAge = p.mAge;
	}

	~Person() {
		cout << "��������" << endl;
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
	// &p��((int *)&p)����
	//&��ȡ��ַ��(int*)p1ֻ�ǰ�����p1ת����ָ�����ͣ�
	//���������ָ�����;���������ָ��ָ��ĵ�ַ��16���Ʊ�ʾ
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