#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* this)
{

    char buffer[4][30];
    int cant = 0;
    int validation = 0;
    Employee* emp;

    if(pFile != NULL && this != NULL)
    {
        while(!feof(pFile)){
            cant =  fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            emp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
            if(emp != NULL && validarEmpleado(emp)){

                ll_add(this,emp);
                validation = 1;
            }
            if(cant < 4){
                if(feof(pFile)){

                    break;
                }else{

                    validation = 0;
                    break;
                }
            }
        }
    }

    return validation;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* this)
{

    int validation = 0;
    int cant = 0;
    Employee* emp;

    if(pFile!=NULL && this!= NULL){

        while(!feof(pFile)){

            emp = employee_new();
            cant = fread(emp, sizeof(Employee), 1, pFile);

            if(emp!=NULL){

                if(validarEmpleado(emp) == 1){

                    ll_add(this,emp);
                    validation = 1;
                }else{

                    employee_delete(emp);
                }
            }

            if(cant < 1){

                if(feof(pFile)){

                    break;
                }else{

                    validation = 0;
                    break;
                }
            }
        }
    }

    return validation;
}
