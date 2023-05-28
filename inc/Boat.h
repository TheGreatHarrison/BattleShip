#pragma once


class Boat {
private:
    int x;
    int y;
    int size;
    int ori;
    int health;

public:
    Boat(int x, int y, int size, int ori);

    // Accessor methods
    int getX();
    int getY();
    int getHealth();
    int getOri();
    int getSize();

};