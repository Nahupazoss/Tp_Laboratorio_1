/*
 * validaciones.h
 *
 *  Created on: 5 abr 2022
 *      Author: Rodri
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * funcion la cual muestra todos los resultados (printf)
 * @param entero precio aerolineas
 * @param float
 * @param float
 * @param float
 * @param float
 * @param entero precio latam
 * @param float
 * @param float
 * @param float
 * @param float
 * @param entero
 */
void mostrarDatos(int,float,float,float,float,int,float,float,float,float,int);

/**
 *Pide los datos de ingreso y los valida para que esten dentro del rango indicado
 * @param char mensaje
 * @param entero precio
 * @param entero kilometros
 * @return un mensaje especifico
 */
int ingresarDatos(char * mensaje,int,int);
#endif /* VALIDACIONES_H_ */
