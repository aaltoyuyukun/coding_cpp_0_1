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

	//����һ������ָ��ָ��
	while (pBegin != pEnd) {
		cout << *pBegin << endl;
		pBegin++;
	}

	//������
	for (vector<int>::iterator it = pBegin; it != pEnd; it++) {
		cout << *it << endl;
	}

	//��������ʹ��STL�ṩ��׼�����㷨
	for_each(pBegin, pEnd, MyPrint);
}

int main() {
	test01();
	system("pause");
	return 0;
}