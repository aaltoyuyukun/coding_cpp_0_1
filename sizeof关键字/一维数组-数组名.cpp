#include<iostream>
using namespace std;

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "整个数组占用的内存空间为： " << sizeof(arr) << endl;
	cout << "每个元素占用内存空间为： " << sizeof(arr[0]) << endl;
	cout << "数组中元素个数为： " << sizeof(arr) / sizeof(arr[0]) << endl;
}


