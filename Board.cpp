
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
		if (i == 0) {
			char label = 'A';
			s << " ";
			for (int i = 0; i < cols; i++) {
				s << " " << (char)(label + i);
			}
			s << "\n";
		}
		s << i + 1 << " ";
		for(int j = 0; j < cols; ++j){
			s << board[i][j] << " ";
		}
		s << "\n";
	}
	return s.str();
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
