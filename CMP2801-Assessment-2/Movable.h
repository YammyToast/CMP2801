#pragma once
#ifndef _MOVABLE_
#define _MOVABLE_

class Movable {
public:
    // Pure Virtual Functions to imply an interface required for movable objects.
    virtual void move(const int& _newX, const int& _newY) = 0;
    virtual void scale(const int& _scaleX, const int& _scaleY) = 0;
};

#endif