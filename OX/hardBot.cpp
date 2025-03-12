#include "hardBot.h"

hardBot::hardBot() { }

std::vector<std::pair<int, int>> hardBot::analyzeBoard(const std::vector<std::vector<char>>& board)
{
	std::vector<std::pair<int, int>> res;

	if (board[1][1] == ' ') { res.push_back({ 1, 1 }); return res; }
	if (board[0][0] == ' ') res.push_back({ 0, 0 });
	if (board[0][2] == ' ') res.push_back({ 0, 2 });
	if (board[2][0] == ' ') res.push_back({ 2, 0 });
	if (board[2][2] == ' ') res.push_back({ 2, 2 });

	if (res.empty())
	{
		if (board[0][1] == ' ') res.push_back({ 0, 1 });
		if (board[1][0] == ' ') res.push_back({ 1, 0 });
		if (board[1][2] == ' ') res.push_back({ 1, 2 });
		if (board[2][1] == ' ') res.push_back({ 2, 1 });
	}
	return res;
}

void hardBot::makeMove(std::vector<std::vector<char>>& board)
{
	std::vector<std::pair<int, int>> posValues = closeToWinCheck(board);
	if (!posValues.empty())
	{
		int random = rand() % posValues.size();
		board[posValues[random].first][posValues[random].second] = 'O';
	}
	else
	{
		posValues = analyzeBoard(board);
		if (posValues.empty())
			return;
		int random = rand() % posValues.size();
		board[posValues[random].first][posValues[random].second] = 'O';
	}
}

std::vector<std::pair<int, int>> hardBot::closeToWinCheck(const std::vector<std::vector<char>>& board)
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

hardBot::~hardBot() { }