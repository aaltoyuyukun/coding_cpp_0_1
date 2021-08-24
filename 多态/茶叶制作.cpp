#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking {
public:
	//´¿Ðéº¯Êý
	virtual void Boil() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void PutSomething() = 0;
	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class coffee : public AbstractDrinking {
public:
	virtual void Boil() {
		cout << "ÖóÅ©·òÉ½Èª" << endl;
	}

	virtual void Brew() {
		cout << "³åÅÝ¿§·È" << endl;
	}

	virtual void PourInCup() {
		cout << "½«¿§·Èµ¹Èë±­ÖÐ" << endl;
	}

	virtual void PutSomething() {
		cout << "¼ÓÈëÅ£ÄÌ" << endl;
	}
};

class tea : public AbstractDrinking {
public:
	virtual void Boil() {
		cout << "Öó²è" << endl;
	}
	virtual void Brew() {
		cout << "³åÅÝ²èÒ¶" << endl;
	}
	virtual void PourInCup() {
		cout << "½«²èË®µ¹Èë±­ÖÐ" << endl;
	}
	virtual void PutSomething() {
		cout << "¼ÓÈëèÛè½" << endl;
	}
};

void DoWork(AbstractDrinking *drink) {
	drink->MakeDrink();
	delete drink;
}

void test01() {
	DoWork(new coffee);
	DoWork(new tea);
}

int main() {
	test01();
	system("pause");
	return 0;
}