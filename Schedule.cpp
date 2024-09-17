#include "Schedule.h"

Schedule::Schedule()
{
	date = "";
	startHour = "";
	endHour = "";
	schedules = nullptr;
	movie = nullptr;
}

Schedule::Schedule(string date, string startHour, string endHour)
{
	this->date = date;
	this->startHour = startHour;
	this->endHour = endHour;
	this->schedules = nullptr;
	this->movie = nullptr;
}

Schedule::~Schedule()
{
	delete[] schedules;
}

void Schedule::createSchedule(int numOfFuntions)
{
	if (schedules != nullptr)
	{
		for (int i = 0; i < numOfFuntions; ++i) {
			delete schedules[i];
		}
		delete[] schedules;
	}

	int day = 0, month = 0, year = 0, start = 0, end = 0;
	int countSchedules = 0;

	schedules = new Schedule * [numOfFuntions];


	bool access = true;
	while (access)
	{
		printf("Digite dia, mes y anio de estreno (dd-mm-aaaa): ");
		scanf_s("%d %d %d", &day, &month, &year);
		if (validDate(day, month, year))
		{
			year = (year < 999) ? year + 2000 : year;
			if (year < 2024)
			{
				printf("Lo sentimos, no puede agregar un anio anterior a 2024.\nIntente de nuevo\n");
				return;
			}
			else
			{
				date = (day < 10) ? "0" + to_string(day) + "/" : to_string(day) + "/";
				date += (month < 10) ? "0" + to_string(month) + "/" : to_string(month) + "/";
				date += to_string(year);
				access = false;
			}
		}
		else
		{
			printf("Fecha invalida, intente de nuevo\n");
		}
	}
	printf("Digite la hora de inicio (Formato 24h): ");
	scanf_s("%d", &start);

	end = start + 3;
	startHour = (start <= 12) ? to_string(start) + ":00AM" : to_string(start - 12) + ":00PM";
	endHour = (end <= 12) ? to_string(end) + ":00AM" : to_string(end - 12) + ":00PM";

	schedules[countSchedules] = new Schedule(date, startHour, endHour);
	countSchedules++;
}

bool Schedule::leapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

bool Schedule::validDate(int day, int month, int year)
{
	if (day > 0 && day <= validMonth(month, year))
	{
		return true;
	}
	else {
		return false;
	}
}

int Schedule::validMonth(int month, int year)
{
	if (month == 2)
	{
		return leapYear(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else
	{
		return 30;
	}
}

string Schedule::getHour()
{
	return startHour;
}

int Schedule::convertToMinutes(string hourStart)
{
	int hour = stoi(hourStart.substr(0, hourStart.find(":")));
	int minutes = stoi(hourStart.substr(hourStart.find(":") + 1, 2));
	bool PM = hourStart.find("PM") != string::npos;

	if (PM && hour < 12)
	{
		hour += 12;
	}
	if (!PM && hour == 0)
	{
		hour = 0;
	}
	return hour * 60 + minutes;
}

int Schedule::differenceBetweenHours(string start)
{
	int currentHour = 0;
	int currentMinutes = 0;
	int totalHour = 0;
	int startMinutes = 0;

	time_t actuallHour = time(0);
	tm localTime = { 0 };
	localtime_s(&localTime, &actuallHour);

	currentHour = localTime.tm_hour;
	currentMinutes = localTime.tm_min;
	totalHour = currentHour * 60 + currentMinutes;

	startMinutes = convertToMinutes(startHour);

	return startMinutes - totalHour;
}

string Schedule::printSchedule()
{
	string schedule;

	schedule += "Fecha: " + date + "\n";
	schedule += "Hora inicio: " + startHour + "\n";
	schedule += "Hora fin: " + endHour + "\n";

	return schedule;
}