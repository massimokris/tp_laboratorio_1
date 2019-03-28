#include <stdio.h>
#include <stdlib.h>

int main(){

    int factorial;
    int a;

    printf("ingrese un numero.");
    scanf("%d", &a);

    for( int i = 0; i < a; i++){

       factorial += a*i;
    }

    factorial++;

    printf("Hello world!\n %d", factorial);
    return 0;
}
