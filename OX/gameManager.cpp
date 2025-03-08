#include <iostream>
#include "gameManager.h"

void gameManager::playRound(std::vector<std::vector<char>>& board, bool isXturn)
{
	unsigned short pos = 0;
    if (isXturn)
    {
        std::cout << "X turn!" << '\n';
        isXturn = false;
    }
    else
    {
        std::cout << "O turn!" << '\n';
        isXturn = true;
    }
    insertValue(board, pos, isXturn);
}

void gameManager::playRound(std::vector<std::vector<char>>& board, bool isXturn, bot* aiBot)
{
    if (isXturn)
    {
        unsigned short pos = 0;
        std::cout << "X turn!" << '\n';
        isXturn = false;
        insertValue(board, pos, isXturn);
    }
    else
    {
        std::cout << "O turn!" << '\n';
        isXturn = true;
        aiBot->makeMove(board);
    }
}

void gameManager::insertValue(std::vector<std::vector<char>>& board, unsigned short pos, bool isXturn)
{
    while (true)
    {
        std::cout << "Write here the position: ";
        std::cin >> pos;
        if (pos >= 1 && pos <= 3 && (board[0][pos - 1] != 'X' && board[0][pos - 1] != 'O'))
        {
            board[0][pos - 1] = (isXturn ? 'O' : 'X');
            break;
        }
        else if (pos >= 4 && pos <= 6 && (board[1][pos - 4] != 'X' && board[1][pos - 4] != 'O'))
        {
            board[1][pos - 4] = (isXturn ? 'O' : 'X');
            break;
        }
        else if (pos >= 7 && pos <= 9 && (board[2][pos - 7] != 'X' && board[2][pos - 7] != 'O'))
        {
            board[2][pos - 7] = (isXturn ? 'O' : 'X');
            break;
        }
        else
        {
            std::cout << "The position is incorrect or already occupied!\n";
        }
    }
}