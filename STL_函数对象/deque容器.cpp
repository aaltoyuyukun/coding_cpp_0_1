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
		string name = "ѡ��";
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

		//cout << "ѡ�֣�" << it->m_Name << "��֣�" << endl;
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
	//-����5��ѡ��
	vector<Person> v; // ���ѡ������
	createPerson(v);
	//printPerson(v);

	//-��5��ѡ�ִ��
	setScore(v);
	//-��ʾ���÷�
	printPerson(v);

	system("pause");
	return 0;
}