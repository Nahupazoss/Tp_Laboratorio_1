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
/********************************************/
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;
/********************************************/
struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif
/********************************************/
//Publicas
LinkedList* ll_newLinkedList(void);//crea la lista en memoria
/********************************************/
int ll_len(LinkedList* this);//saca el largo (cuantos pasajeros tengo)
/********************************************/
Node* test_getNode(LinkedList* this, int nodeIndex);//
/********************************************/
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
/********************************************/
int ll_add(LinkedList* this, void* pElement);//agregar pasajero
/********************************************/
void* ll_get(LinkedList* this, int index);//devolver un pasajero
/********************************************/
int ll_set(LinkedList* this, int index,void* pElement);//reemplaza el elemento(que espere x en tu lugar)
/********************************************/
int ll_remove(LinkedList* this,int index);//eliminar el elemento del lugar del indice que se especifica
/********************************************/
int ll_clear(LinkedList* this);//limpia la lista pero sigue existiendo(vaciar la botella)
/********************************************/
int ll_deleteLinkedList(LinkedList* this);//borra de memoria la lista(vacia y rompe la botella)
/********************************************/
int ll_indexOf(LinkedList* this, void* pElement);//en que posicion esta(si es que esta)
/********************************************/
int ll_isEmpty(LinkedList* this);
/********************************************/
int ll_push(LinkedList* this, int index, void* pElement);//colarse/meterse(saca el lugar)
/********************************************/
void* ll_pop(LinkedList* this,int index);//saca de la lista pero lo devuelve
/********************************************/
int ll_contains(LinkedList* this, void* pElement);//si esta contenido dentro de la lista
/********************************************/
int ll_containsAll(LinkedList* this,LinkedList* this2);//si todos los elementos de la lista 2 estan contenidos en la lista 1
/********************************************/
LinkedList* ll_subList(LinkedList* this,int from,int to);//un pedazo de la lista
/********************************************/
LinkedList* ll_clone(LinkedList* this);//nueva lista que es identica a la original
/********************************************/
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//ordena la lista
