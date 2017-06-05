#include "AI.h"


AI::AI() {
	timerFlag = false;
	lastMove = "";
}


AI::~AI() {
}

std::string AI::search(Board* current) {
	int depth = 1;
	float v;
	while (depth <= 5) 
	{
		v = MaxValue(current, -INFINITY, +INFINITY, depth);
		if (v >= 10000) return lastMove;
		depth++;
	}
	timerFlag = false;
	return lastMove;
}

void AI::triggerTimerFlag() {
	timerFlag = true;
}

float AI::MaxValue(Board* current, float alpha, float beta, int depth) {
	float score = current->myScore;
	//cutoff test
	if (current->isFinished(depth, score)) return evaluate(current);
	float v = -INFINITY;
	std::vector<Board*>* successors = current->getSuccessors('X');
	for (int s = 0; s < successors->size(); s++) {
		Board* temp = successors->at(s);
		v = fmax(v, MinValue(temp, alpha, beta, depth-1));
		if (v >= beta) {
			lastMove = temp->move;
			return v;
		} else {
			alpha = fmax(alpha, v);
		}
	}		//clear memory
	for (int i = 0; i < successors->size(); ++i) {
		delete successors->at(i);
	}
	delete successors;
	return v;
}

float AI::MinValue(Board* current, float alpha, float beta, int depth) {
	float score = current->myScore;
	//cutoff test
	if (current->isFinished(depth, score)) {
		return evaluate(current);
	}
	float v = +INFINITY;
	std::vector<Board*>* successors = current->getSuccessors('O');

	for (size_t s = 0; s < successors->size(); s++) {
		Board* temp = successors->at(s);
		v = fmin(v, MaxValue(temp, alpha, beta, depth-1));
		if (v <= alpha) {
			lastMove = temp->move;
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

bool AI::cutOff(Board* state, float score) {
	return false;
	//return state->calculateScore < score;
}

float AI::evaluate(Board* state) {
	return state->calculateScore();
}
