#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include<deque>
#include<algorithm>
#include<time.h>
#include<stdlib.h>

class Person {
public:
	Person(string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};

void createPerson(vector<Person>&v) {
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);
		v.push_back(p);
	}
}

void printPerson(vector<Person>& v) {
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "name: " << (*it).m_Name << ", average score: " << (*it).m_Score << endl;
	}
}

void setScore(vector<Person>&v){
	srand((unsigned)time(NULL));
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int>d;
		for (int j = 0; j < 10; j++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		//cout << "选手：" << it->m_Name << "打分：" << endl;
		//for (deque<int>::iterator vit = d.begin(); vit != d.end(); vit++) {
		//	cout << *vit << " ";
		//}
		//cout << endl;

		sort(d.begin(), d.end());
		d.pop_front();
		d.pop_back();
		
		int sum = 0;
		for (deque<int>::iterator vit = d.begin(); vit != d.end(); vit++) {
			sum += (*vit);
		}

		int avg = sum / d.size();
		it->m_Score = avg;
	}
}

int main() {
	//-创建5名选手
	vector<Person> v; // 存放选手容器
	createPerson(v);
	//printPerson(v);

	//-给5名选手打分
	setScore(v);
	//-显示最后得分
	printPerson(v);

	system("pause");
	return 0;
}