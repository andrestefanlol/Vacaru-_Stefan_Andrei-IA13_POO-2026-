#include "volvo.h"
Volvo::Volvo() {
	this->fuel = 60;
	this->cons = 10;
	this->avgRain = 100;
	this->avgSun = 150;
	this->avgSnw = 80;
}
int Volvo::GetAvg(weather w) const {
	if (w == Rain) 	return avgRain;
	if (w == Sunny) return avgSun;
	if (w == Snow) return avgSnw;
	return 0;
	
}
const char* Volvo::GetName() const {
	return "Volvo";
}