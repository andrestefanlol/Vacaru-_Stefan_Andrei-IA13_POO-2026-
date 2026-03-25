#pragma once
#include "car.h"
class BMW :public car
{
public:
	BMW();
	int GetAvg(weather w) const override;
	const char* GetName() const override;
};

