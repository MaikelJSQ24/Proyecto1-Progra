#include "Person.h"

Person::Person()
{
	name = " ";
	id = " ";
}

Person::Person(string name, string id)
{
	this->name = name;
	this->id = id;
}

void Person::setName(string name)
{
	this->name = name;
}

void Person::setId(string id)
{
	this->id = id;
}

string Person::getName()
{
	return name;
}

string Person::getId()
{
	return id;
}
