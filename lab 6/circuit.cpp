#include "circuit.h"
#include <iostream>
circuit::circuit() {
	lenght = 0;
	count = 0;
	w = Sunny;
	fcount = 0;
	dnfcount = 0;
}
circuit::~circuit() {
	for (int i = 0; i < count; i++) {
		delete competitors[i];
	}
}
void circuit::SetLenght(int len) {
	this->lenght = len;
}
void circuit::SetWeather(weather w) {
	this->w = w;
}
void circuit::AddCar(car* car) {
	if (count < 100) {
		competitors[count++] = car;
	}
}
void circuit::Race() {
	fcount = 0;
	dnfcount = 0;
	for (int i = 0; i < count; i++) {
		car* c = competitors[i];
		double fuel = (lenght / 100.0) * c->GetCons();
		if (fuel <= c->GetFuel())
		{
			finish[fcount] = c;
			times[fcount++] = lenght / c->GetAvg(w);
		}
		else
		{
			dnf[dnfcount++] = c;
		}
	}
	for (int i = 0; i < fcount - 1; i++) {
		for (int j = 0; j < fcount - i - 1; j++) {
			if (times[j] > times[j + 1]) {
				std::swap(times[j], times[j + 1]);
				std::swap(finish[j], finish[j + 1]);
			}
		}
	}
}
void circuit::ShowFinalRanks() {
	std::cout << "Final Ranks:\n";
	for (int i = 0; i < fcount; i++) {
		std::cout << i + 1 << ". " << finish[i]->GetName() << " - Time: " << times[i] << "s\n";
	}
}
void circuit::ShowWhoDidNotFinish() {
	std::cout << "Did Not Finish:\n";
	for (int i = 0; i < dnfcount; i++) {
		std::cout << "- " << dnf[i]->GetName() << "\n";
	}
}
