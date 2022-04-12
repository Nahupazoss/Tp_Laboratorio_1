/*
 * cuentas.c
 *
 *  Created on: 10 abr 2022
 *      Author: Rodri
 */

#include <stdio.h>

float cuentas(int numeroUno,float numeroDos,char operacion)
{
	float resultado;

	resultado = 0;

	if(operacion == '*')
	{
		resultado = (float)numeroUno * numeroDos;
	}
	else
	{
		if(operacion == '+')
		{
			resultado = (float)numeroUno + numeroDos;
		}
		else
		{
			if(operacion == '-')
			{
				resultado = (float)numeroUno - numeroDos;
			}
			else
			{
				if(operacion == '/' && numeroDos != 0)
						{
							resultado = (float)numeroUno / numeroDos;
						}
						else
						{
							printf("Error,diviste por 0\n");
						}
			}

		}
	}

	return resultado;
}

