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
	int numOfMovies;
	int numOfRooms;
	int numOfFuntions;
	int seatsReserved;
	int numOfTickets;
	int roomSelected;
	int numOfClients;
	int option;
	int allSeatsReserved;
	bool open;
	int* ticketVector;
	int* reservedSeatsRow;
	int* reservedSeatsColumn;
	Movie* movieInfo;
	Room* roomInfo;
	Schedule* scheduleInfo;
	Client* clientVector;
	Client clientInfo;
public:
	Cinema();
	~Cinema();
	void archiveMenu();
	void menuOfMaintenance();
	void reserveMenu();
	void buyMenu();
	void about();
	void assignScheduleAndMovie();
	void loadTicketVector(int* firstTicketVector, int* secondTicketVector, int sizeOfVector);
	void loadTickets(int*& ticketVector, int& size, int newTicket);
	int generateTicket();
	void createTicket();
	int* getTicketVector();
	bool correctTicket(int typedTicket);
	void addClient(string nameClient, int& size, int ticket);
	int findTheTicket(string name);
	void dataClient();
	int getRoomSelect();

};