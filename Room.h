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
	int numOfRooms;
	Movie assignedMovie;
	Schedule assignedSchedule;
	Schedule** assignedSchedules;
	int scheduleCount;
public:
	Room();
	void setScheduleCount(int scheduleCount);
	int getScheduleCount();


	void createRooms(int numOfRooms);
	void printRoom(int room);
	void assingMovie(int roomSelect, Movie& movie);
	void assingSchedule(int roomSelect, Schedule* schedules, int scheduleCount);
	Movie getAssingnedMovie(int roomSelect);
	Schedule getAssignedSchedule(int roomSelect);

	bool freeSeats(int roomSelect, int row, int column);
	void reserveSeats(int roomSelect, int row, int column);
	void printRoomInfo(int room);
};