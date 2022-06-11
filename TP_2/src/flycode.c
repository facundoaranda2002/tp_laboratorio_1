#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flycode.h"
#include "validaciones.h"


int listarVuelos(eFlycode vec[], int tam)
{
    int todoOk=0;
    char desc[20];

    if(vec!=NULL && tam>0)
    {
        //system("cls");
        printf("    *** Lista de Vuelos ***\n\n");
        printf("   Codigo de vuelo    Estado\n");
        printf("-------------------------------\n");
        for(int i=0; i<tam; i++)
        {
           cargarDescripcionEstado(vec, tam, desc, vec[i].flycode);
           printf("   %10s    %10s\n", vec[i].flycode, desc);
        }
        printf("\n\n");
        todoOk=1;
    }

    return todoOk;
}

int validarVuelos(eFlycode vec[], int tam, char code[])
{
    int todoOk=0;

    if(vec!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
           if(strcmp(vec[i].flycode, code)==0)
           {
              todoOk=1;
              break;
           }
        }
    }

    return todoOk;
}

int cargarDescripcionEstado(eFlycode vec[], int tam, char descripcion[], char code[])
{
    int todoOk=0;

    if(vec!=NULL && tam>0 && validarVuelos(vec, tam, code) && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
           if(strcmp(vec[i].flycode,code)==0)
           {
               switch(vec[i].statusFly)
               {
                case 1:
                    strcpy(descripcion, "ACTIVO");
                    break;
                case 2:
                    strcpy(descripcion, "DEMORADO");
                    break;
                default:
                    strcpy(descripcion, "CANCELADO");
                    break;
               }
               todoOk=1;
           }
        }
    }

    return todoOk;
}

int utn_getFlyCode(eFlycode vec[], int tam, char code[])
{
    int todoOk=0;
    char c[50];
    if(vec!=NULL && tam>0 && code!=NULL)
    {
        listarVuelos(vec, tam);
        utn_getCadenaChar(c, "Ingrese Codigo de Vuelo: ", "Error. ", 1, 9);
        while(!validarVuelos(vec, tam, c))
        {
            printf("Error. Codigo invalido. ");
            utn_getCadenaChar(c, "Ingrese Codigo de Vuelo: ", "Error. ", 1, 9);
        }
        strcpy(code, c);
        todoOk=1;
    }
    return todoOk;
}

int utn_getFlyCodeMod(eFlycode vec[], int tam, char code[])
{
    int todoOk=0;
    char c[50];
    if(vec!=NULL && tam>0 && code!=NULL)
    {
        listarVuelos(vec, tam);
        utn_getCadenaChar(c, "Ingrese el nuevo Codigo de Vuelo: ", "Error. ", 1, 9);
        while(!validarVuelos(vec, tam, c))
        {
            printf("Error. Codigo invalido. ");
            utn_getCadenaChar(c, "Ingrese el nuevo Codigo de Vuelo: ", "Error. ", 1, 9);
        }
        strcpy(code, c);
        todoOk=1;
    }
    return todoOk;
}
