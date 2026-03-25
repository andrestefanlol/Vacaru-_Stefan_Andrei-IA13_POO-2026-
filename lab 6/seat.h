#pragma once
#include "car.h"
class Seat :public car
{
public:
	Seat();
	int GetAvg(weather w) const override;
	const char* GetName() const override;
};

