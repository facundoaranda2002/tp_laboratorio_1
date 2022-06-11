#include "flycode.h"

#ifndef ARRAYPASSENGER_H_INCLUDED
#define ARRAYPASSENGER_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int isEmpty;
}
ePassenger;

#endif // ARRAYPASSENGER_H_INCLUDED

/** \brief muestra el menu de opciones principal y devuelve la opcion elegida
 *
 * \return int devuelve la opcion elegida
 *
 */
int menu();

/** \brief Para indicar que todas las posiciones del array estan vacas, esta funcion pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.
* \param vec ePassenger[] Array de pasajeros
* \param tam int Tamanio del array
* \return int Retorna (-1) Si hay Error [Tamanio invalido o puntero nulo] - (0) si esta Ok
*
*/
int inicializarPasajeros(ePassenger vec[], int tam);

/** \brief busca una posicion libre en el vector de pasajeros y la devuelve
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio del array de pasajeros
 * \param pIndex int* direccion de memoria donde se guarda la ubicacion del primer indice libre del array
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int buscarPasajeroLibre(ePassenger vec[], int tam, int* pIndex);

/** \brief realiza el alta de un pasajero
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio del array de pasajeros
 * \param vuelos[] eFlycode array de vuelos
 * \param tamVuelos int tamanio del array de vuelos
 * \param pId int* direccion de memoria que guarda el id asignado automaticamente al nuevo pasajero
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int altaPasajero(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos, int* pId);

/** \brief aniade a un pasajero al array
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio del array de pasajeros
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param price float
 * \param typePassenger int
 * \param flycode[] char
 * \return int retorna 0 si los parametros son validos o -1 si alguno es invalido o no hay lugar en el array
 *
 */
int addPassenger(ePassenger vec[], int tam, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);

/** \brief permite al usuario ingresar un id de tipo de pasajero y lo valida
 *
 * \param pId int* id a validar
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getTypePassenger(int *pId);

/** \brief permite al usuario ingresar un id de tipo de pasajero a modificar y lo valida
 *
 * \param pId int* id a validar
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getTypePassengerMod(int *pId);

/** \brief muestra el contenido del array de pasajeros
*
* \param vec[] ePassenger array de pasajeros
* \param tam int tamanio array de pasajeros
* \param vuelos[] eFlycode array de vuelos
* \param tamVuelos int tamanio del array de vuelos
* \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
*
*/
int printPassenger(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos);

/** \brief carga la descripcion del tipo de pasajero correspondiente al id recibido
 *
 * \param id int id recibido
 * \param desc[] char direccion de memoria donde se guardara la descripcion del tipo de pasajero
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int cargarDescripcionTipoPasajero(int id, char desc[]);

/** \brief hardcodea una cantidad de pasajeros en la lista
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio del array de pasajeros
 * \param cant int cantidad de pasajeros a hardcodear
 * \param pId int* direccion de memoria que guarda el id asignado automaticamente al nuevo pasajero
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int hardcodearPasajeros(ePassenger vec[], int tam, int cant, int* pId);

/** \brief modifica ciertos apartados de un pasajero previamente ingresado
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \param vuelos[] eFlycode array de vuelos
 * \param tamVuelos int tamanio del array de vuelos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int modificarPasajero(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param vec[] ePassenger array de pasajeros
* \param tam int tamanio array de pasajeros
* \param id int id a buscar
* \return retorna la posicion del pasajero en el array o -1 si hubo algun error o no se encontro al pasajero
*
*/
int findPassengerById(ePassenger vec[], int tam, int id);

/** \brief muestra el menu de opciones para modificar al pasajero y devuelve la opcion ingresada
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuModificarPasajero();

/** \brief realiza la baja de un pasajero del array
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \param vuelos[] eFlycode array de vuelos
 * \param tamVuelos int tamanio del array de vuelos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int bajaPasajero(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos);

/** \brief Remuve un Pasajero por Id (pone su isEmpty Flag en 1)
*
* \param vec[] ePassenger array de pasajeros
* \param tam int tamanio array de pasajeros
* \param vuelos[] eFlycode array de vuelos
* \param tamVuelos int tamanio del array de vuelos
* \param id int id del pasajero a remover
* \return retorna la posicion del pasajero en el array o -1 si hubo algun error o no se encontro al pasajero o se cancelo la baja
*
*/
int removePassenger(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos, int id);

/** \brief despliega el menu de los informes
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \param vuelos[] eFlycode array de vuelos
 * \param tamVuelos int tamanio del array de vuelos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int menuInformes(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos);

/** \brief realiza el primer informe
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \param vuelos[] eFlycode array de vuelos
 * \param tamVuelos int tamanio del array de vuelos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int informeUno(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos);

/** \brief ordena a los pasajeros por apellido y tipo
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \param orden int criterio a ordenar 1 ascendente y 2 descendente
 * \return int retorna 0 si los parametros son validos o -1 si alguno es invalido
 *
 */
int sortPassengers(ePassenger vec[], int tam, int orden);

/** \brief realiza el segundo informe
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \param vuelos[] eFlycode array de vuelos
 * \param tamVuelos int tamanio del array de vuelos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int informeDos(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos);

/** \brief realiza el tercer informe
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \param vuelos[] eFlycode array de vuelos
 * \param tamVuelos int tamanio del array de vuelos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int informeTres(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos);

/** \brief ordena a los pasajeros por codigo de vuelo
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \param orden int criterio a ordenar 1 ascendente y 2 descendente
 * \return int retorna 0 si los parametros son validos o -1 si alguno es invalido
 *
 */
int sortPassengersByCode(ePassenger vec[], int tam, int orden);

/** \brief muestra los pasajeros del array cuyo estado de vuelo sea activo
*
* \param vec[] ePassenger array de pasajeros
* \param tam int tamanio array de pasajeros
* \param vuelos[] eFlycode array de vuelos
* \param tamVuelos int tamanio del array de vuelos
* \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
*
*/
int printPassengerActive(ePassenger vec[], int tam, eFlycode vuelos[], int tamVuelos);

/** \brief ordena a los pasajeros por id
 *
 * \param vec[] ePassenger array de pasajeros
 * \param tam int tamanio array de pasajeros
 * \return int retorna 0 si los parametros son validos o -1 si alguno es invalido
 *
 */
int sortPassengersById(ePassenger vec[], int tam);
