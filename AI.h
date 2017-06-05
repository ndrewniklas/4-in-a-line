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
	std::vector<std::string> moves;
	std::string search(Board* current);
	float MaxValue(Board* current, float alpha, float beta, int depth) ;
	float MinValue(Board* current, float alpha, float beta, int depth) ;
	bool cutOff(Board* state, float score);
	float evaluate(Board* state) ;
	void triggerTimerFlag();

};

