#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#include "validar.h"

int validarInt (char* cad, int* num, int min, int max){

    int validar = 0;

    if(atoi(cad) != 0 && (atoi(cad) >= min && atoi(cad) <= max)){

        *num = atoi(cad);
        validar = 1;
    }

    return validar;
}

int getInt (char* mes, char* emes, int* num, int min, int max){

    char auxnum[20] = {"m"};
    int i = 0;
    int validar;

    printf("%s\n", mes);
    fflush(stdin);
    scanf("%s", auxnum);
    validar = validarInt(auxnum, num, min, max);

    while(validar == 0){

        if(i == 2){

            system("cls");
            printf("\nSupero el limite de intentos\n");
            *num = -1;
            break;
        }

        printf("%s\n", emes);
        fflush(stdin);
        scanf("%s", auxnum);
        validar = validarInt(auxnum, num, 10, 1000);

        i++;
    }

    return *num;
}

int getFloat(float* num,char mes[],char emes[], int min, int max){

    int validar=1;
    int isFloat=0;
    int numeroValidado=0;
    int i = 0;
    char auxNum[10]={'0'};

    system("cls");
    printf("%s : ", mes);
    fflush(stdin);
    scanf("%s", auxNum);
    isFloat = validarFloat(auxNum, min, max);

    if(isFloat){

       numeroValidado=atof(auxNum);
       *num=numeroValidado;
    }

    while(isFloat == 0){

        if(i == 2){

            system("cls");
            printf("\nSupero el limite de intentos\n");
            validar = 0;
            break;
        }

        system("cls");
        printf("%s : ", emes);
        fflush(stdin);
        scanf("%s", auxNum);
        isFloat=validarFloat(auxNum, min, max);

        if(isFloat){

           numeroValidado=atof(auxNum);
           *num=numeroValidado;
           break;
        }

        i++;
    }
    return validar;
}

int validarFloat(char auxNum[], int min, int max){

   int i=0;
   int validar = 1;
   int coma=0;

   while(auxNum[i] != '\0'){

       if(auxNum[i]<'0' || auxNum[i]>'9'){

           if(auxNum[i]=='.'){

               coma++;
           }
       }

       if((atof(auxNum))==0 || coma>1){

           validar = 0;
       }
       i++;
   }

   if(atof(auxNum) < min || atof(auxNum) > max){

        validar = 0;
   }
   return validar;
}
