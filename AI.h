#pragma once

#include <string>
#include <cmath>
#include "Board.h"

class AI {

private:
	float alpha;
	float beta;
	bool timerFlag;
public:
	AI();
	~AI();

	std::string search(Board* current);
	Board depthLimitedSearch(Board* board, int depth);
	float MaxValue(Board* current, float alpha, float beta) const;
	float MinValue(Board* current, float alpha, float beta) const;
	bool cutOff(Board* state, int depth) const;
	long evaluate(Board* state)const;
	void triggerTimerFlag();

};

