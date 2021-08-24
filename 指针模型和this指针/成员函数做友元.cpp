#include<iostream>
#include<string>
using namespace std;

//class Building;
class goodGay {
public:
	goodGay();
	void visit();
	void visit2();

private:
	Building* building;
};

class Building {
	friend void goodGay::visit();
	//friend void goodGay::visit2();
public:
	Building();
public:
	string m_SittingRoom;
private:
	string m_BedRoom;
};

Building::Building() {
	this->m_SittingRoom = "living room";
	this->m_BedRoom = "bedroom";
}

goodGay::goodGay() {
	building = new Building;
}

void goodGay::visit() {
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
}

void goodGay::visit2() {
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRoom << endl;
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