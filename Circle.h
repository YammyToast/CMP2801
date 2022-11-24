#ifndef _CIRCLE_
#define _CIRCLE_

#include "Shape.h"
#include "Movable.h"


class Circle : public Shape, public Movable{
    private:
        int radius;
    public:
        Circle(const int& _x, const int& _y, const int& _radius) : radius(_radius) {
            updateShape(_x, _y);

        }   

        void calculatePoints() {
            points.push_back(leftTop);
            points.push_back(Point(leftTop.getX() + (2 * radius), leftTop.getY() + (2 * radius)));
        }

        void calculateArea() {
            area = 3.14 * std::pow(radius, 2.00);
        }

        void calculatePerimeter() {
            perimeter = 6.18 * radius;
        }

        void move(const int& _newX, const int& _newY) {
            updateShape(_newX, _newY);
        }


        void scale(const int& _scaleX, const int& _scaleY) {
            radius = ((2 * radius) * _scaleX) / 2;
        }

        void updatePropertyString() {
            std::stringstream ss;
            ss << "r=" << radius;
            ss >> propertyString;
        }

        // std::string toString() {
            
        //     return buf.str();
        // }  

        
};

#endif 