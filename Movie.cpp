#include "Movie.h"

Movie::Movie()
{
	name = " ";
	country = " ";
	review = " ";
	duration = 0;
	year = 0;
}

Movie::Movie(string name, string country, string review, int duration, int year)
{
	this->name = name;
	this->country = country;
	this->review = review;
	this->duration = duration;
	this->year = year;
}

void Movie::setName(string name)
{
	this->name = name;
}

void Movie::setCountry(string country)
{
	this->country = country;
}

void Movie::setReview(string review)
{
	this->review = review;
}

void Movie::setDuration(int duration)
{
	this->duration = duration;
}

void Movie::setYear(int year)
{
	this->year = year;
}

string Movie::getName()
{
	return name;
}

string Movie::getCountry()
{
	return country;
}

string Movie::getReview()
{
	return review;
}

int Movie::getDuration()
{
	return duration;
}

int Movie::getYear()
{
	return year;
}
