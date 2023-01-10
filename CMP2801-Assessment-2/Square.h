#pragma once
#ifndef _SQUARE_
#define _SQUARE_

#include "Shape.h"
#include "Movable.h"

class Square : public Shape, public Movable {
private:
    int edge;
public:
    Square(const int& _x, const int& _y, const int& _edge);

    // Implementation of calculatePoints for a square.
    void calculatePoints();

    // As the square type is isotropic, area can be calculated using edge^2.
    void calculateArea();

    // A move can be processed by calling the updateShape macro (which requires an anchor Point object).
    void move(const int& _newX, const int& _newY);

    // As the square type is isotropic, only one scale value is needed. This function calls the two-parameter scale method as defined in the interface, 
    // filling the other parameter with an empty value.
    void scale(const int& _scale);

    // Check above function for implementation. This method performs the actual scale on the shape.
    // As all of the dependents parameters for this shape are set from the edge value, we simply scale the edge, and call for all of the properties to be updated.
    void scale(const int& _scaleX, const int& _scaleY);

    // Updates this shape's string property with its unique attribute.
    void updatePropertyString();



};

#endif