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
		cout << "Circle " << i+1 << " Name & Radius >> ";
		cin >> name >> radius;
		p[i].setCircle(name, radius);
	}
}

CircleManager::~CircleManager() {
	delete [] p;
}

void CircleManager::searchByName() {
	cout << "Search Circle Name >> ";
	cin >> name;
	for (int i=0; i<size; i++) {
		if (name == p[i].getName()) {
			cout << name << " area = " << p[i].getArea() << endl;
		}
	}
}

void CircleManager::searchByArea() {
	cout << "Enter Min Area >> ";
	cin >> radius;
	cout << "Search for a Circle greater than " << radius << endl;
	for (int i=0; i<size; i++) {
		if (radius < p[i].getArea()) {
			cout << p[i].getName() << " Area = " << p[i].getArea() << endl;
		}
	}
}

int main() {
	int size;
	cout << "the number of Circles >> ";
	cin >> size;
	CircleManager CM(size);
	CM.searchByName();
	CM.searchByArea();

}
