﻿#include <iostream>
#include "easyBot.hpp"
#include "mediumBot.hpp"
#include "game.h"
#include "gameManager.h"

using namespace std;

void clear();

int main()
{
    vector<vector<char>> board = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    // 0 -> empty    1 -> X    2 -> O
    bool isXturn = true;
    unsigned short turnCount = 0;
    unsigned short option;
    repeat:
    bot* aiBot = nullptr;
    cout << "Tic-Tac-Toe Board:" << endl << endl;
    cout << " 1 | 2 | 3 " << endl;
    cout << "---+---+---" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "---+---+---" << endl;
    cout << " 7 | 8 | 9 " << endl << endl;
    cout << "The tic-tac-toe board will look like this. Type the number (1-9)\n";
    cout << "to place either O or X\n";
    clear();
    cout << "\nYou can either play solo or with a friend.\n";
    cout << "There are 4 difficulties to choose:\n\n";
    
    cout << "1 - EASY\n";
    cout << "2 - MEDIUM\n";
    cout << "3 - HARD\n";
    cout << "4 - IMPOSSIBLE TO WIN\n";
    cout << "\n0 - Other modes\n\n";
    cin >> option;
    if ((option < 0 || option > 4) || option == 1)
    {
        cout << "Mode set to easy!";
        aiBot = new easyBot();
    }
    else if (option == 2)
    {
        cout << "Mode set to medium!";
        aiBot = new mediumBot();
    }
    else
    {
        cout << "Not yet implemented! Mode set to easy!";
        aiBot = new easyBot();
    }
    game Game;
    gameManager GameManager;
    Game.clearBoard(board);
    Game.resetGame(isXturn, turnCount, option);
    cin.ignore(); clear();
    while (true)
    {
        turnCount++;
        Game.displayBoard(board);
        if (turnCount >= 10)
        {
            cout << "Its a draw!\n\n";
            break;
        }
        GameManager.playRound(board, isXturn, aiBot);
        isXturn = !isXturn;
        if (Game.winCheck(board, isXturn, turnCount))
        {
            clear();
            Game.displayBoard(board);
            cout << (isXturn ? "O wins!\n" : "X wins!\n");
            cin.ignore();
            break;
        }
        clear();
    }
    delete aiBot;
    cout << "Would you like to play again? (y/n)  ";
    char c;
    cin >> c;
    if (c == 'y')
        goto repeat;
}

void clear()
{
    cin.ignore();
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}