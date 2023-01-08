#ifndef _RECTANGLE_
#define _RECTANGLE_

#include "Shape.h"
#include "Movable.h"

class Rectangle : public Shape, public Movable {
    private:
        int height;
        int width;
    public:
    
        Rectangle(const int& _x, const int& _y, const int& _height, const int& _width);

        // Implementation of calculatePoints for a rectangle.
        void calculatePoints();

        // Area of a rectangle equation.
        void calculateArea();

        // A move can be processed by calling the updateShape macro (which requires an anchor Point object).
        void move(const int& _newX, const int& _newY);

        // As the square type is isotropic, only one scale value is needed. This function calls the two-parameter scale method as defined in the interface, 
        // filling the other parameter with an empty value.
        void scale(const int& _scaleX, const int& _scaleY);

        // Updates this shape's string property with its unique attribute.
        void updatePropertyString();

};


#endif