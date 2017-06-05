#include "AI.h"


AI::AI() {
	timerFlag = false;
	lastMove = "";
}


AI::~AI() {
}

std::vector<int> AI::search(Board* current) {
	int depth = 1;
	float v;
	while (depth <= 4) 
	{
		v = MaxValue(current, -INFINITY, +INFINITY, depth);
		if (v >= 5000) 	return current->getMove();
		depth++;
	}
	timerFlag = false;
	return current->getMove();
}

void AI::triggerTimerFlag() {
	timerFlag = true;
}

float AI::MaxValue(Board* currBoard, float alpha, float beta, int depth) 
{
	float score = currBoard->calculateScore();
	//cutoff test
	if (depth <= 0 || score >= 999 || score <= -999 || currBoard->isBoardFull())
	{
		currMove = currBoard->getMove();
		return evaluate(*(currBoard));
	}
	float v = -INFINITY;
	//std::vector<Board>* successors = currBoard->getSuccessors('X', *(currBoard));
	/*for (int s = 0; s < successors->size(); s++)
	{
		Board* temp = &successors->at(s);
		v = fmax(v, MinValue(temp, alpha, beta, depth - 1));
		if (v >= beta) {
			currMove = currBoard->getMove();
			return v;
		}
		else {
			alpha = fmax(alpha, v);
		}
	}*/
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Board tempB = *(currBoard);
			Board* temp(&(tempB));
			if (temp->isEmpty(i,j)) {
				temp->setPiece(i, j, 'X');
				temp->setMyMove(i, j);
				v = fmax(v, MinValue(temp, alpha, beta, depth - 1));
				if (v >= beta) {
					currMove = currBoard->getMove();
					return v;
				}
				else {
					alpha = fmax(alpha, v);
				}
			}
		}
	}
	return v;
}

float AI::MinValue(Board* currBoard, float alpha, float beta, int depth) {
	float score = currBoard->calculateScore();
	//cutoff test
	if (depth <= 0 || score >= 999 || score <= -999 || currBoard->isBoardFull())
	{
		currMove = currBoard->getMove();
		return evaluate(*(currBoard));
	}
	float v = +INFINITY;
	/*std::vector<Board>* successors = currBoard->getSuccessors('O', *(currBoard));

	for (int s = 0; s < successors->size(); s++) 
	{
		Board* temp = &successors->at(s);
		v = fmin(v, MaxValue(temp, alpha, beta, depth-1));
		if (v <= alpha) 
		{
			currMove = currBoard->getMove();
			return v;
		} 
		else 
		{
			beta = fmin(beta, v);
		} 
	}	*/
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Board tempB = *(currBoard);
			Board* temp(&(tempB));
			if (temp->isEmpty(i, j)) {
				temp->setPiece(i, j, 'X');
				temp->setMyMove(i, j);
				v = fmin(v, MaxValue(temp, alpha, beta, depth - 1));
				if (v <= alpha)
				{
					currMove = currBoard->getMove();
					return v;
				}
				else
				{
					beta = fmin(beta, v);
				}
			}
		}
	}
	return v;
}

bool AI::cutOff(Board state, float score) {
	return false;
	//return state->calculateScore < score;
}

float AI::evaluate(Board state) {
	float score = state.calculateScore();
	return score;
}
