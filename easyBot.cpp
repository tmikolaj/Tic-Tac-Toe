#include <vector>
#include <utility>
#include <stdlib.h>
#include <ctime>
#include "easyBot.hpp"

easyBot::easyBot() { }

std::vector<std::pair<int, int>> easyBot::analyzeBoard(const std::vector<std::vector<int>>& board)
{
	std::vector<std::pair<int, int>> posValues;
	int temp = 0;
	for (int j = 0; j < 3; j++)
	{
		if (board[j][temp] == 0)
		{
			posValues.push_back({ j, temp });
		}
		temp += 1;
		if (board[j][temp] == 0)
		{
			posValues.push_back({ j, temp });
		}
		temp += 1;
		if (board[j][temp] == 0)
		{
			posValues.push_back({ j, temp });
		}
		temp = 0;
	}
	return posValues;
}

void easyBot::makeMove(std::vector<std::vector<int>>& board)
{
	srand(time(0));
	std::vector<std::pair<int, int>> posValues = analyzeBoard(board);
	if (posValues.size() <= 0)
		return;
	int pos = rand() % posValues.size();
	board[posValues[pos].first][posValues[pos].second] = 2;
}

std::pair<int, int> easyBot::closeToWinCheck(const std::vector<std::vector<int>>& board) { return { -1, -1 }; }

easyBot::~easyBot() { }