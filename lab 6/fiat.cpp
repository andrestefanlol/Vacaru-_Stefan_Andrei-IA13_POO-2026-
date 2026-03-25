#include "fiat.h"
Fiat::Fiat() {
	this->fuel = 50;
	this->cons = 8;
	this->avgRain = 70;
	this->avgSun = 130;
	this->avgSnw = 60;
}
int Fiat::GetAvg(weather w) const {
	if (w == Rain) 	return avgRain;
	if (w == Sunny) return avgSun;
	if (w == Snow) return avgSnw;
	return 0;

}
const char* Fiat::GetName() const {
	return "Fiat";
}