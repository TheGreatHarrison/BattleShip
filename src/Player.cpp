#include <iostream>
#include "../inc/Player.h"

Player::Player(char** playerBoard, char** enemyBoard, std::array<Boat,4> &boatArr)
    : playerBoard(playerBoard), enemyBoard(enemyBoard), boatArr(boatArr) {}

    // Accessor methods
    char** Player::getPlayerBoard() {
        return playerBoard;
    }

    char** Player::getEnemyBoard() {
        return enemyBoard;
    }

    int Player::defendShot(int x, int y) { // TODO
        return 1;
    }

    int Player::takeShot(int x, int y, char** DefensiveBoard) {
        char** board = this->getEnemyBoard();
        if (DefensiveBoard[y-1][x-1] == '@') {
            board[y-1][x-1] = 'X';
            return 1;
        } else {
            board[y-1][x-1] = 'O';
            return 0;
        }
        return 1;

    }

    Boat getBoat(std::array<Boat,4> &boatArr, int number) {
        return boatArr[number-2];
    }

    int Player::getHealth() {
        return health;
    }
