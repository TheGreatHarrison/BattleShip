#pragma once
#include "../inc/Boat.h"
#include <array>


class Player {
private:
    char** playerBoard;
    char** enemyBoard;
    std::array<Boat,4> boatArr;
    int health = 2+3+4+5;

public:
    Player(char** playerBoard, char** enemyBoard, std::array<Boat,4> &boatArr);

    // Accessor methods
    int takeShot(int x, int y, char** DefensiveBoard);
    int getHealth();
    void reduceHealth();
    char** getPlayerBoard();
    char** getEnemyBoard();
    int defendShot(int x, int y);
    Boat getBoat(std::array<Boat,4> &boatArr, int number);

};