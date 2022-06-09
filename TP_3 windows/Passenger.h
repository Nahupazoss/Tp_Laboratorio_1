/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */
//todo lo relaciona al pasajero
#ifndef PASSENGER_H_
#define PASSENGER_H_
/********************************************/
typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char statusFlight[20];
	char codigoVuelo[7];
}Passenger;
/**************************************************************/
Passenger* Passenger_new();
/**************************************************************/
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* tipoPasajeroStr,char* statusFlightStr,char* codigoVueloStr);
/**************************************************************/
void Passenger_delete(Passenger* this);
/**************************************************************/
int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);
/**************************************************************/
int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);
/**************************************************************/
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);
/**************************************************************/
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
/**************************************************************/
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);
/**************************************************************/
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);
/**************************************************************/
int Passenger_setStatusFlight(Passenger* this,char* statusFlight);
int Passenger_getStatusFlight(Passenger* this,char* statusFlight);
/**************************************************************/
//AGREGO FUNCIONES
/**************************************************************/
void Passenger_mostrar(Passenger* this);
/**************************************************************/
int Passenger_TipoPasajeroStr(char* tipoStr);
int Passenger_TipoPasajeroInt(int tipo,char* tipoStr);
/**************************************************************/
int Passenger_flightCodeInt(int flightCode,char* flightcodeStr);
int Passenger_flightCodeStr(char* flyCodeStr);
/**************************************************************/
int Passenger_statusInt(int status,char* statusStr);
int Passenger_statusFlightStr(char* statusStr);
/**************************************************************/
int Passenger_add(LinkedList* this);
/**************************************************************/
int Passenger_modificar(Passenger* auxPassenger);
/**************************************************************/
int Passenger_encontrarPorId(LinkedList* pArrayListPassenger, int buscadorId);
/**************************************************************/
int Passenger_OrdenaNombre(void* pPassengerUno , void* pPassengerDos);
/**************************************************************/
int Passenger_OrdenaApellido(void* pPassengerUno , void* pPassengerDos);
/**************************************************************/
int Passenger_OrdenaId(void* pPassengerUno , void* pPassengerDos);
/**************************************************************/
int Passenger_OrdenarStatus(void* pPassengerUno, void* pPassengerDos);
/********************************************/
#endif /* PASSENGER_H_ */
