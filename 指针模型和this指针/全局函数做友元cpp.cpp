#include<iostream>
#include<string>
using namespace std;

//class Building;
class goodGay {
public:
	goodGay();
	void visit();
	
private:
	Building* building;
};

class Building {
	friend class goodGay;
public:
	Building();

public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

goodGay::goodGay() {
	building = new Building;
}

void goodGay::visit() {
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

//类外声明函数
Building::Building() {
	this->m_SittingRoom = "客厅";
	this->m_BedRoom = "卧室";
}

void test01() {
	goodGay gg;
	gg.visit();
}

int main() {

	test01();
	system("pause");
	return 0;
}
