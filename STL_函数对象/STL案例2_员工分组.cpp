#include<iostream>
#include<string>
using namespace std;
#include<vector>
#include<ctime>
#include<map>

class Worker {
public:
	string m_Name;
	int m_salary;
};

//分配10个人员
void createWorker(vector<Worker>& v) {
	string str = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		Worker worker;
		worker.m_Name = "employee";
		worker.m_Name += str[i];
		worker.m_salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
}

void setDept(vector<Worker>& v, multimap<int, Worker>& m) {
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		int deptId = rand() % 3;
		m.insert(make_pair(deptId, *it));
	}
}

void showWorkerInfo(multimap<int, Worker>& m) {
	multimap<int, Worker>::iterator pos = m.find(0);
	int index = 0;
	int deptEmpNum = m.count(0);
	for (; pos != m.end(), index < deptEmpNum; pos++, index++) {
		cout << pos->first << " " << pos->second.m_Name << " " << pos->second.m_salary << endl;
	}

	multimap<int, Worker>::iterator pos_ = m.find(1);
	int index_ = 0;
	int deptEmpNum_ = m.count(1);
	for (; pos_ != m.end(), index_ < deptEmpNum_; pos_++, index_++) {
		cout << pos_->first << " " << pos_->second.m_Name << " " << pos_->second.m_salary << endl;
	}

	multimap<int, Worker>::iterator pos__ = m.find(2);
	int index__ = 0;
	int deptEmpNum__ = m.count(2);
	for (; pos__ != m.end(), index__ < deptEmpNum__; pos__++, index__++) {
		cout << pos__->first << " " << pos__->second.m_Name << " " << pos__->second.m_salary << endl;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	vector<Worker>v;
	createWorker(v);
	multimap<int, Worker>m;
	setDept(v,m);
	//for (multimap<int, Worker>::iterator it = m.begin(); it != m.end(); it++) {
	//	cout << it->first << " " << it->second.m_Name << " " << it->second.m_salary << endl;
	//}
	showWorkerInfo(m);
	system("pause");
	return 0;
}