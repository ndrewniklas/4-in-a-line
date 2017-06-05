
#include "Board.h"
#include <string>
#include <sstream>


/*Board::Board () {
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			board[r][c] = EMPTY;
		}
	}
	myScore = 0;
}*/
Board::Board () {
	vBoard = new std::vector<std::vector<char>*>(8);
	for (int r = 0; r < rows; r++) {
		vBoard->at(r) = new std::vector<char>(8);
			for (int c = 0; c < cols; c++) {
				vBoard->at(r)->at(c) = EMPTY;
			}
		}
	myScore = 0;
}
Board::Board (const Board& other) {
	vBoard = new std::vector<std::vector<char>*>(8);
	for (int r = 0; r < 8; r++) {
		vBoard->at(r) = new std::vector<char>(8);
		for (int c = 0; c < 8; c++) {
			//std::cout << other.getBoard()->at(r)->at(c);
			vBoard->at(r)->at(c) = other.getBoard()->at(r)->at(c);
		}
	}
}
Board::~Board() {
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			delete vBoard->at(r);
		}
	}
	delete vBoard;
}

std::vector<std::vector<char>*>* Board::getBoard() const {
	return vBoard;
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
			s << vBoard->at(i)->at(j) << " ";
		}
		s << "\n";
	}
	return s.str();
}

bool Board::setPiece (int x, int y, char piece) {
	if (checkBounds(x, y)) {
		if (vBoard->at(x)->at(y) == EMPTY) {
			vBoard->at(x)->at(y) = piece;
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
	if (checkBounds(ix, y) && vBoard->at(ix)->at(y) == EMPTY) {
		vBoard->at(ix)->at(y) = piece;
		return true;
	} else {
		return false;
	}
	return false;
}

char Board::getPiece(int x, int y) {
	if (checkBounds(x, y)) {
		return vBoard->at(x)->at(y);
	} else {
		return 0;
	}
}

char Board::getPiece(char x, int y) {
	int ix = toupper(x) - 65;
	if (checkBounds(ix, y)) {
		return vBoard->at(ix)->at(y);
	} else {
		return 0;
	}
}

bool Board::checkBounds(int x, int y)  {
	if (x >= rows || y >= cols) {
		return false;
	} else if (x < 0 || y < 0) {
		return false;
	} else {
		return true;
	}
}

bool Board::isEmpty(int x, int y)  {
	if (x >= rows || y >= cols) return false;
	if (vBoard->at(x)->at(y) == EMPTY) {
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

std::vector<Board*>* Board::getSuccessors(char player)  {
	std::vector<Board*>* temp = new std::vector<Board*>();
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (isEmpty(r, c)) {
				Board* next = new Board(*(this));
				next->setPiece((int)r, (int)c, player);
				next->setMove(r + 65, (int)c+1);
				temp->push_back(next);
			}
		}
	}
	return temp;
}

bool Board::isFinished(int depth, float score) {
	if (depth == 0 || score >= 10000 || score <= -10000 || isBoardFull()) return true;
	return false;
}

bool Board::isBoardFull() {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			//If there is at least one empty slot then it isn't full
			if (vBoard->at(i)->at(j) == EMPTY) return false;
		}
	}
	return true;
}

bool Board::checkHorizontal(int x, int y) {
	char piece = vBoard->at(x)->at(y);
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
		if (vBoard->at(i)->at(y) == piece) {
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
	char piece = vBoard->at(x)->at(y);
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
		if (vBoard->at(x)->at(i) == piece) {
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

float Board::calculateScore() {
	float score = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			char piece = vBoard->at(i)->at(j);
			if (piece == BOT) { //Found the CPU piece
				//Compute score for the CPU's pieces, add to total
				score += computePlrScore(piece, i, j);
			}
			else if (piece == PLAYER) { //Found the PLR piece
				//Compute score for PLR's pieces, subtract from total
				score -= computePlrScore(piece, i, j);
			}
		}
	}
	return score;
}

void Board::setMove(char row, int col) {
	std::stringstream oss;
	oss << row << col;
	move = oss.str();
	//move = row + col;
	//std::cout << move << std::endl;
	/*move[0] = row;
	move[1] = col;*/
}

std::string Board::getMove()  {
	return move;
}

float Board::computePlrScore(char plr, int row, int col) {
	float score = 0;
	int inARow = 1, inACol = 1, totalRow = 1, totalCol = 1;
	//Horizontal Count
	if (row < rows - 3) {
		for (int r = row + 1; r <= row + 3; ++r) {
			char nextPiece = vBoard->at(r)->at(col);
			if (nextPiece == plr || nextPiece == EMPTY) {
				if (nextPiece == plr) {
					inARow++;
					totalRow++;
				}
				else if(r != row + 3){
					//We found an empty slot, don't count it 
					inARow = 0;
				}
			}
			else { // Found player piece
				inARow = 0;
				totalRow = 0;
				break; //This block is useless since it is being blocked off
			}
		}
	}
	//Vertical Count
	if (col < cols - 3) {
		for (int c = col + 1; c <= col + 3; ++c) {
			char nextPiece = vBoard->at(row)->at(c);
			if (nextPiece == plr || nextPiece == EMPTY) {
				if (nextPiece == plr) {
					inACol++;
					totalCol++;
				}
				else if (c != col+3){
					//We found an empty slot, don't count it 
					inACol = 0;
				}
			}
			else { // Found player piece
				inARow = 0;
				totalRow = 0;
				break; //This block is useless since it is being blocked off
			}
		}
	}
	if (inARow == 4 || inACol == 4) score += 10000;
	if (inARow == 3) {
		//DEBUG
		//std::cout << "3 IN A ROW\n";
		//if (row - 1 >= 0) std::cout << board[row - 1][col] << std::endl;
		//inARow will be 3 if i,i+1,and i+2 == 'X' AND i+3 == EMPTY which means that the right side is open
		if (row - 1 >= 0 && vBoard->at(row-1)->at(col) == EMPTY) {
			//The player would have to choose between blocking i-1 or i+3 and the bot
			//could take the other thus making 4 in a row. Bot wins, return a high score
			score += 10000;
		}
		else {
			//Three is a row with only 1 opening, still good but not game winning
			score += 500;
		}
	}
	else if (inACol == 3) {
		//DEBUG
		//std::cout << "3 IN A COL\n";
		//if (col - 1 >= 0) std::cout << board[row][col - 1] << std::endl;
		//inARow will be 3 if i,i+1,and i+2 == 'X' AND i+3 == EMPTY which means that the right side is open
		if (col - 1 >= 0 && vBoard->at(row)->at(col-1) == EMPTY) {
			//The player would have to choose between blocking i-1 or i+3 and the bot
			//could take the other thus making 4 in a row. Bot wins, return a high score
			score += 10000;
		}
		else {
			//Three is a row with only 1 opening, still good but not game winning
			score += 500;
		}
	}
	else {
		if (totalRow > 0) {
			if (totalRow == 3) score += 100;
			else score += totalRow * 10;
		}
		if (totalCol > 0) {
			if (totalCol == 3) score += 100;
			else score += totalCol * 10;
		}
	}

	return score;
}

//Board::~Board () {
	//if(board != nullptr){
	//	delete[] board;
	//}
//}

std::ostream & operator<<(std::ostream & os, const Board & c) {
	os << c.print();
	return os;
}
