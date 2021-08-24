#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	Person() {
		mA = 0;
	}
	int mA;
	static int mB;
	void func() {
		cout << "mA:" << this->mA << endl;
	}
	//static void sfunc() {
	//}
};

int main() {
	cout << sizeof(Person) << endl;
	Person p;
	p.func();
	system("pause");
	return 0;
}