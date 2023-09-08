// Write a program to access the private user radius for a circle that uses another function print_area() to find the area of a circle using FRIEND function

#include <iostream>
#include <cmath>
using namespace std;
class Circle;
class Calculator {
public:
    static double calculateArea(const Circle& circle);
};
class Circle {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    friend double Calculator::calculateArea(const Circle& circle);
};
double Calculator::calculateArea(const Circle& circle) {
    double area = 3.14159265359 * pow(circle.radius, 2);
    return area;
}
int main() {
    double radius;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    Circle circle(radius);
    double area = Calculator::calculateArea(circle);
    cout << "Area of the circle with radius " << radius << " is: " << area << endl;
    return 0;
}
