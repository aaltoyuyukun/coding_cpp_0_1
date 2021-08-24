#include<iostream>
#include<string>
using namespace std;

struct Hero {
	string name;
	int age;
	string sex;
};

void HeroAgeSort(Hero hArray[], int len) {
	Hero temp;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (hArray[j].age > hArray[j + 1].age) {
				temp = hArray[j];
				hArray[j] = hArray[j + 1];
				hArray[j + 1] = temp;
			}
		}
	}
}

void printHeros(Hero hArray[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "name" << hArray[i].name 
			 << "age" << hArray[i].age 
			 << "sex" << hArray[i].sex << endl;
	}
}

int main() {

	Hero hArray[5] = {
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
	};

	int len = sizeof(hArray) / sizeof(Hero);
	
	HeroAgeSort(hArray, len);

	printHeros(hArray, len);

	system("pause");

	return 0;
}
