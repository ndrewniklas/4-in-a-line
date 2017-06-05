#include "AlphaBetaPruning.h"



AlphaBetaPruning::AlphaBetaPruning() :lastMove(""){
}


AlphaBetaPruning::~AlphaBetaPruning() {
}

std::string AlphaBetaPruning::search(Board current) {
	float v = MaxValue(current, -INFINITY, +INFINITY);

	return lastMove;
}

float AlphaBetaPruning::MaxValue(Board current, float alpha, float beta){
	if (cutOff(current, 1)) {
		return evaluate(current);
	}
	float v = -INFINITY;
	std::vector<Board*>* successors = current.getSuccessors('X');

	for (size_t s = 0; s < successors->size(); s++) {
		Board temp = successors->at(s);
		lastMove = temp.getMove();
		v = fmax(v, MinValue(temp, alpha, beta));
		if (v >= beta) {
			return v;
		} else {
			alpha = fmax(alpha, v);
		}
	}
	return v;
}

float AlphaBetaPruning::MinValue(Board current, float alpha, float beta){
	if (cutOff(current, 1)) {
		return evaluate(current);
	}
	float v = +INFINITY;
	std::vector<Board*>* successors = current.getSuccessors('O');

	for (size_t s = 0; s < successors->size(); s++) {
		Board temp = successors->at(s);
		lastMove = temp.getMove();
		v = fmin(v, MaxValue(successors->at(s), alpha, beta));
		if (v <= alpha) {
			return v;
		} else {
			beta = fmin(beta, v);
		}
	}
	return v;
}

bool AlphaBetaPruning::cutOff(Board state, int depth) const {
	return false;
}

float AlphaBetaPruning::evaluate(Board state) const {
	return state.calculateScore();
}
