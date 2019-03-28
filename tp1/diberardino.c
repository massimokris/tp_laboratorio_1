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

    for( int i = 0; i < a; i++){

        factorial = a*i;
    }

    factorial++;

    return factorial;
}

//funcion de menu de la calculadora
int menu (){

    char seguir = 's';

    do{

        switch(mostrarMenu ()){

        case 1:
            printf("Opcion Alta\n");
            break;
        case 2:
            printf("Opcion Baja\n");
            break;
        case 3:
            printf("Opcion Modificaciones\n");
            break;
        case 4:
            printf("Opcion Informes\n");
            break;
        case 5:
            printf("Opcion salir\n");
            break;
        }

        printf("Desea continuar ?");
        scanf("%c", &seguir);

    }while(seguir == 's');

    return 0;
}

int mostrarMenu (){

    int opcion;

    system("cls");

    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificaciones\n");
    printf("4- Informes\n");
    printf("5- Salir\n");
    printf("\n Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
