#include "mediumBot.hpp"

mediumBot::mediumBot() { }

std::vector<std::pair<int, int>> mediumBot::analyzeBoard(const std::vector<std::vector<char>>& board)
{
	std::vector<std::pair<int, int>> res;
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == ' ')
		{
			res.push_back({ i, 0 });
		}
		if (board[i][1] == ' ')
		{
			res.push_back({ i , 1 });
		}
		if (board[i][2] == ' ')
		{
			res.push_back({ i, 2 });
		}
	}
	return res;
}

void mediumBot::makeMove(std::vector<std::vector<char>>& board)
{
	std::vector<std::pair<int, int>> posValues = closeToWinCheck(board);
	if (!posValues.empty())
	{
		int pos = rand() % posValues.size();
		board[posValues[pos].first][posValues[pos].second] = 'O';
	}
	else
	{
		posValues = analyzeBoard(board);
		if (posValues.empty())
			return;
		int pos = rand() % posValues.size();
		board[posValues[pos].first][posValues[pos].second] = 'O';
	}
}

std::vector<std::pair<int, int>> mediumBot::closeToWinCheck(const std::vector<std::vector<char>>& board)
{
	std::vector<std::pair<int, int>> res;
	for (int i = 0; i < 3; i++)
	{
		// row check
		if ((board[i][0] == board[i][1] && board[i][2] == ' ') && board[i][0] != ' ') res.push_back({ i, 2 });
		if ((board[i][0] == board[i][2] && board[i][1] == ' ') && board[i][0] != ' ') res.push_back({ i, 1 });
		if ((board[i][1] == board[i][2] && board[i][0] == ' ') && board[i][1] != ' ') res.push_back({ i, 0 });
		// column check
		if ((board[0][i] == board[1][i] && board[2][i] == ' ') && board[0][i] != ' ') res.push_back({ 2, i });
		if ((board[0][i] == board[2][i] && board[1][i] == ' ') && board[1][i] != ' ') res.push_back({ 1, i });
		if ((board[1][i] == board[2][i] && board[0][i] == ' ') && board[1][i] != ' ') res.push_back({ 0, i });
	}
	// first diagonal check (/)
	if (board[0][0] == board[1][1] && board[2][2] == ' ' && board[0][0] != ' ') res.push_back({ 2, 2 });
	if (board[0][0] == board[2][2] && board[1][1] == ' ' && board[0][0] != ' ') res.push_back({ 1, 1 });
	if (board[1][1] == board[2][2] && board[0][0] == ' ' && board[1][1] != ' ') res.push_back({ 0, 0 });

	// second diagonal check (\)
	if (board[0][2] == board[1][1] && board[2][0] == ' ' && board[0][2] != ' ') res.push_back({ 2, 0 });
	if (board[0][2] == board[2][0] && board[1][1] == ' ' && board[0][2] != ' ') res.push_back({ 1, 1 });
	if (board[1][1] == board[2][0] && board[0][2] == ' ' && board[1][1] != ' ') res.push_back({ 0, 2 });

	return res;
}

mediumBot::~mediumBot() { }