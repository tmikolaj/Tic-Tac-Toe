#pragma once
#include <vector>
#include "botClass.hpp"

class gameManager {
public:
	void playRound(std::vector<std::vector<char>>&, bool);
	void playRound(std::vector<std::vector<char>>&, bool, bot*);
	void insertValue(std::vector<std::vector<char>>&, unsigned short, bool);
};