#pragma once
#include "car.h"
#include "weather.h"
class circuit
{
private:
	double lenght;
	car* competitors[100];
	int count;
	weather w;
	car* finish[100];
	double times[100];
	int fcount;
	car* dnf[100];
	int dnfcount;
public:
	circuit();
	~circuit();
	void SetLenght(int len);
	void SetWeather(weather w);
	void AddCar(car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

