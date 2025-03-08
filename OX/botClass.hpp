#pragma once
#include <vector>

class bot {
public:
	bot();
	virtual void makeMove(std::vector<std::vector<char>>&) = 0;
	virtual std::vector<std::pair<int, int>> analyzeBoard(const std::vector<std::vector<char>>&) = 0;
	virtual std::vector<std::pair<int, int>> closeToWinCheck(const std::vector<std::vector<char>>&) = 0;
	virtual ~bot() = 0;
};