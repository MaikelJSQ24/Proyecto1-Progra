#include "Cinema.h"

int main()
{
	srand(time(nullptr));
	Cinema cinema1;
	int option = 0;
	bool open = true;
	bool access = false;

	while (open)
	{
		printf("---Bienvenido a Nueva Cinema SA---\n");
		printf("Digite una opcion.\n");
		printf("1. Archivo\n");
		printf("2. Mantenimiento\n");
		printf("3. Reserva\n");
		printf("4. Venta\n");
		scanf_s("%d", &option);
		system("CLS");

		switch (option)
		{
		case 1:
			cinema1.archiveMenu();
			break;
		case 2:
			cinema1.menuOfMaintenance();
			access = true;
			break;
		case 3:
			if (access)
			{
				cinema1.reserveMenu();
			}
			else {
				printf("Error, primero haga el mantenimiento.\n");
			}
			break;
		case 4:
			if (access)
			{
				cinema1.buyMenu();
			}
			else {
				printf("Error, primero haga el mantenimiento.\n");
			}
			break;
		}
	}
	
}
