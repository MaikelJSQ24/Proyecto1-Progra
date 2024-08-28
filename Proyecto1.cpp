#include "Cinema.h"

int main()
{
	Cinema cinema1;
	bool open = true;
	int option = 0;

	while (open)
	{
		printf("---Bienvenido a Nueva Cinema SA---\n");
		printf("Digite una opcion.\n");
		printf("1. Archivo\n");
		printf("2. Mantenimiento\n");
		printf("3. Reserva\n");
		printf("4. Venta\n");
		printf("5. Salir\n");
		scanf_s("%d", &option);
		system("CLS");

		switch (option)
		{
		case 1:
			cinema1.archiveMenu();
			break;
		case 2:
			cinema1.maintenanceMenu();
			break;
		case 3:
			cinema1.reserveMenu();
			break;
		case 4:

			break;
		case 5:
			exit(0);
			break;
		}
	}
}