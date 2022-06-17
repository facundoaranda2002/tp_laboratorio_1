#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "funcionesExtra.h"
#include "Controller.h"



int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	FILE* f=fopen(path, "r");
	if(f!=NULL && pArrayListPassenger!=NULL)
	{
		if(parser_PassengerFromText(f, pArrayListPassenger))
		{
			todoOk=1;
		}
		fclose(f);
	}
    return todoOk;
}

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	if(pArrayListPassenger!=NULL)
	{
		int x=ll_len(pArrayListPassenger);
		if(x>0)
		{
			if(mostrarPasajeros(pArrayListPassenger))
			{
				todoOk=1;
			}
		}
		else
		{
			printf("No hay datos cargados en la lista\n");
		}
	}
    return todoOk;
}





