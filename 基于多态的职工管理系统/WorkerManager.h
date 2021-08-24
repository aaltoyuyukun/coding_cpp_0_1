#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//显示栏
	void Show_Menu();

	//退出系统
	void exitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//保存创建人员
	void save();

	//统计文件中人数
	int get_EmpNum();

	//初始化员工信息
	void init_Emp();

	//显示员工信息
	void show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在， 如果存在返回职工所在数组中位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序
	void Sort_Emp();

	//清空的文件操作
	void clean_file();

	//析构函数
	~WorkerManager();
};