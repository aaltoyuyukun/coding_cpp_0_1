#include<iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {
	/*Worker* worker = NULL;
	worker = new Employee(1, "����", 1001);
	worker->showInfo();
	delete worker;

	Manager* manager = NULL;
	manager = new Manager(2, "����", 2001);
	manager->showInfo();
	delete manager;

	Boss* boss = NULL;
	boss = new Boss(3, "��ɭ", 3001);
	boss->showInfo();
	delete boss;*/

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//չʾ�˵�
		wm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //���ְ��
			wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			wm.show_Emp();
			break;
		case 3: //ɾ��ְ��
		{
	/*		int ret = wm.IsExist(1);
			if (ret != -1) {
				cout << "Ա������" << endl;
			}
			else {
				cout << "ְ��������" << endl;
			}*/
			wm.Del_Emp();
			break; 
		}
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: //����ְ��
			wm.Sort_Emp();
			break;
		case 7: //����ļ�
			wm.clean_file();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}