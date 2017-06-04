#include "AI.h"



AI::AI() {
	timerFlag = false;
}


AI::~AI() {
}

std::string AI::search(Board* current) {
	float v = MaxValue(current, -INFINITY, +INFINITY);

	return std::string();
}

void AI::triggerTimerFlag() {
	timerFlag = true;
}

Board AI::depthLimitedSearch(Board* board, int limit) {
	return NULL;
}

float AI::MaxValue(Board* current, float alpha, float beta) const {
	if (cutOff(current, 1)) {
		return evaluate(current);
	}
	float v = -INFINITY;
	std::vector<Board*>* successors = current->getSuccessors('X');
	
	for (size_t s = 0; s < successors->size(); s++) {
		v = fmax(v, MinValue(successors->at(s), alpha, beta));
		if (v >= beta) {
			return v;
		} else {
			alpha = fmax(alpha, v);
		}
	}
	//clear memory
	for (int i = 0; i < successors->size(); ++i) {
		delete successors->at(i);
	}
	delete successors;
	return v;
}

float AI::MinValue(Board* current, float alpha, float beta) const {
	if (cutOff(current, 1)) {
		return evaluate(current);
	}
	float v = +INFINITY;
	std::vector<Board*>* successors = current->getSuccessors('O');
	
	for (size_t s = 0; s < successors->size(); s++) {
			v = fmin(v, MaxValue(successors->at(s), alpha, beta));
			if (v <= alpha) {
				return v;
			} else {
				beta = fmin(beta, v);
			}
	}
	//clear memory
	for (int i = 0; i < successors->size(); ++i) {
		delete successors->at(i);
	}
	delete successors;
	return v;
}

bool AI::cutOff(Board* state, int depth) const {
	//Cut off the branches where the new score is worse than the previous score
	//if (state->calculateScore() < depth) return true;
	return false;
}

long AI::evaluate(Board* state) const {
	return state->calculateScore();
}
