#pragma once
#ifndef _POINT_
#define _POINT_

#include <cmath>

class Point {
private:
    int X;
    int Y;
public:
    Point();

    /**
     * @brief Constructs a point given two cartesian coordinates.
     * @param _X Cartesian X coordinate given to the point.
     * @param _Y Cartesian Y coordinate given to the point.
    */
    Point(const int& _X, const int& _Y);

    /**
     * @brief Gets the X coordinate of the point.
     * @returns The X coordinate as int.
    */
    int getX() const;
    /**
     * @brief Gets the Y coordinate of the point.
     * @returns The Y coordinate as int.
    */
    int getY() const;

    /**
     * @brief Calculates the distance to another point object's coordinates (that exists on the same plane) from this point's coordinates.
     * @param _targetPoint Point object to use as the target coordinates.
     * @return Distance from point-to-point as double.
    */
    double distanceToPoint(const Point* _targetPoint);
};

#endif