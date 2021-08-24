#include<iostream>
#include<string>
using namespace std;

#define MAX 1000

void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.查找联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空通讯录  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
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
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else {
		//name
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[abs->msize].M_name = name;

		//sex
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;

		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->msize].sex = sex;
				break;
			}
			cout << "输入有误，请重行输入" << endl;
		}

		//age
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->msize].age = age;

		//phonenr
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->msize].phonenr = phone;

		//address
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->msize].address = address;

		//contact people number
		abs->msize++;
		cout << "添加成功" << endl;

		system("pause"); //请按任意键继续
		system("cls"); //清屏操作
	}
}

void showPerson(Addressbooks * abs) {
	if (abs->msize == 0) {
		cout << "当前记录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->msize; i++) {
			cout << "姓名: " << abs->personArray[i].M_name << "\t";
			cout << "性别: " << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";
			cout << "地址: " << abs->personArray[i].address << "\t";
			cout << "电话: " << abs->personArray[i].phonenr << "\t";
			cout << "住址: " << abs->personArray[i].address << endl;
		}
	}

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
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
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		for (int i = ret; i < abs->msize; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->msize--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

void findContacts(Addressbooks * abs) {
	cout << "请输入要查找的联系人的姓名： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "姓名: " << abs->personArray[ret].M_name;
		cout << "性别: " << abs->personArray[ret].sex;
		cout << "地址: " << abs->personArray[ret].address;
		cout << "电话: " << abs->personArray[ret].phonenr;
		cout << "住址: " << abs->personArray[ret].address << endl;
	}
	else {
		cout << "未找到联系人" << endl;
	}

	system("pause");
	system("cls");
}

void modifyContacts(Addressbooks * abs) {
	string name;
	cout << "请输入您要修改的联系人" << endl;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入修改后联系人的姓名: " << endl;
		cin >> name;
		abs->personArray[ret].M_name = name;
		cout << "请输入性别： " << endl;
		cout << "1 ---- 男: " << endl;
		cout << "2 ---- 女: " << endl;
		int sex = 0;

		//性别
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].age = age;

		//电话
		cout << "请输入电话： " << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].phonenr = phone;

		//住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].address = address;

		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

void cleanContacts(Addressbooks * abs) {
	cout << "是否确定要清空联系人" << endl;
	cout << "确认清空，请输入1" << endl;
	int flag;
	cin >> flag;
	if (flag == 1) {
		abs->msize = 0;
		cout << "通讯录已清空" << endl;
		//按任意键后清屏
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
			cout << "请输入删除联系人姓名： " << endl;
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
			cout << "欢迎下次使用" << endl;
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