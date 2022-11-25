#ifndef _POINT_
#define _POINT_

#include <cmath>

class Point {
    private:
        int X;
        int Y;
    public:
        Point() {
            X = 0;
            Y = 0;
        }
        
        /**
         * @brief Constructs a point given two cartesian coordinates.
         * @param _X Cartesian X coordinate given to the point.
         * @param _Y Cartesian Y coordinate given to the point.
        */
        Point(const int& _X, const int& _Y) : X(_X), Y(_Y) {} 

        /**
         * @brief Gets the X coordinate of the point.
         * @returns The X coordinate as int.
        */
        int getX() const { return X; }
        /**
         * @brief Gets the Y coordinate of the point.
         * @returns The Y coordinate as int.
        */
        int getY() const { return Y; }

        /**
         * @brief Calculates the distance to another point object's coordinates (that exists on the same plane) from this point's coordinates.
         * @param _targetPoint Point object to use as the target coordinates.
         * @return Distance from point-to-point as double.
        */
        double distanceToPoint(const Point* _targetPoint) {
            // Pythagorean theorem to find the distance between the points.
            return std::sqrt(
                // Potentially remove std::fabs as std::pow MAY convert to positive.
                std::pow(std::fabs((double)X - (double)_targetPoint->X), 2.00)
                +
                std::pow(std::fabs((double)Y - (double)_targetPoint->Y), 2.00)
            );
        }
};

#endif