#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int size = ll_len(this);

    if(this != NULL){

        if(nodeIndex > -1 && nodeIndex < size){

            pNode = this->pFirstNode;

            while(nodeIndex > 0){

                pNode = pNode->pNextNode;
                nodeIndex--;
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int size = ll_len(this);
    Node* pNode;
    Node* auxNode;

    if(this != NULL){

        if(nodeIndex > -1 && nodeIndex <= size){

            pNode = (Node*) malloc(sizeof(Node));

            if(pNode != NULL){

                if(nodeIndex == 0){

                    pNode->pNextNode = this->pFirstNode;
                    pNode->pElement = pElement;
                    this->pFirstNode = pNode;
                    this->size = size + 1;
                    returnAux = 0;
                }else if(nodeIndex > 0){

                    auxNode = getNode(this, (nodeIndex - 1));
                    auxNode->pNextNode = pNode;
                    pNode->pNextNode = getNode(this, (nodeIndex + 1));
                    pNode->pElement = pElement;
                    this->size = size + 1;
                    returnAux = 0;
                }
            }
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size = ll_len(this);

    if(this != NULL){

        if(addNode(this, size, pElement) == 0){

            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* aux;
    int size = ll_len(this);

    if(this != NULL && (index > -1 && index < size)){

        if(getNode(this, index) != NULL){

            aux = getNode(this, index);
            returnAux = aux->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int size = ll_len(this);

    if(this != NULL){

        if(index > -1 && index < size){

            if(addNode(this, index, pElement) == 0){

                 returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int size = ll_len(this);
    Node* pAux;
    Node* pNode;

    if(this != NULL && index > -1 && index < size){

        if(index == 0){

            pAux = getNode(this, 1);
            pNode = getNode(this, 0);
            this->pFirstNode = pAux;
            this->size--;
            free(pNode);
            returnAux=0;
        }else{

            pNode=getNode(this, index);
            pAux=getNode(this, index-1);
            pAux->pNextNode = pNode->pNextNode;
            this->size--;
            free(pNode);
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int size = ll_len(this);

    if(this != NULL){

        this->pFirstNode = NULL;
        this->size = 0;
        returnAux = 0;

        for(int i = size; i < -1; i--){

            ll_remove(this, i);
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

        if(ll_clear(this) == 0){

            free(this);
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size = ll_len(this);
    Node* pNode;

    if(this != NULL){

        for(int i = 0; i < size; i++){

            pNode = getNode(this, i);

            if(pNode->pElement == pElement){

                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){

        if(this->size > 0){

            returnAux = 0;
        }else{

            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int size = ll_len(this);

    if(this != NULL){

        if(index > -1 && index <= size){

            returnAux = addNode(this, index, pElement);
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int size = ll_len(this);

    if(this != NULL){

        if(index > -1 && index <= size){

            returnAux = ll_get(this, index);
            ll_remove(this, index);
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int size = ll_len(this);
    Node* pNode;

    if(this != NULL){

        for(int i = 0; i < size; i++){

            pNode = getNode(this, i);

            if(pNode->pElement == pElement){

                returnAux = 1;
                break;
            }
        }

        if(returnAux != 1){

            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int size = ll_len(this);
    int size2 = ll_len(this2);
    Node* pNode;
    Node* pAux;

    if(this != NULL && this2 != NULL){

        for(int i = 0; i < size2; i++){

            pAux = getNode(this2, i);

            for(int j = 0; j < size; j++){

                pNode = getNode(this, j);

                if(pAux->pElement == pNode->pElement){

                    returnAux = 1;
                    break;
                }
            }

            if(returnAux != 1){

                break;
            }
        }

        if(returnAux != 1){

            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    Node* pNode;
    int size = ll_len(this);

    if(this != NULL){

        if(from > -1 && from < to && to <= size){

            cloneArray = ll_newLinkedList();

            if(cloneArray != NULL){

                for(int i = from; i < to; i++){

                    pNode = getNode(this, i);

                    ll_add(cloneArray, pNode->pElement);
                }
            }
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int size = ll_len(this);

    if(this != NULL){

        cloneArray = ll_subList(this, 0, size);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int size = ll_len(this);
    void* pElementi;
    void* pElementj;
    void* auxElement;

    if(this != NULL && size > 1 && (order == 0 || order == 1)){

        returnAux = 0;

        if(pFunc != NULL){

            for(int i = 0; i < size - 1; i++){

                for(int j = i + 1; j < size; j++){

                    pElementi = ll_get(this, i);
                    pElementj = ll_get(this, j);

                    if(order == 1){
                        //menor a mayor
                        if(pFunc(pElementi, pElementj) > 0){

                            auxElement = pElementi;
                            pElementi = ll_set(this, i, pElementj);
                            pElementj = ll_set(this, j, auxElement);
                        }
                    }

                    if(order == 0){
                        //mayor a menor
                        if(pFunc(pElementi, pElementj) < 0){

                            auxElement = pElementi;
                            pElementi = ll_set(this, i, pElementj);
                            pElementj = ll_set(this, j, auxElement);
                        }
                    }
                }
            }
        }
    }

    return returnAux;
}

LinkedList* ll_map(LinkedList* this, void* (*pFunc)(void*)){

    LinkedList* cloneArray = NULL;
    void* pAux;
    int size = ll_len(this);

    if(this != NULL){

        cloneArray = ll_newLinkedList();

        if(pFunc != NULL){

            for(int i = 0; i < size; i++){

                pAux = ll_get(this, i);

                ll_add(cloneArray, pFunc(pAux));
            }
        }
    }

    return cloneArray;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*)){

    LinkedList* cloneArray = NULL;
    void* pAux;
    int size = ll_len(this);

    if(this != NULL){

        cloneArray = ll_newLinkedList();

        if(pFunc != NULL){

            for(int i = 0; i < size; i++){

                pAux = getNode(this, i)->pElement;

                if(pFunc(pAux) == 1){

                    ll_add(cloneArray, pAux);
                }
            }
        }
    }

    return cloneArray;
}











