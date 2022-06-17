#include "Passenger.h"
#include "../inc/LinkedList.h"

#ifndef FUNCIONESEXTRA_H_
#define FUNCIONESEXTRA_H_



#endif /* FUNCIONESEXTRA_H_ */


/** \brief Recibe una descripcion de tipo de pasajero y segun su contenido se devuelve la id correspondiente
 *
 * \param id int* id a cargar segun el contenido de la descripcion
 * \param desc char* descripcion de tipo de pasajero
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int cargarIdTipoPasajero(int* id, char* desc);

/** \brief Recibe una descripcion de estado de vuelo y segun su contenido se devuelve la id correspondiente
 *
 * \param id int* id a cargar segun el contenido de la descripcion
 * \param desc char* descripcion de estado de vuelo
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int cargarIdEstadoVuelo(int* id, char* desc);

/** \brief Recibe un pasajero y segun su id de tipo de pasajero carga el contenido correspondiente en la descripcion
 *
 * \param p Passenger* pasajero
 * \param desc char* descripcion a cargar segun id de tipo del pasajero
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int cargarDescTipoPasajero(Passenger* p, char* desc);

/** \brief Recibe un pasajero y segun su id de estado de vuelo carga el contenido correspondiente en la descripcion
 *
 * \param p Passenger* pasajero
 * \param desc char* descripcion a cargar segun id de estado del vuelo del pasajero
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int cargarDescEstadoVuelo(Passenger* p, char* desc);

/** \brief Recibe un pasajero y lo muestra por pantalla
 *
 * \param p Passenger* pasajero
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int mostrarPasajero(Passenger* p);

/** \brief Recibe una lista de pasajeros y la muestra por pantalla
 *
 * \param lista LinkedList* lista de pasajeros
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int mostrarPasajeros(LinkedList* lista);

/** \brief Recibe una lista de pasajeros y carga el id que le corresponderia al proximo pasajero de esa lista en una variable
 *
 * \param lista LinkedList* lista de pasajeros
 * \param pProxId int* id que le corresponderia al proximo pasajero que se agregue a la lista
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int buscarMayorId(LinkedList* lista, int* pProxId);

