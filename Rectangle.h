#ifndef _RECTANGLE_
#define _RECTANGLE_

#include "Shape.h"
#include "Movable.h"

 

class Rectangle : public Shape, public Movable {
    private:
        int height;
        int width;
    public:
        Rectangle(const int& _x, const int& _y, const int& _height, const int& _width): height(_height), width(_width){
            updateShape(_x, _y);
        }


        void calculatePoints() {
            points.push_back(leftTop);
            points.push_back(Point(leftTop.getX() + width, leftTop.getY()));
            points.push_back(Point(leftTop.getX() + width, leftTop.getY() + height));
            points.push_back(Point(leftTop.getX(), leftTop.getY() + height));
        }

        void calculateArea() {
            area = height * width;
        }


        void move(const int& _newX, const int& _newY) {
            updateShape(_newX, _newY);
        }

        void scale(const int& _scaleX, const int& _scaleY) {
            height = height * _scaleY;
            width = width * _scaleX;
        }

        void updatePropertyString() {
            std::stringstream ss;
            ss << "h=" << height << ",w=" << width;
            ss >> propertyString;
        }
};

#endif