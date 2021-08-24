#include<iostream>
#include<string>
using namespace std;

class Animal {
public:
	//virtual可以实现晚绑定
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal {
public:
	void speak() {
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal {
public:
	void speak() {
		cout << "小狗在说话" << endl;
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