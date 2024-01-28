
#include <iostream>
#include <cstdlib>

#include "../inc/boat.h"
#include "../inc/Player.h"
#include <array>

void PrintBoard(char** board) 
{
    std::cout << "@  "; // Top corner 
    for (int p = 1 ; p <= 10; p++) //  Print numbers along the top
    {
        std::cout << p << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < 10; ++i) 
    {

        std::cout << i+1 << " "; //  Print the numbers along the left edge
        if (i != 9) // Odd spacing for when 2 char 10 is put on baord and it throws out the lines
        {
            std::cout << " ";
        }
        for (int j = 0; j < 10; ++j) 
        {
            std::cout << board[i][j] << " "; 
        }
        std::cout << "\n";
    }
}

int checkBoat(Boat boat, char** board, int pc)
{
    int x=0, y=0, ori=0, size=0;
    x = boat.getX();
    y = boat.getY();
    ori = boat.getOri();
    size = boat.getSize();

    if (ori == 1 && (y+size > 10 || x < 1)) 
    {
        return 0;
    } else if (ori == 0 && (x+size > 10 || y < 1)) 
    {
        return 0;
    } else if (board[y-1][x-1] == '@') 
    {
        return 0 ;
    }
    board[y-1][x-1] = '@'; 
    for (int i = 0 ; i < size-1; i++) 
    {
        if(ori == 0)
        {
            x++;
        } else 
        {
            y++;
        }
        if (board[y-1][x-1] == '@') 
        {
            return 0;
        }
        board[y-1][x-1] = '@'; 
    }
    if (pc == 0) 
    {
        PrintBoard(board);
    }
    return 1;
}

Boat PlaceShip(int size, char** board)
{
    int x=0,y=0,ori=0;
    std::cout << "Place Boat - Length " << size << ": \n";
    std::cout << "Input your X Y coord: ";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> x >> y;
    while(std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Invalid input - Try again:\n";
        std::cout << "Input your X Y coord: ";
        std::cin >> x >> y;
    }
    std::cout <<"Orientation: \nVertical - 1  Horizontal - 0 : \n";
    std::cin.clear();
    std::cin.ignore();
    std::cin >> ori;
    while(std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Invalid input - Try again:\n";
        std::cout <<"Orientation: \nVertical - 1  Horizontal - 0 : ";
        std::cin >> ori;
    }

    Boat boat(x, y, size, ori);
    if (checkBoat(boat, board, 0) == 0)
    {
        std::cout << "Invalid Placement - Try again\n";
        return PlaceShip(size, board);
    } else 
    {
        return boat;
    }
}

char** EstablishBoard() // Make empty board 
{
    char** array = new char*[10];  // Allocate memory for rows
    for (int i = 0; i < 10; ++i) 
    {
        array[i] = new char[10];  // Allocate memory for columns of each row
        for (int j = 0; j < 10; ++j) 
        {
            array[i][j] = '~';
        }
    }
    return array;  // Return the pointer to the 2D array
}

Boat PlacePCShip(int size, char ** board) 
{
    int x=0, y=0, ori=0;
    srand(time(NULL));
    x = rand() % 9 + 1;
    y = rand() % 9 + 1;
    ori = rand() % 2;
    Boat boat(x, y, size, ori);
    while (checkBoat(boat, board, 1) == 0) 
    {
        int x = rand() % 10 + 1;
        int y = rand() % 10 + 1;
        int ori = rand() % 2;
        boat.setX(x);
        boat.setY(y);
        boat.setOri(ori);
    }
    return boat;
}

int main() 
{

    char** playerDefensiveBoard;
    char** playerAttackBoard;
    playerDefensiveBoard = EstablishBoard();    // Construct empty Board to be populated
    playerAttackBoard = EstablishBoard();       // Construct empty Board
    
    printf("Welcome to Battle Ships\n");

    // Place player Boats
    printf("Place your boats\n");
    std::array<Boat, 4> boatArr;
    for (int j = 2 ; j <= 5 ; j++)
    {
        boatArr[j-2] = PlaceShip(j, playerDefensiveBoard);
    }
    Player player(playerDefensiveBoard, playerAttackBoard, boatArr);

    char** pcDefensiveBoard;
    char** pcAttackBoard;

    pcDefensiveBoard = EstablishBoard();
    pcAttackBoard = EstablishBoard();

    // Place pc boats
    std::array<Boat, 4> pcBoatArr;
    for (int j = 2 ; j <= 5 ; j++) 
    {
        pcBoatArr[j-2] = PlacePCShip(j, pcDefensiveBoard);
    }

    Player pc(pcDefensiveBoard, pcAttackBoard, pcBoatArr);

    int playerShot = 0;
    int x = 0, y = 0;
    int pcShot = 0;
    int i = 0;
    int gameover = 0;
    while(!gameover) // pc.getHealth() > 0 && player.getHealth()
    {
        std::cout << "Take your shot: \n";
        std::cout << "Input x y coordinates: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> x >> y;
        std::cout << "\n";
        playerShot = player.takeShot(x, y, pc.getPlayerBoard());
        while(playerShot == -1 || std::cin.fail()) 
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Out of bounds or you already shot there!\nTry again\n";
            std::cout << "Input different x y coordinates: ";
            std::cin >> x >> y;
            std::cout << "\n";
            if (x>10 || x<0 || y>10 || y<0)
            {
                playerShot = -1;
            } else
            {
                playerShot = player.takeShot(x, y, pc.getPlayerBoard());
            }
        }
        if (playerShot == 1) 
        {
            pc.reduceHealth();
        }
        std::cout << "     Offensive Map \n";
        PrintBoard(player.getEnemyBoard());

        // pc player takes a shot
        srand(time(NULL));
        x = rand() % 10 + 1;
        y = rand() % 10 + 1;
        pcShot = pc.takeShot(x, y, player.getPlayerBoard());
        while(pcShot == -1) 
        {
            x = rand() % 10 + 1;
            y = rand() % 10 + 1;
            pcShot = pc.takeShot(x, y, player.getPlayerBoard());
        }
        if (pcShot == 1) 
        {
            player.reduceHealth();
        }

        std::cout << "     Defensive Map \n";
        PrintBoard(player.getPlayerBoard());
        i++;

        // Check game status
        if (pc.getHealth() <= 0 || player.getHealth() <= 0) 
        {
            gameover = 1;
        }
    }

    // Work out the winner
    if (pc.getHealth() == 0) 
    {
        std::cout << "YOU WIN!!!";
    } else 
    {
        std::cout << "YOU LOST!!!";
    }

    return 0;
}