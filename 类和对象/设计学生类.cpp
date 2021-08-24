#include<iostream>
#include<string>
using namespace std;

class Student {
public:
	void setName(string name) {
		s_name = name;
	}

	void setID(int id) {
		s_num = id;
	}

	void showStudent() {
		cout << "学号: " << s_num << "," << "姓名: " << s_name << endl;
	}

public:
	string s_name;
	int s_num;
	string r_name;
	int r_num;
};

int main() {
	Student stu;
	cout << "请输入学生姓名: " << endl;
	cin >> stu.r_name;
	cout << "请输入学生学号: " << endl;
	cin >> stu.r_num;

	stu.setName(stu.r_name);
	stu.setID(stu.r_num);

	stu.showStudent();

	system("pause");
	return 0;
}