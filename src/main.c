#include<stdio.h>
#include "llist.h"

int main(int argc, char **argv) {
  llist *exemplo = LinkedList_Create();
  LinkedList_Prepend(exemplo, 1);
  LinkedList_Show(exemplo);
  return 0;
}
