#pragma once
#include "weather.h"
class car
{
protected:
	int fuel, cons, avgRain, avgSun, avgSnw;
public:
	virtual ~car() = default;
	virtual int GetFuel() const { return fuel; };
	virtual int GetCons() const { return cons; };
	virtual int GetAvg(weather w) const=0;
	virtual const char* GetName() const = 0;
};

