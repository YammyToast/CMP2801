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
        
        Point(const int& _X, const int& _Y) : X(_X), Y(_Y) {} 

        int getX() const { return X; }
        int getY() const { return Y; }

        double distanceToPoint(const Point* _targetPoint) {
            return std::sqrt(
                // Potentially remove std::fabs as std::pow MAY convert to positive.
                std::pow(std::fabs((double)X - (double)_targetPoint->X), 2.00)
                +
                std::pow(std::fabs((double)Y - (double)_targetPoint->Y), 2.00)
            );
        }
};

#endif