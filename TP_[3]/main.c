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
/****************************************************
 * NAHUEL RODRIGO PAZOS DIV 1K TP 3 TERMINADO
*****************************************************/
int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int flag = 0;
    int flagGuardadoTxt = 0;
    int flagGuardadoBn = 0;
    int controlador;

    LinkedList* listaPasajeros = ll_newLinkedList();

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
            	controlador = controller_addPassenger(listaPasajeros);
            	if(controlador == 0)
            	{
            		printf("\nEl pasajero se añadio exitosamente\n");
            	}
            	else
            	{
            		printf("\nEl pasajero no se ha podido añadir..\n\nPorfavor reintente..\n");
            	}
            break;
            case 4://modificar
            	if(ll_isEmpty(listaPasajeros) == 0)
            	{
            		controlador = controller_editPassenger(listaPasajeros);

            		if(controlador == 0)
            		{
            			printf("\nEl pasajero se ha modificado exitosamente\n");
            		}
            		else
            		{
            			printf("\nEl pasajero no se ha podido modificar..\n\nPorfavor reintente..\n");
            		}
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
            	if(flag == 1 || ll_isEmpty(listaPasajeros) == 0)
            	{
                	controller_sortPassenger(listaPasajeros);
            	}
            	else
            	{
            		printf("\nPrimero cargar o dar de alta algun pasajero..\n\nRedirigiendo al menu principal...\n");
            	}
            break;
            case 8://guardar los datos txt
            	if(flag == 1)
            	{
            		controller_saveAsText("data.csv", listaPasajeros);
            		flagGuardadoTxt = 1;

            	}
            	else
            	{
            		printf("\nPrimero cargar la lista de pasajeros..\n\nRedirigiendo al menu principal...\n");
            	}
            break;
            case 9://guardar los datos bn
            	if(flag == 1)
            	{
            		controller_saveAsBinary("data2.bin", listaPasajeros);
            		flagGuardadoBn = 1;

            	}
            	else
            	{
            		printf("\nPrimero cargar la lista de pasajeros..\n\nRedirigiendo al menu principal...\n");
            	}
            break;
            case 10:
            	if(flagGuardadoTxt == 0 || flagGuardadoBn == 0)
            	{
            		printf("\nAntes de salir del programa debe guardar en las opciones (8 y 9)\n\nRedirigiendo al menu principal...\n");
            	}
            	else
            	{
            		if(flagGuardadoTxt == 1 && flagGuardadoBn == 1)
            		{
            			printf("\n◉Left seccsfull....\n");
            		}
            	}
            break;
            default:
            	printf("\n◉Wrong option....\n");
            break;
        }

    }while(option != 10 || flagGuardadoTxt != 1 || flagGuardadoBn != 1);

    ll_deleteLinkedList(listaPasajeros);

    return 0;//
}
