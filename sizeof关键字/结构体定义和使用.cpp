#include<iostream>
#include<string>
using namespace std;

struct Student {
	string name;
	int age;
	int score;
};

int main() {
	struct Student s1;
	s1.name = "alex";
	s1.age = 18;
	s1.score = 100;

	cout << "name: " << s1.name << " age: " << s1.age << " score: " << s1.score << endl;

	struct Student s2 = {"lisi", 19, 80};
	cout << "name: " << s2.name << " age: " << s2.age << " score: " << s2.score << endl;
}