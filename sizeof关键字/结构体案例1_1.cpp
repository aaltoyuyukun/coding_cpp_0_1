#include<iostream>
#include<string>
#include<ctime>

using namespace std;

struct Student {
	string name;
	int score;
};

struct Teacher {
	string name;
	Student sArray[5];
};

void allocateSpace(Teacher tArray[], int len, int len2) {
	string tname = "教师";
	string sname = "学生";
	string nameSeed = "ABCDE";

	for (int i = 0; i < len; i++) {
		tArray[i].name = tname + nameSeed[i];

		for (int j = 0; j < len2; j++) {
			tArray[i].sArray[j].name = sname + nameSeed[j];
			tArray[i].sArray[j].score = rand() % 61 + 40;
		}
	}
}

void printTeachers(Teacher tArray[], int len, int len2) {
	for (int i = 0; i < len; i++) {
		cout << tArray[i].name << endl;
		for (int j = 0; j < len2; j++) {
			cout << "\t姓名：" << tArray[i].sArray[j].name
				 << " 分数：" << tArray[i].sArray[j].score
				 << endl;
		}
	}
}

int main() {
	srand((unsigned int)time(NULL));
	Teacher tArray[3];
	Student sArray[5];
	int len = sizeof(tArray) / sizeof(Teacher);
	int len2 = sizeof(sArray) / sizeof(Student);
	allocateSpace(tArray, len, len2);
	printTeachers(tArray, len, len2);

	system("pause");

	return 0;
}
