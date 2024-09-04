#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;
class Client : public Person
{
private:
	int card;
	int ticket;
public:
	Client();
	Client(string name, string id, int card, int ticket);

	void setCard(int card);
	void setTicket(int ticket);

	int getCard();
	int getTicket();
};

