#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	void showClassName() {
		cout << "ÎÒÊÇPersonÀà" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl;
	}
	static int mAge;
};

int Person::mAge = 10;

void test01() {
	Person *p = NULL;
	p->showClassName();
	p->ShowPerson();
	//p->showClassName();
	//p.showClassName();
	//p.ShowPerson();
}

int main() {
	test01();
	system("pause");
	return 0;
}