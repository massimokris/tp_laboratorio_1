#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* this)
{
    FILE* f;
    int validation = 0;

    if(path != NULL && this != NULL){

        f=fopen(path, "r");

        if(f != NULL){

            parser_EmployeeFromText(f, this);

            fclose(f);

            validation = 1;
        }else{

            validation = 0;
        }
    }

    return validation;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* this)
{
    FILE* f;
    int validation = 0;

    if(path != NULL && this != NULL){

        f=fopen(path, "rb");

        if(f != NULL){

            parser_EmployeeFromBinary(f, this);

            fclose(f);

            validation = 1;
        }else{

            validation = 0;
        }
    }

    return validation;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* this)
{

    int validation = 0;
    int id;
    int sueldo;
    int horas;
    char auxNombre[100] = "";
    Employee* emp = employee_new();

    if(randomId(this) != -1){

        id = randomId(this);
        validation = 1;
    }

    system("cls");
    printf("Ingrese nombre: \n");
    fflush(stdin);
    gets(auxNombre);

    if(auxNombre == NULL || validation == 0){

        validation = 0;
    }

    system("cls");
    printf("Ingrese sueldo: \n");
    scanf("%d", &sueldo);

    system("cls");
    printf("Ingrese horas trabajadas: \n");
    scanf("%d", &horas);

    if(validation){

        if(employee_setId(emp, id) &&
           employee_setNombre(emp, auxNombre) &&
           employee_setHorasTrabajadas(emp, horas) &&
           employee_setSueldo(emp, sueldo)){

                if(ll_add(this, emp) == 0){

                    validation = 1;
                }
           }

    }

    return validation;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* this)
{

    int validation = 0;
    int auxInt;
    int flag = 0;
    char auxString[128];
    char respuesta = ' ';

    if(this != NULL){
        system("cls");
        printf("Ingrese id del empleado a modificar: \n");
        scanf("%d", &auxInt);

        for(int i = 0; i < ll_len(this); i++){

            if(((Employee*) ll_get(this, i))->id == auxInt){

                flag = 1;
                system("cls");
                mostrarEmpleado((Employee*) ll_get(this, i));

                printf("Desea modificar este empleado? (s/n)\n");
                fflush(stdin);
                scanf("%c", &respuesta);

                if(respuesta == 's'){

                    system("cls");
                    printf("Que desea modificar?\n\n");
                    printf("1- Nombre\n");
                    printf("2- Sueldo\n");
                    printf("3- Horas trabajadas\n");

                    printf("\nIngrese un opcion: \n");
                    scanf("%d", &auxInt);

                    switch(auxInt){

                    case 1:

                        system("cls");
                        printf("Ingrese nuevo nombre\n");
                        fflush(stdin);
                        scanf("%s", auxString);
                        if(employee_setNombre(((Employee*) ll_get(this, i)), auxString)){

                            validation = 1;
                        }
                        break;
                    case 2:

                        system("cls");
                        printf("Ingrese nuevo sueldo\n");
                        scanf("%d", &auxInt);
                        if(employee_setSueldo(((Employee*) ll_get(this, i)), auxInt)){

                            validation = 1;
                        }
                        break;
                    case 3:

                        system("cls");
                        printf("Ingrese nuevas horas trabajadas\n");
                        scanf("%d", &auxInt);
                        if(employee_setHorasTrabajadas(((Employee*) ll_get(this, i)), auxInt)){

                            validation = 1;
                        }
                        break;
                    default:
                        printf("Opcion no valida\n");
                        break;
                    }
                }else{

                    validation = 0;
                    break;
                }
            }
        }

        if(!flag){

            system("cls");
            printf("El empleado no existe\n");
            system("pause");
        }
    }

    return validation;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* this)
{
    int validation = 0;
    int auxInt;
    int flag = 0;
    char respuesta = ' ';

    if(this != NULL){
        system("cls");
        printf("Ingrese id del empleado a eliminar: \n");
        scanf("%d", &auxInt);

        for(int i = 0; i < ll_len(this); i++){

            if(((Employee*) ll_get(this, i))->id == auxInt){

                flag = 1;
                system("cls");
                mostrarEmpleado((Employee*) ll_get(this, i));

                printf("Desea eliminar este empleado? (s/n)\n");
                fflush(stdin);
                scanf("%c", &respuesta);

                if(respuesta == 's'){

                    if(ll_remove(this, i) == 0){

                        validation = 1;
                    }else{

                        validation = 0;
                    }
                }else{

                    validation = 0;
                    break;
                }
            }
        }

        if(!flag){

            system("cls");
            printf("El empleado no existe\n");
            system("pause");
        }
    }

    return validation;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* this)
{
    if(this != NULL){
        system("cls");
        for(int i = 0; i < ll_len(this); i++){

            mostrarEmpleado(((Employee*) ll_get(this, i)));
        }
        system("pause");
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* this)
{
    int auxInt;
    int validation = 0;

    if(this != NULL){

        system("cls");
        printf("Como desea ordenar los empleados?\n");
        printf("1- Por nombre\n");
        printf("2- Por Id\n");
        printf("3- Por Sueldo\n");
        printf("4- Por horas trabajadas\n");

        printf("Ingrese una opcion\n");
        scanf("%d", &auxInt);

        switch(auxInt){

        case 1:
            system("cls");
            printf("1- [A - Z]\n");
            printf("2- [Z - A]\n");
            printf("Ingrese una opcion\n");
            scanf("%d", &auxInt);

            if(auxInt == 1){

                if(ll_sort(this, ordenarPorNombre, 1) == 0){

                    validation = 1;
                }
            }else if(auxInt == 2){

                if(ll_sort(this, ordenarPorNombre, 0) == 0){

                    validation = 1;
                }
            }else{

                system("cls");
                printf("Opcion no valida\n");
                system("pause");
                validation = 0;
            }
            break;
        case 2:
            system("cls");
            printf("1- [Mayor - Menor]\n");
            printf("2- [Menor - Mayor]\n");
            printf("Ingrese una opcion\n");
            scanf("%d", &auxInt);

            if(auxInt == 1){

                if(ll_sort(this, ordenarPorId, 0) == 0){

                    validation = 1;
                }
            }else if(auxInt == 2){

                if(ll_sort(this, ordenarPorId, 1) == 0){

                    validation = 1;
                }
            }else{

                system("cls");
                printf("Opcion no valida\n");
                system("pause");
                validation = 0;
            }
            break;
        case 3:
            system("cls");
            printf("1- [Mayor - Menor]\n");
            printf("2- [Menor - Mayor]\n");
            printf("Ingrese una opcion\n");
            scanf("%d", &auxInt);

            if(auxInt == 1){

                if(ll_sort(this, ordenarPorSueldo, 0) == 0){

                    validation = 1;
                }
            }else if(auxInt == 2){

                if(ll_sort(this, ordenarPorSueldo, 1) == 0){

                    validation = 1;
                }
            }else{

                system("cls");
                printf("Opcion no valida\n");
                system("pause");
                validation = 0;
            }
            break;
        case 4:
            system("cls");
            printf("1- [Mayor - Menor]\n");
            printf("2- [Menor - Mayor]\n");
            printf("Ingrese una opcion\n");
            scanf("%d", &auxInt);

            if(auxInt == 1){

                if(ll_sort(this, ordenarPorHoras, 0) == 0){

                    validation = 1;
                }
            }else if(auxInt == 2){

                if(ll_sort(this, ordenarPorHoras, 1) == 0){

                    validation = 1;
                }
            }else{

                system("cls");
                printf("Opcion no valida\n");
                system("pause");
                validation = 0;
            }
            break;
        default:
            system("cls");
            printf("Opcion no valida\n");
            system("pause");
            validation = 0;
            break;
        }
    }

    return validation;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* this)
{
    FILE* f;
    Employee* emp;
    int cont;
    int size;
    int id;
    int sueldo;
    int horas;
    int validation = 1;
    char nombre[128];

    if(path != NULL && this != NULL){

        size = ll_len(this);
        f = fopen(path,"w");

        if(f != NULL){
            for(int i = 0; i < size; i++){

                emp = (Employee*) ll_get(this,i);

                employee_getId(emp, &id);
                employee_getNombre(emp, nombre);
                employee_getHorasTrabajadas(emp, &horas);
                employee_getSueldo(emp, &sueldo);

                fprintf(f,"%d,%s,%d,%d\n", id, nombre, horas, sueldo);
                cont++;
            }

            fclose(f);

            if(cont == size){

                validation = 1;
            }

        }else{

            validation = 0;
        }

    }

    return validation;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param this LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* this)
{
    FILE* f;
    Employee* emp;
    int validation = 1;
    int cont;
    int size = ll_len(this);

    if(path != NULL && this!= NULL){

        f = fopen(path, "wb");

        if(f != NULL){

            for(int i = 0; i < size; i++){

                emp = ll_get(this, i);

                if(emp != NULL){

                    fwrite(emp,sizeof(Employee),1,f);
                    cont++;
                }

                if(cont == size){

                    validation = 1;
                    fclose(f);
                }else{

                    validation = 0;
                }
            }
        }
    }

    return validation;
}

