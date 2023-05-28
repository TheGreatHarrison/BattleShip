#include <iostream>
#include "../inc/boat.h"

Boat::Boat(int x, int y, int size, int ori)
    : x(x), y(y), size(size), ori(ori) {}

    // Accessor methods
    int Boat::getX() {
        return x;
    }

    int Boat::getY() {
        return y;
    }

    int Boat::getHealth() {
        return health;
    }

    int Boat::getOri() {
        return ori;
    }

    int Boat::getSize() {
        return size;
    }