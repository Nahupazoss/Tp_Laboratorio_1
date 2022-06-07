/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

// todo lo que int y float si es * en el getter tambien *
/***************************************************************************************/
Passenger* Passenger_new()
{
	return malloc(sizeof(Passenger));
}
/***************************************************************************************/
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* statusFlightStr,char* codigoVueloStr)
{
	Passenger* onePassenger;

	onePassenger = Passenger_new();

	if(onePassenger != NULL && idStr != NULL && nombreStr != NULL
	&& apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL
	&& statusFlightStr != NULL && codigoVueloStr != NULL)
	{
		Passenger_setId(onePassenger , atoi(idStr) );
		Passenger_setNombre(onePassenger , nombreStr);
		Passenger_setApellido(onePassenger , apellidoStr);
		Passenger_setPrecio(onePassenger , atof(precioStr) );
		Passenger_setTipoPasajero(onePassenger , Passenger_TipoPasajeroStr(tipoPasajeroStr));
		Passenger_setStatusFlight(onePassenger , statusFlightStr );
		Passenger_setCodigoVuelo(onePassenger , codigoVueloStr);
	}
	else
	{
		printf("\nNo se pudo asignar memoria..\n");
	}

	return  onePassenger;
}
/***************************************************************************************/
void Passenger_delete(Passenger* this)
{
	free(this);
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
int Passenger_setId(Passenger* this,int id)
{
	int retorno=-1;

	if(this != NULL && id > 0 )
	{
		retorno = 0;
		this->id = id;
	}

	return retorno;
}
/***************************************************************************************/
int Passenger_getId(Passenger* this,int* id)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*id = this->id;
	}

	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
int Passenger_setNombre(Passenger* this,char* nombre)
{
    int retorno = -1;
    //falta validar
    if(this != NULL && nombre != NULL && strlen(nombre) > 2 )
    {
        strcpy(this->nombre, nombre);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
int Passenger_setApellido(Passenger* this,char* apellido)
{
    int retorno = -1;

    if(this != NULL && apellido != NULL && strlen(apellido) > 2)
    {
        strcpy(this->apellido, apellido);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=-1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=-1;

	if(this != NULL && precio > 0)
	{
		retorno = 0;
		this->precio = precio;
	}

	return retorno;
}
/***************************************************************************************/
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=-1;

	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio  = this->precio;
	}

	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		this->tipoPasajero = tipoPasajero;
	}

	return retorno;
}
/***************************************************************************************/
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno=-1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;

	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strcpy(codigoVuelo,this->codigoVuelo);
	}

	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
int Passenger_setStatusFlight(Passenger* this,char* statusFlight)
{
	int retorno=-1;

	if(this != NULL)
	{
		strcpy(this->statusFlight, statusFlight);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int Passenger_getStatusFlight(Passenger* this,char* statusFlight)
{
	int retorno=-1;

	if(this != NULL && statusFlight != NULL)
	{
		strcpy(statusFlight,this->statusFlight);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
//FUNCIONES AGREGADAS//
/***************************************************************************************/
void Passenger_mostrar(Passenger* onePassenger)
{
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	int typePassenger;
	char auxTypePassenger[20];
	char auxFlyCode[20];
	char auxStatusFlight[20];

	Passenger_getId(onePassenger, &auxId);
	Passenger_getNombre(onePassenger, auxNombre);
	Passenger_getApellido(onePassenger, auxApellido);
	Passenger_getPrecio(onePassenger, &auxPrecio);
	Passenger_getTipoPasajero(onePassenger, &typePassenger);
	Passenger_getCodigoVuelo(onePassenger, auxFlyCode);
	Passenger_getStatusFlight(onePassenger, auxStatusFlight);
	Passenger_TipoPasajeroInt(typePassenger, auxTypePassenger);

	if(onePassenger != NULL)
	{
		printf("%4d\t%-15s\t%-15s\t%2.f\t%15s\t%15s\t%15s\n",auxId,auxNombre,auxApellido,auxPrecio,
				auxTypePassenger,auxFlyCode,auxStatusFlight);

	}
	else
	{
		printf("\nError\n");
	}

}
/***************************************************************************************/
int Passenger_TipoPasajeroStr(char* tipoStr)
{
	int retorno = -1;

	if(tipoStr !=NULL)
	{
		if(strcmp(tipoStr,"FirstClass") == 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(tipoStr,"ExecutiveClass") == 0)
			{
				retorno = 2;
			}
			else
			{
				if(strcmp(tipoStr,"EconomyClass") == 0)
				{
					retorno = 3;
				}
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
int Passenger_TipoPasajeroInt(int tipo,char* tipoStr)
{
	int retorno = -1;

	if(tipoStr != NULL)
	{
		switch(tipo)
		{
		case 1:
			strcpy(tipoStr,"FirstClass");
		break;
		case 2:
			strcpy(tipoStr,"ExecutiveClass");
		break;
		case 3:
			strcpy(tipoStr,"EconomyClass");
		break;
		}
	}
	return retorno;
}
/***************************************************************************************/

/***************************************************************************************/

/***************************************************************************************/

/***************************************************************************************/
