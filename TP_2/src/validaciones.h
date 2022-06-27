/*
 * validaciones.h
 *
 *  Created on: 26 abr 2022
 *      Author: Rodri
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 *	esta funcion valida que lo que se ingreso cumpla los parametros indicados
 * @param n
 * @return
 */
int validarNumero(char numero[]);
//=======================================================================
/**
 *	esta funcion sirve para crear menus o submenus y se utiliza la funcion de validacion para que no se ingresen cosas no deseadas
 * @param mensaje mensaje el cual se va a mostrar si se cumplen las condiciones
 * @param mensajeError mensaje de error en caso de que no se cumplan las condiciones
 * @return mensaje o mensaje de error
 */
int pedirEntero(char mensaje[],char mensajeError[]);
//=======================================================================
/**
 * menu principal
 * @return
 */
int menu();
//=======================================================================
/**
 * submenu para modificar
 * @return
 */
int subMenu();
//=======================================================================
/**
 * verifica que sean caracteres
 * @param palabra
 * @return
 */
int validarChar(char palabra[]);//crear funcion
//=======================================================================
/**
 * se utiliza para pedir caracteres y si no es caracter muestra mensaje de error,
 * dentro de esta funcion se utiliza el validarchar
 * @param mensaje
 * @param mensajeError
 * @param palabra
 * @return
 */
int pedirChar(char mensaje[],char mensajeError[],char* palabra);
//=======================================================================
/**
 * menu de informar
 * @return
 */
int subMenuInformar();
//=======================================================================
/**
 * pide un numero flotante y que este dentro de los rangos minimo y maximo
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @return
 */
float pedirNumFlotante(char mensaje[],char mensajeError[], int min, int max);//crear funcion
//=======================================================================
/**
 * pide un numero intero que este dentro de los rangos minimo y maximo
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @return
 */
int pedirNumeroInt(char mensaje[],char mensajeError[],int min,int max);
#endif /* VALIDACIONES_H_ */
