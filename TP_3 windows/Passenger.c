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
#include "utn.h"

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
		Passenger_setStatusFlight(onePassenger ,statusFlightStr);
		Passenger_setCodigoVuelo(onePassenger ,codigoVueloStr );
	}
	else
	{
		printf("\n◉No se pudo asignar memoria..\n");
	}

	return  onePassenger;
}
/***************************************************************************************/
void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}

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
/***************************************************************************************/
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
int Passenger_statusFlightStr(char* statusStr)
{
	int retorno = -1;

	if(statusStr !=NULL)
	{
		if(strcmp(statusStr,"Aterrizado") == 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(statusStr,"En Horario") == 0)
			{
				retorno = 2;
			}
			else
			{
				if(strcmp(statusStr,"Demorado") == 0)
				{
					retorno = 3;
				}
				else
				{
					if(strcmp(statusStr,"En Vuelo")== 0)
					{
						retorno = 4;
					}
				}
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
int Passenger_flightCodeStr(char* flyCodeStr)
{
	int retorno = -1;

	if(flyCodeStr !=NULL)
	{
		if(strcmp(flyCodeStr,"IB0800A") == 0)
		{
			retorno = 1;
		}
		else
		{
			if(strcmp(flyCodeStr,"MM0987B") == 0)
			{
				retorno = 2;
			}
			else
			{
				if(strcmp(flyCodeStr,"BA2491A") == 0)
				{
					retorno = 3;
				}
				else
				{
					if(strcmp(flyCodeStr,"BR3456J")== 0)
					{
						retorno = 4;
					}
					else
					{
						if(strcmp(flyCodeStr,"FR5678G")== 0)
						{
							retorno = 5;
						}
						else
						{
							if(strcmp(flyCodeStr,"HY4567D")== 0)
							{
								retorno = 6;
							}
							else
							{
								if(strcmp(flyCodeStr,"GU2345F")== 0)
								{
									retorno = 7;
								}
								else
								{
									if(strcmp(flyCodeStr,"TU6789B")== 0)
									{
										retorno = 8;
									}
									else
									{
										if(strcmp(flyCodeStr,"HY4567D")== 0)
										{
											retorno = 9;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
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
		default:
			printf("error");
		break;
		}
	}
	return retorno;
}
/***************************************************************************************/
int Passenger_flightCodeInt(int flightCode,char* flightcodeStr)
{
	int retorno = -1;

	if(flightcodeStr != NULL)
	{
		switch(flightCode)
		{
		case 1:
			strcpy(flightcodeStr,"IB0800A");
		break;
		case 2:
			strcpy(flightcodeStr,"MM0987B");
		break;
		case 3:
			strcpy(flightcodeStr,"BA2491A");
		break;
		case 4:
			strcpy(flightcodeStr,"BR3456J");
		break;
		case 5:
			strcpy(flightcodeStr,"FR5678G");
		break;
		case 6:
			strcpy(flightcodeStr,"HY4567D");
		break;
		case 7:
			strcpy(flightcodeStr,"GU2345F");
		break;
		case 8:
			strcpy(flightcodeStr,"TU6789B");
		break;
		case 9:
			strcpy(flightcodeStr,"HY4567D");
		break;
		default:
			printf("error");
		break;
		}
	}
	return retorno;
}
/***************************************************************************************/
int Passenger_statusInt(int status,char* statusStr)
{
	int retorno = -1;

	if(statusStr != NULL)
	{
		switch(status)
		{
		case 1:
			strcpy(statusStr,"Aterrizado");
		break;
		case 2:
			strcpy(statusStr,"En Horario");
		break;
		case 3:
			strcpy(statusStr,"Demorado");
		break;
		case 4:
			strcpy(statusStr,"En Vuelo");
		break;
		default:
			printf("error");
		break;
		}
	}
	return retorno;
}
/***************************************************************************************/
/***************************************************************************************/
/***************************************************************************************/
int Passenger_add(LinkedList* this)
{
	int retorno = -1;
	char auxId[10] = "1001";
	char auxNombre[50];
	char auxApellido[50];
	char auxPrecio[10];
	int typePassenger;
	char auxTypePassenger[20];
	int flyCode;
	char auxFlyCode[20];
	int statusFlight;
	char auxStatusFlight[20];
	Passenger* aux = NULL;
	//FILE* auxid;

	if(this != NULL)
	{
			if(!(utn_getNombre(auxNombre, 50, "\n◉Ingrese su nombre:", "\n◉Error,reingrese su nombre:(no se aceptan numeros ni simbolos)", 3))&&
			   !(utn_getNombre(auxApellido, 50, "\n◉Ingrese su apellido:", "\n◉Error,reingrese su apellido:(no se aceptan numeros ni simbolos)", 3))&&
			   !(utn_getDni(auxPrecio, 10, "\n◉Ingrese su precio:", "\n◉Error,reingrese su precio", 3))&&
			   !(utn_getNumero(&typePassenger, "\n◉Ingrese su typePassenger:", "\n◉Error,reingrese su typePassenger:(1-2-3)", 1, 3, 3))&&
			   !(utn_getNumero(&flyCode, "\n◉Ingrese su flyCode:", "\n◉Error,reingrese su flyCode:(1-2-3-4-5-6-7-8-9)", 1, 9, 3))&&
			   !(utn_getNumero(&statusFlight, "\n◉Ingrese su statusFlight:", "\n◉Error,reingrese su status:(1-2-3-)", 1, 3, 3)))
			{
				Passenger_TipoPasajeroInt(typePassenger, auxTypePassenger);
				Passenger_flightCodeInt(flyCode,auxFlyCode);
				Passenger_statusInt(statusFlight, auxStatusFlight);

				aux = Passenger_newParametros(auxId, auxNombre, auxApellido, auxPrecio, auxTypePassenger, auxStatusFlight, auxFlyCode);

				if(aux != NULL)
				{
					ll_add(this, aux);
				}
			}
	}

	return retorno;
}
/***************************************************************************************/
int Passenger_modificar(Passenger* auxPassenger)
{
	int opcion;
	int retorno = -1;
	int auxStatus;
	int auxFlyCode;

	if(auxPassenger != NULL)
	{
		do
		{
			opcion = menu_modificar();
			//
			//TENGO QUE USAR LOS SET (Passenger_get....)
			//
			switch(opcion)
			{
			case 1:
				utn_getNombre(auxPassenger->nombre, 20, "\n◉Ingrese su nuevo nombre:",
				"\n◉Error,reingrese su nombre:(no se aceptan numeros ni simbolos)", 3);

				printf("\nSu cambio se ha realizado exitosamente\n");
			break;
			case 2:
				utn_getNombre(auxPassenger->apellido, 20, "\n◉Ingrese su nuevo apellido:",
				"\n◉Error,reingrese su apellido:(no se aceptan numeros ni simbolos)", 3);

				printf("\nSu cambio se ha realizado exitosamente\n");
			break;
			case 3:
				utn_getNumeroFlotante(&auxPassenger->precio, "\n◉Ingrese su nuevo precio:", "\n◉Error,reingrese su precio", 1, 10000, 3);

				printf("\nSu cambio se ha realizado exitosamente\n");
			break;
			case 4:
				utn_getNumero(&auxStatus,  "\n1►Aterrizado\n2►En Horario\n3►Demorado\n4►En Vuelo"
				"\n◉Ingrese su nuevo status:", "\n◉Error,reingrese su status", 1, 9, 3);
				Passenger_statusInt(auxStatus, auxPassenger->statusFlight);
				printf("\nSu cambio se ha realizado exitosamente\n");
			break;
			case 5:
				utn_getNumero(&auxFlyCode, "\n1►IB0800A\n2►MM0987B\n3►BA2491A\n4►BR3456J"
				"\n5►FR5678G\n6►HY4567D\n7►GU2345F\n8►TU6789B\n9►HY4567D\n◉Ingrese su nuevo fly code:", "\n◉Error,reingrese su fly code""", 1, 9, 3);
				Passenger_flightCodeInt(auxFlyCode,auxPassenger->codigoVuelo);
				printf("\nSu cambio se ha realizado exitosamente\n");
			break;
			case 6:
				utn_getNumero(&auxPassenger->tipoPasajero, "\n1►FirstClass\n2►ExecutiveClass\n3►EconomyClass"
				"\n◉Ingrese su nuevo type passenger:", "\n◉Error,reingrese su type passenger:", 1, 3, 3);

				printf("\n◉Su cambio se ha realizado exitosamente\n");
			break;
			case 7:
				printf("\n◉Has left..\n");
			break;
			}

		}while(opcion != 7);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/

/***************************************************************************************/
