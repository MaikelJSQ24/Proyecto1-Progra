#include "Cinema.h"

Cinema::Cinema()
{
	open = true;
	option = 0;
	movies = nullptr;
	numOfSchedules = 0;
	schedules = nullptr;
}

void Cinema::archiveMenu()
{
	while (open)
	{
		printf("Elija una opcion\n");
		printf("1. Acerca de\n");
		printf("2. Salir\n");
		printf("3. Regresar\n");
		scanf_s("%d", &option);
		system("CLS");

		switch (option)
		{
		case 1:
			about();
			break;
		case 2:
			exit(0);
			break;
		case 3:
			return;
			break;
		}
	}
}

void Cinema::maintenanceMenu()
{
	int numOfMovies = 0;
	int numOfRooms = 0;
	int movieNumber = 0;
	int roomSelect = 0;
	int scheduleSelect = 0;

	while (open)
	{
		printf("Elija una opcion\n");
		printf("1. Crear Peliculas\n");
		printf("2. Crear horarios\n");
		printf("3. Crear salas\n");
		printf("4. Regresar\n");
		scanf_s("%d", &option);
		system("CLS");

		switch (option)
		{
		case 1:
			printf("Cuantas peliculas desea crear: \n");
			scanf_s("%d", &numOfMovies);
			cin.ignore();

			movies = new Movie[numOfMovies];
			for (int i = 0; i < numOfMovies; i++)
			{
				createMovies(movies[i]);
			}

			break;
		case 2:
			printf("Cuantos horarios tendra el cine: ");
			scanf_s("%d", &numOfSchedules);
			cin.ignore();

			schedules = new Schedule[numOfSchedules];

			for (int i = 0; i < numOfSchedules; i++)
			{
				createSchedules(schedules[i]);

			}

			break;
		case 3:
			printf("Cuantas salas desea crear: \n");
			scanf_s("%d", &numOfRooms);
			cin.ignore();
			roomInfo.createRooms(numOfRooms);

			for (int i = 0; i < numOfMovies; i++)
			{
				printf("Seleccione el numero de sala a la que asignar la pelicula 1 a %d: \n", numOfRooms);
				scanf_s("%d", &roomSelect);
				cin.ignore();

				printf("Selecciona el numero de pelicula a asignar 1 a %d: \n", numOfMovies);
				scanf_s("%d", &movieNumber);
				cin.ignore();

				roomInfo.assingMovie(roomSelect - 1, movies[movieNumber - 1]);

				printf("Cuantos horarios desea asignar a la sala %d: \n", roomSelect);
				scanf_s("%d", &numOfSchedules);
				cin.ignore();

				Schedule* roomSchedules = new Schedule[numOfSchedules];
				for (int j = 0; j < numOfSchedules; j++)
				{
					printf("Selecciona el horario %d: \n", j + 1);
					scanf_s("%d", &scheduleSelect);
					cin.ignore();

					roomSchedules[j] = schedules[scheduleSelect - 1];
				}

				roomInfo.assingSchedule(roomSelect - 1, roomSchedules, numOfSchedules);
			}
			break;
		case 4:
			return;
			break;
		}
	}
}

void Cinema::reserveMenu()
{
	int roomSelect = 0;
	int seatRow = 0, seatColumn = 0;
	int seatsCount = 0;
	printf("Seleccione el numero de sala a reservar: \n");
	scanf_s("%d", &roomSelect);
	system("CLS");
	printf("Aqui reservara su asiento.\n");
	printf("En total hay 112 butacas.\n");
	printf("Para elegir un asiento primero escriba la fila y despues la columna que desea reservar.\n");
	system("PAUSE");
	printf("\n");

	printf("D = Disponible. R = Reservado. C = Comprado\n");
	roomInfo.printRoomInfo(roomSelect);
	printf("Cuantos asientos desea reservar: ");
	scanf_s("%d", &seatsCount);

	while (seatsCount > 0)
	{
		printf("Digite fila y columna a reservar: \n");
		scanf_s("%d %d", &seatRow, &seatColumn);
		roomInfo.freeSeats(roomSelect, seatRow, seatColumn);
		roomInfo.reserveSeats(roomSelect, seatRow, seatColumn);
		seatsCount--;
	}
	roomInfo.printRoom(roomSelect);
}

void Cinema::about()
{
	string text = "Estudiante: Maikel Jordan Segura Quiros|\n";
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < 39; i++)
		{
			cout << "*";
			if (i == 38)
			{
				cout << "|";
			}
		}
		cout << endl << text;
		text = "Programacion 1. ING Sistemas\t       |\n";
	}
	for (int i = 0; i < 39; i++)
	{
		cout << "*";
		if (i == 38)
		{
			cout << "|\n";
		}
	}

}

void Cinema::createMovies(Movie& movies)
{
	string name = " ";
	string country = " ";
	string review = " ";
	int duration = 0;
	int year = 0;

	printf("Nombre de la pelicula: \n");
	getline(cin, name);

	printf("Pais de la pelicula: \n");
	getline(cin, country);

	printf("Review de la pelicula: \n");
	getline(cin, review);

	printf("Duracion de la pelicula en minutos: \n");
	scanf_s("%d", &duration);

	printf("Anio de la pelicula: \n");
	scanf_s("%d", &year);
	cin.ignore();

	movies.setName(name);
	movies.setCountry(country);
	movies.setReview(review);
	movies.setDuration(duration);
	movies.setYear(year);
}

void Cinema::createSchedules(Schedule& schedule)
{
	int day = 0;
	int month = 0;
	int year = 0;
	string date = " ";
	int start = 0;
	string startHour = " ";
	int end = 0;
	string endHour = " ";
	int restriction = 0;
	bool open = true;

	printf("Digite un dia: ");
	scanf_s("%d", &day);
	while (day < 1 || day > 31)
	{
		printf("Dia invalido, intente de nuevo: ");
		scanf_s("%d", &day);
	}

	printf("Digite un mes: ");
	scanf_s("%d", &month);
	while (month < 1 || month > 12)
	{
		printf("Mes invalido, intente de nuevo: ");
		scanf_s("%d", &month);
	}

	printf("Digite un anio: ");
	scanf_s("%d", &year);
	if (year < 999)
	{
		year += 2000;
	}
	while (year > 9999)
	{
		printf("Anio invalido, intente de nuevo: ");
		scanf_s("%d", &year);
	}
	while (open)
	{
		printf("Minimo de tiempo en pelicula 3 horas.\n");
		printf("Digite hora de inicio (Formato 24h): ");
		scanf_s("%d", &start);

		printf("Digite hora de salida (Formato 24h): ");
		scanf_s("%d", &end);
		cin.ignore();

		restriction = end - start;

		if (restriction >= 3)
		{
			open = false;
		}
		else
		{
			printf("Tiempo entre inicio y fin muy corto.\n");
		}
	}

	date = to_string(day) + "-" + to_string(month) + "-" + to_string(year);
	startHour = to_string(start) + ":00";
	endHour = to_string(end) + ":00";
	if (start > 12)
	{
		startHour += "PM";
	}
	else
	{
		startHour += "AM";
	}
	if (end > 12)
	{
		endHour += "PM";
	}
	else
	{
		endHour += "AM";
	}
	schedule.setDay(date);
	schedule.setStartHour(startHour);
	schedule.setEndHour(endHour);
}
