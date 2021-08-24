#include<iostream>
#include<string>
using namespace std;

class Building
{
	friend void goodGay(Building* building);

public:
	Building() {
		this->m_Sittingroom = "living_room";
		this->m_Bedroom = "卧室";
	}

public:
	string m_Sittingroom;
private:
	string m_Bedroom;
};

void goodGay(Building* building) {
	cout << "好基友正在访问：" << building->m_Sittingroom << endl;
	cout << "好基友正在访问：" << building->m_Bedroom << endl;
}

int main() {

	Building b;
	goodGay(&b);
	system("pause");
	return 0;
}
