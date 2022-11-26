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

        // Implementation of calculatePoints for a rectangle.
        void calculatePoints() {
            points.push_back(leftTop);
            points.push_back(Point(leftTop.getX() + width, leftTop.getY()));
            points.push_back(Point(leftTop.getX() + width, leftTop.getY() + height));
            points.push_back(Point(leftTop.getX(), leftTop.getY() + height));
        }

        // Area of a rectangle equation.
        void calculateArea() {
            area = height * width;
        }

        // A move can be processed by calling the updateShape macro (which requires an anchor Point object).
        void move(const int& _newX, const int& _newY) {
            updateShape(_newX, _newY);
        }

        // As the square type is isotropic, only one scale value is needed. This function calls the two-parameter scale method as defined in the interface, 
        // filling the other parameter with an empty value.
        void scale(const int& _scaleX, const int& _scaleY) {
            height = height * _scaleY;
            width = width * _scaleX;
            updateShape(leftTop.getX(), leftTop.getY());
        }

        // Updates this shape's string property with its unique attribute.
        void updatePropertyString() {
            std::stringstream ss;
            propertyString = " ";
            ss << "h=" << height << ",w=" << width;
            ss >> propertyString;
        }

};


#endif