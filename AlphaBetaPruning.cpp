#include "AlphaBetaPruning.h"



AlphaBetaPruning::AlphaBetaPruning() {
}


AlphaBetaPruning::~AlphaBetaPruning() {
}

std::string AlphaBetaPruning::search(Board current) {
	float v = MaxValue(current, -INFINITY, +INFINITY);

	return std::string();
}

float AlphaBetaPruning::MaxValue(Board current, float alpha, float beta) const {
	if (cutOff(current, 1)) {
		return evaluate(current);
	}
	float v = -INFINITY;
	//for each a in ACTIONS(state) do
	for (size_t a = 0; a < length; a++) {
		for (size_t s = 0; s < length; s++) {
			v = fmax(v, MinValue(s, alpha, beta));
			if (v >= beta) {
				return v;
			} else {
				alpha = fmax(alpha, v);
			}
		}
	}
	return v;
}

float AlphaBetaPruning::MinValue(Board current, float alpha, float beta) const {
	if (cutOff(current, 1)) {
		return evaluate(current);
	}
	float v = +INFINITY;
	//for each a in ACTIONS(state) do
	for (size_t a = 0; a < length; a++) {
		for (size_t s = 0; s < length; s++) {
			v = fmin(v, MaxValue(s, alpha, beta));
			if (v <= alpha) {
				return v;
			} else {
				beta = fmin(beta, v);
			}
		}
	}
	return v;
}

bool AlphaBetaPruning::cutOff(Board state, int depth) const {
	return false;
}

float AlphaBetaPruning::evaluate(Board state) const {
	return 0;
}
