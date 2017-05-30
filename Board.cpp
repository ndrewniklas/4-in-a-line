
#include "Board.h"



Board::Board () {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			board[r][c] = '-';
		}
	}
}

Board::Board (const Board &other) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			board[r][c] = other.board[rows][cols];
		}
	}
}

int Board::getSize () const {
	return rows;
}

std::string Board::print () const {
	std::stringstream s;
	for(int i = 0; i < rows; ++i){
		char label = 'A';
		if (i == 0) {
			s << " ";
			for (int i = 0; i < cols; i++) {
				s << " " << i + 1;
			}
			s << "\n";
		}
				s << (char)(label + i) << " " ;
		for(int j = 0; j < cols; ++j){
			s << board[i][j] << " ";
		}
		s << "\n";
	}
	return s.str();
}

bool Board::setPiece (int x, int y, char piece) {
	if (checkBounds(x, y)) {
		if (board[x][y] == empty) {
			board[x][y] = piece;
			return true;
		} else {
			return false;
		}
	}
}

bool Board::setPiece (char x, int y, char piece) {
	int ix = toupper(x) - 65;
	if (checkBounds(ix, y)) {
		board[ix][y] = piece;
		return true;
	} else {
		return false;
	}
}

char Board::getPiece(int x, int y) {
	if (checkBounds(x, y)) {
		return board[x][y];
	} else {
		return 0;
	}
}

char Board::getPiece(char x, int y) {
	int ix = toupper(x) - 65;
	if (checkBounds(ix, y)) {
		return board[ix][y];
	} else {
		return 0;
	}
}

bool Board::checkBounds(int x, int y) const {
	if (x > rows || y > cols) {
		return false;
	} else if (x < 0 || y < 0) {
		return false;
	} else {
		return true;
	}
}
Board::~Board () {
	if(board != nullptr){
		delete[] board;
	}
}

std::ostream & operator<<(std::ostream & os, const Board & c) {
	os << c.print();
	return os;
}
