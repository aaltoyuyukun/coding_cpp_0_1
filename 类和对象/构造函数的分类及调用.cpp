#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person() {
		cout << "�޲ι��캯��" << endl;
	}
	Person(int a) {
		age = a;
		cout << "�вι��캯��" << endl;
	}
	Person(const Person & p) {
		age = p.age;
		cout << "�������캯��" << endl;
	}
	~Person() {
		cout << "��������" << endl;
	}
public:
	int age;
};

void test01() {
	Person p; //�޲ι���
}

void test02() {
	//���ŷ�
	//Person p1(10); //�вι���

	//��ʾ��
	//Person p2 = Person(10); //�вι���
	//Person p3 = Person(p2); //��������

	//��ʽת����
	Person p4 = 10; //�вι���
	Person p5 = p4; //��������
}

int main() {

	//test01();
	test02();
	system("pause");
	return 0;
}
