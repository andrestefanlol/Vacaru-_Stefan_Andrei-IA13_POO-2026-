#include "car.h"
class Volvo : public car
{
public:
	Volvo();
	int GetAvg(weather w) const override;
	const char* GetName() const override;
	
};