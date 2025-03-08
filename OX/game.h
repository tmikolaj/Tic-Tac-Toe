#pragma once
#include <vector>
#include <string>

class game {
public:
	void displayBoard(const std::vector<std::vector<char>>&);
	bool winCheck(const std::vector<std::vector<char>>&, bool, unsigned short);
	void clearBoard(std::vector<std::vector<char>>&);
	void resetGame(bool&, unsigned short&, unsigned short&);
};