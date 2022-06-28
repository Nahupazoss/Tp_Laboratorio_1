/*
 ============================================================================
 Name        : TRABAJO.c
 Author      : NAHUEL PAZOS | DIV: 1K | PRIMER CUATRIMESTRE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayPassenger.h"
#include "validaciones.h"

#define TAM 2000
#define TAMP 5
#define TAMTYPE 3

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int contador;

	contador = 5;//lo inicializo dependiendo de cuantos pasajeros hardcodee

	//estructuras  //nombre para llamarlas[tamanio]
	eTypePassenger types[TAMTYPE];
	ePassenger pasajero[TAM];
	eStatusFlight status[TAMTYPE];
	eFlyCode code[TAMP];

	//hardcodeo
	inicializarVector(pasajero,TAM);
	hardcodePassenger(pasajero, TAMP,contador);
	hardCodeType(types, TAMTYPE);
	hardcodeStatus(status, TAMTYPE);
	hardCode(code, TAMP);

	do
	{
		opcion=menu();//menu de opciones

		switch(opcion)
		{
		case 1://alta
			contador++;
			altaPasajero(pasajero,TAM,types,status,TAMTYPE,code,TAMP,contador);
		break;
		case 2://modificar
			if(contador > 0)
			{
				modificarPasajeros(pasajero, TAM,types,status,TAMTYPE,code,TAMP);
			}
			else
			{
				printf("Enter passengers first (option 1)..\n");
			}
		break;
		case 3://baja
			if(contador > 0)
			{
				if(!darDeBaja(pasajero,TAM,types,status,TAMTYPE,code,TAMP))
				{
					continue;
				}
				else
				{
					printf("\nTere was an error, could not unsubscribe..(please retry)");
				}
			}
			else
			{
				printf("\nEnter passengers first (option 1)..\n");
			}
		break;
		case 4://informar
			opcionesLista(pasajero, TAM, types, status,TAMTYPE, code,TAMP,contador);
		break;
		case 5://salir
			printf("\nLeave");
		break;
		default:
			printf("\nWrong option...");
		break;
		}

	}while(opcion != 5);

	return EXIT_SUCCESS;
}
