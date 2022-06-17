#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"



/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex);

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this= (LinkedList*)malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
        this->size=0;
        this->pFirstNode=NULL;
    }

    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}



static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodo=NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        pNodo=this->pFirstNode;
        for(int i=0; i<nodeIndex; i++)
        {
           pNodo=pNodo->pNextNode;
        }
    }
    return pNodo;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}



static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;
    Node* pNodoAnterior=NULL;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
        pNodo=(Node*)malloc(sizeof(Node));
        if(pNodo!=NULL)
        {
            pNodo->pElement=pElement;
            if(nodeIndex==0)
            {
                pNodo->pNextNode=this->pFirstNode;
                this->pFirstNode=pNodo;
            }
            else
            {
                pNodoAnterior=getNode(this, nodeIndex-1);
                pNodo->pNextNode=pNodoAnterior->pNextNode;
                pNodoAnterior->pNextNode=pNodo;
            }
            this->size++;
            returnAux=0;
        }
    }

    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}



int ll_add(LinkedList* this, void* pElement)
{
    return addNode(this, ll_len(this), pElement);
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        returnAux=getNode(this, index)->pElement;
    }
    return returnAux;
}



int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        getNode(this, index)->pElement=pElement;
        returnAux=0;
    }

    return returnAux;
}



int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode=NULL;
    Node* auxNodeAnt=NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {

        auxNode=getNode(this, index);
        if(auxNode==this->pFirstNode)
        {
            this->pFirstNode=auxNode->pNextNode;
        }
        else
        {
            auxNodeAnt=getNode(this, index-1);
            auxNodeAnt->pNextNode=auxNode->pNextNode;
        }

        this->size--;
        free(auxNode);
        returnAux=0;
    }

    return returnAux;
}



int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int tam;
    if(this!=NULL)
    {
        tam=ll_len(this);
        for(int i=tam-1; i>=0; i--)
        {
            ll_remove(this, i);
        }
        returnAux=0;
    }

    return returnAux;
}



int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }
    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;
    if(this!=NULL)
    {
        tam=ll_len(this);
        for(int i=0; i<tam; i++)
        {
            if(pElement==ll_get(this, i))
            {
                returnAux=i;
                break;
            }
        }
    }

    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=0;
        if(!ll_len(this))
        {
            returnAux=1;
        }
    }

    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}



void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        returnAux=ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}



int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux=0;
        if(ll_indexOf(this, pElement)!=-1)
        {
            returnAux=1;
        }
    }

    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam;
    if(this!=NULL && this2!=NULL)
    {
        tam=ll_len(this2);
        returnAux=1;
        for(int i=0; i<tam; i++)
        {
            if(!ll_contains(this, ll_get(this2, i)))
            {
                returnAux=0;
                break;
            }
        }
    }

    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL && from>=0 && from<ll_len(this) && to>from && to<=ll_len(this))
    {
        cloneArray=ll_newLinkedList();
        if(cloneArray!=NULL)
        {
            for(int i=from; i<to; i++)
            {
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }

    return cloneArray;
}




LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}



int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int tam;
    void* auxI=NULL;
    void* auxJ=NULL;
    if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
    {
        tam=ll_len(this);
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                auxI=ll_get(this, i);
                auxJ=ll_get(this, j);
                if((pFunc(auxI, auxJ)>0 && order==1) || (pFunc(auxI, auxJ)<0 && order==0))
                {
                    ll_set(this, i, auxJ);
                    ll_set(this, j, auxI);
                }
            }
        }
        returnAux=0;
    }

    return returnAux;

}
