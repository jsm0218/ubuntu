#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	double getArea();
	double getPerimeter();
};

double Circle::getArea() {
	return radius*radius*3.14;
}

double Circle::getPerimeter() {
	return radius*2*3.14;
}

int main() {
	Circle circle;
	cin >> circle.radius;
	cout << circle.getArea() << endl;
	cout << circle.getPerimeter() << endl;
}
