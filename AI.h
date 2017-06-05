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
	std::string lastMove = "";
	std::string search(Board* current);
	Board depthLimitedSearch(Board* board, int depth);
	float MaxValue(Board* current, float alpha, float beta) ;
	float MinValue(Board* current, float alpha, float beta) ;
	bool cutOff(Board* state, int depth);
	long evaluate(Board* state) ;
	void triggerTimerFlag();

};

