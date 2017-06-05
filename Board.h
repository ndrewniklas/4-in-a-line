#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

class Board {
private:
	const char EMPTY = '-';
	const char PLAYER = 'O';
	const char BOT = 'X';
	
	int rows = 8;
	int cols = 8;
	char board[8][8];
	bool checkHorizontal(int x, int y);
	bool checkVertical(int x, int y);
	bool checkBounds(int x, int y)const;
	bool isEmpty(int x, int y) const;
	long computePlrScore(char plr, int row, int col);
	void setMove(char row, int col);
public:

	Board ();
	Board(const Board * other);
	~Board ();

	std::string move;
	int getSize () const;
	std::string print ()const;
	bool setPiece(int x, int y, char piece);
	bool setPiece (char x, int y, char piece);
	char getPiece (int x, int y);
	char getPiece (char x, int y);
	bool checkWinCondition(char x, int y);
	bool checkWinCondition(int x, int y);
	long calculateScore();
	std::string getMove() const;
	std::vector<Board*>* getSuccessors(char player)const;
};

std::ostream& operator<<(std::ostream& os, const Board& c);

#endif