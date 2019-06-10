#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int menu();


int main()
{
    char seguir = 'n';
    LinkedList* listaEmpleados = ll_newLinkedList();

//    Employee* emp1 = employee_newParametros("1234", "Juan", "234", "25000");
//    Employee* emp2 = employee_newParametros("2222", "Julia", "100", "15000");
//    Employee* emp3 = employee_newParametros("1111", "Juana", "340", "35000");
//    Employee* emp4 = employee_newParametros("4444", "Sofia", "210", "23000");
//
//    printf("Cantidad elementos: %d\n\n", ll_len(listaEmpleados));
//
//    //lo agrego y lo valido con la funcion del linked list ll_add
//    if(ll_add(listaEmpleados, emp1) == 0){
//
//            printf("se ha agredado\n\n\n");
//    }
//
//    printf("Cantidad elementos: %d\n\n", ll_len(listaEmpleados));
//
//    if(ll_add(listaEmpleados, emp2) == 0){
//
//            printf("se ha agredado\n\n\n");
//    }
//
//    printf("Cantidad elementos: %d\n\n", ll_len(listaEmpleados));
//
//    if(ll_add(listaEmpleados, emp3) == 0){
//
//            printf("se ha agredado\n\n\n");
//    }
//
//    printf("Cantidad elementos: %d\n\n", ll_len(listaEmpleados));
//
//    mostrarEmpleado(((Employee*) ll_get(listaEmpleados, 1)));
//
//    printf("Cantidad elementos: %d\n\n", ll_len(listaEmpleados));
//
//    if(ll_push(listaEmpleados, 1, emp4) == 0){
//
//            printf("se ha agredado\n\n\n");
//    }
//
//    mostrarEmpleado(((Employee*) ll_get(listaEmpleados, 1)));
//    mostrarEmpleado(((Employee*) ll_get(listaEmpleados, 2)));
//
//    printf("Cantidad elementos: %d\n\n", ll_len(listaEmpleados));
//
//    printf("----------------------------------------------------\n");
//
//    for(int i = 0; i < ll_len(listaEmpleados); i++){
//
//        mostrarEmpleado(((Employee*) ll_get(listaEmpleados, i)));
//    }
//
//    printf("ordeno la lista por sueldo\n\n");
//
//    ll_sort(listaEmpleados, ordenarPorSueldo, 0);
//
//    for(int i = 0; i < ll_len(listaEmpleados); i++){
//
//        mostrarEmpleado(((Employee*) ll_get(listaEmpleados, i)));
//    }
//
//    printf("ordeno la lista por id\n\n");
//
//    ll_sort(listaEmpleados, ordenarPorSueldo, 1);
//
//    for(int i = 0; i < ll_len(listaEmpleados); i++){
//
//        mostrarEmpleado(((Employee*) ll_get(listaEmpleados, i)));
//    }
//
//    printf("ordeno la lista por horas\n\n");
//
//    ll_sort(listaEmpleados, ordenarPorHoras, 1);
//
//    for(int i = 0; i < ll_len(listaEmpleados); i++){
//
//        mostrarEmpleado(((Employee*) ll_get(listaEmpleados, i)));
//    }

    do{
        switch(menu()){
            case 1:
                //printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
                if(controller_loadFromText("data.csv", listaEmpleados)){

                    system("cls");
                    printf("Datos cargados exitosamente!\n");
                    system("pause");
                }else{

                    system("cls");
                    printf("Datos no cargados!\n");
                    system("pause");
                }
                break;
            case 2:
                //printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
                if(controller_loadFromBinary("data.bin", listaEmpleados)){

                    system("cls");
                    printf("Datos cargados exitosamente!\n");
                    system("pause");
                }else{

                    system("cls");
                    printf("Datos no cargados!\n");
                    system("pause");
                }
                break;
            case 3:
                //printf("3. Alta de empleado\n");
                if(controller_addEmployee(listaEmpleados)){

                    system("cls");
                    printf("Alta exitosa!\n");
                    system("pause");
                }else{

                    system("cls");
                    printf("Alta no exitosa!\n");
                    system("pause");
                }
                break;
            case 4:
                //printf("4. Modificar datos de empleado\n");
                if(ll_len(listaEmpleados) > 0){
                    if(controller_editEmployee(listaEmpleados)){

                        system("cls");
                        printf("Modificacion exitosa!\n");
                        system("pause");
                    }else{

                        system("cls");
                        printf("Modificacion no exitosa!\n");
                        system("pause");
                    }
                }else{

                    system("cls");
                    printf("Aun no hay empleados para modificar\n");
                    system("pause");
                }
                break;
            case 5:
                //printf("5. Baja de empleado\n");
                if(ll_len(listaEmpleados) > 0){
                    if(controller_removeEmployee(listaEmpleados)){

                        system("cls");
                        printf("Baja exitosa!\n");
                        system("pause");
                    }else{

                        system("cls");
                        printf("Baja no exitosa!\n");
                        system("pause");
                    }
                }else{

                    system("cls");
                    printf("Aun no hay empleados para eliminar\n");
                    system("pause");
                }
                break;
            case 6:
                //printf("6. Listar empleados\n");
                if(ll_len(listaEmpleados) > 0){
                    controller_ListEmployee(listaEmpleados);
                }else{

                    system("cls");
                    printf("Aun no hay empleados para mostrar\n");
                    system("pause");
                }
                break;
            case 7:
                //printf("7. Ordenar empleados\n");
                if(ll_len(listaEmpleados) > 0){
                    if(controller_sortEmployee(listaEmpleados)){

                        system("cls");
                        printf("lista ordenada exitosamente!\n");
                        system("pause");
                    }else{

                        system("cls");
                        printf("lista no ordenada exitosamente!\n");
                        system("pause");
                    }
                }else{

                    system("cls");
                    printf("Aun no hay empleados para ordenar\n");
                    system("pause");
                }
                break;
            case 8:
                //printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
                if(ll_len(listaEmpleados) > 0){
                    if(controller_saveAsText("data.csv", listaEmpleados)){

                        system("cls");
                        printf("Datos guardados exitosamente!\n");
                        system("pause");
                    }else{

                        system("cls");
                        printf("Datos no guardados!\n");
                        system("pause");
                    }
                }else{

                    system("cls");
                    printf("Aun no hay empleados para guardar\n");
                    system("pause");
                }
                break;
            case 9:
                //printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
                if(ll_len(listaEmpleados) > 0){
                    if(controller_saveAsBinary("data.bin", listaEmpleados)){

                        system("cls");
                        printf("Datos guardados exitosamente!\n");
                        system("pause");
                    }else{

                        system("cls");
                        printf("Datos no guardados!\n");
                        system("pause");
                    }
                }else{

                    system("cls");
                    printf("Aun no hay empleados para guardar\n");
                    system("pause");
                }
                break;
            case 10:
                printf("Desea salir? (s/n)\n");
                fflush(stdin);
                scanf("%c", &seguir);
                break;
        }
    }while(seguir == 'n');
    return 0;
}

int menu(){

    int opcion;

    system("cls");
    printf("Menu\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");

    printf("Ingrese una opcion\n");
    scanf("%d", &opcion);

    return opcion;
}





