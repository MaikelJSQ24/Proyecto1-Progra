#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
protected:
	string name;
	string id;
public:
	Person();
	Person(string name, string id);

	void setName(string name);
	void setId(string id);
	
	string getName();
	string getId();
};

