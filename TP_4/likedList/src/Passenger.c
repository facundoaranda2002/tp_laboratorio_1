#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"
#include "funcionesExtra.h"


Passenger* Passenger_new()
{
	Passenger* nuevoPasajero = (Passenger*) calloc(1,sizeof(Passenger));
    return nuevoPasajero;
}

Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio, char* codigoVuelo, int tipoPasajero,int estadoVuelo)
{
	Passenger* nuevoPasajero = Passenger_new();
	if(nuevoPasajero != NULL)
	{
		if(!(Passenger_setId(nuevoPasajero, id) &&
				Passenger_setNombre(nuevoPasajero, nombre) &&
				Passenger_setApellido(nuevoPasajero, apellido) &&
				Passenger_setPrecio(nuevoPasajero, precio) &&
				Passenger_setCodigoVuelo(nuevoPasajero, codigoVuelo) &&
				Passenger_setTipoPasajero(nuevoPasajero, tipoPasajero) &&
				Passenger_setEstadoVuelo(nuevoPasajero, estadoVuelo)))
		{
			Passenger_delete(nuevoPasajero);
			nuevoPasajero = NULL;
		}
	}
	return nuevoPasajero;
}

Passenger* Passenger_newParametrosString(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr,char* estadoVueloStr)
{
	Passenger* nuevoPasajero = Passenger_new();
	if(nuevoPasajero != NULL)
	{
		int idTipo;
		int estadoVuelo;
		cargarIdTipoPasajero(&idTipo, tipoPasajeroStr);
		cargarIdEstadoVuelo(&estadoVuelo, estadoVueloStr);

		if(!(Passenger_setId(nuevoPasajero, atoi(idStr)) &&
				Passenger_setNombre(nuevoPasajero, nombreStr) &&
				Passenger_setApellido(nuevoPasajero, apellidoStr) &&
				Passenger_setPrecio(nuevoPasajero, atof(precioStr)) &&
				Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr) &&
				Passenger_setTipoPasajero(nuevoPasajero, idTipo) &&
				Passenger_setEstadoVuelo(nuevoPasajero, estadoVuelo)))
		{
			Passenger_delete(nuevoPasajero);
			nuevoPasajero = NULL;
		}
	}
	return nuevoPasajero;
}

void Passenger_delete(Passenger* p)
{
	free(p);
}

int Passenger_setId(Passenger* p,int id)
{
    int todoOk = 0;
    if(p != NULL && id>0)
    {
        p->id = id;
        todoOk = 1;

    }
    return todoOk;
}
int Passenger_getId(Passenger* p, int *id)
{
    int todoOk = 0;
    if(p != NULL && id!=NULL)
    {
        *id = p->id;
        todoOk = 1;
    }
    return todoOk;
}


int Passenger_setNombre(Passenger* p,char* nombre)
{
    int todoOk = 0;
    if(p != NULL && nombre != NULL && strlen(nombre) < 51 && strlen(nombre) > 1)
    {
        strcpy(p->nombre, nombre);
        strlwr(p->nombre);
        (p->nombre)[0] = toupper((p->nombre)[0]);

        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getNombre(Passenger* p,char* nombre)
{
    int todoOk = 0;
    if(p != NULL && nombre != NULL)
    {
        strcpy(nombre, p->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setApellido(Passenger* p,char* apellido)
{
    int todoOk = 0;
    if(p != NULL && apellido != NULL && strlen(apellido) < 51 && strlen(apellido) > 1)
    {
        strcpy(p->apellido, apellido);
        strlwr(p->apellido);
        (p->apellido)[0] = toupper((p->apellido[0]));

        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getApellido(Passenger* p,char* apellido)
{
    int todoOk = 0;
    if(p != NULL && apellido != NULL)
    {
        strcpy(apellido, p->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* p,char* codigoVuelo)
{
    int todoOk = 0;
    if(p != NULL && codigoVuelo != NULL && strlen(codigoVuelo) < 10 && strlen(codigoVuelo) > 2)
    {
        strcpy(p->codigoVuelo, codigoVuelo);
        strupr(p->codigoVuelo);

        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getCodigoVuelo(Passenger* p,char* codigoVuelo)
{
    int todoOk = 0;
    if(p != NULL && codigoVuelo != NULL)
    {
        strcpy(codigoVuelo, p->codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setTipoPasajero(Passenger* p,int tipoPasajero)
{
    int todoOk = 0;
    if(p != NULL && tipoPasajero>=1 && tipoPasajero<=3)
    {
        p->tipoPasajero = tipoPasajero;
        todoOk = 1;

    }
    return todoOk;
}
int Passenger_getTipoPasajero(Passenger* p,int* tipoPasajero)
{
    int todoOk = 0;
    if(p != NULL && tipoPasajero!=NULL)
    {
        *tipoPasajero = p->tipoPasajero;
        todoOk = 1;

    }
    return todoOk;
}

int Passenger_setPrecio(Passenger* p,float precio)
{
    int todoOk = 0;
    if(p != NULL && precio > 0 && precio <= 1000000)
    {
        p->precio = precio;
        todoOk = 1;

    }
    return todoOk;
}
int Passenger_getPrecio(Passenger* p,float* precio)
{
    int todoOk = 0;
    if(p != NULL && precio !=NULL)
    {
        *precio = p->precio;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_setEstadoVuelo(Passenger* p,int estadoVuelo)
{
    int todoOk = 0;
    if(p != NULL && estadoVuelo>=1 && estadoVuelo<=4)
    {
        p->estadoVuelo = estadoVuelo;
        todoOk = 1;
    }
    return todoOk;
}
int Passenger_getEstadoVuelo(Passenger* p,int* estadoVuelo)
{
    int todoOk = 0;
    if(p != NULL && estadoVuelo!=NULL)
    {
        *estadoVuelo = p->estadoVuelo;
        todoOk = 1;
    }
    return todoOk;
}



int pasajeroSortId(void* a, void* b)
{
    int retorno=0;
    Passenger* pasA;
    Passenger* pasB;

    if(a!=NULL && b!=NULL)
    {
    	pasA=(Passenger*) a;
		pasB=(Passenger*) b;

        if(pasA->id > pasB->id)
        {
            retorno=1;
        }
        else if(pasA->id < pasB->id)
        {
            retorno=-1;
        }
    }

    return retorno;
}


int pasajeroSortNombre(void* a, void* b)
{
    int retorno=0;
    Passenger* pasA;
    Passenger* pasB;

    if(a!=NULL && b!=NULL)
    {
        pasA=(Passenger*) a;
        pasB=(Passenger*) b;

        retorno=strcmp(pasA->nombre, pasB->nombre);
    }

    return retorno;
}

int pasajeroSortApellido(void* a, void* b)
{
    int retorno=0;
    Passenger* pasA;
    Passenger* pasB;

    if(a!=NULL && b!=NULL)
    {
        pasA=(Passenger*) a;
        pasB=(Passenger*) b;

        retorno=strcmp(pasA->apellido, pasB->apellido);
    }

    return retorno;
}

int pasajeroSortPrecio(void* a, void* b)
{
    int retorno=0;
    Passenger* pasA;
	Passenger* pasB;

    if(a!=NULL && b!=NULL)
    {
    	pasA=(Passenger*) a;
		pasB=(Passenger*) b;

        if(pasA->precio > pasB->precio)
        {
            retorno=1;
        }
        else if(pasA->precio < pasB->precio)
        {
            retorno=-1;
        }
    }

    return retorno;
}

int pasajeroSortCodigoVuelo(void* a, void* b)
{
    int retorno=0;
    Passenger* pasA;
    Passenger* pasB;

    if(a!=NULL && b!=NULL)
    {
        pasA=(Passenger*) a;
        pasB=(Passenger*) b;

        retorno=strcmp(pasA->codigoVuelo, pasB->codigoVuelo);
    }

    return retorno;
}

int pasajeroSortTipoPasajero(void* a, void* b)
{
    int retorno=0;
    Passenger* pasA;
    Passenger* pasB;

    if(a!=NULL && b!=NULL)
    {
    	pasA=(Passenger*) a;
		pasB=(Passenger*) b;

        if(pasA->tipoPasajero > pasB->tipoPasajero)
        {
            retorno=1;
        }
        else if(pasA->tipoPasajero < pasB->tipoPasajero)
        {
            retorno=-1;
        }
    }

    return retorno;
}

int pasajeroSortEstadoVuelo(void* a, void* b)
{
    int retorno=0;
    Passenger* pasA;
    Passenger* pasB;

    if(a!=NULL && b!=NULL)
    {
    	pasA=(Passenger*) a;
		pasB=(Passenger*) b;

        if(pasA->estadoVuelo > pasB->estadoVuelo)
        {
            retorno=1;
        }
        else if(pasA->estadoVuelo < pasB->estadoVuelo)
        {
            retorno=-1;
        }
    }

    return retorno;
}
