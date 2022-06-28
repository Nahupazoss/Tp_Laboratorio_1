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
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));//reserva memoria dinamica para la linkedlist

    if(this != NULL)
    {
        this->pFirstNode = NULL; //inicializo en NULL para que no apunte a busura,etc

        this->size = 0;//inicializa el tamaño

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

    if(this != NULL)
    {

    	returnAux = this->size;//retorna el tamaño

    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i = 0;
	int tam = ll_len(this);
	Node* pNodo = NULL;

	if(this != NULL && nodeIndex > -1 && nodeIndex < tam)
	{
		pNodo = this->pFirstNode;//obtenemos el primer nodo de la lista

		if(pNodo != NULL)
		{
			for(i=0;i<nodeIndex;i++)
			{
				pNodo = pNodo->pNextNode;//obtenemos el ultimo nodo
			}
		}
	}

    return pNodo;
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
	Node* pNode = NULL;
	Node* auxNode = NULL;

	int tam;

	if(this != NULL && nodeIndex > -1)
	{
		tam = ll_len(this); //obtenemos el tamaño

		if(nodeIndex >= 0 && nodeIndex <= tam)
		{
			pNode = (Node*)malloc(sizeof(Node)); //reservamos memoria dinamica para el nuevo nodo

			if(pNode != NULL)
			{
				pNode->pElement = pElement; // pasamos el elemento
				this->size += 1; //incrementamos el tamaño de la ll
				returnAux = 0;

				if(nodeIndex == 0)
				{
					pNode->pNextNode = auxNode;//enlazamos el nuevo nodo
					this->pFirstNode = pNode;
				}
				else
				{
					auxNode = getNode(this, nodeIndex -1);

					if(auxNode != NULL)
					{
						pNode->pNextNode = auxNode->pNextNode;
						auxNode->pNextNode = pNode;
					}
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
    int tam;

    if(this != NULL )
    {
    	tam = ll_len(this);//sacamos el tamaño
    	addNode(this, tam, pElement);//agregamos
    	returnAux = 0;
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
    Node* pNodo = NULL;
    int tam;

    if(this != NULL)
    {
    	tam = ll_len(this);

    	if(index >= 0 && index < tam)
    	{
    		pNodo = getNode(this, index);//obtenemos el nodo

    		if(pNodo != NULL)
    		{
    			returnAux = pNodo->pElement; //retornamos el elemento del nodo
    		}
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
    Node* pNodo = NULL;
    int tam;

    if(this != NULL)
    {
    	tam = ll_len(this);

    	if(index >= 0 && index < tam)
    	{
    		pNodo = getNode(this, index); // obtenemos el nodo

    		if(pNodo != NULL)
    		{
    			pNodo->pElement = pElement; //modifica ese elemento del nodo obtenido
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
    int tam;
    Node* pNodo = NULL;
    Node* auxNode = NULL;

    if(this != NULL)
    {
    	tam = ll_len(this);

    	if(index >= 0 && index <= tam)
    	{
    		pNodo = getNode(this, index);//obtenemos el nodo

    		if(pNodo != NULL)
    		{
    			returnAux = 0;

    			if(index == 0)
    			{
    				this->pFirstNode = pNodo->pNextNode;//hacemos que el primer nodo apunte a la dir de memoria del 2do
    			}
    			else
    			{
    				auxNode = getNode(this, index -1);//obtenemos el nodo anterior

    				if(auxNode != NULL)
    				{
    					auxNode->pNextNode = pNodo->pNextNode;
    				}
    			}
    		}
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
    Node* pNodo = NULL;
    int tam;
    int i;

    if(this != NULL)
    {
    	tam = ll_len(this);

    	for(i=0;i<tam;i++)
    	{
    		pNodo = getNode(this, i);//obtengo el nodo

    		if(pNodo != NULL)
    		{
    			ll_remove(this, i);//elimino los elementos
    			free(this);//libero la memoria
    			returnAux = 0;
    		}
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

    if(this != NULL)
    {
    	ll_clear(this);
    	returnAux = 0;
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
    Node* pNodo = NULL;
    int tam;

    if(this!=NULL)
    {
    	tam = ll_len(this);

    	for(int i=0;i<tam;i++)
    	{
    		pNodo = getNode(this, i);

    		if(pNodo!=NULL)
    		{
    			if(pNodo->pElement==pElement)
    			{
    				returnAux=i;
    			}
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

	if(this != NULL)
	{
		if(this->pFirstNode == NULL)
		{
			returnAux = 1;
		}
		else
		{
			returnAux = 0;
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
	 int tam;

	 if(this != NULL)
	 {
		 tam = ll_len(this);

		 if(index >= 0 && index <= tam)//verifico que este dentro del primer y ultimo nodo
		 {
			 addNode(this, index, pElement);//agrego el nodo en la posicion indicada
			 returnAux=0;
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
	int tam;
	Node* pNodo;

	if(this != NULL)
	{
		tam = ll_len(this);

		if(index >= 0 && index <= tam)
		{
			pNodo = getNode(this, index);//obtengo el nodo

			if(pNodo != NULL)
			{
				returnAux = pNodo->pElement;//retorno el elemento de la posicion
				ll_remove(this, index);//lo elimino
				free(pNodo);//libero
			}
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
	int tam;
	void* unElemento = NULL;
	int i;

	if(this!=NULL)
	{
		tam = ll_len(this);
		returnAux = 0;

		for(i=0;i<tam;i++)
		{
			unElemento = ll_get(this, i);//obtengo el nodo

			if(unElemento == pElement)//verifico si contiene el elemento pasado
			{
				returnAux = 1;
				break;
			}
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
	 int tam;
	 void* elementoDos;
	 int retorno;
	 int i;

	 if(this != NULL && this2 != NULL)
	 {
		 returnAux = 1;
		 tam = ll_len(this2);

		 for(i=0;i<tam;i++)
		 {
			 elementoDos = ll_get(this2, i);//obtengo los elementos de this2
			 retorno = ll_contains(this, elementoDos);//verifico que esten contenidos en this

			 if(retorno == 0)
			 {
				 returnAux = 0;
				 break;
			 }
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
    void* pAuxElement = NULL;
    int indexCopy = from;

    if(this != NULL && from >= 0 && from < this->size && to > from && to <= this->size)
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		do
    		{
        		pAuxElement = ll_get(this,indexCopy);

        		if(!ll_add(cloneArray,pAuxElement))
        		{
        			indexCopy++;
        		}
        		else if(!ll_deleteLinkedList(cloneArray))
				{
					cloneArray = NULL;
					break;
				}
    		}while(indexCopy < to);
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
	int tam;

	if(this!=NULL)
	{
		cloneArray = ll_newLinkedList();
		tam = ll_len(this);

		for(int i=0;i<tam;i++)
		{
			if(tam>0)
			{
				ll_subList(this, i, tam);
			}
		}
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
	int returnAux =-1;
	int tam;
	int i,j;
	int retornoFuncion;
	void* elementoUno = NULL;
	void* elementoDos = NULL;
	void* auxElemento = NULL;

	if(this != NULL && pFunc != NULL && (order == 1||order == 0))
	{
		tam = ll_len(this);

		for(i=0;i<tam-1;i++)
		{
			for(j=i+1;j<tam;j++)
			{
				elementoUno = ll_get(this, i);//ob
				elementoDos = ll_get(this, j+1);//borarr +1 si rompe//ob
				retornoFuncion = pFunc(elementoUno,elementoDos);

				if(order == 0 && retornoFuncion < 0)
				{
					auxElemento = elementoDos;
					ll_set(this, j, elementoUno);
					ll_set(this, i, auxElemento);
				}
				else
				{
					if(order == 1 && retornoFuncion > 0)
					{
						auxElemento = elementoUno;
						ll_set(this, i, elementoDos);
						ll_set(this, j, auxElemento);
					}
				}
			}
		}
		returnAux=0;
	}
	return returnAux;
}

