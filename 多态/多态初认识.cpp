#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
	//virtual����ʵ�����
	virtual void speak() {
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal {
public:
	void speak() {
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal {
public:
	void speak() {
		cout << "С����˵��" << endl;
	}
};

void DoSpeak(Animal& animal) {
	animal.speak();
}

void test01() {
	Cat cat;
	DoSpeak(cat);
}

void test02() {
	Dog dog;
	DoSpeak(dog);
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}