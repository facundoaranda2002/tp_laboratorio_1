#ifndef FLYCODE_H_INCLUDED
#define FLYCODE_H_INCLUDED

typedef struct
{
    char flycode[10];
    int statusFly;
}
eFlycode;

#endif // FLYCODE_H_INCLUDED

/** \brief lista los vuelos que se encuentran en el array
 *
 * \param vec[] eFlycode array de vuelos
 * \param tam int tamanio del array de vuelos
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int listarVuelos(eFlycode vec[], int tam);

/** \brief valida que el codigo de vuelo ingresado coincida con uno del array de vuelos
 *
 * \param vec[] eFlycode array de vuelos
 * \param tam int tamanio del array de vuelos
 * \param code[] char codigo a validar
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int validarVuelos(eFlycode vec[], int tam, char code[]);

/** \brief carga la descripcion del estado de vuelo correspondiente al codigo recibido
 *
 * \param vec[] eFlycode array de vuelos
 * \param tam int tamanio del array de vuelos
 * \param descripcion[] char direccion de memoria donde se guardara la descripcion del estado
 * \param code[] char codigo recibido
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int cargarDescripcionEstado(eFlycode vec[], int tam, char descripcion[], char code[]);

/** \brief permite al usuario ingresar un codigo de vuelo y lo valida
 *
 * \param vec[] eFlycode array de vuelos
 * \param tam int tamanio del array de vuelos
 * \param code[] char codigo a validar
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getFlyCode(eFlycode vec[], int tam, char code[]);

/** \brief permite al usuario ingresar un codigo de vuelo a modificar y lo valida
 *
 * \param vec[] eFlycode array de vuelos
 * \param tam int tamanio del array de vuelos
 * \param code[] char codigo a validar
 * \return int retorna 1 si los parametros son validos o 0 si alguno es invalido
 *
 */
int utn_getFlyCodeMod(eFlycode vec[], int tam, char code[]);
