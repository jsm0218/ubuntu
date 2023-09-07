#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

class CircleManager {
	Circle *p;
	int size;
	int radius;
	string name;
public:
	CircleManager(int size);
	~CircleManager();
	void searchByName();
	void searchByArea();
};

void Circle::setCircle(string name, int radius) {
	this->name = name;
	this->radius = radius;
}

double Circle::getArea() {
	return radius * radius * 3.14;
}

string Circle::getName() {
	return name;
}

CircleManager::CircleManager (int size) {
	p = new Circle[size];
	this->size = size;
	for (int i=0; i<size; i++) {
		cout << "원 " << i+1 << "의 이름과 반지름 >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius);
	}
}

CircleManager::~CircleManager() {
	delete [] p;
}

void CircleManager::searchByName() {
	cout << "원의 이름 검색  >> ";
	cin >> name;
	for (int i=0; i<size; i++) {
		if (name == p[i].getName()) {
			cout << name << "의 넓이 = " << p[i].getArea() << endl;
		}
	}
}

void CircleManager::searchByArea() {
	cout << "최소 넓이 >> ";
	cin >> radius;
	//cout << radius << endl;
	for (int i=0; i<size; i++) {
		if (radius < p[i].getArea()) {
			cout << p[i].getName() << "의 넓이 = " << p[i].getArea() << endl;
		}
	}
}

int main() {
	int size;
	cout << "원의 개수 >> ";
	cin >> size;
	CircleManager CM(size);
	CM.searchByName();
	CM.searchByArea();

}
