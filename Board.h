#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <sstream>
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
	//char board[8][8];
	std::vector<std::vector<char>> vBoard;
	bool checkHorizontal(int x, int y);
	bool checkVertical(int x, int y);
	bool checkBounds(int x, int y);
	float computePlrScore(char plr, int row, int col);
	void setMove(char row, int col);
	std::vector<int> myMove;
public:

	Board ();
	Board(const Board &other);
	~Board ();
	void setMyMove(int x, int y);
	bool isEmpty(int x, int y);
	std::vector<std::vector<char>> getBoard() const;
	std::string move = "A1";
	float myScore;
	int getSize () const;
	std::string print ()const;
	bool setPiece(int x, int y, char piece);
	bool setPiece (char x, int y, char piece);
	char getPiece (int x, int y);
	char getPiece (char x, int y);
	bool checkWinCondition(char x, int y);
	bool checkWinCondition(int x, int y);
	float calculateScore();
	bool isBoardFull();
	bool isFinished(int depth, float score);
	std::vector<int> getMove() const;
	std::vector<Board>* getSuccessors(char player, Board current);
};

std::ostream& operator<<(std::ostream& os, const Board& c);

#endif