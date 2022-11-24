#ifndef _SQUARE_
#define _SQUARE_

#include "Shape.h"
#include "Movable.h"

class Square : public Shape, public Movable {
    private:
        int edge;
    public:
        Square(const int& _x, const int& _y, const int& _edge): edge(_edge) {
            updateShape(_x, _y);
        }

        void calculatePoints() {
            points.push_back(leftTop);
            points.push_back(Point(leftTop.getX() + edge, leftTop.getY()));
            points.push_back(Point(leftTop.getX() + edge, leftTop.getY() + edge));
            points.push_back(Point(leftTop.getX(), leftTop.getY() + edge));
        }
    
        void calculateArea() {
            area = edge * edge;
        }

        void move(const int& _newX, const int& _newY) {
            updateShape(_newX, _newY);
        }

        void scale(const int& _scale) {
            scale(_scale, 0);
        }

        void scale(const int& _scaleX, const int& _scaleY) {
            edge = edge * _scaleX;
        }

        void updatePropertyString() {
            std::stringstream ss;
            ss << "e=" << edge;
            ss >> propertyString;
        }

};

#endif