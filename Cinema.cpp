#include "Cinema.h"

Cinema::Cinema()
{
	option = 0;
	open = true;
	numOfMovies = 0;
	numOfRooms = 0;
	numOfFuntions = 0;
	numOfClients = 0;
	seatsReserved = 0;
	roomSelected = 0;
	allSeatsReserved = 0;
	numOfTickets = 0;
	reservedSeatsColumn = nullptr;
	reservedSeatsRow = nullptr;
	ticketVector = new int[numOfTickets];
	movieInfo = nullptr;
	roomInfo = nullptr;
	scheduleInfo = nullptr;
	clientVector = nullptr;
}

Cinema::~Cinema()
{
	delete[] ticketVector;
	delete[] reservedSeatsRow;
	delete[] reservedSeatsColumn;
	delete[] movieInfo;
	delete[] roomInfo;
	delete[] scheduleInfo;
	delete[] clientVector;
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
			printf("Gracias por preferirnos, hasta pronto\n");
			exit(0);
			break;
		case 3:
			return;
			break;
		}
	}
}

void Cinema::menuOfMaintenance()
{
	while (open)
	{
		printf("Elija una opcion\n");
		printf("1. Crear Peliculas\n");
		printf("2. Crear salas\n");
		printf("3. Crear horarios\n");
		printf("4. Asignar pelicula, sala, horario\n");
		printf("5. Regresar\n");
		scanf_s("%d", &option);
		system("CLS");

		switch (option)
		{
		case 1:
			printf("Cuantas peliculas desea crear: ");
			scanf_s("%d", &numOfMovies);
			cin.ignore();
			movieInfo = new Movie[numOfMovies];
			for (int i = 0; i < numOfMovies; i++)
			{
				movieInfo[i].createMovies(numOfMovies);
			}

			break;
		case 2:
			printf("Cuantas salas desea crear: ");
			scanf_s("%d", &numOfRooms);
			cin.ignore();
			roomInfo = new Room[numOfRooms];
			for (int i = 0; i < numOfRooms; i++)
			{
				roomInfo[i].createRooms(numOfRooms);
			}


			break;
		case 3:
			printf("Cuantas funciones se tendran: ");
			scanf_s("%d", &numOfFuntions);
			scheduleInfo = new Schedule[numOfFuntions];
			for (int i = 0; i < numOfFuntions; i++)
			{
				scheduleInfo[i].createSchedule(numOfFuntions);
			}

			break;
		case 4:
			for (int i = 0; i < numOfMovies; i++)
			{
				assignScheduleAndMovie();
			}

			break;
		case 5:
			if (movieInfo != nullptr || roomInfo != nullptr || scheduleInfo != nullptr)
			{
				return;
			}
			else
			{
				printf("Primero debe terminar el mantenimiento\n");
			}

			break;
		}
	}
}

void Cinema::reserveMenu()
{
	string name = "";
	int roomSelect = 0;
	int seatRow = 0, seatColumn = 0;
	int seatsCount = 0;

	printf("Seleccione el numero de sala a reservar: \n");
	scanf_s("%d", &roomSelect);
	cin.ignore();
	system("CLS");
	printf("Aqui reservara su asiento.\n");
	printf("En total hay 112 butacas.\nCada butaca cuesta 2800 colones.\n");
	printf("Para elegir un asiento primero escriba la fila y despues la columna que desea reservar.\n");
	system("PAUSE");

	printf("Antes de reservar, digite su nombre: ");
	getline(cin, name);
	printf("\nD = Disponible. R = Reservado. C = Comprado\n");
	roomInfo[roomSelect - 1].printRoom(roomSelect);
	printf("Cuantos asientos desea reservar: ");
	scanf_s("%d", &seatsCount);

	roomSelected = roomSelect;

	if (allSeatsReserved < seatsCount)
	{
		delete[] reservedSeatsRow;
		delete[] reservedSeatsColumn;
		allSeatsReserved = seatsCount;
		reservedSeatsRow = new int[allSeatsReserved];
		reservedSeatsColumn = new int[allSeatsReserved];
	}

	while (seatsCount > 0)
	{
		bool isAvailable = false;
		while (!isAvailable)
		{
			printf("Digite fila y columna a reservar: \n");
			scanf_s("%d %d", &seatRow, &seatColumn);
			if (roomInfo[roomSelect - 1].isValidSeats(seatRow, seatColumn))
			{
				isAvailable = true;
				roomInfo[roomSelect - 1].reservedSeats(seatRow, seatColumn);
				reservedSeatsRow[seatsReserved] = seatRow;
				reservedSeatsColumn[seatsReserved] = seatColumn;
				seatsReserved++;
				seatsCount--;
				if (seatsCount == 0)
				{
					createTicket();
				}
			}
		}

	}
	int ticket = clientInfo.getTicket();
	printf("Su ticket de compra es: %d\n", ticket);
	addClient(name, numOfClients, ticket);
	roomInfo[roomSelect - 1].printRoom(roomSelect);
	system("PAUSE");
}

void Cinema::buyMenu()
{
	cin.ignore();
	string name = "";
	string option = "";
	bool pay = true;
	int room = getRoomSelect();
	int entrance = 2800;
	printf("En caso de no recordar su ticket, digite SI para obtener su ticket o NO para escribir el ticket: ");
	getline(cin, option);
	if (option == "SI" || option == "Si" || option == "si")
	{
		printf("Digite su nombre: ");
		getline(cin, name);
		printf("Su ticket es: %d", findTheTicket(name));

	}


	bool buy = false;
	int typedTicket = 0;

	while (!buy)
	{
		printf("\nDigite su ticket de compra: ");
		scanf_s("%d", &typedTicket);
		cin.ignore();

		if (typedTicket != 0)
		{
			if (correctTicket(typedTicket))
			{
				buy = true;
				dataClient();
				printf("Compra realizada con exito.\n");
				printf("Factura.\n");
				printf("Nombre del cliente: %s\n", clientInfo.getName().c_str());
				printf("Identificacion: %s\n", clientInfo.getId().c_str());
				printf("Asientos reservados: %d\n", seatsReserved);
				roomInfo[room - 1].printOnlyMovie(room);
				printf("Total pagado: %d\n", entrance * seatsReserved);

				for (int i = 0; i < seatsReserved; i++)
				{
					int rowSeat = reservedSeatsRow[i];
					int columnSeat = reservedSeatsColumn[i];
					printf("Asiento reservado en la fila: %d y columna: %d \n", rowSeat, columnSeat);
					roomInfo[room - 1].changeReservedToPurchased(rowSeat, columnSeat);
				}
				delete[] reservedSeatsRow;
				delete[] reservedSeatsColumn;
				reservedSeatsRow = nullptr;
				reservedSeatsColumn = nullptr;
				seatsReserved = 0;
				allSeatsReserved = 0;
				open = false;
				system("PAUSE");
				system("CLS");
			}
			else
			{
				printf("Ticket incorrecto. Por favor, intente nuevamente.\n");
			}
		}
	}



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

void Cinema::assignScheduleAndMovie()
{
	int roomSelect = 0, scheduleSelect = 0, movieSelect = 0;
	printf("Seleccione una sala (1 a %d):", numOfRooms);
	scanf_s("%d", &roomSelect);
	printf("Seleccione una pelicula (1 a %d):", numOfMovies);
	scanf_s("%d", &movieSelect);
	printf("Seleccione un horario(1 a %d):", numOfFuntions);
	scanf_s("%d", &scheduleSelect);

	if (roomSelect > 0 && roomSelect <= numOfRooms && movieSelect > 0 && movieSelect <= numOfMovies && scheduleSelect > 0 && scheduleSelect <= numOfFuntions)
	{
		roomInfo[roomSelect - 1].assignMovie(&movieInfo[movieSelect - 1]);
		roomInfo[roomSelect - 1].assignSchedule(&scheduleInfo[scheduleSelect - 1]);
		printf("Asignacion exitosa\n");
	}
	else
	{
		printf("Seleccion invalida, intente de nuevo: \n");
	}
}

void Cinema::loadTicketVector(int* firstTicketVector, int* secondTicketVector, int sizeOfVector)
{
	for (int i = 0; i < sizeOfVector; i++)
	{
		firstTicketVector[i] = secondTicketVector[i];
	}
}

void Cinema::loadTickets(int*& ticketVector, int& size, int newTicket)
{
	int* auxTicketVector = ticketVector;
	size++;
	ticketVector = new int[size];
	loadTicketVector(ticketVector, auxTicketVector, size - 1);
	ticketVector[size - 1] = newTicket;
	delete[] auxTicketVector;
}

int Cinema::generateTicket()
{
	return rand() % 99 + 1;
}

void Cinema::createTicket()
{
	int ticket = generateTicket();
	loadTickets(ticketVector, numOfTickets, ticket);
	clientInfo.setTicket(ticket);
}

void Cinema::dataClient()
{
	string nameClient = " ";
	string idClient = " ";
	int card = 0;

	printf("Digite su nombre completo: ");
	getline(cin, nameClient);
	printf("Digite su identificacion: ");
	getline(cin, idClient);
	printf("Digite numero de su targeta: ");
	scanf_s("%d", &card);

	clientInfo.setName(nameClient);
	clientInfo.setId(idClient);
	clientInfo.setCard(card);
}

bool Cinema::correctTicket(int typedTicket)
{
	int* tickets = getTicketVector();
	for (int i = 0; i < 112; i++)
	{
		if (tickets[i] == typedTicket)
		{
			return true;
		}
	}
	return false;
}

void Cinema::addClient(string nameClient, int& size, int ticket)
{
	Client* auxClientVector = new Client[numOfClients + 1];
	for (int i = 0; i < numOfClients; i++)
	{
		auxClientVector[i] = clientVector[i];
	}
	Client newClient = Client(nameClient, "", 0, ticket);
	auxClientVector[numOfClients] = newClient;
	delete[] clientVector;

	clientVector = auxClientVector;
	numOfClients++;
}

int Cinema::findTheTicket(string name)
{
	for (int i = 0; i < numOfClients; i++)
	{
		if (clientVector[i].getName() == name)
		{
			return clientVector[i].getTicket();
		}
	}
	return -1;
}

int* Cinema::getTicketVector()
{
	return ticketVector;
}

int Cinema::getRoomSelect()
{
	return roomSelected;
}
