#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "utn.h"


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
			printf("\n◉Carga exitosa...\n");
		}
		else
		{
			printf("\n◉Error con la carga\n");
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
			printf("\n◉Carga exitosa del archivo binario...\n");
		}
		else
		{
			printf("\n◉Error con la carga del archivo binario\n");
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
		Passenger_add(pArrayListPassenger);

		retorno = 0;
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
	int retorno = - 1;
	int buscadorId;
	int index;
	Passenger* auxPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);

		utn_getNumero(&buscadorId, "◉Ingrese el ID a modificar:", "◉Error,reingrese el ID a modificar", 1, 2000, 3);

		index = encontrarPassengerPorId(pArrayListPassenger,buscadorId);

		if(index != -1)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, index);

			Passenger_modificar(auxPassenger);

			retorno = 0;
		}
	}
    return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////
int encontrarPassengerPorId(LinkedList* pArrayListPassenger, int buscadorId)
{
	int tam;
	int retorno=-1;
	Passenger* auxPassenger = NULL;
	if(pArrayListPassenger!=NULL)
	{
		tam = ll_len(pArrayListPassenger);
		for(int i=0;i<tam;i++)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);

			if(auxPassenger->id == buscadorId)
			{
				retorno = ll_indexOf(pArrayListPassenger, auxPassenger);
			}
		}
	}
	return retorno;
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
	int retorno = - 1;
	int index;
	int buscadorId;
	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumero(&buscadorId, "\n◉Ingrese el ID del passenger a eliminar:", "\n◉Error,reigrese el ID del passenger a eliminar\n", 1, 2000, 3);
		index = encontrarPassengerPorId(pArrayListPassenger, buscadorId);

		if(index != -1)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, index);

			ll_remove(pArrayListPassenger, index);
			Passenger_delete(auxPassenger);

			printf("\n◉La baja se ha realizado con exito\n");
			retorno = 0;
		}
		else
		{
			printf("\n◉Error en la baja,reintentar..\n");
		}
	}
    return retorno;
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
		printf("\n◉Error\n");
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

		if(pFile != NULL)
		{
			parser_guardarTexto(pFile, pArrayListPassenger);
			printf("\n◉Se guardo correctamente en texto..\n");

			fclose(pFile);
		}

		retorno = 0;
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
	FILE* pFile;

		if(path != NULL && pArrayListPassenger != NULL)
		{
			pFile = fopen(path,"wb");

			if(pFile != NULL)
			{
				parser_guardarBinario(pFile, pArrayListPassenger);
				printf("\n◉Se guardo correctamente en bin..\n");

				fclose(pFile);
			}

			retorno = 0;
		}
	    return retorno;
}

