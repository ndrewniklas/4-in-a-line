#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Board {
private:
	const char EMPTY = '-';
	int rows = 8;
	int cols = 8;
	char board[8][8];
	bool checkHorizontal(int x, int y);
	bool checkVertical(int x, int y);
	bool checkBounds(int x, int y)const;
	bool isEmpty(int x, int y) const;
	long computePlrScore(char plr, int row, int col);
public:

	Board ();
	Board(Board * other);
	~Board ();

	int getSize () const;
	std::string print ()const;
	bool setPiece(int x, int y, char piece);
	bool setPiece (char x, int y, char piece);
	char getPiece (int x, int y);
	char getPiece (char x, int y);
	bool checkWinCondition(char x, int y);
	bool checkWinCondition(int x, int y);
	long calculateScore();
	std::vector<Board>* getSuccessors(char player)const;
};

std::ostream& operator<<(std::ostream& os, const Board& c);

#endif