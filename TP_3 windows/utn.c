/*
 * utn.c
 *
 *  Created on: 7 jun 2022
 *      Author: Rodri
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esFlotante(char* cadena);
static int getFloat(float* pResultado);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena,int longitud);
static int getNombre(char* pResultado,int longitud);
static int esDescripcion(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);
static int getDni(char* pResultado, int longitud);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un maximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{

    int retorno=-1;
    char bufferString[50];

    if(	pResultado != NULL && getString(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString,sizeof(bufferString)))
    {
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
static int esNumerica(char* cadena, int len)
{
	int retorno = -1;
	int i;

	if(cadena != NULL && len > 0)
	{
		retorno = 1;

		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	do{
		printf("%s",mensaje);

		if(	getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}

		printf("%s",mensajeError);
		reintentos--;

	}while(reintentos>=0);

	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un numero flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
static int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++){
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita un numero flotante al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;

				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 && esNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);

			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] != ' '))
			{
				retorno = 0;

				break;
			}
		}
	}
	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);

		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud && bufferString[0] != '\0' && bufferString[0] != ' ')
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;

			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 && esDescripcion(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;

				break;
			}
		}
	}
	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{

	char bufferString[4096];
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);

			retorno = 0;

			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * \brief Obtiene un string valido como DNI
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDni(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 && esNumerica(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);

			retorno = 0;
		}
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Solicita un DNI al usuario, luego de verificarlo devuelve el resultado
/// @param pResultado pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @param longitud Es la longitud del array resultado
/// @param mensaje Es el mensaje a ser mostrado
/// @param mensajeError Es el mensaje de Error a ser mostrado
/// @param reintentos Cantidad de reintentos
/// @return Retorna 0 si se obtuvo el numero flotante y -1 si no
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;

		printf("%s",mensaje);

		if(getDni(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);

			retorno = 0;

			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
int validarNumero(char *numero)
{
    int retorno=1;
    int len;

    if(numero!=NULL)
    {
        len=strlen(numero);

        for(int i=0;i<len;i++)
        {
            if(!isdigit(numero[i]))
            {
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

    while(!validarNumero(numero))
    {
        printf(mensajeError);
        printf(mensaje);
        scanf("%s",numero);
    }

    retorno = atoi(numero);

    return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{
	int opcion;

	  printf("\n=============================================MENU==================================================");
	opcion = pedirEntero("\n1►Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)"
			"\n2►Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)"
			"\n3►Alta de pasajero"
			"\n4►Modificar datos de pasajero"
			"\n5►Baja de pasajero"
			"\n6►Listar pasajeros"
			"\n7►Ordenar pasajeros"
			"\n8►Guardar los datos de los pasajeros en el archivo data.csv (modo texto)"
			"\n9►Guardar los datos de los pasajeros en el archivo data.csv (modo binario)"
			"\n10►Salir"
			"\n◉Opcion:","\nಠ╭╮ಠ\nError, opcion no valida\n");
	  printf("===================================================================================================\n");

	  return opcion;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu_modificar()
{
	int opcion;
	 printf("\n=============================================MODIFICAR=============================================");
		opcion = pedirEntero("\n1►Modificar nombre"
				"\n2►Modificar apellido"
				"\n3►Modificar precio"
				"\n4►Modificar status flight"
				"\n5►Modificar fly code"
				"\n6►Modificar type passenger"
				"\n7►Salir"
				"\n◉Opcion:","\nಠ╭╮ಠ\nError, opcion no valida\n");
		  printf("===================================================================================================\n");
	return opcion;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu_ordenar()
{
	int opcion;
	 printf("\n=============================================ORDENAR===============================================");
		opcion = pedirEntero("\n1►Ordenar por nombre"
				"\n2►Ordenar por apellido"
				"\n3►Ordenar por ID"
				"\n4►Ordenar por status flight"
				"\n5►Salir"
				"\n◉Opcion:","\nಠ╭╮ಠ\nError, opcion no valida\n");
		  printf("===================================================================================================\n");
	return opcion;
}
//////////////////////////////////////////////////////////////////////////////////////
void mensajeAviso()
{
	printf("\n◉Ordenando a los pasajeros por su status flight\n");
	printf("\n◉Cargando......\n◉(esto puede demorar unos segundos)\n");
}
//////////////////////////////////////////////////////////////////////////////////////
void mensajeAviso2()
{
	printf("\n◉Ordenando a los pasajeros por ID del mas chico al mas grande\n");
	printf("\n◉Cargando......\n◉(esto puede demorar unos segundos)\n");
}
//////////////////////////////////////////////////////////////////////////////////////
void mensajeAviso3()
{
	printf("\n◉Ordenando a los pasajeros por apellido de la A a la Z\n");
	printf("\n◉Cargando......\n◉(esto puede demorar unos segundos)\n");
}
//////////////////////////////////////////////////////////////////////////////////////
void mensajeAviso4()
{
	printf("\n◉Ordenando a los pasajeros por nombre de la A a la Z\n");
	printf("\n◉Cargando......\n◉(esto puede demorar unos segundos)\n");
}
