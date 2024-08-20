#include "Room.h"

const int rows = 6;
const int columns = 6;

Room::Room()
{
	seats = nullptr;
	rooms = nullptr;
	movieSelect = 0;
}

void Room::createRooms(int numOfRooms)
{
	rooms = new Room[numOfRooms];

	for (int i = 0; i < numOfRooms; i++)
	{
		rooms[i].seats = new string * [rows];
		for (int j = 0; j < rows; j++)
		{
			rooms[i].seats[j] = new string[columns];
			for (int k = 0; k < columns; k++)
			{
				rooms[i].seats[j][k] = "D";
			}
		}
	}


}

void Room::printRoom(int room)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << rooms[room - 1].seats[i][j] << " | ";
		}
		cout << "\n";
	}
}


