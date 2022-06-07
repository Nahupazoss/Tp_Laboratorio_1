#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
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
int validarNumero(char *numero);

int pedirEntero(char *mensaje,char *mensajeError);

int menu();

int main()
{
	setbuf(stdout,NULL);
    int option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do
    {
    	option = menu();

        switch(option)
        {
            case 1://cargar datos txt
                controller_loadFromText("data.csv",listaPasajeros);
            break;
            case 2://cargar datos bn
            	controller_loadFromBinary("data.bin", listaPasajeros);
            break;

            case 3://alta

            break;

            case 4://modificar
            break;

            case 5://baja
            break;

            case 6://list passenger
            	controller_ListPassenger(listaPasajeros);
            break;

            case 7://ordenar pasajeros
            break;

            case 8://guardar los datos txt
            	controller_saveAsText("data2.csv", listaPasajeros);
            break;

            case 9://guardar los datos bn

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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int validarNumero(char *numero)
{
    int retorno=1;
    int len;
    if(numero!=NULL){
        len=strlen(numero);
        for(int i=0;i<len;i++){ //"51"
            if(!isdigit(numero[i])){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int pedirEntero(char *mensaje,char *mensajeError)
{
    int retorno;
    char numero[1000];
    printf(mensaje);
    scanf("%s",numero);
    while(!validarNumero(numero)){
        printf(mensajeError);
        printf(mensaje);
        scanf("%s",numero);
    }
    retorno=atoi(numero);
    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{
	int opcion;

	  printf("\n=============================================MENU==================================================");
	opcion = pedirEntero("\n1〉〉Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)"
			"\n2〉〉Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)"
			"\n3〉〉Alta de pasajero"
			"\n4〉〉Modificar datos de pasajero"
			"\n5〉〉Baja de pasajero"
			"\n6〉〉Listar pasajeros"
			"\n7〉〉Ordenar pasajeros"
			"\n8〉Guardar los datos de los pasajeros en el archivo data.csv (modo texto)"
			"\n9〉〉Guardar los datos de los pasajeros en el archivo data.csv (modo binario)"
			"\n10〉〉Salir"
			"\n◉Opcion:","\nError, opcion no valida\n");
	  printf("===================================================================================================\n");

	  return opcion;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
