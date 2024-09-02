#include "Client.h"

Client::Client()
{
	nameClient = " ";
	card = " ";
	ticket = 0;
}

Client::Client(string nameClient, string card, int ticket)
{
	this->nameClient = nameClient;
	this->card = card;
	this->ticket = ticket;
}

void Client::setClient(string nameClient)
{
	this->nameClient = nameClient;
}

void Client::setId(int card)
{
	this->card = card;
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
	return card;
}

int Client::getTicket()
{
	return ticket;
}