#include <stdio.h>
#include <stdlib.h>

int main (){

    char seguir = 's';
    int num1;
    int num2;

    do{

        switch(mostrarMenu ()){

        case 1:
            printf("ingrese un numero: ");
            scanf("%d", &num1);
            break;
        case 2:
            printf("ingrese un numero: ");
            scanf("%d", &num2);
            break;
        case 3:
            printf("a) Calcular la suma (%d+%d) \n", num1, num2);
            printf("b) Calcular la resta (%d-%d) \n", num1, num2);
            printf("c) Calcular la division (%d/%d) \n", num1, num2);
            printf("d) Calcular la multiplicacion (%d*%d) \n", num1, num2);
            printf("e) Calcular el factorial de: (%d!) y: (%d)\n", num1, num2);
            break;
        case 4:
            printf("a) El resultado de A+B es: %d\n", suma(num1, num2));
            printf("b) El resultado de A-B es: %d\n", resta(num1, num2));
            printf("c) El resultado de A/B es: %d\n", division(num1, num2));
            printf("d) El resultado de A*B es: %d\n", multiplicacion(num1, num2));
            printf("e) El factorial de A es: %d y el factorial de B es: %d\n", factorial(num1));
            break;
        case 5:
            printf("Opcion salir\n");
            break;
        }

        printf("Desea continuar ?");
        fflush(stdin);
        scanf("%c", &seguir);

    }while(seguir == 's');

    return 0;
}

int mostrarMenu (){

    int opcion;

    printf("**************\n*    Menu    *\n**************\n\n");
    printf("1- Ingresar 1er operando (A=x)\n");
    printf("2- Ingresar 2do operando (B=y)\n");
    printf("3- Calcular todas las operaciones\n");
    printf("4- Informar resultados\n");
    printf("5- Salir\n");
    printf("\n\n Ingrese una opcion: ");
    scanf("%d", &opcion);

    system("cls");

    return opcion;
}
