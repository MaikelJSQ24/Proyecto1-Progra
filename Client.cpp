#include "Client.h"

Client::Client()
{
	nameClient = " ";
	id = " ";
	ticket = 0;
}

Client::Client(string nameClient, string id, int ticket)
{
	this->nameClient = nameClient;
	this->id = id;
	this->ticket = ticket;
}

void Client::setClient(string nameClient)
{
	this->nameClient = nameClient;
}

void Client::setId(int id)
{
	this->id = id;
}

void Client::setTicket(int ticket)
{
	this->ticket = ticket;
}

string Client::getClient()
{
	return nameClient;
}

string Client::getId()
{
	return id;
}

int Client::getTicket()
{
	return ticket;
}
