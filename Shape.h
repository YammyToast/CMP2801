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
        leftTop = Point();
    }
    Shape(const Point &_leftTop)
    {
        leftTop = _leftTop;
    }
    virtual void calculateArea() = 0;

    virtual void calculatePerimeter()
    {
        if (points.size() > 2)
        {
            int newPerimeter = 0;
            for (size_t it = 0; it < (points.size() - 1); ++it)
            {
                newPerimeter += points.at(it).distanceToPoint(&points.at(it + 1));
            }
            // Complete the perimeter loop.
            newPerimeter += points.front().distanceToPoint(&points.back());

            perimeter = newPerimeter;
        }
    };

    virtual void calculatePoints() = 0;

    virtual void updateShape(const int &_x, const int &_y)
    {
        leftTop = Point(_x, _y);
        calculatePoints();
        calculateArea();
        calculatePerimeter();
        updatePropertyString();
    }

    virtual void updatePropertyString() = 0;
    friend std::ostream& operator<<(std::ostream &_out, const Shape& _self);
};

std::ostream& operator<<(std::ostream &_out, const Shape& _self)
{
    std::cout << "test" << std::endl;
    _out << typeid(_self).name() << ": [" << _self.propertyString << "]\n";
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
