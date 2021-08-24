#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray {
public:
	//构造函数
	MyArray(int capacity) {
		//cout << "构造函数输出" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& arr) {
		//cout << "拷贝函数输出" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;

		//深拷贝
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//operator=,防止浅拷贝问题
	MyArray& operator=(const MyArray& arr) {
		//先判断堆区是否有数据，有数据先释放
		//cout << "重载函数输出" << endl;
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}

		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < this->m_Size; i++) {
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	//尾插法
	void Push_Back(const T& val) {
		if (this->m_Capacity == this->m_Size) {
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//尾删法
	void Pop_Back() {
		if (this->m_Size == 0) {
			return;
		}
		this->m_Size--;
	}

	//通过下标方式访问数组中元素 arr[0] = 100
	T& operator[] (int index) {
		return this->pAddress[index];
	}

	//返回数组容量
	int getCapacity() {
		return this->m_Capacity;
	}

	int getSize() {
		return this->m_Size;
	}
	
	//析构函数
	~MyArray() {
		if (this->pAddress != NULL) {
			//cout << "析构函数输出" << endl;
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

private:
	int m_Size;
	T* pAddress;
	int m_Capacity;
};