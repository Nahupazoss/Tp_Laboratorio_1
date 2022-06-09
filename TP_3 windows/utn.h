/*
 * utn.h
 *
 *  Created on: 7 jun 2022
 *      Author: Rodri
 */



#ifndef UTN_H_
#define UTN_H_

/********************************************/
//
//Funciones de validacion utn
//
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/********************************************/
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
/********************************************/
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
/********************************************/
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
/********************************************/
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
/********************************************/
//
//Funciones mias de validaciones//
//
int validarNumero(char *numero);
/********************************************/
int pedirEntero(char *mensaje,char *mensajeError);
/********************************************/
int menu();
/********************************************/
int menu_modificar();
/********************************************/
int menu_ordenar();
/********************************************/
void mensajeAviso();
/********************************************/
void mensajeAviso2();
/********************************************/
void mensajeAviso3();
/********************************************/
void mensajeAviso4();
/********************************************/

#endif /* UTN_H_ */
