#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#include "arrayEmployees.h"

#define LEN 1000

int main()
{
    char salir = 's';
    char confirma;
    int auxInt;
    eSector sectors[] =
    {
        {1, "Sistemas"},
        {2, "RRHH"},
        {3, "Compras"},
        {4, "Ventas"},
        {5, "Legales"},

    };

    eEmployee employees[LEN];

    initEmployees(employees, LEN);

    do{

        switch(menuABM()){

        case 1:
            //printf("Ingrese un empleado\n");
            system("cls");
            addEmployee(employees, LEN);
            system("pause");
            break;
        case 2:
            //printf("Modificar empleado\n");
            if(isEmpty(employees, LEN) == 0){

                system("cls");
                printf("Debe ingresar al menos un empleado\n");
                system("pause");
            }else{

                system("cls");
                printf("Ingrese legajo: \n");
                scanf("%d", &auxInt);
                printEmployee(sectors, 5, employees[findEmployeeById(employees, LEN, auxInt)]);
                printf("\nSeguro quiere modificar este empleado (s/n) ?\n");
                fflush(stdin);
                scanf("%c", &salir);
                system("pause");
                if(tolower(salir) == 's'){

                    changesMenu(employees, LEN, auxInt);
                    system("pause");
                }
            }
            break;
        case 3:
            //printf("baja empleado\n");
            if(isEmpty(employees, LEN) == 0){

                system("cls");
                printf("Debe ingresar al menos un empleado\n");
                system("pause");
            }else{

                system("cls");
                printf("Ingrese legajo: \n");
                scanf("%d", &auxInt);
                removeEmployee(employees, LEN, auxInt);
                system("pause");
            }
            break;
        case 4:
            //printf("ordenar empleados\n");
            if(isEmpty(employees, LEN) == 0){

                system("cls");
                printf("Debe ingresar al menos un empleado\n");
                system("pause");
            }else{

                system("cls");
                reports(employees, LEN, sectors, 5);
                system("pause");
            }
            break;
        case 5:
            //printf("mostrar empleados\n");
            if(isEmpty(employees, LEN) == 0){

                system("cls");
                printf("Debe ingresar al menos un empleado\n");
                system("pause");
            }else{

                system("cls");
                printEmployees(employees, LEN, sectors, 5);
                system("pause");
            }
            break;
        case 6:
            system("cls");
            printf("Confirma salida (s/n) ?\n");
            fflush(stdin);
            scanf("%c", &confirma);

            if(tolower(confirma) == 's'){

                salir = 'n';
            }
            break;
        }
    }while(salir == 's');
}
