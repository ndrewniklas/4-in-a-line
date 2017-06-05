#include "AI.h"


AI::AI() {
	timerFlag = false;
	lastMove = "";
}


AI::~AI() {
}

std::string AI::search(Board current) {
	int depth = 1;
	float v;
	while (depth <= 4) 
	{
		v = MaxValue(current, -INFINITY, +INFINITY, depth);
		if (v >= 5000) return lastMove;
		depth++;
	}
	timerFlag = false;
	return lastMove;
}

void AI::triggerTimerFlag() {
	timerFlag = true;
}

float AI::MaxValue(Board currBoard, float alpha, float beta, int depth) 
{
	float score = currBoard.calculateScore();
	//cutoff test
	if (depth == 0 || score >= 5000 || score <= -5000) 
	{
		return evaluate(currBoard);
	}
	float v = -INFINITY;
	std::vector<Board> successors = currBoard.getSuccessors('X', currBoard);
	for (int s = 0; s < successors.size(); s++)
	{
		Board temp = successors.at(s);
		v = fmax(v, MinValue(temp, alpha, beta, depth - 1));
		if (v >= beta) {
			lastMove = temp.move;
			return v;
		}
		else {
			alpha = fmax(alpha, v);
		}
	}
	return v;
}

float AI::MinValue(Board currBoard, float alpha, float beta, int depth) {
	float score = currBoard.calculateScore();
	//cutoff test
	if (depth == 0 || score >= 5000 || score <= -5000) 
	{
		return evaluate(currBoard);
	}
	float v = +INFINITY;
	std::vector<Board> successors = currBoard.getSuccessors('O', currBoard);

	for (size_t s = 0; s < successors.size(); s++) 
	{
		Board temp = successors.at(s);
		v = fmin(v, MaxValue(temp, alpha, beta, depth-1));
		if (v <= alpha) 
		{
			lastMove = temp.move;
			return v;
		} 
		else 
		{
			beta = fmin(beta, v);
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
