#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");
		if(pArchivo != NULL)
		{
			parser_PassengerFromText(pArchivo, pArrayListPassenger);
			printf("\nCarga exitosa...\n");
		}
		else
		{
			printf("\nError con la carga\n");
		}
		fclose(pArchivo);
		retorno = 0;
	}
    return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListPassenger != NULL && path != NULL)
	{
		pArchivo = fopen(path,"rb");
		if(pArchivo != NULL)
		{
			parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
			printf("\nCarga exitosa...\n");
		}
		else
		{
			printf("\nError con la carga\n");
		}
		fclose(pArchivo);
		retorno = 0;
	}

    return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = - 1;

	if(pArrayListPassenger != NULL)
	{




	}


    return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{



    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListPassenger);
	Passenger* auxOnePassenger;

	if(pArrayListPassenger != NULL)
	{
		printf("\n===========================================Passenger list==========================================\n");
		printf("ID\tNAME\t        LAST NAME\tPRICE\t   TYPE PASSENGER     FLIGTH CODE   STATUS FLIGHT\n");
		printf("===================================================================================================\n");
		for(i=0;i<tam;i++)
		{
			auxOnePassenger = ll_get(pArrayListPassenger, i);
			Passenger_mostrar(auxOnePassenger);
		}
		retorno = 0;
	}
	else
	{
		printf("\nError\n");
	}
	printf("===================================================================================================\n");


    return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

//////////////////////////////////////////////////////////////////////////////////////

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"w");

		parser_PassengerFromText(pFile, pArrayListPassenger);

		fclose(pFile);
	}


    return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

    return retorno;
}

