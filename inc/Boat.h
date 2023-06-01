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
    void setX(int x);
    int getY();
    void setY(int Y);
    int getHealth();
    int getOri();
    void setOri(int ori);
    int getSize();

};