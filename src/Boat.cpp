#include <iostream>
#include "../inc/boat.h"

// Default constructor
Boat::Boat() : x(0), y(0), size(0), ori(0), health(0) {}

Boat::Boat(int x, int y, int size, int ori)
    : x(x), y(y), size(size), ori(ori) {}

    // Accessor methods
    int Boat::getX() 
    {
        return x;
    }

    void Boat::setX(int x) 
    {
        this->x = x;
    }

    int Boat::getY() 
    {
        return y;
    }

    void Boat::setY(int y) 
    {
        this->y = y;
    }

    int Boat::getHealth() 
    {
        return health;
    }

    int Boat::getOri() 
    {
        return ori;
    }

    void Boat::setOri(int ori) 
    {
        this->ori = ori;
    }

    int Boat::getSize() 
    {
        return size;
    }