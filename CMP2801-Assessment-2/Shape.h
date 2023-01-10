#pragma once
#ifndef _SHAPE_
#define _SHAPE_

#include <vector>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include "Point.h"

#include "Movable.h"

class Shape
{
protected:
    double area;
    bool isCircular;
    double perimeter;

    Point leftTop;
    std::vector<Point> points;
    std::string propertyString;
public:
    Shape();

    Shape(const Point& _leftTop);

    /**
     * @brief Calculates the area of the shape and saves to area attributeproperties
     * @returns Void. Result is saved into shape attributeproperties
    */
    virtual void calculateArea() = 0;

    /**
     * @brief Calculates the perimeter of the shape and saves to perimeter attributeproperties     * @returns Void. Result is saved into perimeter attributeproperties
    */
    virtual void calculatePerimeter();

    /**
     * @brief Finds the set of points needed to represent the shape object.
     * @returns Void. Points are pushed into the 'points' vector.
    */
    virtual void calculatePoints() = 0;

    /**
     * @brief Macro Function to update all the properties of a shape. This is called whenever properties have been changed that affect other properties in the object.
     * @returns Void. Internal functions all write to internal properties.
    */
    virtual void updateShape(const int& _x, const int& _y);

    /**
     * @brief Updates the variable responsible for holding the object display string. Essentially this allows for each shape to define how its properties are displayed.
     * @returns Void. New property string is written to the internal property so that it can be called at any time.
    */
    virtual void updatePropertyString() = 0;

    virtual ~Shape() {
        points.clear();
    }

    /**
     * @brief Operator Overload Declaration.
    */
    friend std::ostream& operator<<(std::ostream& _out, const Shape& _self);
};



#endif
