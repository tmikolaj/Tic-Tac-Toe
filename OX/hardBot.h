#pragma once
#include "botClass.h"

class hardBot : public bot {
public:
	hardBot();
	void makeMove(std::vector<std::vector<char>>&) override;
	std::vector< std::pair<int, int>> analyzeBoard(const std::vector<std::vector<char>>&) override;
	std::vector<std::pair<int, int>> closeToWinCheck(const std::vector<std::vector<char>>&) override;
	~hardBot() override;
};