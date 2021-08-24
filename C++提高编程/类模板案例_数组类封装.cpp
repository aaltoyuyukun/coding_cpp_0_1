#include<iostream>
using namespace std;
#include "MyArray.hpp"
#include<string>

void printArray(MyArray <int> & arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}

class Person {
public:

	Person() {};
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

public:
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << endl;
	}
}

void test01() {
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ���Ϊ�� " << endl;
	//printArray(arr1);
	cout << "arr1������С��" << arr1.getCapacity() << endl;
	cout << "arr1������С��" << arr1.getSize() << endl;
	
	MyArray <int>arr2(arr1);
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	//printArray(arr2);
	
	//βɾ��
	//arr1.Pop_Back();
	arr2.Pop_Back();
	//printArray(arr1);
	printArray(arr2);
}

void test02()
{
	MyArray<Person> arr(10);

	Person p1("�����", 999);
	Person p2("����", 30);
	Person p3("槼�", 20);
	Person p4("����", 25);
	Person p5("������", 27);
	Person p6("С����", 33);

	//�����ݲ��뵽������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	arr.Push_Back(p6);

	//��ӡ����
	printPersonArray(arr);

	//������� 
	cout << "arr����Ϊ�� " << arr.getCapacity() << endl;
	//�����С
	cout << "arr��СΪ�� " << arr.getSize() << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}