#pragma once
#include "car.h"
class RangeRover :public car
{
public:
	RangeRover();
	int GetAvg(weather w) const override;
	const char* GetName() const override;
};


