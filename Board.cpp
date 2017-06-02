
#include "Board.h"



Board::Board () {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			board[r][c] = EMPTY;
		}
	}
}

Board::Board (Board* other) {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			board[r][c] = other->board[rows][cols];
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
		if (board[x][y] == EMPTY) {
			board[x][y] = piece;
			return true;
		} else {
			return false;
		}
	}
	return false;
}

bool Board::setPiece (char x, int y, char piece) {
	int ix = toupper(x) - 65;
	y -= 1;
	if (checkBounds(ix, y) && board[ix][y] == '-') {
		board[ix][y] = piece;
		return true;
	} else {
		return false;
	}
	return false;
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
	if (x >= rows || y >= cols) {
		return false;
	} else if (x < 0 || y < 0) {
		return false;
	} else {
		return true;
	}
}

bool Board::isEmpty(int x, int y) const {
	if (board[x][y] == EMPTY) {
		return true;
	} else {
		return false;
	}
}

bool Board::checkWinCondition(char x, int y) {
	int ix = toupper(x) - 65;
	y -= 1;
	return (checkHorizontal(ix, y) == true || checkVertical(ix, y) == true);
}

bool Board::checkWinCondition(int x, int y) {
	y -= 1;
	return (checkHorizontal(x, y) == true || checkVertical(x, y) == true);
}

std::vector<Board>* Board::getSuccessors(char player) const {
	std::vector<Board> temp;
	for (size_t r = 0; r < rows; r++) {
		for (size_t c = 0; c < cols; c++) {
			if (isEmpty(r, c)) {
				Board next(*this);
				next.setPiece((int)r, (int)c, player);
				temp.push_back(next);
			}
		}
	}
	return &temp;
}

bool Board::checkHorizontal(int x, int y) {
	char piece = board[x][y];
	int start = x - 3;
	while (start < 0) {
		start++;
	}
	int end = x + 3;
	while (end >= 8) {
		end--;
	}
	int count = 0;
	for (int i = start; i < end; ++i) {
		if (board[i][y] == piece) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			return true;
		}
	}
	return false;
}

bool Board::checkVertical(int x, int y) {
	char piece = board[x][y];
	int start = y - 3;
	while (start < 0) {
		start++;
	}
	int end = y + 3;
	while (end >= 8) {
		end--;
	}
	int count = 0;
	for (int i = start; i < end; ++i) {
		if (board[x][i] == piece) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 4) {
			return true;
		}
	}
	return false;
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
