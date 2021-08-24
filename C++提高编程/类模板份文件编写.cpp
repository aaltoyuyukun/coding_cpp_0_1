#include<iostream>
using namespace std;
//#include "person.h"
#include "person.hpp"

void test01() {
	Person<string, int> P("Tom", 20);
	P.showPerson();
}

int main() {
	test01();
	system("pause");
	return 0;
}