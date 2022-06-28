/*
 ============================================================================
 Name        : TRABAJO.c
 Author      : NAHUEL PAZOS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 DIVISION 1K.
 TRABAJO PRACTICO 1.
 NAHUEL RODRIGO PAZOS.
 */
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "cuentas.h"

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int kilometros;

	int precioLatam;
	float tarjetaDeDebitoLatam;
	float tarjetaDeCreditoLatam;
	float bitcoinLatam;
	float precioUnitarioLatam;

	int precioAerolineas;
	float tarjetaDeDebitoAerolineas;
	float tarjetaDeCreditoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioAerolineas;

	int banderaCalculos;
	int diferenciaDePrecios;

	float valorBitcoin;

	valorBitcoin = 4606954.55;
	banderaCalculos = 0;


	do//cuerpo del menu que se ejecuta si o si una vez.
	{
		printf("\n1-Ingresar Kilometros\n2-Ingresar Precio de Vuelos: \n3-Calcular todos los costos \n4-Informar Resultados \n5-Carga forzada de datos\n6-Salir\n\nOpcion:");
		scanf("%d",&opcion);

		switch(opcion)         //menu
		{
			case 1://pido el ingreso de los km
			kilometros = ingresarDatos("\nIngrese kilometros: ",2,2000000000);
			break;

			case 2://pido el ingreso del valor de ambas agencias
			precioAerolineas = ingresarDatos("\nIngrese precio de empres Aerolineas:",2,2000000000);
			precioLatam = ingresarDatos("\nIngrese precio de empresa Latam:",2,2000000000);
			break;

			case 3://cuentas de los ejercicios pedidos
			//TARJETAS DE CREDITO Y DEBITO AEROLINEAS
			tarjetaDeDebitoAerolineas = cuentas(precioAerolineas,0.90,'*');//debito
			tarjetaDeCreditoAerolineas = cuentas(precioAerolineas,1.25,'*');//credito
			bitcoinAerolineas = cuentas(precioAerolineas,valorBitcoin,'/');//bitcoin
			precioUnitarioAerolineas = cuentas(precioAerolineas,kilometros,'/');//precio x km
			//TARJETAS DE CREDITO Y DEBITO LATAM
			tarjetaDeDebitoLatam = cuentas(precioLatam,0.90,'*');//debito
			tarjetaDeCreditoLatam = cuentas(precioLatam,1.25,'*');//credito
			bitcoinLatam = cuentas(precioLatam,valorBitcoin,'/');//bitcoin
			precioUnitarioLatam = cuentas(precioLatam,kilometros,'/');//precio x km
			diferenciaDePrecios = cuentas(precioLatam,precioAerolineas,'-');//diferencia de $ entre agencias
			banderaCalculos = 1;
			break;

			case 4://muestro los resultados de ambas agencias
			if(banderaCalculos == 1)
			{
				mostrarDatos(precioLatam, tarjetaDeDebitoLatam, tarjetaDeCreditoLatam, bitcoinLatam, precioUnitarioLatam, precioAerolineas, tarjetaDeDebitoAerolineas, tarjetaDeCreditoAerolineas, bitcoinAerolineas, precioUnitarioAerolineas, diferenciaDePrecios);
			}
			else
			{
				if(banderaCalculos == 0)
				{
					printf("Primero calcular los datos ingresados (opcion 3)");
				}
			}

			break;

			case 5://carga forzada de datos
			kilometros = 7090;
			precioAerolineas = 162965;
			precioLatam = 159339;
			break;

			case 6://sale del menu
			printf("\nHas salido");
			break;

			default://error si no se ingresa uno de los numeros del menu
			printf("\nError, no ingreso una opcion correcta\n");
			break;
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
