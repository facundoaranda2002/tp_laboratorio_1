/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);


/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger);

