#pragma once
#include <iostream>
#include <string>
using namespace std;
class Schedule
{
private:
	string date;
	string startHour;
	string endHour;

public:
	Schedule();
	Schedule(string day, string startHour, string endHour);

	void setDay(string day);
	void setStartHour(string startHour);
	void setEndHour(string endHour);

	string getDay();
	string getStartHour();
	string getEndHour();
};
