#include<iostream>
#include<string>
using namespace std;

//抽象CPU虚类
class CPU {
public:
	virtual void calculate() = 0;
};

class VideoCard {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

class computer {
public:
	computer(CPU * cpu, VideoCard * vc, Memory * mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	void work() {
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	~computer() {
		if(m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}

private:
	CPU* m_cpu;
	VideoCard* m_vc;
	Memory* m_mem;
};

//Intel厂商
class IntelCpu : public CPU {
public:
	virtual void calculate() {
		cout << "Intel的CPU开始工作了" << endl;
	}
};

class IntelVideoCard : public VideoCard {
public:
	virtual void display() {
		cout << "Intel的显卡开始工作了" << endl;
	}
};

class IntelMemory : public Memory {
public:
	virtual void storage() {
		cout << "Intel的内存开始工作了" << endl;
	}
};

//Dell厂商
class DellCpu : public CPU {
public:
	virtual void calculate() {
		cout << "Dell的CPU开始工作了" << endl;
	}
};

class DellVideoCard : public VideoCard {
public:
	virtual void display() {
		cout << "Dell的显卡开始工作了" << endl;
	}
};

class DellMemory : public Memory {
public:
	virtual void storage() {
		cout << "Dell的内存开始工作了" << endl;
	}
};

void test01() {
	cout << "------------------- computer 1 --------------------" << endl;
	CPU* intelcpu = new IntelCpu;
	VideoCard* intelcard = new IntelVideoCard;
	Memory* intelmem = new IntelMemory;
	computer* computer1 = new computer(intelcpu, intelcard, intelmem);
	computer1->work();
	delete computer1;
	cout << "-------------------- computer 2 -------------------" << endl;
	computer* computer2 = new computer(new DellCpu, new DellVideoCard, new DellMemory);
	computer2->work();
	delete computer2;
	cout << "-------------------- computer 3 -------------------" << endl;
	computer* computer3 = new computer(new IntelCpu, new DellVideoCard, new DellMemory);
	computer3->work();
	delete computer3;
}

int main() {
	test01();
	system("pause");
	return 0;
}
