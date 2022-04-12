/*
 * validaciones.c
 *
 *  Created on: 5 abr 2022
 *      Author: Rodri
 */
#include <stdio.h>

void mostrarDatos(int precioLatam,float tarjetaDeDebitoLatam,float tarjetaDeCreditoLatam,float bitcoinLatam,float precioUnitarioLatam,int precioAerolineas,float tarjetaDeDebitoAerolineas,float tarjetaDeCreditoAerolineas,float bitcoinAerolineas,float precioUnitarioAerolineas,int diferenciaDePrecios)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n===================================================\n");
	printf("|LATAM DATOS");
	printf("\n*El precio con tarjeta de debito es: $%.2f",tarjetaDeDebitoLatam);
	printf("\n*El precio con tarjeta de credito es: $%.2f",tarjetaDeCreditoLatam);
	printf("\n*El precio pagando con bitcion es: $%f",bitcoinLatam);
	printf("\n*El precio unitario es: $%.2f\n",precioUnitarioLatam);
	printf("\n|AEROLINEA DATOS|");
	printf("\n*El precio con tarjeta de debito es: $%.2f",tarjetaDeDebitoAerolineas);
	printf("\n*El precio con tarjeta de credito es: $%.2f",tarjetaDeCreditoAerolineas);
	printf("\n*El precio pagando con bitcion es: $%f",bitcoinAerolineas);
	printf("\n*El precio unitario es: $%.2f",precioUnitarioAerolineas);
	printf("\n\n*La diferencia de precio es: $%d\n",diferenciaDePrecios);
	printf("===================================================\n");
}

int ingresarDatos(char * mensaje ,int minimo ,int maximo)
{
	int numero;

	printf("%s",mensaje);
	scanf("%d",&numero);

	while(numero < minimo  || numero > maximo)
	{
		printf("Error,es un numero muy bajo:\n");
		scanf("%d",&numero);
	}



	return numero;
}
