#include "AI.h"


AI::AI() {
	timerFlag = false;
	lastMove = "";
}


AI::~AI() {
}

std::string AI::search(Board* current) {
	float v = MaxValue(current, -INFINITY, +INFINITY);

	return lastMove;
}

void AI::triggerTimerFlag() {
	timerFlag = true;
}

Board AI::depthLimitedSearch(Board* board, int limit) {
	return NULL;
}

float AI::MaxValue(Board* current, float alpha, float beta) {
	if (timerFlag) {
		return evaluate(current);
	}
	float v = -INFINITY;
	std::vector<Board*>* successors = current->getSuccessors('X');
	for (size_t s = 0; s < successors->size(); s++) {
		Board* temp = successors->at(s);
		lastMove = temp->move;
		v = fmax(v, MinValue(temp, alpha, beta));
		if (v >= beta) {
			return v;
		} else {
			alpha = fmax(alpha, v);
		}
		//clear memory
		for (int i = 0; i < successors->size(); ++i) {
			delete successors->at(i);
		}
		delete successors;
	}
	return v;
}

float AI::MinValue(Board* current, float alpha, float beta) {
	if (timerFlag) {
		timerFlag = false;
		return evaluate(current);
	}
	float v = +INFINITY;
	std::vector<Board*>* successors = current->getSuccessors('O');

	for (size_t s = 0; s < successors->size(); s++) {
		Board* temp = successors->at(s);
		lastMove = temp->move;
		v = fmin(v, MaxValue(temp, alpha, beta));
		if (v <= alpha) {
			return v;
		} else {
			beta = fmin(beta, v);
		}
		//clear memory
		for (int i = 0; i < successors->size(); ++i) {
			delete successors->at(i);
		}
		delete successors;
	}
	return v;
}

bool AI::cutOff(Board* state, int depth) {
	return timerFlag;
}

long AI::evaluate(Board* state) {
	return state->calculateScore();
}
