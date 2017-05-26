#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Board {
private:
	int rows = 8;
	int cols = 8;
	char board[8][8];
	//std::vector<std::vector<char>> board;
public:

	Board ();
	Board (const Board &other);
	~Board ();

	int getSize () const;
	std::string print ()const;
};

std::ostream& operator<<(std::ostream& os, const Board& c);

#endif