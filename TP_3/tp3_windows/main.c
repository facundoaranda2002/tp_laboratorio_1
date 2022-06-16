#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "funcionesExtra.h"
#include "validaciones.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo datos.bin (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo datos.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int proximoId=1;
    int salir=0;
    int flagGuardado=0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    if(listaPasajeros==NULL)
    {
    	printf("No se consiguio memoria\n");
    	system("pause");
    	exit(1);
    }
    else
    {
		do{
			switch(menu())
			{
				case 1:
					if(!controller_loadFromText("data.csv",listaPasajeros))
					{
						printf("Error al cargar desde archivo csv\n");
					}
					else
					{
						printf("Archivo cargado con exito\n");
						buscarMayorId(listaPasajeros, &proximoId);
					}
					break;
				case 2:
					if(!controller_loadFromBinary("datos.bin",listaPasajeros))
					{
						printf("Error al cargar desde archivo bin\n");
					}
					else
					{
						printf("Archivo cargado con exito\n");
						buscarMayorId(listaPasajeros, &proximoId);
					}
					break;
				case 3:
					if(!controller_addPassenger(listaPasajeros, proximoId))
					{
						printf("Error al agregar pasajero\n");
					}
					else
					{
						printf("Pasajero agregado con exito\n");
						proximoId++;
					}
					break;
				case 4:
					if(ll_len(listaPasajeros)>0)
					{
						if(!controller_editPassenger(listaPasajeros, proximoId))
						{
							printf("Error al modificar pasajero\n");
						}
					}
					else
					{
						printf("No hay pasajeros en el sistema\n");
					}
					break;
				case 5:
					if(ll_len(listaPasajeros)>0)
					{
						if(!controller_removePassenger(listaPasajeros, proximoId))
						{
							printf("Error al borrar pasajero\n");
						}
						else
						{
							printf("Pasajero removido con exito\n");
						}
					}
					else
					{
						printf("No hay pasajeros en el sistema\n");
					}
					break;
				case 6:
					if(!controller_ListPassenger(listaPasajeros))
					{
						printf("Error al leer lista\n");
					}
					break;
				case 7:
					if(ll_len(listaPasajeros)>1)
					{
						if(!controller_sortPassenger(listaPasajeros))
						{
							printf("Error al ordenar pasajeros\n");
						}
						else
						{
							printf("Pasajeros ordenados con exito\n");
						}
					}
					else
					{
						printf("No hay pasajeros en el sistema suficientes para un ordenamiento\n");
					}
					break;
				case 8:
					if(!controller_saveAsText("data.csv",listaPasajeros))
					{
						printf("Error al guardar archivo csv\n");
					}
					else
					{
						printf("Archivo guardado con exito\n");
						flagGuardado=1;
					}
					break;
				case 9:
					if(!controller_saveAsBinary("datos.bin",listaPasajeros))
					{
						printf("Error al guardar archivo bin\n");
					}
					else
					{
						printf("Archivo guardado con exito\n");
						flagGuardado=1;
					}
					break;
				case 10:
					if(flagGuardado)
					{
						salir=1;
					}
					else
					{
						printf("No puede salir de programa sin antes guardar un archivo\n");
					}
					break;
			}
			system("pause");
		  }while(salir != 1);
    }
    ll_deleteLinkedList(listaPasajeros);
    return 0;
}

