#include "Room.h"

const int rows = 6;
const int columns = 6;

Room::Room()
{
	seats = nullptr;
	rooms = nullptr;
	assignedMovie;
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

void Room::assingMovie(int roomSelect, Movie& movie)
{
	rooms[roomSelect].assignedMovie = movie;
}

Movie Room::getAssingnedMovie(int roomSelect)
{
	return rooms[roomSelect].assignedMovie;
}

void Room::printRoomWithMovie(int room)
{
	Room& selectedRoom = rooms[room - 1];
	Movie movie = selectedRoom.assignedMovie;

	cout << "Sala " << room << " - Pelicula: " << movie.getName() << endl;
	cout << "Pais: " << movie.getCountry() << endl;
	cout << "Review: " << movie.getReview() << endl;
	cout << "Duracion: " << movie.getDuration() << " minutos" << endl;
	cout << "Anio: " << movie.getYear() << endl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << selectedRoom.seats[i][j] << " | ";
		}
		cout << "\n";
	}
}


