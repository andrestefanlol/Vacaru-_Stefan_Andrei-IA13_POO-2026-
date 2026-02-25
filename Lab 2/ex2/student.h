#pragma once
class student
{
private:
	char* name;
	float mgrade;
	float engrade;
	float hgrade;
public:
	student();
	~student();

	void setname(const char* name);
	const char* getname();

	void set_math(float grade);
	float get_math();

	void set_eng(float grade);
	float get_eng();

	void set_his(float grade);
	float get_his();

	float getaverage();
};

