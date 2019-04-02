#include <stdio.h>
#include <stdlib.h>
#include "diberardino.h"

//funcion para sumar dos enteros y devolver el resultado
int suma (int a, int b){

    int suma;

    suma = a + b;

    return suma;
}

//funcion para restar dos enteros y devolver el resultado
int resta (int a, int b){

    int resta;

    resta = a - b;

    return resta;
}

//funcion para multiplicar dos enteros y devolver el resultado
int multiplicacion (int a, int b){

    int multiplicacion;

    multiplicacion = a * b;

    return multiplicacion;
}

//funcion para dividir dos enteros y devolver el resultado
float dividir (int a, int b){

    float dividir;

    dividir = (float) a / b;

    return dividir;
}

//funcion para calcular el factorial de un entero y regresar el resultado
long factorial(int a){

    long factorial;

    for(factorial = 1; a > 1; a--){

        factorial *= a;
    }

    return factorial;
}

