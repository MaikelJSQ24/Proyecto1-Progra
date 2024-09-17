#include "Client.h"

Client::Client()
{
	name = "";
	id = "";
	card = 0;
	ticket = 0;
}

Client::Client(string name, string id, int card, int ticket)
{
	this->name = name;
	this->id = id;
	this->card = card;
	this->ticket = ticket;
}

Client::~Client()
{
}

void Client::setName(string name)
{
	this->name = name;
}

void Client::setId(string id)
{
	this->id = id;
}

void Client::setCard(int card)
{
	this->card = card;
}

void Client::setTicket(int ticket)
{
	this->ticket = ticket;
}

string Client::getName()
{
	return name;
}

string Client::getId()
{
	return id;
}

int Client::getCard()
{
	return card;
}

int Client::getTicket()
{
	return ticket;
}
