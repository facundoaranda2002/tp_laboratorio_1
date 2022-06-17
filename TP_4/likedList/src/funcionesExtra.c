#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesExtra.h"
#include "Passenger.h"


int cargarIdTipoPasajero(int* id, char* desc)
{
    int todoOk=0;

    if(desc!=NULL && id!=NULL)
    {

        if(strcmp("FirstClass", desc)==0)
        {
        	*id=1;
        }
        else if(strcmp("ExecutiveClass", desc)==0)
        {
        	*id=2;
        }
        else if(strcmp("EconomyClass", desc)==0)
		{
			*id=3;
		}
        else
		{
			*id=0;
		}
        todoOk=1;
    }

    return todoOk;
}

int cargarIdEstadoVuelo(int* id, char* desc)
{
    int todoOk=0;

    if(desc!=NULL && id!=NULL)
    {

        if(strcmp("Aterrizado", desc)==0)
        {
        	*id=1;
        }
        else if(strcmp("En Horario", desc)==0)
        {
        	*id=2;
        }
        else if(strcmp("En Vuelo", desc)==0)
		{
			*id=3;
		}
        else if(strcmp("Demorado", desc)==0)
		{
			*id=4;
		}
        else
        {
        	*id=0;
        }
        todoOk=1;
    }

    return todoOk;
}

int cargarDescTipoPasajero(Passenger* p, char* desc)
{
    int todoOk=0;
    int x;

    if(desc!=NULL && p!=NULL)
    {
    	if(Passenger_getTipoPasajero(p, &x))
    	{
    		switch(x)
			{
			case 1:
				strcpy(desc, "FirstClass");
				break;
			case 2:
				strcpy(desc, "ExecutiveClass");
				break;
			case 3:
				strcpy(desc, "EconomyClass");
				break;
			}
			todoOk=1;
    	}
    }

    return todoOk;
}

int cargarDescEstadoVuelo(Passenger* p, char* desc)
{
    int todoOk=0;
    int x;

    if(desc!=NULL && p!=NULL)
    {
    	if(Passenger_getEstadoVuelo(p, &x))
    	{
    		switch(x)
    		{
    		case 1:
    			strcpy(desc, "Aterrizado");
    			break;
    		case 2:
    			strcpy(desc, "En Horario");
    			break;
    		case 3:
    			strcpy(desc, "En Vuelo");
    			break;
    		case 4:
    			strcpy(desc, "Demorado");
    			break;
    		}
			todoOk=1;
    	}
    }

    return todoOk;
}

int mostrarPasajero(Passenger* p)
{
    int todoOk = 0;
    char descTipo[20];
    char descEstadoVuelo[20];
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigoVuelo[10];

    if( Passenger_getId(p, &id) &&
    	Passenger_getNombre(p, nombre) &&
		Passenger_getApellido(p, apellido) &&
		Passenger_getPrecio(p, &precio) &&
		Passenger_getCodigoVuelo(p, codigoVuelo) &&
		cargarDescTipoPasajero(p, descTipo) &&
		cargarDescEstadoVuelo(p, descEstadoVuelo))
    {
        printf("%4d %15s %15s %10.2f %10s %15s %15s\n", id, nombre, apellido, precio, codigoVuelo, descTipo, descEstadoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPasajeros(LinkedList* lista)
{
    int todoOk = 0;
    Passenger* auxPassenger=NULL;
    int tam;
    if(lista != NULL)
    {
    	tam=ll_len(lista);
        printf("  id          name       lastname      price       flycode  typePassenger     statusFlight\n");
        for(int i=0; i<tam; i++)
        {
        	auxPassenger=(Passenger*)ll_get(lista, i);
        	if(!mostrarPasajero(auxPassenger))
        	{
        		return todoOk;
        	}
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int buscarMayorId(LinkedList* lista, int* pProxId)
{
	int todoOk = 0;
	Passenger* auxPassenger=NULL;
	int mayor;
	int tam;
	if(lista != NULL)
	{
		tam=ll_len(lista);
		for(int i=0; i<tam; i++)
		{
			auxPassenger=(Passenger*)ll_get(lista, i);
			if(i==0 || auxPassenger->id>mayor)
			{
				mayor=auxPassenger->id;
			}
		}
		*pProxId=mayor+1;
		todoOk = 1;
	}
	return todoOk;
}

