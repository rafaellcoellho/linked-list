#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

typedef struct node* link;

typedef struct node 
{
    uint16_t item;
    link next;
} node;

struct llist 
{
    link head;
    link tail;
};

llist *LinkedList_Create(void) 
{   
    llist *self = malloc(sizeof(llist));

    self->head = NULL;
    self->tail = NULL;
    return self;
}

void LinkedList_Destroy(llist *self)
{
    link p = self->head;
    link aux;

    while (p != NULL) {
        aux = p->next;
        free(p);
        p = aux;
    }
    self->head = NULL;
    self->tail = NULL;
}

void LinkedList_Prepend(llist *self, uint16_t item)
{
    link new_node = (link) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = self->head;

    self->head = new_node;
}

void LinkedList_Append(llist *self, uint16_t item)
{
    link new_node = (link) malloc(sizeof(node));
    new_node->item = item;
    new_node->next = NULL;

    self->tail->next = new_node;
    self->tail = new_node;
}

void LinkedList_Delete(llist *self, uint16_t item)
{
    // Caso seja o primeiro item, já retira e termina a função
    link p = self->head;
    if (p->item == item) {
        self->head = p->next;
        free(p);
        return;
    }

    // Caso esteja no segundo pra frente ou não esteja na lista
    link p_after = p->next;
    while ( (p_after->item != item) && (p_after->next != NULL) ) {
        p = p_after;
        p_after = p_after->next;
    }

    // Esta na lista
    if (p_after->item == item) {
        if(p_after->next == NULL) p->next = NULL; // É o ultimo? 
        else p->next = p_after->next; 
        free(p_after);
    } else return; // Não está na lista, então acaba sem fazer nada
}

void LinkedList_Show(llist *self)
{
    if(LinkedList_IsEmpty(self)) printf("\tEmpty Linked List");
    link p = self->head;

    while(p != NULL) {
        printf("\t%d->", p->item);
        p = p->next;
    }
    printf("\n");
}

bool LinkedList_IsEmpty(llist *self)
{
    if (self->head == NULL && self->tail == NULL) return true;
    else return false;
}
