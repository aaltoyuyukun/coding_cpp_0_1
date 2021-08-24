#include<iostream>
using namespace std;

void bubbleSortPoint( int *arr, int len);
void PrintArr(int* arr, int len);

void bubbleSortPoint(int *arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				arr[j + 1] = arr[j];
			}
		}
	}
}

void PrintArr(int* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		cout << arr[i] << endl;
	}
}

int main() {
	int arr[] = { 4,3,6,9,1,2,10,8,7,5 };
	
	int len = sizeof(arr) / sizeof(arr[0]);
	bubbleSortPoint(arr, len);
	PrintArr(arr, len);
}

