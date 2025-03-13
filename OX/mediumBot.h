#pragma once
#include "botClass.h"

class mediumBot : public bot {
public:
	mediumBot();
	void makeMove(std::vector<std::vector<char>>&) override;
	std::vector< std::pair<int, int>> analyzeBoard(const std::vector<std::vector<char>>&) override;
	std::vector<std::pair<int, int>> closeToWinCheck(const std::vector<std::vector<char>>&) override;
	~mediumBot() override;
};