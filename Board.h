#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Board {
private:
	char empty = '-';
	int rows = 8;
	int cols = 8;
	char board[8][8];

	bool checkBounds(int x, int y)const;
public:

	Board ();
	Board (const Board &other);
	~Board ();

	int getSize () const;
	std::string print ()const;
	bool setPiece(int x, int y, char piece);
	bool setPiece (char x, int y, char piece);
	char getPiece (int x, int y);
	char getPiece (char x, int y);
};

std::ostream& operator<<(std::ostream& os, const Board& c);

#endif