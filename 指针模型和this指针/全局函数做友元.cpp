#include<iostream>
#include<string>
using namespace std;

class Building
{
	friend void goodGay(Building* building);

public:
	Building() {
		this->m_Sittingroom = "living_room";
		this->m_Bedroom = "����";
	}

public:
	string m_Sittingroom;
private:
	string m_Bedroom;
};

void goodGay(Building* building) {
	cout << "�û������ڷ��ʣ�" << building->m_Sittingroom << endl;
	cout << "�û������ڷ��ʣ�" << building->m_Bedroom << endl;
}

int main() {

	Building b;
	goodGay(&b);
	system("pause");
	return 0;
}
