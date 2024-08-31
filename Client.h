#pragma once
#include <iostream>
#include <string>
using namespace std;
class Client
{
private:
	string nameClient;
	string id;
	int ticket;
public:
	Client();
	Client(string nameClient, string id, int ticket);

	void setClient(string nameClient);
	void setId(int id);
	void setTicket(int ticket);

	int getTicket();
	string getClient();
	string getId();
	
};

