
#include <iostream>

#include "../inc/boat.h"

void PrintBoard(char** board) 
{
    std::cout << "@  "; // Top corner 
    for (int p = 1 ; p <= 10; p++) //  Print numbers along the top
    {
        std::cout << p << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < 10; ++i) {

        std::cout << i+1 << " "; //  Print the numbers along the left edge
        if (i != 9) { // Odd spacing for when 2 char 10 is put on baord and it throws out the lines
            std::cout << " ";
        }
        for (int j = 0; j < 10; ++j) {
            std::cout << board[i][j] << " "; 
        }
        std::cout << "\n";
    }
}

int checkBoat (Boat boat, char** board)
{
    int x=0, y=0, ori=0, size=0;
    x = boat.getX();
    y = boat.getY();
    ori = boat.getOri();
    size = boat.getSize();

    if (ori == 0 && (x+size > 9 || x < 1)) {
        return 0;
    } else if (ori == 2 && (y+size > 9 || y < 1)) {
        return 0;
    } else if (board[x-1][y-1] == '@') 
    {
        return 0 ;
    }
    board[y-1][x-1] = '@'; 
    for (int i = 0 ; i < size-1; i++) 
    {
        if(ori == 0)
        {
            x++;
        } else {
            y++;
        }
        if (board[y-1][x-1] == '@') 
        {
            return 0;
        }
        board[y-1][x-1] = '@'; 
    }
    PrintBoard(board);
    return 1;
}

Boat PlaceShip(int size, char** board)
{
    int x=0,y=0,ori=0;
    std::cout << "You are placing Boat of size " << size << "\n";
    std::cout << "Input your x y coor: ";
    std::cin >> x >> y;
    std::cout <<"Input oritentation 1 = vertical 0 = horizontal: ";
    std::cin >> ori;
    Boat boat(x, y, size, ori);
    if (checkBoat(boat, board) == 0)
    {
        std::cout << "invalid placement\n";
        return PlaceShip(size, board);
    } else {
        return boat;
    }
}

char** EstablishBoard()
{
    char** array = new char*[10];  // Allocate memory for rows
    for (int i = 0; i < 10; ++i) {
        array[i] = new char[10];  // Allocate memory for columns of each row
        for (int j = 0; j < 10; ++j) {
            array[i][j] = '~';
        }
    }
    return array;  // Return the pointer to the 2D array
}

int main() {

    char** PlayerBoard;
    PlayerBoard = EstablishBoard();
    
    printf("Welcome to Battle Ships\n");
    printf("Place your boats\n");
    Boat boat2 = PlaceShip(2, PlayerBoard);
    Boat boat3 = PlaceShip(3, PlayerBoard);
    Boat boat4 = PlaceShip(4, PlayerBoard);
    Boat boat5 = PlaceShip(5, PlayerBoard);

    return 0;
}
