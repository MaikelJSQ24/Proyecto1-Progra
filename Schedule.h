#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include "Movie.h"
using namespace std;
using namespace chrono;
class Schedule
{
private:
	string date;
	string startHour;
	string endHour;
	Schedule** schedules;
	Movie* movie;
public:
	Schedule();
	Schedule(string date, string startHour, string endHour);
	~Schedule();
	void createSchedule(int numOfFuntions);
	bool leapYear(int year);
	bool validDate(int day, int month, int year);
	int validMonth(int month, int year);
	string getHour();
	int convertToMinutes(string hour);
	int differenceBetweenHours(string start);
	string printSchedule();
};

