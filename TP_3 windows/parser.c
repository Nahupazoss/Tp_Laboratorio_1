#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
/***************************************************************************************/
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	char titulo[400];
	char auxIdStr[5];
	char nombreStr[30];
	char apellidoStr[30];
	char precioStr[10];
	char flyCodeStr[10];
	char typePassengerStr[15];
	char statusFlightStr[20];
	Passenger* onePassenger;

	if(pFile != NULL && pArrayListPassenger !=NULL)
	{
		fscanf(pFile,"%[^\n]",titulo);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
					,auxIdStr,nombreStr,apellidoStr,precioStr,flyCodeStr,typePassengerStr,statusFlightStr);

			onePassenger = Passenger_newParametros(auxIdStr, nombreStr, apellidoStr, precioStr,
					typePassengerStr, statusFlightStr, flyCodeStr);

			if(onePassenger != NULL)
			{
				ll_add(pArrayListPassenger, onePassenger);
			}
		}

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* aux;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			aux = Passenger_new();

			if(aux != NULL && fread(aux,sizeof(Passenger),1,pFile) == 1)
			{
				ll_add(pArrayListPassenger, aux);
			}

		}while(!feof(pFile));

	retorno = 0;
	}

    return retorno;
}
/***************************************************************************************/
/**
 *
 * @param pFile
 * @param pArrayListPassenger
 * @return
 */
int parser_guardarTexto(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListPassenger);
	Passenger* aux;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int typePassenger;
	char auxTypePassenger[20];
	char auxFlyCode[20];
	char auxStatusFlight[20];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");

		for(i=0;i<tam;i++)
		{
			aux = (Passenger*)ll_get(pArrayListPassenger, i);
			if(aux != NULL)
			{
				Passenger_getId(aux, &auxId);
				Passenger_getNombre(aux, auxNombre);
				Passenger_getApellido(aux, auxApellido);
				Passenger_getPrecio(aux, &auxPrecio);
				Passenger_getTipoPasajero(aux, &typePassenger);
				Passenger_getCodigoVuelo(aux, auxFlyCode);
				Passenger_getStatusFlight(aux, auxStatusFlight);
				Passenger_TipoPasajeroInt(typePassenger, auxTypePassenger);

				fprintf(pFile,"%d,%s,%s,%.0f,%s,%s,%s\n",auxId,auxNombre,auxApellido
						,auxPrecio,auxFlyCode,auxStatusFlight,auxTypePassenger);

				retorno = 0;
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
/**
 *
 * @param pFile
 * @param pArrayListPassenger
 * @return
 */
int parser_guardarBinario(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListPassenger);
	Passenger* aux;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		for(i=0;i<tam;i++)
		{
			aux = (Passenger*)ll_get(pArrayListPassenger, i);

			if(aux != NULL)
			{
				fwrite(aux,sizeof(Passenger),1,pFile);
			}
		}

		retorno = 0;
	}

	return retorno;
}
