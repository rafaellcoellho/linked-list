#ifndef _LLIST_H
#define _LLIST_H

#include <stdint.h>

typedef struct llist llist;

llist *LinkedList_Create(uint16_t item);
void LinkedList_Destroy(llist *self);
void LinkedList_Prepend(llist *self, uint16_t item);
void LinkedList_Append(llist *self, uint16_t item);
void LinkedList_Delete(llist *self, uint16_t item);
void LinkedList_Show(llist *self);

#endif // _LLIST_H
