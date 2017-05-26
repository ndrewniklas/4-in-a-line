
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
	if (board[x][y] == empty) {
		board[x][y] = piece;
		return true;
	} else {
		return false;
	}
}

char Board::getPiece (int x, int y) {
	return board[x][y];
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
