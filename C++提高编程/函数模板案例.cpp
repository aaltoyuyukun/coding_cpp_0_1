#include<iostream>
using namespace std;

template<class T>
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void mySort(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		int max = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[j] > arr[max]) {
				max = j;
			}
		}
		if (max != i) {
			mySwap(arr[i], arr[max]);
		}
	}
}

template<class T>
void printArray(T arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
}

void test01() {
	int arrInt[] = { 10,4,2,5,3,1,8 };
	int num = sizeof(arrInt) / sizeof(arrInt[0]);
	mySort(arrInt, num);
	printArray(arrInt, num);
}

int main() {
	test01();
	system("pause");
	return 0;
}