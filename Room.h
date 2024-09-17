#pragma once
#include <iostream>
#include <string>
#include "Movie.h"
#include "Schedule.h"
using namespace std;
class Room
{
private:
	string** seats;
	Room* rooms;
	Schedule* schedule;
	Movie* movie;

public:
	Room();
	~Room();
	void createRooms(int numOfRooms);
	void printRoom(int roomSelect);
	void printOnlyMovie(int roomSelect);
	void assignSchedule(Schedule* schedule);
	void assignMovie(Movie* movie);
	bool isValidSeats(int row, int column);
	void reservedSeats(int row, int column);
	bool isSeatsPurchased(int row, int column);
	void changeReservedToPurchased(int row, int column);
	Schedule* getSchedule();
	Movie* getMovie();
};

