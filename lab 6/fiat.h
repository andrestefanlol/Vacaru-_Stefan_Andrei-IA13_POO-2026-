#pragma once
#include "car.h"
class Fiat :public car
{
public: 
	Fiat();
	int GetAvg(weather w) const override;
	const char* GetName() const override;
};
