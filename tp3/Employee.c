#include "Employee.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "LinkedList.h"

int employee_setId(Employee* this,int id){

    int validation = 0;

    if(this != NULL && id > 0){

        this->id = id;
        validation = 1;
    }

    return validation;
}

int employee_getId(Employee* this,int* id){

    int validation = 0;

    if(this != NULL && id != NULL){

        *id = this->id;
        validation = 1;
    }

    return validation;
}

int employee_setNombre(Employee* this,char* nombre){

    int validation = 0;

    if(this != NULL && (nombre != NULL && strlen(nombre) > 3)){

        strcpy(this->nombre, nombre);
        validation = 1;
    }

    return validation;
}

int employee_getNombre(Employee* this,char* nombre){

    int validation = 0;

    if(this != NULL && nombre != NULL){

        strcpy(nombre, this->nombre);
        validation = 1;
    }

    return validation;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int validation = 0;

    if(this != NULL && horasTrabajadas > 0){

        this->horasTrabajadas = horasTrabajadas;
        validation = 1;
    }

    return validation;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

    int validation = 0;

    if(this != NULL && horasTrabajadas > 0){

        *horasTrabajadas = this->horasTrabajadas;
        validation = 1;
    }

    return validation;
}

int employee_setSueldo(Employee* this,int sueldo){

    int validation = 0;

    if(this != NULL && sueldo > 0){

        this->sueldo = sueldo;
        validation = 1;
    }

    return validation;
}

int employee_getSueldo(Employee* this,int* sueldo){

    int validation = 0;

    if(this != NULL && sueldo > 0){

        *sueldo = this->sueldo;
        validation = 1;
    }

    return validation;
}

Employee* employee_new(){

    Employee* this = (Employee*) malloc(sizeof(Employee));

    if(this != NULL){

        this->id = 0;
        strcpy(this->nombre, "");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

    Employee* this;

        if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL){

            this = employee_new();

            if(this != NULL){

                if(!employee_setId(this, atoi(idStr)) ||
                   !employee_setNombre(this, nombreStr) ||
                   !employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr)) ||
                   !employee_setSueldo(this, atoi(sueldoStr))){

                        free(this);
                        this = NULL;
                }
            }
        }

    return this;
}

void employee_delete(Employee* this){

    if(this != NULL){

        free(this);
    }
}

void mostrarEmpleado(Employee* emp){

    printf("%d   %s   %d   %d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
}

int ordenarPorSueldo(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL){

        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->sueldo > p2->sueldo){

            retorno = 1;
        }else if(p1->sueldo < p2->sueldo){

            retorno = -1;
        }else{

            retorno = 0;
        }
    }

    return retorno;
}

int ordenarPorId(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL){

        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->id > p2->id){

            retorno = 1;
        }else if(p1->id < p2->id){

            retorno = -1;
        }else{

            retorno = 0;
        }
    }

    return retorno;
}

int ordenarPorHoras(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL){

        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas){

            retorno = 1;
        }else if(p1->horasTrabajadas < p2->horasTrabajadas){

            retorno = -1;
        }else{

            retorno = 0;
        }
    }

    return retorno;
}

int ordenarPorNombre(void* emp1, void* emp2){

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL){

        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(stricmp(p1->nombre, p2->nombre) > 0){

            retorno = 1;
        }else if(stricmp(p1->nombre, p2->nombre) < 0){

            retorno = -1;
        }else{

            retorno = 0;
        }
    }

    return retorno;
}

int randomId (void* this){

    int empty = -1;

    empty = ll_len(this) + 1;

    return empty;
}

int validarEmpleado(Employee* emp){
    int validation = 0;
    int id;
    int horas;
    int sueldo;
    char nombre[128];

    if(emp!=NULL){

        employee_getId(emp,&id);
        employee_getHorasTrabajadas(emp,&horas);
        employee_getSueldo(emp,&sueldo);
        employee_getNombre(emp,nombre);

        if(id>0 && horas >0 && sueldo >0 && nombre !=NULL){

            validation = 1;
        }
    }

    return validation;
}
