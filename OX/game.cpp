#include <iostream>
#include <string>
#include <vector>
#include "game.h"

void game::displayBoard(const std::vector<std::vector<char>>& board)
{
    std::cout << "Tic-Tac-Toe Board:" << '\n' << '\n';
    std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << '\n';
    std::cout << "---+---+---" << '\n';
    std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << '\n';
    std::cout << "---+---+---" << '\n';
    std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << '\n' << '\n';
    std::cout << "X - 1, O - 2\n\n";
}

bool game::winCheck(const std::vector<std::vector<char>>& board, bool isXturn, unsigned short turnCount)
{
    if (turnCount < 5)
    {
        return false;
    }
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return true;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return true;
    }
    else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }
    return false;
}

void game::clearBoard(std::vector<std::vector<char>>& board)
{
    board = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
}

void game::resetGame(bool& isXturn, unsigned short& turnCount, unsigned short& option)
{
    isXturn = true;
    turnCount = 0;
    option = NULL;
}