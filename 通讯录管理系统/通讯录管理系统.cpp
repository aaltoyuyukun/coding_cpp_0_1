#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.�����ϵ��  *****" << endl;
	cout << "*****  2.��ʾ��ϵ��  *****" << endl;
	cout << "*****  3.������ϵ��  *****" << endl;
	cout << "*****  4.������ϵ��  *****" << endl;
	cout << "*****  5.�޸���ϵ��  *****" << endl;
	cout << "*****  6.���ͨѶ¼  *****" << endl;
	cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}

struct Contacts {
	string M_name;
	int sex;
	int age;
	string phonenr;
	string address;
};

struct Addressbooks {
	struct Contacts personArray[MAX]; //MAX person that are stored in the contact lists
	int msize;
};

void addPerson(Addressbooks * abs) {
	if (abs->msize == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else {
		//name
		string name;
		cout << "����������: " << endl;
		cin >> name;
		abs->personArray[abs->msize].M_name = name;

		//sex
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->msize].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//age
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->msize].age = age;

		//phonenr
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->msize].phonenr = phone;

		//address
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->msize].address = address;

		//contact people number
		abs->msize++;
		cout << "��ӳɹ�" << endl;

		system("pause"); //�밴���������
		system("cls"); //��������
	}
}

void showPerson(Addressbooks * abs) {
	if (abs->msize == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->msize; i++) {
			cout << "����: " << abs->personArray[i].M_name << "\t";
			cout << "�Ա�: " << (abs->personArray[i].sex == 1 ? "��" : "Ů") << "\t";
			cout << "��ַ: " << abs->personArray[i].address << "\t";
			cout << "�绰: " << abs->personArray[i].phonenr << "\t";
			cout << "סַ: " << abs->personArray[i].address << endl;
		}
	}

	system("pause"); //�밴���������
	system("cls"); //��������
}

int isExist(Addressbooks * abs, string name) {
	for (int i = 0; i < abs->msize; i++) {
		if (abs->personArray[i].M_name == name) {
			return i;
		}
	}
	return -1;
}

void deleteContacts (Addressbooks * abs){
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->msize; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->msize--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

void findContacts(Addressbooks * abs) {
	cout << "������Ҫ���ҵ���ϵ�˵������� " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "����: " << abs->personArray[ret].M_name;
		cout << "�Ա�: " << abs->personArray[ret].sex;
		cout << "��ַ: " << abs->personArray[ret].address;
		cout << "�绰: " << abs->personArray[ret].phonenr;
		cout << "סַ: " << abs->personArray[ret].address << endl;
	}
	else {
		cout << "δ�ҵ���ϵ��" << endl;
	}

	system("pause");
	system("cls");
}

void modifyContacts(Addressbooks * abs) {
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//����
		string name;
		cout << "�������޸ĺ���ϵ�˵�����: " << endl;
		cin >> name;
		abs->personArray[ret].M_name = name;
		cout << "�������Ա� " << endl;
		cout << "1 ---- ��: " << endl;
		cout << "2 ---- Ů: " << endl;
		int sex = 0;

		//�Ա�
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].age = age;

		//�绰
		cout << "������绰�� " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].phonenr = phone;

		//סַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].address = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	//�����������
	system("pause");
	system("cls");
}

void cleanContacts(Addressbooks * abs) {
	cout << "�Ƿ�ȷ��Ҫ�����ϵ��" << endl;
	cout << "ȷ����գ�������1" << endl;
	int flag;
	cin >> flag;
	if (flag == 1) {
		abs->msize = 0;
		cout << "ͨѶ¼�����" << endl;
		//�������������
		system("pause");
		system("cls");
	}
}

int main() {

	Addressbooks abs;
	abs.msize = 0;

	int select = 0;

	while (true) {
		showMenu();

		cin >> select;
		switch (select) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		{
			cout << "������ɾ����ϵ�������� " << endl;
			string name;
			cin >> name;
			deleteContacts(&abs);
			break;
		}
		case 4:
			findContacts(&abs);
			break;
		case 5:
			modifyContacts(&abs);
			break;
		case 6:
			cleanContacts(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}