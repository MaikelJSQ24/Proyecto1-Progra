#include "Cinema.h"

Cinema::Cinema()
{
	open = true;
	option = 0;
}

void Cinema::archiveMenu()
{
	while (open)
	{
		printf("Elija una opcion\n");
		printf("1. Acerca de\n");
		printf("2. Salir\n");
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
		}
	}
}

void Cinema::maintenanceMenu()
{
	int numOfMovies = 0;
	int numOfRooms = 0;
	int movieNumber = 0;
	while (open)
	{
		printf("Elija una opcion\n");
		printf("1. Crear Peliculas\n");
		printf("2. Crear salas\n");
		printf("3. Crear horarios\n");
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
			printf("Cuantas salas desea crear: \n");
			scanf_s("%d", &numOfRooms);
			cin.ignore();
			roomInfo.createRooms(numOfRooms);

			for (int i = 0; i < numOfRooms; i++)
			{
				printf("Digite cual pelicula desea para la sala %d: \n", i + 1);
				scanf_s("%d", &movieNumber);
				cin.ignore();
			}
			break;
		case 3:
			/*printf("Pelicula a mostrar: ");
			scanf_s("%d", &movieNumber);
			movieInfo.printMovie(movieNumber);*/
			reserveMenu();
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
	printf("Cual sala desea reservar: ");
	scanf_s("%d", &roomSelect);

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


void Cinema::createMovies(Movie movies)
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

	printf("Duracion de la pelicula: \n");
	scanf_s("%d", &duration);

	printf("Anio de la pelicula: \n");
	scanf_s("%d", &year);

	movies.setName(name);
	movies.setCountry(country);
	movies.setReview(review);
	movies.setDuration(duration);
	movies.setYear(year);
}