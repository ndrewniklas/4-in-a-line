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
	float MaxValue(Board currBoard, float alpha, float beta, int depth);
	float MinValue(Board currBoard, float alpha, float beta, int depth);
	std::vector<std::string> moves;
	std::string search(Board current);
	bool cutOff(Board state, float score);
	float evaluate(Board state) ;
	void triggerTimerFlag();

};

