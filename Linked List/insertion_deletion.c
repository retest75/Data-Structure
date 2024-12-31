#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

int main(void){
    listPointer first;

    /* create linked list with 2 nodes */
    printf("Create linked list:\n");
    first = Create2Node();
    printList(first); /* 10 -> 20 -> NULL */

    /* insert a node after second node */
    printf("Insert a node:\n");
    insert(&first, first->link);
    printList(first); /* 10 -> 20 -> 50 -> NULL */

    /* delete the frst node */
    printf("Delete a node:\n");
    delete(&first, NULL, first);
    printList(first); /* 20 -> 50 -> NULL */

    freeList(first);


    return 0;
}

