#include "Shape.h"

Shape::Shape()
{
    // If no coordinates are given, create a 'default' point with coordinates 0,0.
    leftTop = Point();
}

Shape::Shape(const Point &_leftTop)
{
    // If a valid Point object is given, uses this Point object as the anchor for the shape.
    leftTop = _leftTop;
}

Shape::calculatePerimeter()
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

Shape::updateShape(const int &_x, const int &_y)
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

