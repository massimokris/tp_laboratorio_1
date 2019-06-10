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

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);//crea una nueva linked list
int ll_len(LinkedList* this);//devuelve el tamaño de elementos
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);//agrega un elemento al final de linkendlist
void* ll_get(LinkedList* this, int index);//obtiene un puntero del indice que le pasamos
int ll_set(LinkedList* this, int index,void* pElement);//coloca un elemento en el indice que le indicamos en la linkedlist
int ll_remove(LinkedList* this,int index);//elimina un elemento del indice que le indicamos
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);//elimina toda la linked list
int ll_indexOf(LinkedList* this, void* pElement);//si hay algun elemento en ese indice y retorna el indice
int ll_isEmpty(LinkedList* this);//se fija si la lista esta vacio
int ll_push(LinkedList* this, int index, void* pElement);//agrega un elemento a la lista en el indice indicado
void* ll_pop(LinkedList* this,int index);//agrega a un empleado a una variable y lo borra del linkedlist
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);//hace un subconjunto del linkedlist desde y hasta donde le indiques
LinkedList* ll_clone(LinkedList* this);//hace una copia del linkedlist
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//ordena el linked list pasandole una funcion que ordena y el modo a ordenar
