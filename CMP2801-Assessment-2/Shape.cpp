#include "Shape.h"

Shape::Shape()
{
    // If no coordinates are given, create a 'default' point with coordinates 0,0.
    isCircular = false;
    leftTop = Point();
}

Shape::Shape(const Point& _leftTop)
{
    // If a valid Point object is given, uses this Point object as the anchor for the shape.
    leftTop = _leftTop;
}

void Shape::calculatePerimeter()
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

void Shape::updateShape(const int& _x, const int& _y)
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
 * @brief Operator Overload definition. Allows for objects to be streamed to an ostream. Output is a combination of: The shape's unique property string, along with
 * the constant properties of the points, area, and perimeter.
 * @param _out Reference value to an ostream that the properties will be written to.
 * @param _self Reference to a (downcasted) Shape that the properties should be read from.
 * @returns ostream with appended property strings.
 *
*/
std::ostream& operator<<(std::ostream& _out, const Shape& _self)
{
    // Move Address of typeid name to remove the "class" part of the text.
    // typeid can get the type name of derived classes despite _self being a downcasted class.
    _out << "\n" << (typeid(_self).name()) + 6 << ": [" << _self.propertyString << "]\n";
    _out << "Points[";
    for (auto& point : _self.points)
    {
        _out << "(" << point.getX() << "," << point.getY() << ")";
    }
    _out << "]\n";
    _out << "Area=" << _self.area << " Perimeter=" << _self.perimeter;

    return _out;
}