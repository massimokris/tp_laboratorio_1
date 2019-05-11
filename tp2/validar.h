
/** \brief funcion para pedir un entero
 *
 * \param mensaje que muestra al pedir
 * \param mensaje de error
 * \param puntero al numero que desea darle valor
 * \param valor minimo del entero a ingresar
 * \param valor maximo del entero a ingresar
 * \return valor del entero
 *
 */
int getInt (char* mes, char* emes, int *num, int min, int max);


/** \brief funcion para validar un entero en un rango
 *
 * \param cadena a validar y pasar a entero
 * \param puntero al numero que desea darle valor
 * \param valor minimo del entero a ingresar
 * \param valor maximo del entero a ingresar
 * \return
 *
 */
int validarInt (char* cad, int* num, int min, int max);


/** \brief funcion para pedir un float
 *
 * \param mensaje que muestra al pedir
 * \param mensaje de error
 * \param puntero al numero que desea darle valor
 * \param valor minimo del entero a ingresar
 * \param valor maximo del entero a ingresar
 * \return validacion si se puso cambiar
 *
 */
int getFloat(float* input,char mes[],char emes[], int min, int max);


/** \brief funcion para validar un float
 *
 * \param cadena a validar y pasar a float
 * \param valor minimo del entero a ingresar
 * \param valor maximo del entero a ingresar
 * \return validacion si lo pudo pasar o no
 *
 */
int validarFloat(char auxNum[], int min, int max);
