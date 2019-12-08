/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

void nueva(LinkedList* this);
int aumenta(int num);
int filtra(int num);

int main(void)
{
//        starttesting(1);  // ll_newlinkedlist
//        starttesting(2);  // ll_len
//        starttesting(3);  // getnode - test_getnode
//        starttesting(4);  // addnode - test_addnode
//        starttesting(5);  // ll_add
//        starttesting(6);  // ll_get
//        starttesting(7);  // ll_set
//        starttesting(8);  // ll_remove
//        starttesting(9);  // ll_clear
//        starttesting(10); // ll_deletelinkedlist
//        starttesting(11); // ll_indexof
//        starttesting(12); // ll_isempty
//        starttesting(13); // ll_push
//        starttesting(14); // ll_pop
//        starttesting(15); // ll_contains
//        starttesting(16); // ll_containsall
//        starttesting(17); // ll_sublist
//        starttesting(18); // ll_clone
//        starttesting(19); // ll_sort */

    LinkedList* this = ll_newLinkedList();
    LinkedList* this2;
    LinkedList* this3;

    nueva(this);

    for(int i = 0; i < ll_len(this); i++){

        printf("%d ", ll_get(this, i));
    }
    printf("\n");

    this2 = ll_map(this, aumenta);

    for(int j = 0; j < ll_len(this2); j++){

        printf("%d ", ll_get(this2, j));
    }

    printf("\n");

    this3 = ll_filter(this, filtra);

    for(int k = 0; k < ll_len(this3); k++){

        printf("%d ", ll_get(this3, k));
    }

    return 0;
}

void nueva(LinkedList* this){

    int returnAux = -1;
    int size = 10;

    for(int i = 0; i < size; i++){

        ll_add(this, i);
    }
}

int aumenta(int num){

    return num*2;
}

int filtra(int num){

    int validar = 0;

    if(num%2 == 0){

        validar = 1;
    }

    return validar;
}






























