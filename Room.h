#pragma once
#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;
class Room
{
private:
	string** seats;
	Room* rooms;
	int movieSelect;
	Movie movie1;
public:
	Room();

	void createRooms(int numOfRooms);
	void printRoom(int room);
};

