#include "seat.h"
Seat::Seat() {
	this->fuel = 50;
	this->cons = 9;
	this->avgRain = 80;
	this->avgSun = 120;
	this->avgSnw = 50;
}
int Seat::GetAvg(weather w) const {
	if (w == Rain) 	return avgRain;
	if (w == Sunny) return avgSun;
	if (w == Snow) return avgSnw;
	return 0;

}
const char* Seat::GetName() const {
	return "Seat";
}