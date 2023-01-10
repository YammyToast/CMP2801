#include "Square.h"

Square::Square(const int& _x, const int& _y, const int& _edge) : edge(_edge) {
    updateShape(_x, _y);
}

void Square::calculatePoints() {
    points.push_back(leftTop);
    points.push_back(Point(leftTop.getX() + edge, leftTop.getY()));
    points.push_back(Point(leftTop.getX() + edge, leftTop.getY() + edge));
    points.push_back(Point(leftTop.getX(), leftTop.getY() + edge));
}

void Square::calculateArea() {
    area = (double)edge * (double)edge;
}

void Square::move(const int& _newX, const int& _newY) {
    updateShape(_newX, _newY);
}

void Square::scale(const int& _scale) {
    scale(_scale, 0);
}

void Square::scale(const int& _scaleX, const int& _scaleY) {
    edge = edge * _scaleX;
    updateShape(leftTop.getX(), leftTop.getY());
}

void Square::updatePropertyString() {
    std::stringstream ss;
    propertyString = " ";
    ss << "e=" << edge;
    ss >> propertyString;
}

