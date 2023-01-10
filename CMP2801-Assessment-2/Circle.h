#pragma once
#ifndef _CIRCLE_
#define _CIRCLE_

#include "Shape.h"
#include "Movable.h"

#include <cmath>

class Circle : public Shape, public Movable {
private:
    int radius;
    double pi;
public:
    Circle();
    Circle(const int& _x, const int& _y, const int& _radius);

    // Implementation of calculatePoints for a circle.
    void calculatePoints();

    // Area of a circle equation.
    void calculateArea();

    // Unique perimeter definition using circle equation.
    void calculatePerimeter();

    // A move can be processed by calling the updateShape macro (which requires an anchor Point object).
    void move(const int& _newX, const int& _newY);

    // Scale method for circles. As circles are isotrophic, only one value is used for the scale.
    void scale(const int& _scaleX, const int& _scaleY);

    // Updates this shape's string property with its unique attribute.
    void updatePropertyString();

    // std::string toString() {

    //     return buf.str();
    // }  


};

#endif 