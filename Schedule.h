#pragma once
#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;
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
	string printSchedule();

	void assingMovie(Movie* movie);
};

