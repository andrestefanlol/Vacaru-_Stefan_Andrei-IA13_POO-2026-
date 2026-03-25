#include "weather.h"
#include "circuit.h"
#include "volvo.h"
#include "bmw.h"
#include "seat.h"
#include "fiat.h"
#include "rangerover.h"
#include <iostream>
int main()
{
	circuit c;
	c.SetLenght(600);
	c.SetWeather(weather::Rain);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}
