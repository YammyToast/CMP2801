#ifndef _CIRCLE_
#define _CIRCLE_

#include "Shape.h"
#include "Movable.h"

#include <cmath>

class Circle : public Shape, public Movable{
    private:
        int radius;
        double pi;
    public:
        
        Circle(const int& _x, const int& _y, const int& _radius) : radius(_radius) {
            pi = ((double)std::atan(1) * 4);
            updateShape(_x, _y);

        }   

        // Implementation of calculatePoints for a circle.
        void calculatePoints() {
            points.push_back(leftTop);
            points.push_back(Point(leftTop.getX() + (2 * radius), leftTop.getY() + (2 * radius)));
        }

        // Area of a circle equation.
        void calculateArea() {
            area = pi * std::pow(radius, 2.00);
        }

        // Unique perimeter definition using circle equation.
        void calculatePerimeter() {
            perimeter = 2 * pi * radius;
        }

        // A move can be processed by calling the updateShape macro (which requires an anchor Point object).
        void move(const int& _newX, const int& _newY) {
            updateShape(_newX, _newY);
        }

        // Scale method for circles. As circles are isotrophic, only one value is used for the scale.
        void scale(const int& _scaleX, const int& _scaleY) {
            radius = ((2 * radius) * _scaleX) / 2;
            updateShape(leftTop.getX(), leftTop.getY());
        }
        
        // Updates this shape's string property with its unique attribute.
        void updatePropertyString() {
            std::stringstream ss;
            propertyString = " ";
            ss << "r=" << radius;
            ss >> propertyString;
        }

        // std::string toString() {
            
        //     return buf.str();
        // }  

        
};

#endif 