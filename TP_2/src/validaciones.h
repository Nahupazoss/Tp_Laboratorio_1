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
 * submenu para util
 * @return
 */
int subMenu();
//=======================================================================

int subMenuInformar();
#endif /* VALIDACIONES_H_ */
