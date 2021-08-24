#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件为空
		cout << "文件为空" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且数据存在
	int num = this->get_EmpNum();
	//cout << "职工人数:" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "职工编号：" << this->m_EmpArray[i]->m_Id
	//		 << ",姓名：" << this->m_EmpArray[i]->m_Name
	//		 << ",部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

void WorkerManager::show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//退出系统
void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum (){
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		//统计人数变量
		num++;
	}
	return num;
}

//添加系统
void WorkerManager::Add_Emp() {
	cout << "请输入添加职工数量" << endl;
	int addNum = 0; //保存用户输入的数量
	cin >> addNum;
	if (addNum > 0) {
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;
		Worker ** newSpace = new Worker* [newSize];
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//add
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			//int ret = this->IsExist(id); //未找到ret为-1
			//if (ret != -1) {
			//	cout << "该员工已存在" << endl;
			//}
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, 1001);
				break;
			case 2:
				worker = new Manager(id, name, 2001);
				break;
			case 3:
				worker = new Boss(id, name, 3001);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更新新空间指向
		this->m_EmpArray = newSpace;
		//更新新职工人数
		this->m_EmpNum = newSize;
		//更新职工不为空情况
		this->m_FileIsEmpty = false;
		//提示添加成功
		cout << "成功添加员工人数：" << addNum << endl;
		this->save();
	}
	else {
		cout << "输入有误" << endl;
	}
	//按任意键后，清屏回到上级目录
	system("pause");
	system("cls");
}

//功能显示
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//初始化员工
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入想要删除的职工号: " << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1) {
			for (int i = index; i < this->m_EmpNum; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "没有找到对应员工" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在，记录为空" << endl;
	}
	else {
		cout << "请输入要修改员工id" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查找： " << id << "号职工，请输入新职工" << endl;
			cin >> newId;
			
			cout << "请输入新员工姓名" << endl;
			cin >> newName;

			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
		else {
			cout << "没有找到对应员工" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入查找方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select = 0;
		cin >> select;
		bool flag = false;
		if (select == 1) {
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			for (int i = 0; i < m_EmpNum; i++) {
				//int ret = IsExist(id);
				if (id == this->m_EmpArray[i]->m_Id) {
					//找到职工
					cout << "查找成功，该职工信息如下" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "未找到此人" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					//找到员工
					cout << "查找成功，职工编号为："
						 << this->m_EmpArray[i]->m_Id
						 << "号职工信息如下："
						 << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				cout << "查找失败，查无此人" << endl;
			}
		}
		else {
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp(){
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请选择排序方式：" << endl;
		cout << "1、按职工号进行排序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++){
			int minOrMax = i;
			for (int j = i + 1; j < m_EmpNum; j++) {
				//升序
				if (select == 1) {
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
				//降序
				else {
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功,排序后结果" << endl;
		this->save();
		this->show_Emp();
	}
	system("pause");
	system("cls");
}

void WorkerManager::clean_file() {
	cout << "确定清空" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}