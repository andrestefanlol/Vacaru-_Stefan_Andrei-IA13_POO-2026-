#include "bmw.h"
BMW::BMW() {
	this->fuel = 70;
	this->cons = 12;
	this->avgRain = 120;
	this->avgSun = 170;
	this->avgSnw = 75;
}
int BMW::GetAvg(weather w) const {
	if (w == Rain) 	return avgRain;
	if (w == Sunny) return avgSun;
	if (w == Snow) return avgSnw;
	return 0;

}
const char* BMW::GetName() const {
	return "BMW";
}