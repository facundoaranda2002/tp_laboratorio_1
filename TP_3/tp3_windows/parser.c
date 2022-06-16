#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	int cant;
	char buffer[7][50];
	Passenger* pasajero=NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
		while(!feof(pFile))
		{
			cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
			if(cant==7)
			{
				pasajero=Passenger_newParametrosString(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
				if(pasajero!=NULL)
				{
					if(ll_add(pArrayListPassenger, pasajero)==0)
					{
						todoOk=1;
					}
					else
					{
						todoOk=0;
						break;
					}
				}
				else
				{
					todoOk=0;
					break;
				}
			}
		}

	}
    return todoOk;
}

int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	Passenger pasajeroEstatico;
	Passenger* pasajero=NULL;

	if(pFile!=NULL && pArrayListPassenger!=NULL)
	{
		while(!feof(pFile))
		{
			if(fread(&pasajeroEstatico, sizeof(Passenger), 1, pFile)==1)
			{
				pasajero=Passenger_newParametros(pasajeroEstatico.id, pasajeroEstatico.nombre, pasajeroEstatico.apellido, pasajeroEstatico.precio, pasajeroEstatico.codigoVuelo, pasajeroEstatico.tipoPasajero, pasajeroEstatico.estadoVuelo);
				if(pasajero!=NULL)
				{
					if(ll_add(pArrayListPassenger, pasajero)==0)
					{
						todoOk=1;
					}
					else
					{
						todoOk=0;
						break;
					}
				}
				else
				{
					todoOk=0;
					break;
				}
			}
		}

	}
	return todoOk;
}
