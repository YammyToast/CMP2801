#include "Rectangle.h"

Rectangle::Rectangle(const int& _x, const int& _y, const int& _height, const int& _width) : height(_height), width(_width){
    updateShape(_x, _y);
}

void Rectangle::calculatePoints() {
    points.push_back(leftTop);
    points.push_back(Point(leftTop.getX() + width, leftTop.getY()));
    points.push_back(Point(leftTop.getX() + width, leftTop.getY() + height));
    points.push_back(Point(leftTop.getX(), leftTop.getY() + height));
}

void Rectangle::calculateArea() {
    area = height * width;
}

void Rectangle::move(const int& _newX, const int& _newY) {
    updateShape(_newX, _newY);
}

void Rectangle::scale(const int& _scaleX, const int& _scaleY) {
    height = height * _scaleY;
    width = width * _scaleX;
    updateShape(leftTop.getX(), leftTop.getY());
}

void Rectangle::updatePropertyString() {
    std::stringstream ss;
    propertyString = " ";
    ss << "h=" << height << ",w=" << width;
    ss >> propertyString;
}
