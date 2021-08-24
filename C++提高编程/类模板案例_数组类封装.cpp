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
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}
}

void test01() {
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++) {
		arr1.Push_Back(i);
	}
	cout << "arr1的打印输出为： " << endl;
	//printArray(arr1);
	cout << "arr1容量大小：" << arr1.getCapacity() << endl;
	cout << "arr1容量大小：" << arr1.getSize() << endl;
	
	MyArray <int>arr2(arr1);
	cout << "arr2的打印输出为：" << endl;
	//printArray(arr2);
	
	//尾删除
	//arr1.Pop_Back();
	arr2.Pop_Back();
	//printArray(arr1);
	printArray(arr2);
}

void test02()
{
	MyArray<Person> arr(10);

	Person p1("孙悟空", 999);
	Person p2("韩信", 30);
	Person p3("妲己", 20);
	Person p4("赵云", 25);
	Person p5("安其拉", 27);
	Person p6("小公主", 33);

	//将数据插入到数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);
	arr.Push_Back(p6);

	//打印数组
	printPersonArray(arr);

	//输出容量 
	cout << "arr容量为： " << arr.getCapacity() << endl;
	//输出大小
	cout << "arr大小为： " << arr.getSize() << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}