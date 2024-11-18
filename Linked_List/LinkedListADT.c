#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

/* for basic linked list */
listPointer Create2Node(){
    /* create and initialize a linkedlist with 2 nodes */
    
    listPointer first, second;
    MALLOC(first, sizeof(listNode));
    MALLOC(second, sizeof(listNode));

    first -> data = 10;
    first -> link = second;
    second -> data = 20;
    second -> link = NULL;

    return first;
}

void insert(listPointer *ptr, listPointer node){
    /* Insert a new node with data = 50 into the list after node */

    listPointer temp;
    MALLOC(temp, sizeof(listNode));
    temp -> data = 50;

    if (*ptr){
        temp -> link = node -> link;
        node -> link = temp;
    }

    else{
        temp -> link = NULL;
        *ptr = temp;
    }
}

void delete(listPointer *ptr, listPointer trail, listPointer node){
    /** Delete the node from the list.
     *  trail is the preceding node.
     *  ptr is the head of the list.
     */

    if (trail){ /* the deleted node is NOT head */
        trail -> link = node -> link;
    }
    else{       /* the deleted node is head*/
        *ptr = node -> link;
    }
    free(node);
}

void printList(listPointer ptr){
    for (; ptr; ptr = ptr -> link){
        printf("data = %d\n", ptr->data);
    }
}

void freeList(listPointer ptr){
    listPointer temp;

    while (ptr){
        temp = ptr;        /* save current head node */
        ptr = ptr -> link; /* move the head node to second */
        free(temp);
    }
}

