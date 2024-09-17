#pragma once
#include <iostream>
#include <string>
using namespace std;
class Client
{
private:
	string name;
	string id;
	int card;
	int ticket;
public:
	Client();
	Client(string name, string id, int card, int ticket);
	~Client();

	void setName(string name);
	void setId(string id);
	void setCard(int card);
	void setTicket(int ticket);

	string getName();
	string getId();
	int getCard();
	int getTicket();
};

