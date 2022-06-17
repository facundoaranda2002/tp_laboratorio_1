/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoVuelo;

}Passenger;

/** \brief Reserva el espacio en memoria dinamica para un nuevo pasajero
 *
 * \return Passenger* retorna al nuevo pasajero o NULL en caso de error
 *
 */
Passenger* Passenger_new();

/** \brief Utiliza los setters para cargar la informacion recibida en un nuevo pasajero
 *
 * \param id int
 * \param nombre char*
 * \param apellido char*
 * \param precio float
 * \param codigoVuelo char*
 * \param tipoPasajero int
 * \param estadoVuelo int
 * \return Passenger* retorna al nuevo pasajero o NULL en caso de error
 *
 */
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido,float precio, char* codigoVuelo, int tipoPasajero,int estadoVuelo);

/** \brief Utiliza los setters para cargar la informacion recibida en cadena de caracteres en un nuevo pasajero
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param apellidoStr char*
 * \param precioStr char*
 * \param codigoVueloStr char*
 * \param tipoPasajeroStr char*
 * \param estadoVueloStr char*
 * \return Passenger* retorna al nuevo pasajero o NULL en caso de error
 *
 */
Passenger* Passenger_newParametrosString(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr,char* estadoVueloStr);

/** \brief Libera el espacio de memoria asignado a un pasajero
 *
 * \param p Passenger* pasajero a eliminar
 * \return void
 *
 */
void Passenger_delete(Passenger* p);

/** \brief Asigna un valor de id al pasajero en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param id int
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_setId(Passenger* p,int id);

/** \brief Asigna un valor de id de un pasajero a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param id int*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_getId(Passenger* p, int *id);

/** \brief Asigna un valor de nombre al pasajero en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param nombre char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_setNombre(Passenger* p,char* nombre);

/** \brief Asigna un valor de nombre de un pasajero a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param nombre char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_getNombre(Passenger* p,char* nombre);

/** \brief Asigna un valor de apellido al pasajero en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param apellido char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_setApellido(Passenger* p,char* apellido);
/** \brief Asigna un valor de apellido de un pasajero a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param apellido char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_getApellido(Passenger* p,char* apellido);

/** \brief Asigna un valor de codigo de vuelo al pasajero en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param codigoVuelo char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_setCodigoVuelo(Passenger* p,char* codigoVuelo);

/** \brief Asigna un valor de codigo de vuelo de un pasajero a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param codigoVuelo char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_getCodigoVuelo(Passenger* p,char* codigoVuelo);

/** \brief Asigna un valor de tipo de pasajero al pasajero en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param tipoPasajero int
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_setTipoPasajero(Passenger* p,int tipoPasajero);

/** \brief Asigna un valor de tipo de pasajero de un pasajero a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param tipoPasajero int*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_getTipoPasajero(Passenger* p,int* tipoPasajero);

/** \brief Asigna un valor de precio del vuelo al pasajero en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param precio float
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_setPrecio(Passenger* p,float precio);

/** \brief Asigna un valor de precio del vuelo de un pasajero a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param precio float*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_getPrecio(Passenger* p,float* precio);

/** \brief Asigna un valor de estado del vuelo al pasajero en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param estadoVuelo int
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_setEstadoVuelo(Passenger* p,int estadoVuelo);

/** \brief Asigna un valor de estado del vuelo de un pasajero a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param p Passenger* pasajero
 * \param estadoVuelo int*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Passenger_getEstadoVuelo(Passenger* p,int* estadoVuelo);

/** \brief Compara a 2 pasajeros por id
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int 1 si el id del pasajero A es mayor al del pasajero B, -1 en caso contrario y 0 si son iguales o hubo algun error
 *
 */
int pasajeroSortId(void* a, void* b);

/** \brief Compara a 2 pasajeros por nombre
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int 1 si el nombre del pasajero A es mayor al del pasajero B, -1 en caso contrario y 0 si son iguales o hubo algun error
 *
 */
int pasajeroSortNombre(void* a, void* b);

/** \brief Compara a 2 pasajeros por apellido
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int 1 si el apellido del pasajero A es mayor al del pasajero B, -1 en caso contrario y 0 si son iguales o hubo algun error
 *
 */
int pasajeroSortApellido(void* a, void* b);

/** \brief Compara a 2 pasajeros por precio de su vuelo
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int 1 si el precio del vuelo del pasajero A es mayor al del pasajero B, -1 en caso contrario y 0 si son iguales o hubo algun error
 *
 */
int pasajeroSortPrecio(void* a, void* b);

/** \brief Compara a 2 pasajeros por codigo de vuelo
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int 1 si el codigo de vuelo del pasajero A es mayor al del pasajero B, -1 en caso contrario y 0 si son iguales o hubo algun error
 *
 */
int pasajeroSortCodigoVuelo(void* a, void* b);

/** \brief Compara a 2 pasajeros por tipo de pasajero
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int 1 si el tipo del pasajero A es mayor al del pasajero B, -1 en caso contrario y 0 si son iguales o hubo algun error
 *
 */
int pasajeroSortTipoPasajero(void* a, void* b);

/** \brief Compara a 2 pasajeros por estado de su vuelo
 *
 * \param a void* pasajero A
 * \param b void* pasajero B
 * \return int 1 si el estado del vuelo del pasajero A es mayor al del pasajero B, -1 en caso contrario y 0 si son iguales o hubo algun error
 *
 */
int pasajeroSortEstadoVuelo(void* a, void* b);

#endif /* PASSENGER_H_ */
