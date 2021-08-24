#include<iostream>
#include<string>
using namespace std;

class Phone
{
public:
	Phone(string name) {
		m_PhoneName = name;
		cout << "Phone构造" << endl;
	}

	~Phone() {
		cout << "Phone构造" << endl;
	}

	string m_PhoneName;
};

class Person {
public:
	Person(string name, string pName) :m_Name(name), m_Phone(pName) {
		cout << "Person构造" << endl;
	}
	
	~Person() {
		cout << "Person构造" << endl;
	}
	
	void playGame() {
		cout << m_Name << "使用" << m_Phone << "牌手机" << endl;
	}

	string m_Name;
	string m_Phone;
};

void test01() {
	Person p("张三", "苹果X");
	p.playGame();
}

int main() {
	test01();
	system("pause");
	return 0;
}