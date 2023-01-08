#include "Circle.h"

Circle::Circle() {
    radius = 0;
}

Circle::Circle(const int& _x, const int& _y, const int& _radius) : radius(_radius) {
    pi = ((double)std::atan(1) * 4);
    updateShape(_x, _y);

}  

void Circle::calculatePoints() {
    points.push_back(leftTop);
    points.push_back(Point(leftTop.getX() + (2 * radius), leftTop.getY() + (2 * radius)));
}

void Circle::calculateArea() {
    area = pi * std::pow(radius, 2.00);
}

void Circle::calculatePerimeter() {
    perimeter = 2 * pi * radius;
}

void Circle::move(const int& _newX, const int& _newY) {
    updateShape(_newX, _newY);
}

void Circle::scale(const int& _scaleX, const int& _scaleY) {
    radius = ((2 * radius) * _scaleX) / 2;
    updateShape(leftTop.getX(), leftTop.getY());
}

void Circle::updatePropertyString() {
    std::stringstream ss;
    propertyString = " ";
    ss << "r=" << radius;
    ss >> propertyString;
}