#pragma once
#include <iostream>
#include <string>
#include "Movie.h"
#include "Room.h"
#include "Schedule.h"
#include "Client.h"
using namespace std;

class Cinema
{
private:
	int option;
	bool open;
	Movie movieInfo;
	Movie* movies;
	Room roomInfo;
	Schedule scheduleInfo;
	Schedule* schedules;
	Client clientInfo;
	int numOfSchedules;
	int* ticketVector;
	int numOfTickets;
	int newNumOfTickets;
	int seatsReserved;
public:
	Cinema();

	void archiveMenu();
	void maintenanceMenu();
	void reserveMenu();
	void buyMenu();

	void about();

	void createMovies(Movie& movie);
	void createSchedules(Schedule& schedule);
	void createTicket();
	int* getTicketVector();
	int getSeats();
	bool correctTicket(int typedTicket);
	void dataClient();
};