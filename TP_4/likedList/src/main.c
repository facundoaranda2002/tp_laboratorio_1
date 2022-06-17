/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "funcionesExtra.h"


int main(void)
{
	setbuf(stdout,NULL);
	int proxId;
	Passenger* nuevoPasajero=NULL;
	Passenger* pasajeroAMostrar=NULL;
	Passenger* pasajeroAModificar=NULL;
	Passenger* pasajeroIndexOf=NULL;
	Passenger* pasajeroPush=NULL;
	Passenger* pasajeroPop=NULL;
	Passenger* pasajeroContains=NULL;


	printf("------ll_newLinkedList------\n\n");
	LinkedList* lista= ll_newLinkedList();
	if(lista==NULL)
	{
		printf("No se consiguio memoria\n");
		system("pause");
		exit(1);
	}
	else
	{
		printf("Se ha creado la lista\n");
	}
	printf("\n\n");
	system("pause");
	system("cls");


	if(!controller_loadFromText("data.csv", lista))
	{
		printf("Error al cargar la lista\n");
		system("pause");
		exit(1);
	}
	else
	{
		printf("Se han cargado los datos del archivo\n");
	}
	printf("\n\n");
	system("pause");
	system("cls");

	printf("------ll_len------\n\n");
	printf("Tamanio de la lista: %d\n", ll_len(lista));
	printf("\n\n");
	controller_ListPassenger(lista);
	printf("\n\n");
	system("pause");
	system("cls");


	printf("------ll_add------\n\n");
	buscarMayorId(lista, &proxId);
	nuevoPasajero=Passenger_newParametros(proxId, "Lautaro", "Gracia", 12000, "ABCD11", 1, 1);
	ll_add(lista, nuevoPasajero);
	printf("Pasajero agregado\n");
	printf("Tamanio de la lista: %d\n", ll_len(lista));
	printf("\n\n");
	controller_ListPassenger(lista);
	printf("\n\n");
	system("pause");
	system("cls");

	printf("------ll_get------\n\n");
	pasajeroAMostrar=(Passenger*)ll_get(lista, 2);
	printf("Pasajero en la posicion 2: \n");
	printf("  id          name       lastname      price       flycode  typePassenger     statusFlight\n");
	mostrarPasajero(pasajeroAMostrar);
	printf("\n\n");
	system("pause");
	system("cls");

	printf("------ll_set------\n\n");
	pasajeroAModificar=Passenger_newParametros(12, "Lazaro", "Garcia", 10000, "ABCD33", 2, 2);
	ll_set(lista, 1, pasajeroAModificar);
	printf("Pasajero modificado en la posicion 1: \n");
	printf("  id          name       lastname      price       flycode  typePassenger     statusFlight\n");
	mostrarPasajero(pasajeroAModificar);
	printf("\n\n");
	controller_ListPassenger(lista);
	system("pause");
	system("cls");

	printf("------ll_remove------\n\n");
	Passenger* p=(Passenger*)ll_get(lista, 10);
	ll_remove(lista, 10);
	free(p);
	printf("Pasajero eliminado en la posicion 10 \n");
	printf("\n\n");
	controller_ListPassenger(lista);
	system("pause");
	system("cls");

	printf("------ll_indexOf------\n\n");
	pasajeroIndexOf=(Passenger*)ll_get(lista, 2);
	printf("El Pasajero:  \n");
	mostrarPasajero(pasajeroIndexOf);
	int indexOf=ll_indexOf(lista, pasajeroIndexOf);
	printf("Esta en la posicion %d \n", indexOf);
	printf("\n\n");
	controller_ListPassenger(lista);
	system("pause");
	system("cls");


	printf("------ll_isEmpty------\n\n");
	if(ll_isEmpty(lista))
	{
		printf("La lista esta vacia\n");
	}
	else
	{
		printf("La lista no esta vacia\n");
	}
	printf("\n\n");
	system("pause");
	system("cls");

	printf("------ll_push------\n\n");
	pasajeroPush=Passenger_newParametros(13, "Miguel", "Torrico", 10022, "ABCD13", 1, 1);
	printf("El siguiente Pasajero sera aniadido en la posicion 4:  \n");
	mostrarPasajero(pasajeroPush);
	ll_push(lista, 4, pasajeroPush);
	printf("\n\n");
	controller_ListPassenger(lista);
	system("pause");
	system("cls");

	printf("------ll_pop------\n\n");
	pasajeroPop=(Passenger*)ll_pop(lista, 6);
	printf("El pasajero en la posicion 6 fue eliminado de la lista y es el siguiente:  \n");
	mostrarPasajero(pasajeroPop);
	free(pasajeroPop);
	printf("\n\n");
	controller_ListPassenger(lista);
	system("pause");
	system("cls");

	printf("------ll_contains------\n\n");
	pasajeroContains=(Passenger*)ll_get(lista, 8);
	printf("El pasajero siguiente esta en la lista?:  \n");
	mostrarPasajero(pasajeroContains);
	if(ll_contains(lista, pasajeroContains))
	{
		printf("El pasajero esta en la lista\n");
	}
	printf("\n\n");
	controller_ListPassenger(lista);
	system("pause");
	system("cls");

	printf("------ll_subList------\n\n");
	LinkedList* subLista=ll_subList(lista, 0, 5);
	printf("Sub-lista creada desde la posicion 0 hasta la 5: \n");
	printf("\n\n");
	controller_ListPassenger(subLista);
	printf("\n\n");
	printf("Lista original: \n");
	printf("\n\n");
	controller_ListPassenger(lista);
	system("pause");
	system("cls");

	printf("------ll_clone------\n\n");
	LinkedList* listaClon=ll_clone(lista);
	printf("Lista clonada de la lista principal: \n");
	printf("\n\n");
	controller_ListPassenger(listaClon);
	printf("\n\n");
	printf("Lista original: \n");
	printf("\n\n");
	controller_ListPassenger(lista);
	system("pause");
	system("cls");

	printf("------ll_containsAll------\n\n");
	if(ll_containsAll(lista, listaClon))
	{
		printf("Todos los elementos de la lista clonada tambien se encuentran en la lista original\n");
	}
	else
	{
		printf("Todos los elementos de la lista clonada no se encuentran en la lista original\n");
	}
	system("pause");
	system("cls");

	printf("------ll_sort------\n\n");
	printf("Lista original: \n");
	printf("\n\n");
	controller_ListPassenger(lista);
	printf("\n\n");
	printf("Lista original ordenada por apellido ascendente: \n");
	printf("\n\n");
	ll_sort(lista, pasajeroSortApellido, 1);
	controller_ListPassenger(lista);
	system("pause");
	system("cls");

	printf("------ll_clear------\n\n");
	ll_clear(lista);
	ll_clear(subLista);
	ll_clear(listaClon);
	printf("Se han vaciado todas las listas\n");
	printf("\n\n");
	if(ll_isEmpty(lista) && ll_isEmpty(listaClon) && ll_isEmpty(subLista))
	{
		printf("No hay elementos en ninguna lista\n");
	}
	system("pause");
	system("cls");


	printf("------ll_deleteLinkedList------\n\n");

	if(ll_deleteLinkedList(lista)==0 &&
	ll_deleteLinkedList(subLista)==0 &&
	ll_deleteLinkedList(listaClon)==0)
	{
		printf("Se han eliminado todas las listas\n");
	}
	printf("\n\n");
	system("pause");

	/*
	startTesting(1);  // ll_newLinkedList
    startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort */

    return 0;
}

































