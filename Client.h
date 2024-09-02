#pragma once
#include <iostream>
#include <string>
using namespace std;
class Client
{
private:
	string nameClient;
	string card;
	int ticket;
public:
	Client();
	Client(string nameClient, string card, int ticket);

	void setClient(string nameClient);
	void setId(int card);
	void setTicket(int ticket);

	int getTicket();
	string getClient();
	string getId();
	
};

