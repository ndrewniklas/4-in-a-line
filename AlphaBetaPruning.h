#pragma once

#include <string>
#include <cmath>
#include "Board.h"

class AlphaBetaPruning {

private:
	float alpha;
	float beta;


public:
	AlphaBetaPruning();
	~AlphaBetaPruning();

	std::string search(Board current);
	float MaxValue(Board current, float alpha, float beta) const;
	float MinValue(Board current, float alpha, float beta) const;
	bool cutOff(Board state, int depth) const;
	float evaluate(Board state)const;
};

