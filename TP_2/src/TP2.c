#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"


#define TAM 2000
#define TAM_FLYCODE 5


int main()
{
	setbuf(stdout,NULL);
    ePassenger lista[TAM];
    eFlycode flycodeLista[TAM_FLYCODE]=
    {
       {"ABCD5511", 1},
       {"ABCD5522", 2},
       {"ABCD5533", 1},
       {"ABCD5544", 3},
       {"ABCD5555", 2}
    };

    char salir='n';
    int proximoId=10000;
    int cantPasajeros=0;

    if(inicializarPasajeros(lista, TAM)==0)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    if(altaPasajero(lista, TAM, flycodeLista, TAM_FLYCODE, &proximoId))
                    {
                        printf("Pasajero agregado con exito!!!\n");
                        cantPasajeros++;
                    }
                    else
                    {
                        printf("Problema al hacer el alta de pasajero\n");
                    }
                    break;
                case 2:
                    if(cantPasajeros==0)
                    {
                        printf("No hay pasajeros en el sistema\n");
                    }
                    else if(!modificarPasajero(lista, TAM, flycodeLista, TAM_FLYCODE))
                    {
                        printf("Problema al modificar pasajero\n");
                    }
                    break;
                case 3:
                    if(cantPasajeros==0)
                    {
                        printf("No hay pasajeros en el sistema\n");
                    }
                    else if(!bajaPasajero(lista, TAM, flycodeLista, TAM_FLYCODE))
                    {
                        printf("Problema al hacer la baja de pasajero o baja cancelada\n");
                    }
                    else
                    {
                        cantPasajeros--;
                    }
                    break;
                case 4:
                    if(cantPasajeros==0)
                    {
                        printf("No hay pasajeros en el sistema\n");
                    }
                    else if(!menuInformes(lista, TAM, flycodeLista, TAM_FLYCODE))
                    {
                        printf("Problema al hacer informes\n");
                    }
                    break;
                case 5:
                    if(!hardcodearPasajeros(lista, TAM, 5, &proximoId))
                    {
                        printf("Problema al hardcodear pasajeros\n");
                    }
                    else
                    {
                        printf("Se han hardcodeado 5 pasajeros\n");
                        cantPasajeros=cantPasajeros+5;
                    }
                    break;
                case 6:
                    salir='s';
                    break;
            }
            system("pause");
        }
        while(salir!='s');
    }
    else
    {
        printf("Problema al inicializar array de pasajeros");
    }

    return 0;
}


