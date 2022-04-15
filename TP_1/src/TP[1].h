#ifndef TP_1__H_
#define TP_1__H_



#endif /* TP_1__H_ */

/** \brief permite al usuario ingresar un numero entero, valida que sea un numero y que se encuentre entre el maximo y el minimo
 *
 * \param pResultado int* es donde se guarda el numero ingresado
 * \param mensaje char* es el mensaje que pide el ingreso del numero
 * \param mensajeError char* es el mensaje que indica al usuario que hubo un error al ingresar el dato
 * \param minimo int es el valor minimo que se le deja ingresar al usuario
 * \param maximo int es el valor maximo que se le deja ingresar al usuario
 * \return void
 *
 */
void utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/** \brief permite al usuario ingresar un numero con decimales, valida que sea un numero y que se encuentre entre el maximo y el minimo
 *
 * \param pResultado float* es donde se guarda el numero ingresado
 * \param mensaje char* es el mensaje que pide el ingreso del numero
 * \param mensajeError char* es el mensaje que indica al usuario que hubo un error al ingresar el dato
 * \param minimo int es el valor minimo que se le deja ingresar al usuario
 * \param maximo int es el valor maximo que se le deja ingresar al usuario
 * \return void
 *
 */
void utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/** \brief despliega el menu de opciones y devuelve la opcion elegida por el usuario
 *
 * \param km float es el valor de los kilometros
 * \param aerolineas float es el valor del precio del viaje en Aerolineas Argentinas
 * \param latam float es el valor del precio del viaje en Latam
 * \return int devuelve la opcion elegida por el usuario
 *
 */
int menu(float km, float aerolineas, float latam);

/** \brief perimite al usuario ingresar los kilometros
 *
 * \param pFlag int* es la bandera que indica si el usuario cargo los kilometros
 * \param pKM float* es donde se guarda el dato de los kilometros
 * \return void
 *
 */
void ingresarKM(int* pFlag, float* pKM);

/** \brief permite al usuario ingresar el precio del vuelo via Aerolineas y via Latam
 *
 * \param pFlag int* es la bandera que indica si el usuario cargo los precios
 * \param pAerolineas float* es donde se guarda el precio del vuelo via Aerolineas
 * \param pLatam float* es donde se guarda el precio del vuelo via Latam
 * \return void
 *
 */
void ingresarPrecioVuelos(int* pFlag, float* pAerolineas, float* pLatam);

/** \brief calcula los costos de los vuelos en sus diferentes formas de pago
 *
 * \param pFlag int* es la bandera que indica si se calcularon los costos
 * \param pKM float* es el valor de los kilometros
 * \param pAerolineas float* es el precio del vuelo via Aerolineas
 * \param pLatam float* es el precio del vuelo via Latam
 * \param pAerolineasDebito float* es el precio del vuelo via Aerolineas si se paga con tarjeta de debito
 * \param pAerolineasCredito float* es el precio del vuelo via Aerolineas si se paga con tarjeta de credito
 * \param pAerolineasBitcoin float* es el precio del vuelo via Aerolineas si se paga con Bitcoin
 * \param pAerolineasPrecioUnitario float* es el precio por km via Aerolineas
 * \param pLatamDebito float* es el precio del vuelo via Latam si se paga con tarjeta de debito
 * \param pLatamCredito float* es el precio del vuelo via Latam si se paga con tarjeta de credito
 * \param pLatamBitcoin float* es el precio del vuelo via Latam si se paga con Bitcoin
 * \param pLatamPrecioUnitario float* es el precio por km via Latam
 * \param pDiferenciaPrecio float* es la diferencia de precio entre Latam y Aerolineas
 * \return void
 *
 */
void calcularCostos(int* pFlag, float* pKM, float* pAerolineas, float* pLatam, float* pAerolineasDebito, float* pAerolineasCredito, float* pAerolineasBitcoin, float* pAerolineasPrecioUnitario, float* pLatamDebito, float* pLatamCredito, float* pLatamBitcoin, float* pLatamPrecioUnitario, float* pDiferenciaPrecio);

/** \brief calcula el precio si se paga con tarjeta de debito
 *
 * \param precio float precio original
 * \return float devuelve el precio si se paga con debito
 *
 */
float calcularDebito(float precio);

/** \brief calcula el precio si se paga con tarjeta de credito
 *
 * \param precio float precio original
 * \return float devuelve el precio si se paga con credito
 *
 */
float calcularCredito(float precio);

/** \brief calcula el precio si se paga con Bitcoin
 *
 * \param precio float precio original
 * \return float devuelve el precio si se paga con Bitcoin
 *
 */
float calcularBitcoin(float precio);

/** \brief calcula el precio por km
 *
 * \param precio float precio original
 * \param km float kilometros ingresados
 * \return float devuelve el precio por km
 *
 */
float calcularPrecioUnitario(float precio, float km);

/** \brief calcula la diferencia de precio entre Aerolineas y Latam
 *
 * \param precioA float precio de Aerolineas
 * \param precioL float precio de Latam
 * \return float devuelve la diferencia de precio entre Aerolineas y Latam
 *
 */
float calcularDiferenciaPrecio(float precioA, float precioL);

/** \brief informa los resultados del calculo de costos
 *
 * \param pFlag1 int* bandera que indica si se ingresaron los km
 * \param pFlag2 int* bandera que indica si se ingresaron los precios
 * \param pFlag3 int* bandera que indica si se calcularon los costos
 * \param pKM float* es el valor de los kilometros ingresados
 * \param pAerolineas float* es el precio del vuelo via Aerolineas
 * \param pLatam float* es el precio del vuelo via Latam
 * \param aerolineasDebito float es el precio del vuelo via Aerolineas si se paga con tarjeta de debito
 * \param aerolineasCredito float es el precio del vuelo via Aerolineas si se paga con tarjeta de credito
 * \param aerolineasBitcoin float es el precio del vuelo via Aerolineas si se paga con Bitcoin
 * \param aerolineasPrecioUnitario float es el precio por km via Aerolineas
 * \param latamDebito float es el precio del vuelo via Latam si se paga con tarjeta de debito
 * \param latamCredito float es el precio del vuelo via Latam si se paga con tarjeta de credito
 * \param latamBitcoin float es el precio del vuelo via Latam si se paga con Bitcoin
 * \param latamPrecioUnitario float es el precio por km via Latam
 * \param diferenciaPrecio float es la diferencia de precio entre Latam y Aerolineas
 * \return void
 *
 */
void informarResultados(int* pFlag1, int* pFlag2, int* pFlag3, float* pKM, float* pAerolineas, float* pLatam, float aerolineasDebito, float aerolineasCredito, float aerolineasBitcoin, float aerolineasPrecioUnitario, float latamDebito, float latamCredito, float latamBitcoin, float latamPrecioUnitario, float diferenciaPrecio);

