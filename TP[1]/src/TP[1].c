#include <stdio.h>
#include <stdlib.h>
#include "TP[1].h"

int main(void) {
	setbuf(stdout, NULL);

	float km=0;
	float aerolineas=0;
	float latam=0;
	float aerolineasDebito;
	float aerolineasCredito;
	float aerolineasBitcoin;
	float aerolineasPrecioUnitario;
	float latamDebito;
	float latamCredito;
	float latamBitcoin;
	float latamPrecioUnitario;
	float diferenciaPrecio;
	int salir=0;
	int flagKM=0;
	int flagIngresarVuelos=0;
	int flagCalcularCostos=0;

	do
	{
		switch(menu(km, aerolineas, latam))
		{
			case 1:
				ingresarKM(&flagKM, &km);
				break;
			case 2:
				ingresarPrecioVuelos(&flagIngresarVuelos, &aerolineas, &latam);
				break;
			case 3:
				if(flagIngresarVuelos && flagKM)
				{
					calcularCostos(&flagCalcularCostos, &km, &aerolineas, &latam, &aerolineasDebito, &aerolineasCredito, &aerolineasBitcoin, &aerolineasPrecioUnitario, &latamDebito, &latamCredito, &latamBitcoin, &latamPrecioUnitario, &diferenciaPrecio);
				}
				else if(!flagKM)
				{
					printf("Error, primero debe ingresar los kilometros\n");
				}
				else if(!flagIngresarVuelos)
				{
					printf("Error, primero debe ingresar el precio de los vuelos\n");
				}
				else
				{
					printf("Error, primero debe ingresar tanto los kilometros como el precio de los vuelos\n");
				}
				break;
			case 4:
				if(flagCalcularCostos)
				{
					informarResultados(&flagKM, &flagIngresarVuelos, &flagCalcularCostos, &km, &aerolineas, &latam, aerolineasDebito, aerolineasCredito, aerolineasBitcoin, aerolineasPrecioUnitario, latamDebito, latamCredito, latamBitcoin, latamPrecioUnitario, diferenciaPrecio);
				}
				else
				{
					printf("Error, primero debe calcular los costos\n");
				}
				break;
			case 5:
				km=7090;
				aerolineas=162965;
				latam=159339;
				calcularCostos(&flagCalcularCostos, &km, &aerolineas, &latam, &aerolineasDebito, &aerolineasCredito, &aerolineasBitcoin, &aerolineasPrecioUnitario, &latamDebito, &latamCredito, &latamBitcoin, &latamPrecioUnitario, &diferenciaPrecio);
				informarResultados(&flagKM, &flagIngresarVuelos, &flagCalcularCostos, &km, &aerolineas, &latam, aerolineasDebito, aerolineasCredito, aerolineasBitcoin, aerolineasPrecioUnitario, latamDebito, latamCredito, latamBitcoin, latamPrecioUnitario, diferenciaPrecio);
				break;
			case 6:
				salir=1;
				break;
		}
	  system("pause");
	}
	while(salir!=1);

	return EXIT_SUCCESS;
}
