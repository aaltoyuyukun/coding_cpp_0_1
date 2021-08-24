#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking {
public:
	//���麯��
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
		cout << "��ũ��ɽȪ" << endl;
	}

	virtual void Brew() {
		cout << "���ݿ���" << endl;
	}

	virtual void PourInCup() {
		cout << "�����ȵ��뱭��" << endl;
	}

	virtual void PutSomething() {
		cout << "����ţ��" << endl;
	}
};

class tea : public AbstractDrinking {
public:
	virtual void Boil() {
		cout << "���" << endl;
	}
	virtual void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	}
	virtual void PourInCup() {
		cout << "����ˮ���뱭��" << endl;
	}
	virtual void PutSomething() {
		cout << "�������" << endl;
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