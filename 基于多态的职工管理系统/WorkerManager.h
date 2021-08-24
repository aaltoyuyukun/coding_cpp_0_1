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
	//���캯��
	WorkerManager();

	//��ʾ��
	void Show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//���洴����Ա
	void save();

	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա����Ϣ
	void init_Emp();

	//��ʾԱ����Ϣ
	void show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ� ������ڷ���ְ������������λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����
	void Sort_Emp();

	//��յ��ļ�����
	void clean_file();

	//��������
	~WorkerManager();
};