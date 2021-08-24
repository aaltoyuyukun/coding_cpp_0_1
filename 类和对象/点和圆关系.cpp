#include<iostream>
#include<string>
using namespace std;

class Point{
public:
	void setX(int x) {
		m_X = x;
	}

	int getX() {
		return m_X;
	}

	void setY(int y) {
		m_Y = y;
	}

	int getY() {
		return m_Y;
	}

private:
	int m_X;
	int m_Y;
};

class Circle {
public:
	void setR(int r) {
		m_R = r;
	}

	int getR() {
		return m_R;
	}

	void setCenter(Point center) {
		m_Center = center;
	}

	Point getCenter() {
		return m_Center;
	}

private:
	int m_R;
	Point m_Center;
};

void isOnCircle(Circle& cir, Point& p) {
	int distance =
		(cir.getCenter().getX() - p.getX()) * (cir.getCenter().getX() - p.getX())
		+ (cir.getCenter().getY() - p.getY()) * (cir.getCenter().getY() - p.getY());

	int r_square = cir.getR() * cir.getR();

	int r_point_diff = distance - r_square;

	if (r_point_diff == 0) {
		cout << "on the circle" << endl;
	}
	else if (r_point_diff > 0) {
		cout << "out of the circle" << endl;
	}
	else {
		cout << "in the circle" << endl;
	}
}

int main() {
	//创建圆
	Circle c;
	c.setR(10);
	Point p;
	p.setX(0);
	p.setY(0);
	c.setCenter(p);

	//创建点
	Point p_p;
	p_p.setX(11);
	p_p.setY(0);

	//作比较
	isOnCircle(c, p_p);

	system("pause");
	return 0;
}

