#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List * lista=(List*)calloc(1,sizeof(List));
  lista->head=NULL;
  lista->tail=NULL;
  lista->current=NULL;
  return lista;
} 

void * firstList(List * lista) {
  if(lista->head ==NULL){return NULL;}
  lista->head=lista->current;
  return lista->head->data;
}

void * nextList(List * lista){
  if(lista->current->next==NULL){return NULL;}
  lista->current->next=lista->current;
  lista->current=lista->current->next;
  return lista->current->data;
}

void * lastList(List * lista) {
    if(lista->tail ==NULL){return NULL;}
    while(lista->current->next != NULL){
        lista->current=lista->current->next;
    }
    lista->tail=lista->current;
    return lista->tail->data;
}

void * prevList(List * lista) {
  if(lista->current->prev ==NULL){return NULL;}
  lista->current->prev=lista->current;
  return lista->current->data;
}

void pushFront(List * list, void * data) {
    Node* n=createNode(data);
    if(n !=NULL)
    {
        n->next=list->head;
        if(list->head !=NULL)
        {
            list->head->prev=n;
        }
        list->head=n;
    }
    

}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    Node* n=createNode(data);
    if (list->head==NULL)
        list->head=n;      
    else
        list->tail->next=n;
    list->tail=n;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
