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
	int numOfRooms;
	Movie assignedMovie;
public:
	Room();

	void createRooms(int numOfRooms);
	void printRoom(int room);
	void assingMovie(int roomSelect, Movie& movie);
	Movie getAssingnedMovie(int roomSelect);
	void printRoomWithMovie(int room);
};

