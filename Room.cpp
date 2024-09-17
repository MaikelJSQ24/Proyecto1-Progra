#include "Room.h"

const int rows = 8;
const int columns = 14;

Room::Room()
{
	seats = nullptr;
	rooms = nullptr;
	movie = nullptr;
	schedule = nullptr;
}

Room::~Room()
{
	if (seats != nullptr)
	{
		for (int i = 0; i < rows; ++i) 
		{
			delete[] seats[i];
		}
		delete[] seats;
	}
	delete movie;
	delete schedule;
}

void Room::createRooms(int numOfRooms)
{
	seats = new string * [rows];
	for (int i = 0; i < rows; i++)
	{
		seats[i] = new string[columns];

		for (int j = 0; j < columns; j++)
		{
			seats[i][j] = "D";
		}
	}
}

void Room::printRoom(int roomSelect)
{

	printf("Sala %d: \n", roomSelect);

	if (movie != nullptr) {
		printf("Pelicula: \n");
		cout << movie->printMovie();
	}
	else
	{
		printf("No hay pelicula asignada.\n");
	}

	if (schedule != nullptr)
	{
		printf("Horario: \n");
		cout << schedule->printSchedule();
	}
	else
	{
		printf("No hay horario asignado.\n");
	}
	printf("\t\t\tPantalla aqui\n\n");

	for (int i = 0; i < columns; i++)
	{
		printf("  %2d", i + 1);
	}
	printf("\n");
	for (int i = 0; i < rows; i++)
	{
		printf("%2d| ", i + 1);
		for (int j = 0; j < columns; j++)
		{
			printf("%s | ", seats[i][j].c_str());
		}
		printf("\n");
	}

}

void Room::printOnlyMovie(int roomSelect)
{
	printf("Pelicula: \n");
	cout << movie->printMoviePurchased();

	printf("Horario: \n");
	cout << schedule->printSchedule();

}

void Room::assignSchedule(Schedule* schedule)
{
	this->schedule = schedule;
}

void Room::assignMovie(Movie* movie)
{
	this->movie = movie;
}

bool Room::isValidSeats(int row, int column)
{
	if (seats[row - 1][column - 1] == "D")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Room::reservedSeats(int row, int column)
{
	bool access = isValidSeats(row, column);
	if (access)
	{
		seats[row - 1][column - 1] = "R";
		printf("Asiento(s) reservado(s)\n");
	}
	else
	{
		printf("Lo sentimos, asiento reservado o comprado.\n");
	}
}

bool Room::isSeatsPurchased(int row, int column)
{
	if (seats[row - 1][column - 1] == "R")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Room::changeReservedToPurchased(int row, int column)
{
	bool change = isSeatsPurchased(row, column);
	if (change)
	{
		seats[row - 1][column - 1] = "C";
	}
}

Schedule* Room::getSchedule()
{
	return schedule;
}

Movie* Room::getMovie()
{
	return movie;
}
