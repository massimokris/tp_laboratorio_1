struct{

        int id;
        char name[51];
        char lastname[51];
        float salary;
        int sector;
        int isEmpty;
}typedef eEmployee;

struct{

    int id;
    char description[30];
}typedef eSector;

/** \brief funcion para mostrar el menu del ABM
 *
 * \return un int (opcion a ejecutar del menu)
 *
 */
int menuABM (void);

/** \brief funcion para inicializar empleados
 *
 * \param list la estructura de empleados
 * \param len el tamanio del array de estructuras
 * \return int 0 para indicar que se iniciaron correctamente los empleados
 *
 */
void initEmployees (eEmployee* list, int len);

/** \brief funcion para buscar espacio libre
 *
 * \param list la estructura de empleados
 * \param len el tamanio del array de estructuras
 * \return indice libre para ingresar empleado
 *
 */
int findEmpty (eEmployee* list, int len);

/** \brief funcion de genera un numero random entro 1000 y 1999
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \return int el numero random para utilizar como id
 *
 */
int randomId(eEmployee* list, int len);

/** \brief funcion para encontrar un empleado por su id
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \return int la posicion del empleado si lo encuentra o -1 si no lo encuentra
 *
 */
int findEmployeeById (eEmployee* list, int len, int id);

/** \brief funcion para darle baja logica al empleado
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param el id del empleado para su buscarlo y darle baja logica
 * \return int -1 si no pudo dar de baja y 0 si logro dar de baja
 *
 */
int removeEmployee (eEmployee* list, int len, int id);

/** \brief funcion para agregar empleado
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \return void
 *
 */
void addEmployee (eEmployee* list, int len);

/** \brief funcion para imprimir empleado
 *
 * \param sectors la estructura de sectores
 * \param len int el tamanio del array de estructuras
 * \param la estructura de un empleado a mostrar
 * \return void
 *
 */
void printEmployee (eSector* sectors, int lenSec, eEmployee emp);

/** \brief funcion para recorrer el array de estructuras de empleado e imprimirlos
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param sectors la estructura de sectores
 * \param len int el tamanio del array de estructuras
 * \return void
 *
 */
void printEmployees (eEmployee* list, int len, eSector* sectors, int lenSec);

/** \brief funcion para encontrar si el sector solicitados esta entre los disponibles
 *
 * \param sectors la estructura de sectores
 * \param len int el tamanio del array de estructuras
 * \param id del sector a buscar
 * \param descripcion del sector
 * \return 0 si no lo encrontro y 1 si lo logro encontrar
 *
 */
int findSector (eSector* sectors, int lenSec, int idSector, char desc[]);

/** \brief funcion para ordenar empleados por orden ascendente o descendente
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param la opcion de orden que quiere hacer
 * \return void
 *
 */
void sortEmpleyees (eEmployee* list, int len, int order);

/** \brief funcion para burbujeo de estructuras
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param int del indice a cambiar
 * \param int del indice a cambiar
 * \return void
 *
 */
void bubble (eEmployee* list, int len, int i, int j);

/** \brief funcion para saber si el array esta vacio o no
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \return int -1 si no esta vacio y 0 si esta vacio
 *
 */
int isEmpty (eEmployee* list, int len);

/** \brief funcion para obtener el salario total de los empleados
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \return float el salario total de todos los empleados
 *
 */
float totalSalary (eEmployee* list, int len);

/** \brief funcion para obtener el promedio de salario de todos los empleados
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \return float el salario promedio de todos los empleados
 *
 */
float averageSalary (eEmployee* list, int len);

/** \brief funcion para obtener cuantos empleados superar el salario promedio
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \return int cantidad de empleados que superan el salario promedio
 *
 */
int higherAverage (eEmployee* list, int len);

/** \brief funcion para obtener el total de empleados activos
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \return int cantidad de empleados activos
 *
 */
int getEmployees (eEmployee* list, int len);

/** \brief funcion menu de informes de empleados
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param sectors la estructura de sectores
 * \param len int el tamanio del array de estructuras
 * \return void
 *
 */
void reports (eEmployee* list, int len, eSector* sectors, int lenSec);

/** \brief funcion de menu de cambios
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param id del empleado a cambiar
 * \return void
 *
 */
void changesMenu (eEmployee* list, int len, int id);

/** \brief funcion para cambiar nombre
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param id del empleado a cambiar
 * \return void
 *
 */
void changeName (eEmployee* list, int len, int id);

/** \brief funcion para cambiar apellido
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param id del empleado a cambiar
 * \return void
 *
 */
 void changeLastname (eEmployee* list, int len, int id);

 /** \brief funcion para cambiar salario
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param id del empleado a cambiar
 * \return void
 *
 */
 void changeSalary (eEmployee* list, int len, int id);

 /** \brief funcion para cambiar sector
 *
 * \param list eEmployee* la estructura de empleados
 * \param len int el tamanio del array de estructuras
 * \param id del empleado a cambiar
 * \return void
 *
 */
 void changeSector (eEmployee* list, int len, int id);

















