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

        // Implementation of calculatePoints for a square.
        void calculatePoints() {
            points.push_back(leftTop);
            points.push_back(Point(leftTop.getX() + edge, leftTop.getY()));
            points.push_back(Point(leftTop.getX() + edge, leftTop.getY() + edge));
            points.push_back(Point(leftTop.getX(), leftTop.getY() + edge));
        }
    
        // As the square type is isotropic, area can be calculated using edge^2.
        void calculateArea() {
            area = (double)edge * (double)edge;
        }
        
        // A move can be processed by calling the updateShape macro (which requires an anchor Point object).
        void move(const int& _newX, const int& _newY) {
            updateShape(_newX, _newY);
        }

        // As the square type is isotropic, only one scale value is needed. This function calls the two-parameter scale method as defined in the interface, 
        // filling the other parameter with an empty value.
        void scale(const int& _scale) {
            scale(_scale, 0);
        }

        // Check above function for implementation. This method performs the actual scale on the shape.
        // As all of the dependents parameters for this shape are set from the edge value, we simply scale the edge, and call for all of the properties to be updated.
        void scale(const int& _scaleX, const int& _scaleY) {
            edge = edge * _scaleX;
            updateShape(leftTop.getX(), leftTop.getY());
        }

        // Updates this shape's string property with its unique attribute.
        void updatePropertyString() {
            std::stringstream ss;
            propertyString = " ";
            ss << "e=" << edge;
            ss >> propertyString;
        }



};

#endif