#pragma once
#include <vector>
#include <utility>
#include "botClass.hpp"

class easyBot : public bot {
public:
	easyBot();
	void makeMove(std::vector<std::vector<char>>&) override;
	std::vector< std::pair<int, int>> analyzeBoard(const std::vector<std::vector<char>>&) override;
	std::vector<std::pair<int, int>> closeToWinCheck(const std::vector<std::vector<char>>&) override;
	~easyBot() override;
};