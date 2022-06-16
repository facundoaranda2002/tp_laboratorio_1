#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "funcionesExtra.h"
#include "validaciones.h"
#include "Controller.h"



int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	char respuesta;
	FILE* f=fopen(path, "r");
	if(f!=NULL && pArrayListPassenger!=NULL)
	{
		if(ll_len(pArrayListPassenger)>0)
		{
			utn_getRespuesta(&respuesta, "Esto eliminara la lista actual del linked list y cargara una nueva desde el archivo seleccionado, asegurese de guardar los datos que ya tiene antes. Seguro que quiere continuar?(s(si), n(no))", "Opcion Invalida. Reingrese respuesta. ");
			if(respuesta=='s')
			{
				if(ll_clear(pArrayListPassenger)==0)
				{
					if(parser_PassengerFromText(f, pArrayListPassenger))
					{
						todoOk=1;
					}
				}
			}
			else
			{
				printf("Carga de archivo cancelada\n");
			}
		}
		else
		{
			if(parser_PassengerFromText(f, pArrayListPassenger))
			{
				todoOk=1;
			}
		}
		fclose(f);
	}
    return todoOk;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	char respuesta;
	FILE* f=fopen(path, "rb");
	if(f!=NULL && pArrayListPassenger!=NULL)
	{
		if(ll_len(pArrayListPassenger)>0)
		{
			utn_getRespuesta(&respuesta, "Esto eliminara la lista actual del linked list y cargara una nueva desde el archivo seleccionado, asegurese de guardar los datos que ya tiene antes. Seguro que quiere continuar?(s(si), n(no))", "Opcion Invalida. Reingrese respuesta. ");
			if(respuesta=='s')
			{
				if(ll_clear(pArrayListPassenger)==0)
				{
					if(parser_PassengerFromBinary(f, pArrayListPassenger))
					{
						todoOk=1;
					}
				}
			}
			else
			{
				printf("Carga de archivo cancelada\n");
			}
		}
		else
		{
			if(parser_PassengerFromBinary(f, pArrayListPassenger))
			{
				todoOk=1;
			}
		}
		fclose(f);
	}
	return todoOk;
}


int controller_addPassenger(LinkedList* pArrayListPassenger, int proxId)
{
	int todoOk = 0;

	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	Passenger* nuevoPasajero = NULL;

	if(pArrayListPassenger != NULL && proxId>0)
	{

		if(
				utn_getCadenaCharLetras(nombre, "Ingrese nombre(solo letras): ", "Error. ", 1, 51) &&
				utn_getCadenaCharLetras(apellido, "Ingrese apellido(solo letras): ", "Error. ", 1, 51) &&
				utn_getNumeroFloat(&precio, "Ingrese precio del vuelo(1-1000000): ", "Error. ", 1, 1000000) &&
				utn_getCadenaChar(codigoVuelo, "Ingrese codigo de vuelo: ", "Error. ", 3, 10) &&
				utn_getNumeroInt(&tipoPasajero, "Ingrese tipo de pasajero(1-FirstClass, 2-ExecutiveClass, 3-EconomyClass): ", "Error. ", 1, 3) &&
				utn_getNumeroInt(&estadoVuelo, "Ingrese estado de vuelo(1-Aterrizado, 2-En Horario, 3-En Vuelo, 4-Demorado): ", "Error. ", 1, 4)
		    )
		{
			nuevoPasajero = Passenger_newParametros(proxId, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

			if(nuevoPasajero != NULL
			   && ll_add(pArrayListPassenger, (Passenger*)nuevoPasajero) == 0)
			{
				todoOk = 1;
			}
		}
	}
    return todoOk;
}


int controller_editPassenger(LinkedList* pArrayListPassenger, int proxId)
{
	int todoOk = 0;
	int id;
	int indice;
	int salir;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[10];
	int tipoPasajero;
	int estadoVuelo;
	Passenger* pasajero=NULL;

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger)>0)
	{
		controller_ListPassenger(pArrayListPassenger);
		do
		{
			utn_getNumeroInt(&id, "Ingrese id de pasajero a modificar: ", "Error. Id invalido. ", 1, proxId-1);
		}
		while(!obtenerIndice(pArrayListPassenger, &indice, id));
		pasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
		if(pasajero != NULL)
		{
			do
			{
				system("cls");
				mostrarPasajero(pasajero);
				switch(menuMod())
				{
				case 1:
					if(utn_getCadenaCharLetras(nombre, "Ingrese nuevo nombre: ", "Error. ", 2, 51)
					   && Passenger_setNombre(pasajero, nombre))
					{
						printf("Se ha modificado el nombre del pasajero %d\n", id);
					}
					break;
				case 2:
					if(utn_getCadenaCharLetras(apellido, "Ingrese nuevo apellido: ", "Error. ", 2, 51)
					   && Passenger_setApellido(pasajero, apellido))
					{
						printf("Se ha modificado el apellido del pasajero %d\n", id);
					}
					break;
				case 3:
					if(utn_getNumeroFloat(&precio, "Ingrese nuevo precio de vuelo(1-1000000): ", "Error. ", 1, 1000000)
					   && Passenger_setPrecio(pasajero, precio))
					{
						printf("Se ha modificado el precio del vuelo del pasajero %d\n", id);
					}
					break;
				case 4:
					if(utn_getCadenaChar(codigoVuelo, "Ingrese nuevo codigo de vuelo: ", "Error. ", 3, 10)
					   && Passenger_setCodigoVuelo(pasajero, codigoVuelo))
					{
						printf("Se ha modificado el codigo de vuelo del pasajero %d\n", id);
					}
					break;
				case 5:
					if(utn_getNumeroInt(&tipoPasajero, "Ingrese el nuevo tipo del pasajero(1-FirstClass, 2-ExecutiveClass, 3-EconomyClass): ", "Error. ", 1, 3)
					   && Passenger_setTipoPasajero(pasajero, tipoPasajero))
					{
						printf("Se ha modificado el tipo del pasajero %d\n", id);
					}
					break;
				case 6:
					if(utn_getNumeroInt(&estadoVuelo, "Ingrese el nuevo estado de vuelo del avion del pasajero(1-Aterrizado, 2-En Horario, 3-En Vuelo, 4-Demorado): ", "Error. ", 1, 4)
					   && Passenger_setEstadoVuelo(pasajero, estadoVuelo))
					{
						printf("Se ha modificado el estado de vuelo del avion del pasajero %d\n", id);
					}
					break;
				case 7:
					{
						salir=1;
						break;
					}
				}
				system("pause");
			}
			while(salir!=1);
			todoOk=1;
		}
	}
	return todoOk;
}


int controller_removePassenger(LinkedList* pArrayListPassenger, int proxId)
{
	int todoOk = 0;
	int id;
	int indice;
	char respuesta='n';
	Passenger* pasajero=NULL;

	if(pArrayListPassenger != NULL && ll_len(pArrayListPassenger)>0)
	{
		controller_ListPassenger(pArrayListPassenger);
		do
		{
			utn_getNumeroInt(&id, "Ingrese id de pasajero a eliminar: ", "Error. Id invalido. ", 1, proxId-1);
		}
		while(!obtenerIndice(pArrayListPassenger, &indice, id));
		pasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
		if(pasajero != NULL)
		{
			system("cls");
			mostrarPasajero(pasajero);
			utn_getRespuesta(&respuesta, "Confirma baja de pasajero?(s(si), n(no)): ", "Error. ");
			if(respuesta=='s')
			{
				if(ll_remove(pArrayListPassenger, indice)==0)
				{
					Passenger_delete(pasajero);
					pasajero=NULL;
					todoOk=1;
				}
			}
			else
			{
				printf("Baja cancelada\n");
			}
		}
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


int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int todoOk=0;
    int orden;
    if(pArrayListPassenger!=NULL && ll_len(pArrayListPassenger)>1)
    {
    	switch(menuSort())
		{
		case 1:
			if(utn_getNumeroInt(&orden, "Elija orden(1-ascendente, 0-descendente)", "Error. ", 0, 1)==1)
			{
				ll_sort(pArrayListPassenger, pasajeroSortId, orden);
			}
			break;
		case 2:
			if(utn_getNumeroInt(&orden, "Elija orden(1-ascendente, 0-descendente)", "Error. ", 0, 1)==1)
			{
				ll_sort(pArrayListPassenger, pasajeroSortNombre, orden);
			}
			break;
		case 3:
			if(utn_getNumeroInt(&orden, "Elija orden(1-ascendente, 0-descendente)", "Error. ", 0, 1)==1)
			{
				ll_sort(pArrayListPassenger, pasajeroSortApellido, orden);
			}
			break;
		case 4:
			if(utn_getNumeroInt(&orden, "Elija orden(1-ascendente, 0-descendente)", "Error. ", 0, 1)==1)
			{
				ll_sort(pArrayListPassenger, pasajeroSortPrecio, orden);
			}
			break;
		case 5:
			if(utn_getNumeroInt(&orden, "Elija orden(1-ascendente, 0-descendente)", "Error. ", 0, 1)==1)
			{
				ll_sort(pArrayListPassenger, pasajeroSortCodigoVuelo, orden);
			}
			break;
		case 6:
			if(utn_getNumeroInt(&orden, "Elija orden(1-ascendente, 0-descendente)", "Error. ", 0, 1)==1)
			{
				ll_sort(pArrayListPassenger, pasajeroSortTipoPasajero, orden);
			}
			break;
		case 7:
			if(utn_getNumeroInt(&orden, "Elija orden(1-ascendente, 0-descendente)", "Error. ", 0, 1)==1)
			{
				ll_sort(pArrayListPassenger, pasajeroSortEstadoVuelo, orden);
			}
			break;
		}
    	todoOk=1;
    }

    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	int tamLista;
	Passenger* aux;
	FILE* f=NULL;
	char descTipo[20];
	char descEstadoVuelo[20];
	char encabezados[100]="id,name,lastname,price,flycode,typePassenger,statusFlight\n";

	if(pArrayListPassenger!=NULL)
	{
		tamLista=ll_len(pArrayListPassenger);
		if(tamLista>0)
		{
			f=fopen(path, "w");
			if(f!=NULL)
			{
				fprintf(f, encabezados);
				for(int i=0; i<tamLista; i++)
				{
					aux=(Passenger*)ll_get(pArrayListPassenger, i);
					if(aux!=NULL)
					{
						cargarDescTipoPasajero(aux, descTipo);
						cargarDescEstadoVuelo(aux, descEstadoVuelo);
						if(fprintf(f, "%d,%s,%s,%.2f,%s,%s,%s\n", aux->id, aux->nombre, aux->apellido, aux->precio, aux->codigoVuelo, descTipo, descEstadoVuelo)==-1)
						{
							fclose(f);
							return todoOk;
						}
					}
					else
					{
						fclose(f);
						return todoOk;
					}
				}
				todoOk=1;
			}
			fclose(f);
		}
	}
	return todoOk;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	int tamLista;
	Passenger* aux;
	FILE* f=NULL;

	if(pArrayListPassenger!=NULL)
	{
		tamLista=ll_len(pArrayListPassenger);
		if(tamLista>0)
		{
			f=fopen(path, "wb");
			if(f!=NULL)
			{
				for(int i=0; i<tamLista; i++)
				{
					aux=(Passenger*)ll_get(pArrayListPassenger, i);
					if(aux == NULL || fwrite(aux, sizeof(Passenger), 1, f)!=1)
					{
						fclose(f);
						return todoOk;
					}
				}
				todoOk=1;
			}
			fclose(f);
		}
	}
	return todoOk;
}

