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
		cout << "ѧ��: " << s_num << "," << "����: " << s_name << endl;
	}

public:
	string s_name;
	int s_num;
	string r_name;
	int r_num;
};

int main() {
	Student stu;
	cout << "������ѧ������: " << endl;
	cin >> stu.r_name;
	cout << "������ѧ��ѧ��: " << endl;
	cin >> stu.r_num;

	stu.setName(stu.r_name);
	stu.setID(stu.r_num);

	stu.showStudent();

	system("pause");
	return 0;
}