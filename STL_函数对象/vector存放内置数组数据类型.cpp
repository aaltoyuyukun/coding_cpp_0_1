#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void MyPrint(int val) {
	cout << val << endl;
}

void test01() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	vector<int>::iterator pBegin = v.begin();
	vector<int>::iterator pEnd = v.end();

	//遍历一，类似指针指向
	while (pBegin != pEnd) {
		cout << *pBegin << endl;
		pBegin++;
	}

	//遍历二
	for (vector<int>::iterator it = pBegin; it != pEnd; it++) {
		cout << *it << endl;
	}

	//遍历三，使用STL提供标准遍历算法
	for_each(pBegin, pEnd, MyPrint);
}

int main() {
	test01();
	system("pause");
	return 0;
}