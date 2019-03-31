#include <stdio.h>
#include <stdlib.h>
#include "diberardino.h"

int main()
{
    int opcion;
    int cambioOperando1 = 0;
    int cambioOperando2 = 0;
    int cambioCalculos = 0;
    int cambioResultados = 0;
    int num1;
    int num2;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    float resultadoDivision;
    long factorial1;
    long factorial2;

    do{
        system("cls");

        printf("**************\n*    Menu    *\n**************\n\n");

        if(cambioOperando1 == 1){

            printf("1. Ingresar 1er operando (A=%d)\n", num1);
        }else{

            printf("1. Ingresar 1er operando (A=x)\n");
        }

        if(cambioOperando2 == 1){

            printf("2. Ingresar 2do operando (B=%d)\n", num2);
        }else{

            printf("2. Ingresar 2do operando (B=y)\n");
        }

        printf("3. Calcular todas las operaciones\n");

        switch(cambioCalculos){

        case 0:
            printf("a) Calcular la suma (A+B) \n");
            printf("b) Calcular la resta (A+B) \n");
            printf("c) Calcular la division (A+B) \n");
            printf("d) Calcular la multiplicacion (A+B) \n");
            printf("e) Calcular el factorial de: (A!) y: (B!)\n");
            break;
        case 1:
            printf("a) Calcular la suma (%d+%d) \n", num1, num2);
            printf("b) Calcular la resta (%d-%d) \n", num1, num2);
            printf("c) Calcular la division (%d/%d) \n", num1, num2);
            printf("d) Calcular la multiplicacion (%d*%d) \n", num1, num2);
            printf("e) Calcular el factorial de: (%d!) y: (%d!)\n", num1, num2);
            break;
        case 2:
            printf("No es posible realizar algunas operaciones, reingrese el segundo operando\n");
            break;
        case 3:
            printf("Operaciones Calculadas\n");
            break;
        }

        printf("4. Informar resultados\n");

        switch(cambioResultados){

        case 0:
            printf("a) El resultado de A+B es: r\n");
            printf("b) El resultado de A-B es: r\n");
            printf("c) El resultado de A/B es: r\n");
            printf("d) El resultado de A*B es: r\n");
            printf("e) El factorial de A es: r1 y El factorial de B es: r2\n");
            break;
        case 1:
            printf("a) El resultado de A+B es: %d\n", resultadoSuma);
            printf("b) El resultado de A-B es: %d\n", resultadoResta);
            printf("c) El resultado de A/B es: %f\n", resultadoDivision);
            printf("d) El resultado de A*B es: %d\n", resultadoMultiplicacion);
            printf("e) El factorial de A es: %li y el factorial de B es: %li\n", factorial1, factorial2);
            break;
        case 2:
            printf("No ingreso correctamente los parametros\n");
            break;
        }

        printf("5- Salir\n");
        printf("\n\n Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){

        case 1:
            printf("Ingrese el primer operando: ");
            scanf("%d", &num1);
            cambioOperando1 = 1;
            break;
        case 2:
            printf("Ingrese el segundo operando: ");
            scanf("%d", &num2);
            cambioOperando2 = 1;
            break;
        case 3:
            if(num2 == 0){

                cambioCalculos = 2;
            }else{

                resultadoSuma = suma(num1, num2);
                resultadoResta = resta(num1, num2);
                resultadoMultiplicacion = multiplicacion(num1, num2);
                resultadoDivision = dividir(num1, num2);
                factorial1 = factorial(num1);
                factorial2 = factorial(num2);
                cambioCalculos = 1;
            }
            break;
        case 4:
            if(num2 == 0){

                cambioCalculos = 2;
                cambioResultados = 2;
            }else{

                cambioResultados = 1;
                cambioCalculos = 3;
            }
        }
    }while(opcion != 5);

    return 0;
}
