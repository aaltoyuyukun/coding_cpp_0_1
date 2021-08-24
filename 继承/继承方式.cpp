#include<iostream>
#include<string>
using namespace std;

class Base1 {
public:
	int m_A;
protected:
	int m_B;	
private:
	int m_C;
};

class son1: public Base1 {
public:
	void func() {
		m_A;
		m_B;
		//m_C;
	}
};

void myClass() {
	son1 s1;
	s1.m_A;
}

//class Base2 {
//public:
//	int m_A;
//protected:
//	int m_B;
//private:
//	int m_C;
//};

class son2: protected Base1 {
public:
	void func() {
		m_A;
		m_B;
	}
};

void myClass2() {
	son2 s;
	//s.m_A;
}

class son3 : private Base1 {
public:
	void func() {
		m_A;
		m_B;
	}
};

class GrandSon3: public son3{
public:
	void func() {
		//m_A;
		//m_B;
	}
};

int main() {
	myClass();
	system("pause");
	return 0;
}
