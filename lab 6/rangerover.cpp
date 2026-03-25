#include "rangerover.h"
RangeRover::RangeRover() {
	this->fuel = 100;
	this->cons = 15;
	this->avgRain = 96;
	this->avgSun = 150;
	this->avgSnw = 85;
}
int RangeRover::GetAvg(weather w) const {
	if (w == Rain) 	return avgRain;
	if (w == Sunny) return avgSun;
	if (w == Snow) return avgSnw;
	return 0;

}
const char* RangeRover::GetName() const {
	return "Range Rover";
}