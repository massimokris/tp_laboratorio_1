#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#include "arrayEmployees.h"
#include "validar.h"

int randomId(eEmployee* list, int len){

    int id;
    int empty;

    empty = findEmpty(list, len);

    id = empty+1000;

    return id;
}

int menuABM (void){

    int opcion;

    system("cls");
    printf("***** ABM *****\n");
    printf("1- Alta empleado\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja empleado\n");
    printf("4- Informes\n");
    printf("5- Mostrar empleados\n");
    printf("6- Salir\n");

    printf("\n\nIngrese una opcion:\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

void initEmployees (eEmployee* list, int len){

    for(int i = 0; i < len; i++){

        list[i].isEmpty = 1;
    }
}

int findEmpty (eEmployee* list, int len){

    int empty = -1;

    for(int i = 0; i < len; i++){

        if(list[i].isEmpty == 1){

            empty = i;
            break;
        }
    }

    return empty;
}

int findEmployeeById (eEmployee* list, int len, int id){

    int position = -1;

    for(int i = 0; i < len; i++){

        if(list[i].id == id){

            position = i;
            break;
        }
    }

    return position;
}

int removeEmployee (eEmployee* list, int len, int id){

    int validation = -1;

    for(int i = 0; i < len; i++){

        if(list[i].id == id){

            list[i].isEmpty = 1;
            validation = 0;

            break;
        }
    }

    return validation;
}

void addEmployee (eEmployee* list, int len){

    int empty;

    empty = findEmpty(list, len);

    if(empty == -1){

        printf("No hay lugares disponibles\n");
    }else{

        list[empty].isEmpty = 0;

        list[empty].id = randomId(list, len);

        printf("Ingrese nombre: \n");
        fflush(stdin);
        gets(list[empty].name);

        printf("Ingrese apellido: \n");
        fflush(stdin);
        gets(list[empty].lastname);

        getFloat(&list[empty].salary, "Ingrese sueldo: \n", "Error, reingrese sueldo: \n");

        printf("Ingrese sector: \n");
        scanf("%d", &list[empty].sector);
        getInt("Ingrese sector: \n", "Error, reingrese sector", &list[empty].sector, 1, 5);
    }
}

void printEmployee (eSector* sectors, int lenSec, eEmployee emp){

    char nameSector[20];
    int findName;

    findName =  findSector(sectors, lenSec, emp.sector, nameSector);

    if( !findName){
         strcpy(nameSector, "Sin definir");
     }
    printf("   %d   %s %s     %.2f    %s\n", emp.id, emp.lastname, emp.name, emp.salary, nameSector);

}

void printEmployees (eEmployee* list, int len, eSector* sectors, int lenSec){

    int contador = 0;

    system("cls");

    printf(" Legajo      Apellido Nombre     Sueldo   Sector\n");
    printf(" ------      -------- ------     ------   ------\n");

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printEmployee(sectors, lenSec, list[i]);
            contador++;
        }
    }
    printf("\n\n");

    if( contador == 0)
    {
        printf("\nNo hay empleados que mostrar\n");
    }
}

int findSector (eSector* sectors, int lenSec, int idSector, char desc[]){

    int validation = 0;

    for(int i=0; i < lenSec; i++)    {

        if(idSector == sectors[i].id)
        {

            strcpy(desc, sectors[i].description);
            validation = 1;
            break;
        }
    }

    return validation;
}

void sortEmpleyees (eEmployee* list, int len, int order){

    switch(order){

    case 1:

        for(int i = 0; i < len-1; i++){

            for(int j = i+1; j < len; j++){

                if(list[i].isEmpty == 0){

                    if(list[i].sector > list[j].sector){

                        bubble(list, len, i, j);
                    }else{

                        if((list[i].sector == list[j].sector) && (stricmp(list[i].lastname, list[j].lastname)>0)){

                            bubble(list, len, i, j);
                        }
                    }
                }
            }
        }
        break;
    case 2:

        for(int i = 0; i < len-1; i++){

            for(int j = i+1; j < len; j++){

                if(list[i].isEmpty == 0){

                    if(list[i].sector < list[j].sector){

                        bubble(list, len, i, j);
                    }else{

                        if((list[i].sector == list[j].sector) && (stricmp(list[i].lastname, list[j].lastname)<0)){

                            bubble(list, len, i, j);
                        }
                    }
                }
            }
        }
        break;
    }
}

void bubble (eEmployee* list, int len, int i, int j){

    eEmployee auxList;

    auxList = list[i];
    list[i] = list[j];
    list[j] = auxList;
}

int isEmpty (eEmployee* list, int len){

    int validation = 0;

    for(int i = 0; i < len; i++){

        if(list[i].isEmpty == 0){

            validation = -1;
            break;
        }
    }

    return validation;
}

float totalSalary (eEmployee* list, int len){

    float total = 0;

    for(int i = 0; i < len; i++){

        if(list[i].isEmpty == 0){

            total += list[i].salary;
        }
    }

    return total;
}

float averageSalary (eEmployee* list, int len){

    float total;
    float average;

    total = totalSalary(list, len);

    average = total/getEmployees(list, len);

    return average;
}

int higherAverage (eEmployee* list, int len){

    int employees = 0;
    float average;

    average = averageSalary(list, len);

    for(int i = 0; i < len; i++){

        if(list[i].isEmpty == 0 && list[i].salary > average){

            employees++;
        }
    }

    return employees;
}

int getEmployees (eEmployee* list, int len){

    int employees = 0;

    for(int i = 0; i < len; i++){

        if(list[i].isEmpty == 0){

            employees++;
        }
    }

    return employees;
}

void reports (eEmployee* list, int len, eSector* sectors, int lenSec){

    int auxInt;
    char seguir = 's';

    do{

        system("cls");
        printf("***** INFORMES *****\n");
        printf("1- Ordenar empleados\n");
        printf("2- Salario total, promedio y mayor al promedio\n\n");
        printf("Ingrese una opcion\n");
        scanf("%d", &auxInt);

        switch(auxInt){

        case 1:
            system("cls");
            printf("Como desea ordenar ?\n");
            printf("1- (A/Z)\n");
            printf("2- (Z/A)\n");
            scanf("%d", &auxInt);
            sortEmpleyees(list, len, auxInt);
            printEmployees(list, len, sectors, lenSec);
            system("pause");
            break;
        case 2:
            system("cls");
            printf("Salario total: %.2f \n", totalSalary(list, len));
            printf("Salario promedio: %.2f \n", averageSalary(list, len));
            printf("%d\n", getEmployees(list, len));
            printf("Cantidad de empleados con salario mayor al promedio: %d \n", higherAverage(list, len));
            system("pause");
            break;
        }

        system("cls");
        printf("Desea seguir (s/n) ? \n");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir == 's');
}

void changeName (eEmployee* list, int len, int id){

    char auxString[51];

    system("cls");
    printf("Ingrese el nuevo nombre del empleado: \n");
    fflush(stdin);
    gets(auxString);

    for(int i = 0; i < len; i++){

        if(list[i].id == id){

            strcpy(list[i].name, auxString);
            system("cls");
            printf("Cambio realizado!\n");
            system("pause");
            break;
        }
    }
}

void changeLastname (eEmployee* list, int len, int id){

    char auxString[51];

    system("cls");
    printf("Ingrese el nuevo apellido del empleado: \n");
    fflush(stdin);
    gets(auxString);

    for(int i = 0; i < len; i++){

        if(list[i].id == id){

            strcpy(list[i].lastname, auxString);
            system("cls");
            printf("Cambio realizado!\n");
            system("pause");
            break;
        }
    }
}

void changeSalary (eEmployee* list, int len, int id){

    float auxFloat;

    system("cls");
    printf("Ingrese nuevo salario del empleado: \n");
    scanf("%f", &auxFloat);

    for(int i = 0; i < len; i++){

        if(list[i].id == id){

            list[i].salary = auxFloat;
            system("cls");
            printf("Cambio realizado!\n");
            system("pause");
            break;
        }
    }
}

void changeSector (eEmployee* list, int len, int id){

    int auxInt;

    system("cls");
    printf("a cual sector desea cambiar al empleado ?\n");
    scanf("%d", &auxInt);

    for(int i = 0; i < len; i++){

        if(list[i].id == id){

            list[i].sector = auxInt;
            system("cls");
            printf("Cambio realizado!\n");
            system("pause");
            break;
        }
    }
}

void changesMenu (eEmployee* list, int len, int id){

    char seguir = 's';
    int auxInt;

    do{
        system("cls");
        printf("Que desea cambiar ?\n");
        printf("1- Nombre del empleado \n");
        printf("2- Apellido del empleado \n");
        printf("3- Sector del empleado \n");
        printf("4- Salario del empleado \n\n");
        printf("opcion\n");
        scanf("%d", &auxInt);

        switch(auxInt){

        case 1:
            changeName(list, len, id);
            break;
        case 2:
            changeLastname(list, len, id);
            break;
        case 3:
            changeSector(list, len, id);
            break;
        case 4:
            changeSalary(list, len, id);
            break;
        }

        system("cls");
        printf("Desea seguir (s/n) ? \n");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir == 's');
}
