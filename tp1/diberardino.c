#include <stdio.h>
#include <stdlib.h>

//funcion para sumar entero
int suma (int a, int b){

    int suma;

    suma = a + b;

    return suma;
}

//funcion para restar enteros
int resta (int a, int b){

    int resta;

    resta = a - b;

    return resta;
}

//funcion para dividir enteros
float division (int a, int b){

    float division;

    division = a / b;

    return division;
}

//funcion para multiplicar enteros
int multiplicacion (int a, int b){

    int multiplicacion;

    multiplicacion = a * b;

    return multiplicacion;
}

//funcion para calcular el factorial de un numero entero
int factorial (int a){

    int factorial;

    for( int i = 1; i < a; i++){

        factorial = a*i;
    }

    factorial++;

    return factorial;
}


