/*
 * ArrayPassenger.c
 *
 *  Created on: 19 abr 2022
 *      Author: Rodri
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"
#include "arrayPassenger.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int totalPrecios(ePassenger pasajero[],int tamanio)
{
	int retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
	{
		if(pasajero[i].isEmpty == 1)
		{
		retorno=retorno+pasajero[i].price;
		}
	}
	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float preciosPromedio(ePassenger pasajero [],int tamanio, int cantidad)
{
	float retorno;
	float can;

	can = totalPrecios(pasajero, tamanio);

	retorno = can/cantidad;

	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float promedioSuperior(ePassenger pasajero [],int tamanio, int cantidad)
{
	float retorno=0;
	float promedio;
	int i;

	promedio = preciosPromedio(pasajero, tamanio, cantidad);

	for(i=0;i<tamanio;i++)
	{
		if(pasajero[i].isEmpty == 1)
		{
			if (pasajero[i].price > promedio)
			{
				retorno++;
			}
		}
	}
	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hardcodePassenger(ePassenger pasajero[],int tamanio,int contador)
{
	int id[]={1,2,3,4,5};
	char names[][51]={"Nahuel","Manuela","Carlos","Agustin","Mariano"};
	char lastNamePassenger[][51]={"Pazos","Lagos","Camusso","Scali","Tapari"};
	float price[]={200,200,100,50,500};
	int idCode[]={1,2,3,4,5};
	int typePassenger[]={2,2,3,3,1};
	int statusFlight[]={2,2,3,3,1};
	int i=0;

	for(i=0;i<tamanio;i++)
		{
			pasajero[i].id= id[i];
			strcpy(pasajero[i].name, names[i]);
			strcpy(pasajero[i].lastname,lastNamePassenger[i]);
			pasajero[i].price = price[i];
			pasajero[i].idCode = idCode[i];
			pasajero[i].typePassenger = typePassenger[i];
			pasajero[i].statusFlight = statusFlight[i];
			pasajero[i].isEmpty = 1;
		}
	ordenarApellido(pasajero, tamanio);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hardCodeType(eTypePassenger types[],int tamanio)
{
	int id[]={1,2,3};
	char descripcion[][15]={"Economic","Tourist","Premium"};
	int i=0;

	for(i=0;i<tamanio;i++)
	{
		types[i].idTypePassenger = id[i];
		strcpy(types[i].descripcion, descripcion[i]);
	}
}

void list_CodeType(eTypePassenger types[],int tamanio)
{
	int i;

	hardCodeType(types, tamanio);
	printf("\n===========================================================================");
	printf("\nCodigo \tType Passenger\n");
	for(i = 0;i<tamanio;i++)
	{
		printf("\n %d\t  %s\n",types[i].idTypePassenger,types[i].descripcion);
	}
	printf("\n===========================================================================");
	printf("\n");

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hardcodeStatus(eStatusFlight status[],int tamanio)
{
	int id[]={1,2,3};
	char descripcion[][10]={"Null","Active","Waiting"};
	int i=0;

	for(i=0;i<tamanio;i++)
	{
		status[i].idStatusFlight = id[i];
		strcpy(status[i].descripcion,descripcion[i]);
	}

}

void list_Status(eStatusFlight status[],int tamanio)
{
	int i;

	hardcodeStatus(status, tamanio);
	printf("\n===========================================================================");
	printf("\nCodigo \tStatus Flight\n");
	for(i = 0;i<tamanio;i++)
	{
		printf("\n %d\t  %s\n",status[i].idStatusFlight,status[i].descripcion);
	}
	printf("\n===========================================================================");
	printf("\n");

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hardCode(eFlyCode code[],int tamanio)
{
	int id[]={1,2,3,4,5};
	char descripcion[][10]={"XHMT-2466","XHMT-2999","XHMT-4236","XHMT-2555","XHMT-6666"};
	int i=0;

	for(i=0;i<tamanio;i++)
	{
		code[i].idFlyCode = id[i];
		strcpy(code[i].descripcion,descripcion[i]);
	}

}

void list_FlyCode(eFlyCode code[],int tamanio)
{
	int i;

	hardCode(code, tamanio);
	printf("\n===========================================================================");
	printf("\nCodigo \tFly Code\n");
	for(i = 0;i<tamanio;i++)
	{
		printf("\n %d\t  %s\n",code[i].idFlyCode,code[i].descripcion);
	}
	printf("\n===========================================================================");
	printf("\n");

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void extraInformation(int totalPrice,float averagePrice,float mostAverage)
{
	printf("\n===================================================================================================");
	printf("\n⇓⇓⇓⇓⇓⇓ Extra information ⇓⇓⇓⇓⇓⇓	");
	printf("\n===================================================================================================");
	printf("\n◉The total price of all flights is: $%d\n",totalPrice);
	printf("◉The averege price of all flights is: $%.2f	\n",averagePrice);
	printf("◉Passengers who exceed the average price is:%2.f",mostAverage);
	printf("\n===================================================================================================\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializarVector(ePassenger listaPasajeros [],int tamanio)
{
	int i;
	if(listaPasajeros != NULL)
	{
		for(i=0;i<tamanio;i++)
		{
			listaPasajeros[i].isEmpty = 0;
			listaPasajeros[i].id = 0;
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int buscarLibre(ePassenger listaPasajeros [],int tamanio)
{
	int index = -1;
	int i;

	for(i=0;i<tamanio;i++)//1
	{
		if(listaPasajeros[i].isEmpty == 0)
		{
			index = i;//1
			break;
		}
	}
	return index;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pedirDatos(ePassenger listaPasajeros[],int tamanio,int indice,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3,int contador)
{
    printf("\n===========================================COMPLETE=================================================\n");

    	pedirChar("◉Enter your name:", "Solo se permiten letras", listaPasajeros[indice].name);

		pedirChar("◉Enter your lats name:", "Solo se permiten letras", listaPasajeros[indice].lastname);

		listaPasajeros[indice].price = pedirNumFlotante("◉Enter price of your flight:", "Solo se permiten numeros mayores a 0", 1, 100000);

		list_FlyCode(code, tamanio3);
		listaPasajeros[indice].idCode = pedirNumeroInt("◉Enter your code of your flight:(1-2-3-4-5):", "Solo se permiten numeros del 1 al 5", 1, 5);

		list_CodeType(types, tamanio2);
		listaPasajeros[indice].typePassenger = pedirNumeroInt("◉Enter your type passenger:(1-2-3):", "Solo se permiten numeros del 1 al 3", 1, 3);

		list_Status(status, tamanio2);
		listaPasajeros[indice].statusFlight = pedirNumeroInt("◉Enter status flight:(1-2-3):", "Solo se permiten numeros del 1 al 3", 1, 3);

		printf("\n===================================================================================================");

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void altaPasajero(ePassenger listaPasajeros[],int tamanio, eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3,int contador)
{
	int indice;

	indice = buscarLibre(listaPasajeros,tamanio);

	if(indice != -1)
	{
		pedirDatos(listaPasajeros,tamanio,indice,types,status,tamanio2,code,tamanio3,contador);

		listaPasajeros[indice].isEmpty = 1;
		listaPasajeros[indice].id = contador;
	}
	else
	{
		printf("Full list!!!");
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void listaModificarePassenger(ePassenger listaPasajeros[],int tamanio,int i,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3)
{
	int opcionModificar;

	do
	{
		opcionModificar = subMenu();
		switch(opcionModificar)
		{
		case 1:
			pedirChar("◉NEW NAME:", "Solo se permiten letras", listaPasajeros[i].name);
		break;
		case 2:
			pedirChar("◉NEW LAST NAME:", "Solo se permiten letras", listaPasajeros[i].lastname);
		break;
		case 3:
			listaPasajeros[i].price = pedirNumFlotante("◉NEW PRICE:", "Solo se permiten numeros", 1, 100000);
		break;
		case 4:
			list_FlyCode(code, tamanio3);
			listaPasajeros[i].idCode = pedirNumeroInt("\n◉NEW FLY CODE:(options:1-2-3-4-5)", "Solo se permiten numeros del 1 al 5", 1, 5);
		break;
		case 5:
			list_CodeType(types, tamanio2);
			listaPasajeros[i].typePassenger = pedirNumeroInt("\n◉NEW TYPE PASSENGER:", "Solo se permiten numeros del 1 al 3", 1, 3);
		break;
		case 6:
			list_Status(status, tamanio2);
			listaPasajeros[i].statusFlight = pedirNumeroInt("\n◉NEW STATUS FLIGHT:", "Solo se permiten numeros del 1 al 3", 1, 3);
		break;
		case 7:
			printf("\nLeave...\n");
		break;
		default:
			printf("\nWrong option...");
		break;
		}
	}while(opcionModificar != 7);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void opcionesLista(ePassenger pasajero[],int tamanio,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3,int contador)
{
	int opcionListar;
	int totalPrice;
	float averagePrice;
	float mostAverage;

	do
	{
		opcionListar = subMenuInformar();

		switch(opcionListar)
		{
		case 1:
			ordenarApellido(pasajero, tamanio);
			mostrarPasajeros(pasajero,tamanio,types,status,tamanio2,code,tamanio3);
		break;
		case 2:
			totalPrice = totalPrecios(pasajero, tamanio);
			averagePrice = preciosPromedio(pasajero, tamanio, contador);
			mostAverage = promedioSuperior(pasajero, tamanio, contador);
			extraInformation(totalPrice, averagePrice, mostAverage);
		break;
		case 3:
			mostrarActivos(pasajero, tamanio, types, status, tamanio2, code, tamanio3);
		break;
		case 4:
			printf("\nLeave....");
		break;
		default:
			printf("\nWrong option..");
		break;
		}
	}while(opcionListar!=4);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarPasajeros2(ePassenger pasajero[],int tamanio , eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3)
{
	int i;
	printf("\n=============================================LIST==================================================");
	printf("\n◉Name\t◉LastName\t◉ID");
	printf("\n===================================================================================================");
	for(i=0;i<tamanio;i++)
	{
		if(pasajero[i].statusFlight !=0 && pasajero[i].isEmpty==1)
		{
			printf("\n%s\t%s\t	%d",pasajero[i].name,pasajero[i].lastname,pasajero[i].id);
		}
	}
	printf("\n===================================================================================================");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int modificarPasajeros(ePassenger listaPasajeros [],int tamanio,eTypePassenger types [],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3)
{
	int i;
	int auxId;
	int retorno = -1;

	printf("\n===================================================================================================");
	mostrarPasajeros2(listaPasajeros, tamanio, types, status, tamanio2, code, tamanio3);
	printf("\n◉Go to modify id:");
	scanf("%d",&auxId);

	for(i=0; i<tamanio; i++)
	{
		if(listaPasajeros[i].isEmpty == 1 && auxId == listaPasajeros[i].id )
		{
			retorno = 1;
			listaModificarePassenger(listaPasajeros, tamanio,i,types,status,tamanio2,code,tamanio3);
		}
	}
	printf("\n===================================================================================================");
	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarPasajeros(ePassenger listaPasajeros [],int tamanio,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3)
{
	int i,j,k,l;
    printf("\n=============================================LIST==================================================\n");
	printf("NAME\tLAST NAME\t  FLIGTH PRICE\t   FLY CODE  \t	TYPEPASSENGER\tSTATUSFLIGHT\tID");
	printf("\n===================================================================================================");
	for(i=0;i<tamanio;i++)
	{
		if(listaPasajeros[i].isEmpty == 1)
		{
			for(j=0;j<tamanio2;j++)
			{
				if(listaPasajeros[i].typePassenger == types[j].idTypePassenger)
				{
					for(k=0;k<tamanio2;k++)
					{
						if(listaPasajeros[i].statusFlight == status[k].idStatusFlight)
						{
							for(l=0;l<tamanio3;l++)
							{
								if(listaPasajeros[i].idCode == code[l].idFlyCode)
								{
									printf("\n%s\t%s\t            $%.2f\t   %s\t          %s\t       %s\t %d ",listaPasajeros[i].name,listaPasajeros[i].lastname,listaPasajeros[i].price,
											code[l].descripcion,types[j].descripcion,status[k].descripcion,listaPasajeros[i].id);
								}
							}

						}
					}
				}
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*int ordenarCodigo(ePassenger listaPasajeros [], int tamanio)
{
	int retorno = -1;
	int i;
	int j;
	ePassenger aux;

	for(i=0;i<tamanio-1;i++)
	{
		if(listaPasajeros[i].isEmpty == 1)
		{
			for(j=i+1;j<tamanio;j++)
			{
				if(strcmp(listaPasajeros[i].flycode,listaPasajeros[i].flycode)>0)
				{
					aux = listaPasajeros[i];
					listaPasajeros[i] = listaPasajeros[j];
					listaPasajeros[j] = aux;
					retorno = 1;
				}
			}
		}
	}
	return retorno;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ordenarApellido(ePassenger listaPasajeros [], int tamanio)
{
	int retorno = -1;
	int i;
	int j;
	ePassenger aux;

	for(i=0;i<tamanio-1;i++)
	{
		if(listaPasajeros[i].isEmpty == 1)
		{
			for(j=i+1;j<tamanio;j++)
			{
				if(strcmp(listaPasajeros[i].lastname,listaPasajeros[j].lastname) > 0)
				{
					aux = listaPasajeros[i];
					listaPasajeros[i] = listaPasajeros[j];
					listaPasajeros[j] = aux;
					retorno = 1;

					if(strcmp(listaPasajeros[i].lastname,listaPasajeros[j].lastname) == 0)
					{
						if(listaPasajeros[i].lastname > listaPasajeros[i].lastname)
						{
							aux = listaPasajeros[i];
							listaPasajeros[i] = listaPasajeros[j];
							listaPasajeros[j] = aux;
						}
					}
				}
			}
		}
	}
	return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarActivos(ePassenger pasajero[],int tamanio , eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3)
{
	int i;
	printf("\n=====================================Passenger Status Active=======================================");
	printf("\n◉Name\t◉LastName\t◉ID");
	printf("\n===================================================================================================");
	for(i=0;i<tamanio;i++)
	{
		if(pasajero[i].statusFlight == 2 && pasajero[i].isEmpty == 1)
		{
			printf("\n%s\t%s\t	%d",pasajero[i].name,pasajero[i].lastname,pasajero[i].id);
		}
	}

	printf("\n===================================================================================================");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int darDeBaja(ePassenger listaPasajeros [],int tamanio,eTypePassenger types[],eStatusFlight status[],int tamanio2,eFlyCode code[],int tamanio3)
{
	int auxId;
	int i;
	int retorno;

	retorno = 1;

	printf("\n===================================================================================================");
	mostrarPasajeros2(listaPasajeros, tamanio, types, status, tamanio2, code, tamanio3);
	printf("\n◉ID to unsubscribe:");//lamar funcion
	scanf("%d",&auxId);

		for(i=0 ; i < tamanio ; i++)
		{
			if(auxId == listaPasajeros[i].id && listaPasajeros[i].isEmpty == 1)
			{
				retorno = 0;
				listaPasajeros[i].isEmpty = -1;
				printf("\nsuccessfully unsubscribed");
			}
		}
		printf("\n===================================================================================================");
		return retorno;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
