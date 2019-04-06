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

    //realizo toda la iteracion por lo menos una vez y hasta que el usurio seleccione la opcion salir
    do{
        //limpio el menu en cada iteracion
        system("cls");

        printf("**************\n*    Menu    *\n**************\n\n");

        //muestro el valor de primer operando cuando el usuario lo haya ingresado
        if(cambioOperando1 == 1){

            printf("1. Ingresar 1er operando (A=%d)\n", num1);
        }else{

            //muestro X si no ha ingresado ningun valor
            printf("1. Ingresar 1er operando (A=x)\n");
        }

        //muestro el valor de primer operando cuando el usuario lo haya ingresado
        if(cambioOperando2 == 1){

            printf("2. Ingresar 2do operando (B=%d)\n", num2);
        }else{

            //muestro X si no ha ingresado ningun valor
            printf("2. Ingresar 2do operando (B=y)\n");
        }

        printf("3. Calcular todas las operaciones\n");

        //muestro en base a lo que es usuario haya hecho o elegido
        switch(cambioCalculos){

        //si no ha calculado nada se muestra esto
        case 0:
            printf("a) Calcular la suma (A+B) \n");
            printf("b) Calcular la resta (A+B) \n");
            printf("c) Calcular la division (A+B) \n");
            printf("d) Calcular la multiplicacion (A+B) \n");
            printf("e) Calcular el factorial de: (A!) y: (B!)\n");
            break;
        //si eligio la opcion calcular se muestra esto
        case 1:
            printf("a) Calcular la suma (%d+%d) \n", num1, num2);
            printf("b) Calcular la resta (%d-%d) \n", num1, num2);
            printf("c) Calcular la division (%d/%d) \n", num1, num2);
            printf("d) Calcular la multiplicacion (%d*%d) \n", num1, num2);
            printf("e) Calcular el factorial de: (%d!) y: (%d!)\n", num1, num2);
            break;
        //si eligio la opcion calcular y alguno de los operando es 0 se muestra esto
        case 2:
            printf("a) Calcular la suma (%d+%d) \n", num1, num2);
            printf("b) Calcular la resta (%d-%d) \n", num1, num2);
            printf("No es posible dividir 0\n");
            printf("d) Calcular la multiplicacion (%d*%d) \n", num1, num2);
            printf("e) Calcular el factorial de: (%d!) y: (%d!)\n", num1, num2);
            break;
        //si eligio la opcion resultados luego de elegir calcular se muestra esto
        case 3:
            printf("Operaciones Calculadas\n");
            break;
        //si no ingreso los 2 parametros se muestra esto
        case 4:
            printf("No es posible realizar los calculos, ingrese correctamente los dos operandos\n");
            break;
         //si eligio la opcion calcular y alguno de los operando es negativo se muestra esto
        case 5:
            printf("a) Calcular la suma (%d+%d) \n", num1, num2);
            printf("b) Calcular la resta (%d-%d) \n", num1, num2);
            printf("c) Calcular la division (%d/%d) \n", num1, num2);
            printf("d) Calcular la multiplicacion (%d*%d) \n", num1, num2);
            if(num1 < 0 && num2 < 0){

                printf("No es posible factorizar numeros negativos\n");
            }else if(num2 < 0){

                printf("e) No se puede calcular el factorial de B porque es negativo, calcular el factorial de A (%li!)\n", factorial1);
            }else{

                printf("e) No se puede calcular el factorial de A porque es negativo,  calcular el factorial de B (%li!)\n", factorial2);
            }
            break;
        }

        printf("4. Informar resultados\n");

        //muestro en base a lo que es usuario haya hecho o elegido
        switch(cambioResultados){

        //si no ha calculado nada y no ha pedido resultados se muestra esto
        case 0:
            printf("a) El resultado de A+B es: r\n");
            printf("b) El resultado de A-B es: r\n");
            printf("c) El resultado de A/B es: r\n");
            printf("d) El resultado de A*B es: r\n");
            printf("e) El factorial de A es: r1 y El factorial de B es: r2\n");
            break;
        //si ya calculo todo y pidio los resultados se muestra esto
        case 1:
            printf("a) El resultado de A+B es: %d\n", resultadoSuma);
            printf("b) El resultado de A-B es: %d\n", resultadoResta);
            printf("c) El resultado de A/B es: %f\n", resultadoDivision);
            printf("d) El resultado de A*B es: %d\n", resultadoMultiplicacion);
            printf("e) El factorial de A es: %li y el factorial de B es: %li\n", factorial1, factorial2);
            break;
        //si ya calculo, pidio los resultados y alguno de los operandos en 0 se muestra esto
        case 2:
            printf("a) El resultado de A+B es: %d\n", resultadoSuma);
            printf("b) El resultado de A-B es: %d\n", resultadoResta);
            printf("No es posible dividir 0\n");
            printf("d) El resultado de A*B es: %d\n", resultadoMultiplicacion);
            printf("e) El factorial de A es: %li y el factorial de B es: %li\n", factorial1, factorial2);
            break;
        //si ya calculo, pidio los resultados y alguno de los operandos en negativo se muestra esto
        case 3:
            printf("a) El resultado de A+B es: %d\n", resultadoSuma);
            printf("b) El resultado de A-B es: %d\n", resultadoResta);
            printf("c) El resultado de A/B es: %f\n", resultadoDivision);
            printf("d) El resultado de A*B es: %d\n", resultadoMultiplicacion);
            if(num1 < 0 && num2 < 0){

                printf("No es posible factorizar numeros negativos\n");
            }else if(num2 < 0){

                printf("e) No se puede calcular el factorial de B porque es negativo, el factorial de A es: %li\n", factorial1);
            }else{

                printf("e) No se puede calcular el factorial de A porque es negativo, el factorial de B es: %li\n", factorial2);
            }
            break;
        //si no ingreso los parametros se muestra esto
        case 4:
            printf("No ingreso correctamente los parametros\n");
            break;
        //si no calculo las operaciones se muestra esto
        case 5:
            printf("Debe calcular las operaciones antes de pedir el resultado\n");
            break;
        }

        //opcion 5 para salir de la iteracion y cortar el programa
        printf("5- Salir\n");
        printf("\n\n Ingrese una opcion: ");
        scanf("%d", &opcion);

        //en base a la opcion que elige el usuario el programa ejecuta algo
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

            //se calculan todas las operaciones
            resultadoSuma = suma(num1, num2);
            resultadoResta = resta(num1, num2);
            resultadoMultiplicacion = multiplicacion(num1, num2);
            resultadoDivision = dividir(num1, num2);
            factorial1 = factorial(num1);
            factorial2 = factorial(num2);

            //condicion que si el divisor es 0 no realice la division
            if(num2 == 0){

                cambioCalculos = 2;
            }else{
                //condicion que si alguno de los operandos es negativo no realice el factoreo
                if(num1 < 0 || num2 < 0){

                    cambioCalculos = 5;
                }else{
                    //si los dos numeros son enteros mayores a 0 realiza todas las operaciones
                    cambioCalculos = 1;
                }
            }
            //condicione que si no ingresado algunos o ninguno de los operandos le informe y se los vuelta a pedir
            if(cambioOperando1 == 0 || cambioOperando2 == 0){

                cambioCalculos = 4;
            }
            break;
        case 4:
            //condicion para mostrar todos los resultados de las operaciones
            if(cambioCalculos == 1){

                cambioCalculos = 3;
                cambioResultados = 1;
            }else{
                //condicion para mostrar los resultados de las operaciones sin la division
                if(cambioCalculos == 2){

                    cambioCalculos = 3;
                    cambioResultados = 2;
                }else{
                     //condicion para mostrar los resultados de las operaciones sin el factoreo
                    if(cambioCalculos == 5){

                        cambioCalculos = 3;
                        cambioResultados = 3;
                    }else{
                        //condicion para informar que no ha calculado y por eso no puede mostrar los resultados
                        if(cambioCalculos == 0){

                            cambioResultados = 5;
                        }
                    }
                }
            }
        }
    //corte de la iteracion con la opcion 5 SALIR
    }while(opcion != 5);

    return 0;
}
