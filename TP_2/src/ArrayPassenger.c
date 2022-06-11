#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayPassenger.h"
#include "validaciones.h"

int menu()
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES:\n");
    printf("1- Alta Pasajero\n");
    printf("2- Modificar Pasajero\n");
    printf("3- Baja Pasajero\n");
    printf("4- Informes\n");
    printf("5- Hardcodear Pasajeros\n");
    printf("6- Salir\n");
    utn_getNumeroInt(&opcion, "Ingrese opcion: ", "Error. Opcion invalida. ", 1, 7);
    return opcion;
}

int inicializarPasajeros(ePassenger vec[], int tam)
{
    int todoOk = -1;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty=1;
        }
      todoOk = 0;
    }
    return todoOk;
}

int buscarPasajeroLibre(ePassenger vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex!=NULL)
    {
        *pIndex=-1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex=i;
                break;
            }
        }
      todoOk = 1;
    }
    return todoOk;
}

int altaPasajero(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos, int* pId)
{
    int todoOk = 0;
    ePassenger nuevoPasajero;

    if(vec!=NULL && tam > 0 && vuelos!=NULL && tamVuelos>0 && pId!=NULL)
    {
        printf("\n\n");

        utn_getCadenaChar(nuevoPasajero.name, "Ingrese el nombre del pasajero: ", "Error. Nombre demasiado largo. ", 1, 51);

        utn_getCadenaChar(nuevoPasajero.lastName, "Ingrese el apellido del pasajero: ", "Error. Apellido demasiado largo. ", 1, 51);

        utn_getNumeroFloat(&nuevoPasajero.price, "Ingrese el precio del vuelo(5000-500000): ", "Error. Precio Invalido. ", 5000, 500000);

        printf("\n\n");
        utn_getFlyCode(vuelos, tamVuelos, nuevoPasajero.flycode);

        printf("\n\n");
        utn_getTypePassenger(&nuevoPasajero.typePassenger);

        if(addPassenger(vec, tam, *pId, nuevoPasajero.name, nuevoPasajero.lastName, nuevoPasajero.price, nuevoPasajero.typePassenger, nuevoPasajero.flycode)==0)
        {
           *pId=*pId+1;
           todoOk = 1;
        }
    }
    return todoOk;
}

int addPassenger(ePassenger vec[], int tam, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
    int todoOk=-1;
    int indice;
    if(vec!=NULL && tam>0)
    {
        if(buscarPasajeroLibre(vec, tam, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                vec[indice].id=id;
                strcpy(vec[indice].name, name);
                strcpy(vec[indice].lastName, lastName);
                strcpy(vec[indice].flycode, flycode);
                vec[indice].price=price;
                vec[indice].typePassenger=typePassenger;
                vec[indice].isEmpty=0;
                todoOk=0;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }

    return todoOk;
}

int utn_getTypePassenger(int *pId)
{
    int todoOk=0;
    int x;
    if(pId!=NULL)
    {
        printf("     *** Lista de Tipos de Pasajeros ***\n\n");
        printf("     id                 tipo\n");
        printf("---------------------------------------------\n");
        printf("    5000            Primera clase\n");
        printf("    5001            Clase ejecutiva\n");
        printf("    5002            Clase premium economy\n");
        printf("    5003            Clase turista\n");
        printf("\n\n");
        utn_getNumeroInt(&x, "Ingrese el id del tipo al que pertenece el pasajero: ", "Error. Id invalido. ", 5000, 5003);
        *pId=x;
        todoOk=1;
    }
    return todoOk;
}

int utn_getTypePassengerMod(int *pId)
{
    int todoOk=0;
    int x;
    if(pId!=NULL)
    {
        printf("     *** Lista de Tipos de Pasajeros ***\n\n");
        printf("     id                 tipo\n");
        printf("---------------------------------------------\n");
        printf("    5000            Primera clase\n");
        printf("    5001            Clase ejecutiva\n");
        printf("    5002            Clase premium economy\n");
        printf("    5003            Clase turista\n");
        printf("\n\n");
        utn_getNumeroInt(&x, "Ingrese el id del nuevo tipo al que pertenece el pasajero: ", "Error. Id invalido. ", 5000, 5003);
        *pId=x;
        todoOk=1;
    }
    return todoOk;
}

int printPassenger(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos)
{
    int todoOk=0;
    char desc[30];
    char estado[20];

    if(vec!=NULL && tam>0 && vuelos!=NULL && tamVuelos>0)
    {
        //system("cls");
        printf("\n\n");
        printf("    *** Lista de Pasajeros ***\n\n");
        printf("   Id               Nombre          Apellido   Precio de Vuelo  Tipo de pasajero  Codigo de Vuelo  Estado del Vuelo\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                cargarDescripcionTipoPasajero(vec[i].typePassenger, desc);
                cargarDescripcionEstado(vuelos, tamVuelos, estado, vec[i].flycode);
                printf("   %5d    %15s   %15s   %10.2f  %25s  %10s  %15s\n", vec[i].id, vec[i].name, vec[i].lastName, vec[i].price, desc, vec[i].flycode, estado);
            }

        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}

int cargarDescripcionTipoPasajero(int id, char desc[])
{
    int todoOk=0;

    if(desc!=NULL && id>=5000 && id<=5003)
    {
        switch(id)
       {
        case 5000:
            strcpy(desc, "Primera clase");
            break;
        case 5001:
            strcpy(desc, "Clase ejecutiva");
            break;
        case 5002:
            strcpy(desc, "Clase premium economy");
            break;
        case 5003:
            strcpy(desc, "Clase turista");
            break;
       }
        todoOk=1;
    }

    return todoOk;
}

int hardcodearPasajeros(ePassenger vec[], int tam, int cant, int* pId)
{

    int todoOk = 0;
    ePassenger impostores[] =
    {
        {0, "Juan", "Lopez", 7000, "ABCD5522", 5000,0},
        {0, "Juana", "Lopez", 8000, "ABCD5511", 5001,0},
        {0, "Juanito", "Garcia", 6000, "ABCD5533", 5002,0},
        {0, "Juan Carlos", "Lopez", 7000, "ABCD5544", 5003,0},
        {0, "Juanfran", "Garcia", 7000, "ABCD5555", 5000,0}
    };

    if(vec != NULL && tam > 0 && pId != NULL && cant > 0 && cant <= tam)
    {

        for(int i=0; i < cant; i++)
        {
            vec[i] = impostores[i];
            vec[i].id = *pId;
            *pId = *pId +1;

        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarPasajero(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos)
{
    int todoOk = 0;
    int indice;
    int id;
    ePassenger auxPassenger;
    char salir='n';
    char desc[50];
    char estado[50];

    if(vec!=NULL && tam > 0 && vuelos!=NULL && tamVuelos>0)
    {
    	sortPassengersById(vec, tam);
        printPassenger(vec, tam, vuelos, tamVuelos);
        utn_getNumeroInt(&id, "Ingrese id de pasajero a modificar: ", "Error. Id invalido. ", 10000, 20000);
        indice=findPassengerById(vec, tam, id);
        if(indice==-1)
        {
            printf("Ocurrio un problema al buscar al pasajero\n");
        }
        else
        {
            system("cls");
            printf("   Id               Nombre          Apellido   Precio de Vuelo  Tipo de pasajero  Codigo de Vuelo  Estado del Vuelo\n");
            printf("---------------------------------------------------------------------------------------------------------------------\n");
            cargarDescripcionTipoPasajero(vec[indice].typePassenger, desc);
            cargarDescripcionEstado(vuelos, tamVuelos, estado, vec[indice].flycode);
            printf("   %5d    %15s   %15s   %.2f  %25s  %10s  %15s\n", vec[indice].id, vec[indice].name, vec[indice].lastName, vec[indice].price, desc, vec[indice].flycode, estado);
            do
            {
                printf("\n\n");
                switch(menuModificarPasajero())
                {
                case 1:
                    utn_getCadenaChar(auxPassenger.name, "Ingrese el nuevo nombre del pasajero: ", "Error. Nombre demasiado largo. ", 1, 51);
                    strcpy(vec[indice].name, auxPassenger.name);
                    printf("Se ha modificado el nombre\n");
                    printf("\n\n");
                    break;
                case 2:
                    utn_getCadenaChar(auxPassenger.lastName, "Ingrese el nuevo apellido del pasajero: ", "Error. Apellido demasiado largo. ", 1, 51);
                    strcpy(vec[indice].lastName, auxPassenger.lastName);
                    printf("Se ha modificado el apellido\n");
                    printf("\n\n");
                    break;
                case 3:
                    utn_getNumeroFloat(&auxPassenger.price, "Ingrese el nuevo precio del vuelo(5000-500000): ", "Error. Precio Invalido. ", 5000, 500000);
                    vec[indice].price=auxPassenger.price;
                    printf("Se ha modificado el precio\n");
                    printf("\n\n");
                    break;
                case 4:
                    utn_getTypePassengerMod(&auxPassenger.typePassenger);
                    vec[indice].typePassenger=auxPassenger.typePassenger;
                    printf("Se ha modificado el tipo de pasajero\n");
                    printf("\n\n");
                    break;
                case 5:
                    utn_getFlyCodeMod(vuelos, tamVuelos, auxPassenger.flycode);
                    strcpy(vec[indice].flycode, auxPassenger.flycode);
                    printf("Se ha modificado el codigo de vuelo\n");
                    printf("\n\n");
                    break;
                case 6:
                    salir='s';
                    break;
                }
            }
            while(salir!='s');
            todoOk=1;
        }
    }
    return todoOk;
}

int findPassengerById(ePassenger vec[], int tam, int id)
{
    if(vec != NULL && tam > 0 && id>0)
    {
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty==0 && vec[i].id==id)
            {
                return i;
            }
        }
    }
    return -1;
}

int menuModificarPasajero()
{
    int opcion;
    printf("Seleccione que apartado modificar:\n");
    printf("1- Nombre\n");
    printf("2- Apellido\n");
    printf("3- Precio\n");
    printf("4- Tipo de pasajero\n");
    printf("5- Codigo de Vuelo\n");
    printf("6- Salir\n");
    utn_getNumeroInt(&opcion, "Ingrese opcion: ", "Error. Opcion Invalida. ", 1, 6);
    return opcion;
}

int bajaPasajero(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos)
{
    int todoOk=0;
    int id;
    if(vec!=NULL && tam > 0 && vuelos!=NULL && tamVuelos>0)
    {
    	sortPassengersById(vec, tam);
        printPassenger(vec, tam, vuelos, tamVuelos);
        utn_getNumeroInt(&id, "Ingrese id de pasajero a remover: ", "Error. Id invalido. ", 10000, 20000);
        if(removePassenger(vec, tam, vuelos, tamVuelos, id)==0)
        {
            todoOk=1;
        }
    }
    return todoOk;
}

int removePassenger(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos, int id)
{
    int todoOk=-1;
    int indice;
    char confirma;
    char desc[50];
    char estado[50];
    if(vec!=NULL && tam > 0 && vuelos!=NULL && tamVuelos>0)
    {
        indice=findPassengerById(vec, tam, id);
        if(indice!=-1)
        {
            system("cls");
            printf("   Id               Nombre          Apellido   Precio de Vuelo  Tipo de pasajero  Codigo de Vuelo  Estado del Vuelo\n");
            printf("---------------------------------------------------------------------------------------------------------------------\n");
            cargarDescripcionTipoPasajero(vec[indice].typePassenger, desc);
            cargarDescripcionEstado(vuelos, tamVuelos, estado, vec[indice].flycode);
            printf("   %5d    %15s   %15s   %.2f  %25s  %10s  %15s\n", vec[indice].id, vec[indice].name, vec[indice].lastName, vec[indice].price, desc, vec[indice].flycode, estado);
            printf("\n\n");
            utn_getRespuesta(&confirma, "Confirma baja?(s/n): ", "Error. ");
            if(confirma=='n')
            {
                printf("Baja cancelada por el usuario\n");
            }
            else
            {
                vec[indice].isEmpty=1;
                printf("Baja realizada con exito\n");
                todoOk=0;
            }
        }
    }
    return todoOk;
}

int menuInformes(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos)
{
    int todoOk=0;
    int opcion;
    char salir='n';

    if(vec!=NULL && tam > 0 && vuelos!=NULL && tamVuelos>0)
    {
        do
        {
            system("cls");
            printf("               *** Informes ***\n");
            printf("------------------------------------------------------------\n");
            printf("Seleccione informe a realizar:\n");
            printf("1- Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero\n");
            printf("2- Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio\n");
            printf("3- Listado de los pasajeros por Codigo de vuelo y estados de vuelos ACTIVO\n");
            printf("4- Salir\n");
            utn_getNumeroInt(&opcion, "Ingrese opcion: ", "Error. Opcion Invalida. ", 1, 4);
            printf("\n\n");
            switch(opcion)
            {
               case 1:
                    if(!informeUno(vec, tam, vuelos, tamVuelos))
                    {
                        printf("Problema al hacer el informe\n");
                    }
                    printf("\n\n");
                    system("pause");
                    break;
                case 2:
                    if(!informeDos(vec, tam, vuelos, tamVuelos))
                    {
                        printf("Problema al hacer el informe\n");
                    }
                    printf("\n\n");
                    system("pause");
                    break;
                case 3:
                    if(!informeTres(vec, tam, vuelos, tamVuelos))
                    {
                        printf("Problema al hacer el informe\n");
                    }
                    printf("\n\n");
                    system("pause");
                    break;
                case 4:
                    salir='s';
                    break;
            }
        }
        while(salir!='s');
        todoOk=1;
    }
    return todoOk;
}

int informeUno(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos)
{
    int todoOk=0;
    int orden;
    if(vec!=NULL && tam > 0 && vuelos!=NULL && tamVuelos>0)
    {
        utn_getNumeroInt(&orden, "Ingrese criterio de ordenamiento(1-ascendente , 0-descendente): ", "Error. ", 0, 1);
        if(sortPassengers(vec, tam, orden)==0)
        {
            printf("\n\n");
            printf("    *** Listado de pasajeros por apellido y tipo  ***\n");
            printf("----------------------------------------------------------\n");
            if(!printPassenger(vec, tam, vuelos, tamVuelos))
            {
                printf("Problema al listar pasajeros\n");
            }
            else
            {
               todoOk=1;
            }
        }
        else
        {
             printf("Error al ordenar pasajeros\n");
        }
    }
    return todoOk;
}

int sortPassengers(ePassenger vec[], int tam, int orden)
{
    int todoOk=-1;
    ePassenger auxPassenger;
    if(vec!=NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(orden==1)
                {
                    if( ( (stricmp(vec[i].lastName, vec[j].lastName) == 0) && (vec[i].typePassenger > vec[j].typePassenger) )
                       || (stricmp(vec[i].lastName, vec[j].lastName) > 0)  )
                    {
                        auxPassenger = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxPassenger;
                    }
                }
                else
                {
                    if( ( (stricmp(vec[i].lastName, vec[j].lastName) == 0) && (vec[i].typePassenger > vec[j].typePassenger) )
                       || (stricmp(vec[i].lastName, vec[j].lastName) < 0)  )
                    {
                        auxPassenger = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxPassenger;
                    }
                }
            }
        }
        todoOk = 0;
    }
    return todoOk;
}

int informeDos(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos)
{
    int todoOk=0;
    float sumaPrecios=0;
    int flag=0;
    int cant=0;
    int cantSupProm=0;
    float prom;
    if(vec!=NULL && tam > 0 && vuelos!=NULL && tamVuelos>0)
    {
        printf("\n\n");
        printf("    *** Informe de precios  ***\n");
        printf("----------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                sumaPrecios=sumaPrecios+vec[i].price;
                cant++;
                flag=1;
            }
        }
        if(!flag)
        {
            printf("No se ingresaron pasajeros\n");
        }
        else
        {
            prom=sumaPrecios/cant;
            for(int i=0; i<tam; i++)
            {
                if(!vec[i].isEmpty && vec[i].price>prom)
                {
                    cantSupProm++;
                }
            }
            printf("Total precio pasajes: $ %.2f\n", sumaPrecios);
            printf("Promedio precio pasajes: $ %.2f\n", prom);
            printf("Cantidad de pasajeros que superan el precio promedio de los pasajes: %d\n", cantSupProm);
            todoOk=1;
        }
        printf("\n\n");
    }
    return todoOk;
}

int informeTres(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos)
{
    int todoOk=0;
    int orden;
    if(vec!=NULL && tam > 0 && vuelos!=NULL && tamVuelos>0)
    {
        utn_getNumeroInt(&orden, "Ingrese criterio de ordenamiento(1-ascendente , 0-descendente): ", "Error. ", 0, 1);
        if(sortPassengersByCode(vec, tam, orden)==0)
        {
            printf("\n\n");
            printf("    *** Listado de pasajeros por codigo de vuelo activos  ***\n");
            printf("---------------------------------------------------------------\n");
            if(!printPassengerActive(vec, tam, vuelos, tamVuelos))
            {
                printf("Problema al listar pasajeros\n");
            }
            else
            {
                todoOk=1;
            }
        }
        else
        {
             printf("Error al ordenar pasajeros\n");
        }
    }
    return todoOk;
}

int sortPassengersByCode(ePassenger vec[], int tam, int orden)
{
    int todoOk=-1;
    ePassenger auxPassenger;
    if(vec!=NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
                if(orden==1)
                {
                    if(stricmp(vec[i].flycode, vec[j].flycode) > 0)
                    {
                        auxPassenger = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxPassenger;
                    }
                }
                else
                {
                    if(stricmp(vec[i].flycode, vec[j].flycode) < 0)
                    {
                        auxPassenger = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxPassenger;
                    }
                }
            }
        }
        todoOk = 0;
    }
    return todoOk;
}

int printPassengerActive(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos)
{
    int todoOk=0;
    char desc[30];
    char estado[20];

    if(vec!=NULL && tam>0 && vuelos!=NULL && tamVuelos>0)
    {
        //system("cls");
        printf("\n\n");
        printf("    *** Lista de Pasajeros ***\n\n");
        printf("   Id               Nombre          Apellido   Precio de Vuelo  Tipo de pasajero  Codigo de Vuelo  Estado del Vuelo\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                cargarDescripcionEstado(vuelos, tamVuelos, estado, vec[i].flycode);
                if(strcmp(estado, "ACTIVO")==0)
                {
                    cargarDescripcionTipoPasajero(vec[i].typePassenger, desc);
                    printf("   %5d    %15s   %15s   %10.2f  %25s  %10s  %15s\n", vec[i].id, vec[i].name, vec[i].lastName, vec[i].price, desc, vec[i].flycode, estado);
                }
            }
        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}

int sortPassengersById(ePassenger vec[], int tam)
{
    int todoOk=-1;
    ePassenger auxPassenger;
    if(vec!=NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++)
        {
            for(int j= i + 1; j < tam; j++)
            {
				if(vec[i].id > vec[j].id)
				{
					auxPassenger = vec[i];
					vec[i] = vec[j];
					vec[j] = auxPassenger;
				}
            }
        }
        todoOk = 0;
    }
    return todoOk;
}
