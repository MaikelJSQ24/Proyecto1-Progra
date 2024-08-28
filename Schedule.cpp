#include "Schedule.h"

Schedule::Schedule()
{
	date= " ";
	startHour = " ";
	endHour = " ";
}

Schedule::Schedule(string date, string startHour, string endHour)
{
	this->date = date;
	this->startHour = startHour;
	this->endHour = endHour;
}

void Schedule::setDay(string date)
{
	this->date = date;
}

void Schedule::setStartHour(string startHour)
{
	this->startHour = startHour;
}

void Schedule::setEndHour(string endHour)
{
	this->endHour = endHour;
}

string Schedule::getDay()
{
	return date;
}

string Schedule::getStartHour()
{
	return startHour;
}

string Schedule::getEndHour()
{
	return endHour;
}

