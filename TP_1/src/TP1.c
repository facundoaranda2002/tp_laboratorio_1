#include <stdio.h>
#include <stdlib.h>
#include "TP[1].h"


void utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    int num;
    int resultadoScanF=0;
    do
    {
        printf(mensaje);
        if(scanf("%d",&num)==1)
        {
            if(num<=maximo && num>=minimo)
            {
                *pResultado = num;
                resultadoScanF=1;
            }
            else
            {
                printf(mensajeError);
            }
        }
        else
        {
            fflush(stdin);
            printf(mensajeError);
        }
    }
    while(resultadoScanF!=1);
}

void utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo)
{
    float num;
    int resultadoScanF=0;
    do
    {
        printf(mensaje);
        if(scanf("%f",&num)==1)
        {
            if(num<=maximo && num>=minimo)
            {
                *pResultado = num;
                resultadoScanF=1;
            }
            else
            {
                printf(mensajeError);
            }
        }
        else
        {
            fflush(stdin);
            printf(mensajeError);
        }
    }
    while(resultadoScanF!=1);
}

int menu(float km, float aerolineas, float latam)
{
    int opcion;

    printf("\n\n\n***Menu de opciones***\n\n\n");
    printf("1. Ingresar kilometros:(km=%.2f)\n\n", km);
    printf("2. Ingresar Precio de Vuelos:(Aerolineas= $%.2f, Latam= $%.2f)\n\n", aerolineas, latam);
    printf("3. Calcular todos los costos\n\n");
    printf("4. Informar Resultados\n\n");
    printf("5. Carga forzada de datos\n\n");
    printf("6. Salir\n\n");
    utn_getNumeroInt(&opcion,"Ingrese opcion: ","Error\n",1,6);

    return opcion;
}

void ingresarKM(int* pFlag, float* pKM)
{
    utn_getNumeroFloat(* &pKM, "Ingrese los kilometros: ", "Error\n", 100, 20000);
    *pFlag=1;
}

void ingresarPrecioVuelos(int* pFlag, float* pAerolineas, float* pLatam)
{
    utn_getNumeroFloat(* &pAerolineas, "Ingrese el precio del vuelo para Aerolineas: ", "Error\n", 10000, 2000000);
    utn_getNumeroFloat(* &pLatam, "Ingrese el precio del vuelo para Latam: ", "Error\n", 10000, 2000000);
    *pFlag=1;
}

void calcularCostos(int* pFlag, float* pKM, float* pAerolineas, float* pLatam, float* pAerolineasDebito, float* pAerolineasCredito, float* pAerolineasBitcoin, float* pAerolineasPrecioUnitario, float* pLatamDebito, float* pLatamCredito, float* pLatamBitcoin, float* pLatamPrecioUnitario, float* pDiferenciaPrecio)
{
    *pAerolineasDebito=calcularDebito(*pAerolineas);
    *pAerolineasCredito=calcularCredito(*pAerolineas);
    *pAerolineasBitcoin=calcularBitcoin(*pAerolineas);
    *pAerolineasPrecioUnitario=calcularPrecioUnitario(*pAerolineas, *pKM);
    *pLatamDebito=calcularDebito(*pLatam);
    *pLatamCredito=calcularCredito(*pLatam);
    *pLatamBitcoin=calcularBitcoin(*pLatam);
    *pLatamPrecioUnitario=calcularPrecioUnitario(*pLatam, *pKM);
    *pDiferenciaPrecio=calcularDiferenciaPrecio(*pAerolineas, *pLatam);
    *pFlag=1;
}

float calcularDebito(float precio)
{
    return precio*0.9;
}

float calcularCredito(float precio)
{
    return precio*1.25;
}

float calcularBitcoin(float precio)
{
    return precio/4606954.55;
}

float calcularPrecioUnitario(float precio, float km)
{
    return precio/km;
}

float calcularDiferenciaPrecio(float precioA, float precioL)
{
    float diferencia=precioL-precioA;
    if(diferencia<0)
    {
        return diferencia*-1;
    }
    else
    {
        return diferencia;
    }
}

void informarResultados(int* pFlag1, int* pFlag2, int* pFlag3, float* pKM, float* pAerolineas, float* pLatam, float aerolineasDebito, float aerolineasCredito, float aerolineasBitcoin, float aerolineasPrecioUnitario, float latamDebito, float latamCredito, float latamBitcoin, float latamPrecioUnitario, float diferenciaPrecio)
{
    printf(" KMs ingresados: %.2f km\n\n", *pKM);
    printf(" Precio Latam: $%.2f\n", *pLatam);
    printf(" a) Precio con tarjeta de debito: $%.2f\n", latamDebito);
    printf(" b) Precio con tarjeta de credito: $%.2f\n", latamCredito);
    printf(" c) Precio pagando con bitcoin: %.2f BTC\n", latamBitcoin);
    printf(" d) Precio unitario: $%.2f\n\n", latamPrecioUnitario);
    printf(" Precio Aerolineas: $%.2f\n", *pAerolineas);
    printf(" a) Precio con tarjeta de debito: $%.2f\n", aerolineasDebito);
    printf(" b) Precio con tarjeta de credito: $%.2f\n", aerolineasCredito);
    printf(" c) Precio pagando con bitcoin: %.2f BTC\n", aerolineasBitcoin);
    printf(" d) Precio unitario: $%.2f\n\n", aerolineasPrecioUnitario);
    printf(" La diferencia de precio es: $%.2f\n\n\n", diferenciaPrecio);
    *pFlag1=0;
    *pFlag2=0;
    *pFlag3=0;
    *pKM=0;
    *pLatam=0;
    *pAerolineas=0;
}



