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
	t1.name = "老王";
	t1.age = 40;

	t1.stu.name = "alex";
	t1.stu.age = 18;
	t1.stu.score = 100;

	cout << "教师 职工编号: " << t1.age << " name: " << t1.name << " age: " << t1.age << endl;
	cout << "辅导学员 name: " << t1.stu.name << " age: " << t1.stu.age << " 考试分数: " << t1.stu.score << endl;

	return 0;
}