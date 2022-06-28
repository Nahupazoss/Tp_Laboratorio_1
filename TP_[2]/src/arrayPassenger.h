/*
 * ArrayPassenger.h
 *
 *  Created on: 19 abr 2022
 *      Author: Rodri
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
	int idFlyCode;
	char descripcion[10];
}typedef eFlyCode;

struct
{
	int idStatusFlight;
	char descripcion[10];
}typedef eStatusFlight;

struct
{
	int idTypePassenger;
	char descripcion[10];
}typedef eTypePassenger;

struct
{
	int id;
	char name[51];
	char lastname[51];
	float price;
	int idCode;
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef ePassenger;


void hardCode(eFlyCode code[],int tamanio);
//=======================================================================
/**
 * inicializa todos los datos de ePassenger en 0
 * @param listaPasajeros declaracion del main que se pasa a ePassanger
 * @param tamanio los 2000 espacios de la lista
 */
void inicializarVector(ePassenger listaPasajeros [],int tamanio);
//=======================================================================
/**
 *muestro todos los pasajeros ingresados en la lista
 * @param listaPsajeros declaracion del main que se pasa a ePassanger
 * @param tamanio los 2000 espacios de la lista
 */
void mostrarPasajeros(ePassenger listaPasajeros [],int tamanio,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3);
//=======================================================================
/**
 *busca en donde se encuentra un espacio libre y si no se encuentra se muestra mensaje de lista llena
 * @param listaPasajeros declaracion del main que se pasa a ePassanger
 * @param tamanio los 2000 espacios de la lista
 * @return si ese espacio esta ocupado(-1)
 */
int buscarLibre (ePassenger listaPasajeros [],int tamanio);
//=======================================================================
/**
 *si se ingresa algo a la lista se cuenta y se ocupa un espacio de esa lista
 * @param listaPasajeros delcaracion del main que se pasa a ePassanger
 * @param tamanio los 200 espacios de la lista
 * @param contador incrementa el id de 1 a 2000
 */
void altaPasajero(ePassenger listaPasajeros[],int tamanio , eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3,int contador);
//=======================================================================
/**
 *muestro todos los printf para pedir los datos (nombre-apellido-precio-status-codigo-type)
 * @param listaPasajeros delcaracion del main que se pasa a ePassanger
 * @param tamanio los 200 espacios de la lista
 * @param indice para saber que se llenaron los datos pedidos
 */
void pedirDatos(ePassenger listaPasajeros[],int tamanio,int indice,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3,int contador);
//=======================================================================
/**
 *si se cumplen las condiciones se borra un pasajero de la lista y si no se cumple muestra mensaje
 * @param listaPasajeros
 * @param tamanio
 * @return
 */
int darDeBaja(ePassenger listaPasajeros [],int tamanio,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3);
//=======================================================================
/**
 *	funcion la cual pide el id,verifica que ese id exista y este activo y luego se hace la modificiacion de cualquiera de los datos
 * @param listaPasajeros
 * @param tamanio
 * @param opcionModificar
 * @return
 */
int modificarPasajeros(ePassenger listaPasajeros [],int tamanio,eTypePassenger types [],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3);
//=======================================================================
/**
 *	listado para elegir que modificar
 * @param listaPasajeros
 * @param tamanio
 * @param i
 */
void listaModificarePassenger (ePassenger listaPasajeros[],int tamanio,int i,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3);
//=======================================================================
/**
 *	ordena x codigo mediante el burbujeo
 * @param listaPasajeros
 * @param tamanio
 * @return
 */
int ordenarCodigo(ePassenger listaPasajeros [], int tamanio);
//=======================================================================
/**
 *	ordenamiento x burbujeo de a a la z por apellido
 * @param listaPasajeros
 * @param tamanio
 * @return
 */
int ordenarApellido(ePassenger listaPasajeros [], int tamanio);
//=======================================================================
/**
 * listado el cual ofrece distintas opciones
 * @param pasajero
 * @param tamanio
 * @param types
 * @param status
 * @param tamanio2
 * @param code
 * @param tamanio3
 * @param contador
 */
void opcionesLista(ePassenger pasajero[],int tamanio,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3,int contador);
//=======================================================================
/**
 * hardcodeo del status
 * @param status
 * @param tamanio
 */
void hardcodeStatus(eStatusFlight status[],int tamanio);
//=======================================================================
/**
 * acumula todos los precios para sumarlos y asi sacar el precio total
 * @param pasajero
 * @param tamanio
 * @return
 */
int totalPrecios(ePassenger pasajero[],int tamanio);
//=======================================================================
/**
 * saca el promedio dividiendo el precio total con todos los pasajeros
 * @param pasajero
 * @param tamanio
 * @param cantidad
 * @return
 */
float preciosPromedio(ePassenger pasajero [],int tamanio, int cantidad);
//=======================================================================
/**
 * muestra la cantidad de pasajeros que tengan un precio superior al promedio
 * @param pasajero
 * @param tamanio
 * @param cantidad
 * @return
 */
float promedioSuperior(ePassenger pasajero [],int tamanio, int cantidad);
//=======================================================================
/**
 * hardcodeo de pasajeros
 * @param pasajero
 * @param tamanio
 * @param contador
 */
void hardcodePassenger(ePassenger pasajero[],int tamanio,int contador);
//=======================================================================
/**
 * muestra todos los datos de precio total, promedio y promedio superior
 * @param totalPrice
 * @param averagePrice
 * @param mostAverage
 */
void extraInformation(int totalPrice,float averagePrice,float mostAverage);
//=======================================================================
/**
 * hardcodeo de type passenger
 * @param types
 * @param tamanio
 */
void hardCodeType(eTypePassenger types[],int tamanio);
//=======================================================================
/**
 * funcion la cual muestra unicamente a los pasajeros los cuales tengan un estado de vuelo activo
 * @param pasajero
 * @param tamanio
 * @param types
 * @param status
 * @param tamanio2
 * @param code
 * @param tamanio3
 */
void mostrarActivos(ePassenger pasajero[],int tamanio , eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3);
//=======================================================================
/**
 *
 * @param pasajero
 * @param tamanio
 * @param types
 * @param status
 * @param tamanio2
 * @param code
 * @param tamanio3
 */
void mostrarPasajeros2(ePassenger pasajero[],int tamanio , eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3);
//=======================================================================
/**
 *	lista fly code
 * @param types
 * @param tamanio
 */
void list_CodeType(eTypePassenger types[],int tamanio);
//=======================================================================
/**
 * lista status flight
 * @param status
 * @param tamanio
 */
void list_Status(eStatusFlight status[],int tamanio);
//=======================================================================
/**
 *	lista flycode
 * @param code
 * @param tamanio
 */
void list_FlyCode(eFlyCode code[],int tamanio);
//=======================================================================
#endif /* ARRAYPASSENGER_H_ */
