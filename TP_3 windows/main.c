#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn.h"
#include "parser.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    //FILE* pArchivoId;

    LinkedList* listaPasajeros = ll_newLinkedList();

    //pArchivoId = fopen("archivoId.txt","w");

    do
    {
    	option = menu();

        switch(option)
        {
            case 1://cargar datos txt
                controller_loadFromText("data.csv",listaPasajeros);
            break;
            case 2://cargar datos bn
            	controller_loadFromBinary("data2.bin", listaPasajeros);
            break;

            case 3://alta
            	controller_addPassenger(listaPasajeros);
            break;

            case 4://modificar
            	controller_editPassenger(listaPasajeros);
            break;

            case 5://baja
            	controller_removePassenger(listaPasajeros);
            break;

            case 6://list passenger
            	controller_ListPassenger(listaPasajeros);
            break;

            case 7://ordenar pasajeros
            	controller_sortPassenger(listaPasajeros);
            break;

            case 8://guardar los datos txt
            	controller_saveAsText("data2.csv", listaPasajeros);
            break;

            case 9://guardar los datos bn
            	controller_saveAsBinary("data2.bin", listaPasajeros);
            break;

            case 10:
            	printf("\nLeft seccsfull....\n");
            break;

            default:
            	printf("\nWrong option....\n");
            break;
        }

    }while(option != 10);

    return 0;
}
