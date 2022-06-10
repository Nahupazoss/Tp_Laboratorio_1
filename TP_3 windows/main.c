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
    int flag = 0;
    //FILE* pArchivoId;
    LinkedList* listaPasajeros = ll_newLinkedList();
    //pArchivoId = fopen("archivoId.txt","w");

    do
    {
    	option = menu();

        switch(option)
        {
            case 1://cargar datos txt
            	if(flag == 0)
            	{
            		controller_loadFromText("data.csv",listaPasajeros);
            		flag = 1;
            	}
            	else
            	{
            		if(flag == 1)
            		{
            			printf("\nYa se realizo una carga de pasajeros...\n\nRedirigiendo al menu principal\n");
            		}
            	}
            break;
            case 2://cargar datos bn
            	if(flag == 0)
            	{
            		controller_loadFromBinary("data2.bin", listaPasajeros);
            	    flag = 1;
            	}
            	else
            	{
            		if(flag == 1)
            		{
            			printf("\nYa se realizo una carga de pasajeros...\n\nRedirigiendo al menu principal\n");
            		}
            	}
            break;
            case 3://alta
            	controller_addPassenger(listaPasajeros);
            break;
            case 4://modificar
            	if(ll_isEmpty(listaPasajeros) == 0)
            	{
            		controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nPrimero cargar o dar de alta algun pasajero..\n\nRedirigiendo al menu principal...\n");
            	}
            break;
            case 5://baja
            	if(ll_isEmpty(listaPasajeros) == 0)
				{
            		controller_removePassenger(listaPasajeros);
				}
            	else
            	{
            		printf("\nPrimero cargar o dar de alta algun pasajero..\n\nRedirigiendo al menu principal...\n");
            	}
            break;
            case 6://list passenger
            	if(ll_isEmpty(listaPasajeros) == 0)
            	{
            		controller_ListPassenger(listaPasajeros);
            	}
               	else
               	{
               		printf("\nPrimero cargar o dar de alta algun pasajero..\n\nRedirigiendo al menu principal...\n");
               	}
            break;
            case 7://ordenar pasajeros
            	if(flag == 1)
            	{
                	controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nPrimero cargar o dar de alta algun pasajero..\n\nRedirigiendo al menu principal...\n");
            	}
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
