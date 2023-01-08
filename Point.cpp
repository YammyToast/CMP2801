#include "Point.h"

Point::Point() {
    X = 0;
    Y = 0;

}

Point::Point(const int& _X, const int& _Y) : X(_X), Y(_Y) {};

int Point::getX() const {
    return X;
}

int Point::getY() const {
    return Y;
}

double Point::distanceToPoint(const Point* _targetPoint)  {
    // Pythagorean theorem to find the distance between the points.
    return std::sqrt(
    // Potentially remove std::fabs as std::pow MAY convert to positive.
        std::pow(std::fabs((double)X - (double)_targetPoint->X), 2.00)
        +
        std::pow(std::fabs((double)Y - (double)_targetPoint->Y), 2.00)
    );
}