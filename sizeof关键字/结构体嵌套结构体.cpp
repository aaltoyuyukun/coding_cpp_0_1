#include<iostream>
#include<string>
using namespace std;

struct Student {
	string name;
	int age;
	int score;
};

struct Teacher {
	int id;
	string name;
	int age;
	struct Student stu;
};

int main() {
	struct Teacher t1;
	t1.id = 10000;
	t1.name = "����";
	t1.age = 40;

	t1.stu.name = "alex";
	t1.stu.age = 18;
	t1.stu.score = 100;

	cout << "��ʦ ְ�����: " << t1.age << " name: " << t1.name << " age: " << t1.age << endl;
	cout << "����ѧԱ name: " << t1.stu.name << " age: " << t1.stu.age << " ���Է���: " << t1.stu.score << endl;

	return 0;
}