#include "Room.h"

const int rows = 8;
const int columns = 14;

Room::Room()
{
	seats = nullptr;
	rooms = nullptr;
	assignedMovie;
	scheduleCount = 0;
	numOfRooms = 0;
	assignedSchedules = nullptr;
}

void Room::setScheduleCount(int scheduleCount)
{
	this->scheduleCount = scheduleCount;
}

int Room::getScheduleCount()
{
	return scheduleCount;
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

void Room::assingMovie(int roomSelect, Movie& movie)
{
	rooms[roomSelect].assignedMovie = movie;
}

void Room::assingSchedule(int roomSelect, Schedule* schedules, int scheduleCount)
{
	Room& room = rooms[roomSelect];
	room.scheduleCount = scheduleCount;
	room.assignedSchedules = new Schedule * [3];
	for (int i = 0; i < scheduleCount; i++)
	{
		room.assignedSchedules[i] = new Schedule(schedules[i]);
	}
}

Movie Room::getAssingnedMovie(int roomSelect)
{
	return rooms[roomSelect].assignedMovie;
}

void Room::printRoom(int room)
{
	Room& selectedRoom = rooms[room - 1];
	Movie movie = selectedRoom.assignedMovie;
	printf("\t\t\tPantalla aqui\n\n");



	for (int i = 0; i < columns; i++)
	{
		printf("  %2d", i + 1);
	}
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		printf("%2d| ", i + 1);
		for (int j = 0; j < columns; j++)
		{
			cout << selectedRoom.seats[i][j] << " | ";
		}
		cout << "\n";
	}
}

Schedule Room::getAssignedSchedule(int roomSelect)
{
	return rooms[roomSelect].assignedSchedule;
}

void Room::printRoomInfo(int room)
{
	Room& selectedRoom = rooms[room - 1];
	Movie movie = selectedRoom.assignedMovie;

	printf("Sala %d - Pelicula: %s\n", room, movie.getName().c_str());
	printf("Pais: %s\n", movie.getCountry().c_str());
	printf("Review: %s\n", movie.getReview().c_str());
	printf("Duracion: %d minutos\n", movie.getDuration());
	printf("Anio: %d\n", movie.getYear());

	printf("Horarios asignados:\n");
	for (int i = 0; i < selectedRoom.scheduleCount; i++) {
		Schedule* schedule = selectedRoom.assignedSchedules[i];
		printf("Fecha: %s\n", schedule->getDay().c_str());
		printf("Hora inicio: %s\n", schedule->getStartHour().c_str());
		printf("Hora fin: %s\n", schedule->getEndHour().c_str());
	}

	printRoom(room);
}

bool Room::freeSeats(int roomSelect, int row, int column)
{
	if (rooms[roomSelect - 1].seats[row - 1][column - 1] == "D")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Room::isReserveSeats(int roomSelect, int row, int column)
{
	if (rooms[roomSelect - 1].seats[row - 1][column - 1] == "R")
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Room::reserveSeats(int roomSelect, int row, int column)
{
	bool access = freeSeats(roomSelect, row, column);

	if (access)
	{
		rooms[roomSelect - 1].seats[row - 1][column - 1] = "R";
		printf("Asiento(s) reservado(s)\n");
	}
	else {
		printf("Lo sentimos, asiento ocupado\n");
	}
}

void Room::buySeats(int roomSelect, int row, int column)
{
	bool access = isReserveSeats(roomSelect, row, column);

	if (access)
	{
		rooms[roomSelect - 1].seats[row - 1][column - 1] = "C";
	}
}
