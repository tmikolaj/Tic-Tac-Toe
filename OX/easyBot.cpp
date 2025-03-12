#include "easyBot.hpp"

easyBot::easyBot() { }

std::vector<std::pair<int, int>> easyBot::analyzeBoard(const std::vector<std::vector<char>>& board)
{
	std::vector<std::pair<int, int>> posValues;
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == ' ')
		{
			posValues.push_back({ i, 0 });
		}
		if (board[i][1] == ' ')
		{
			posValues.push_back({ i, 1 });
		}
		if (board[i][2] == ' ')
		{
			posValues.push_back({ i, 2 });
		}
	}
	return posValues;
}

void easyBot::makeMove(std::vector<std::vector<char>>& board)
{
	std::vector<std::pair<int, int>> posValues = closeToWinCheck(board);
	int random = rand() % 4; // Sometimes the bot will block the win or go for the win and sometimes not
	if (!posValues.empty() && random == 0)
	{
		int pos = rand() % posValues.size();
		board[posValues[pos].first][posValues[pos].second] = 'O';
	}
	else
	{
		posValues = analyzeBoard(board);
		if (posValues.empty())
			return;
		random = rand() % posValues.size();
		board[posValues[random].first][posValues[random].second] = 'O';
	}
}

// Does not check diagonally! Was intended!
std::vector<std::pair<int, int>> easyBot::closeToWinCheck(const std::vector<std::vector<char>>& board)
{
	std::vector<std::pair<int, int>> res;
	for (int i = 0; i < 3; i++)
	{
		if ((board[i][0] == board[i][1] && board[i][2] == ' ') && board[i][0] != ' ')
		{
			res.push_back({ i, 2 });
		}
		if ((board[i][0] == board[i][2] && board[i][1] == ' ') && board[i][0] != ' ')
		{
			res.push_back({ i, 1 });
		}
		if ((board[i][1] == board[i][2] && board[i][0] == ' ') && board[i][1] != ' ')
		{
			res.push_back({ i, 0 });
		}
		if ((board[0][i] == board[1][i] && board[2][i] == ' ') && board[0][i] != ' ')
		{
			res.push_back({ 2, i });
		}
		if ((board[0][i] == board[2][i] && board[1][i] == ' ') && board[1][i] != ' ')
		{
			res.push_back({ 1, i });
		}
		if ((board[1][i] == board[2][i] && board[0][i] == ' ') && board[1][i] != ' ')
		{
			res.push_back({ 0, i });
		}
	}
	return res;
}

easyBot::~easyBot() { }