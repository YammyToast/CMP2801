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
    Shape()
    {
        // If no coordinates are given, create a 'default' point with coordinates 0,0.
        leftTop = Point();
    }
    Shape(const Point &_leftTop)
    {
        // If a valid Point object is given, uses this Point object as the anchor for the shape.
        leftTop = _leftTop;
    }

    /**
     * @brief Calculates the area of the shape and saves to area attributeproperties
     * @returns Void. Result is saved into shape attributeproperties
    */
    virtual void calculateArea() = 0;

    /**
     * @brief Calculates the perimeter of the shape and saves to perimeter attributeproperties     * @returns Void. Result is saved into perimeter attributeproperties
    */
    virtual void calculatePerimeter()
    {
        // This algorithm requires more than 2 points to work.
        if (points.size() > 2)
        {
            int newPerimeter = 0;
            // Connect points in the shape together and use distance as 'perimeter lines'/edges.
            // Sum up these edges to find the perimeter.
            for (size_t it = 0; it < (points.size() - 1); ++it)
            {
                newPerimeter += points.at(it).distanceToPoint(&points.at(it + 1));
            }
            // Complete the perimeter loop.
            newPerimeter += points.front().distanceToPoint(&points.back());
            // Write new perimeter sum to perimeter attributeproperties
            perimeter = newPerimeter;
        }
    };

    /**
     * @brief Finds the set of points needed to represent the shape object.
     * @returns Void. Points are pushed into the 'points' vector. 
    */
    virtual void calculatePoints() = 0;

    /**
     * @brief Macro Function to update all the properties of a shape. This is called whenever properties have been changed that affect other properties in the object.
     * @returns Void. Internal functions all write to internal properties.
    */
    virtual void updateShape(const int &_x, const int &_y)
    {
        points.clear();
        leftTop = Point(_x, _y);
        // Calculating points has to be done first as Area and Perimeter can rely on points.
        calculatePoints();
        calculateArea();
        calculatePerimeter();
        // Update the property string now that all of the properties have been updated.
        updatePropertyString();
    }

    /**
     * @brief Updates the variable responsible for holding the object display string. Essentially this allows for each shape to define how its properties are displayed.
     * @returns Void. New property string is written to the internal property so that it can be called at any time.
    */
    virtual void updatePropertyString() = 0;
    /**
     * @brief Operator Overload Declaration.
    */
    friend std::ostream& operator<<(std::ostream &_out, const Shape& _self);
};

/**
 * @brief Operator Overload definition. Allows for objects to be streamed to an ostream. Output is a combination of: The shape's unique property string, along with
 * the constant properties of the points, area, and perimeter.
 * @param _out Reference value to an ostream that the properties will be written to.
 * @param _self Reference to a (downcasted) Shape that the properties should be read from.
 * @returns ostream with appended property strings.
 * 
*/
std::ostream& operator<<(std::ostream &_out, const Shape& _self)
{
    // Trim first character of typeid name as its the length of the name?
    // Move pointer forwards once address to trim the number.
    // typeid can get the type name of derived classes despite _self being a downcasted class.
    _out << (typeid(_self).name()) + 1 << ": [" << _self.propertyString << "]\n";
    _out << "Points[";
    for (auto &point : _self.points)
    {
        _out << "(" << point.getX() << "," << point.getY() << ")";
    }
    _out << "]\n";
    _out << "Area=" << _self.area << " Perimeter=" << _self.perimeter;

    return _out;
}

#endif
