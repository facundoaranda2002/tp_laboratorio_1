/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);

/** \brief Carga los datos de los pasajeros desde el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);

/** \brief Alta de pasajero
 *
 * \param pArrayListPassenger LinkedList*
 * \param proxId int
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int proxId);

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger, int proxId);

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger, int proxId);

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);

/** \brief Guarda los datos de los pasajeros en el archivo datos.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


