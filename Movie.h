#pragma once
#include <iostream>
#include <string>
using namespace std;
class Movie
{
private:
	string name;
	string country;
	string review;
	int duration;
	int year;
public:
	Movie();
	Movie(string name, string country, string review, int duration, int year);

	void setName(string name);
	void setCountry(string country);
	void setReview(string review);
	void setDuration(int duration);
	void setYear(int year);

	string getName();
	string getCountry();
	string getReview();
	int getDuration();
	int getYear();

	void toString();
};



