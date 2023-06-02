#pragma once
#include "../inc/Boat.h"
#include <array>


class Player {
private:
    char** playerBoard;
    char** enemyBoard;
    std::array<Boat,4> boatArr;
    int health = boatArr[0].getHealth() + boatArr[1].getHealth() + boatArr[2].getHealth() + boatArr[3].getHealth();

public:
    Player(char** playerBoard, char** enemyBoard, std::array<Boat,4> &boatArr);

    // Accessor methods
    int takeShot(int x, int y, char** DefensiveBoard);
    int getHealth();
    char** getPlayerBoard();
    char** getEnemyBoard();
    int defendShot(int x, int y);
    Boat getBoat(std::array<Boat,4> &boatArr, int number);

};