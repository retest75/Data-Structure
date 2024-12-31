#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

listPointer listInvert(listPointer lead){
    /**
     * lead is the linked list which we want to invert.
     * middle is the linked list which save inverted list.
     */

    listPointer middle, trail;
    middle = NULL; /* initialize middle */

    while (lead){
        trail = middle;
        middle = lead;
        lead = lead -> link;
        middle -> link = trail;
    }

    return middle;
}

listPointer concatenate(listPointer ptr1, listPointer ptr2){
    listPointer temp;

    if (!ptr1) return ptr2;
    if (!ptr2) return ptr1;

    for (temp=ptr1; temp -> link; temp = temp -> link); /* find the last node of ptr1 */
    temp -> link = ptr2;

    return ptr1;
}

listPointer createCircularList(){
    listPointer first, second;
    MALLOC(first, sizeof(*first));
    MALLOC(second, sizeof(*second));
    
    /* data */
    first -> data = 10;
    second -> data = 20;

    /* link */
    first -> link = second;
    second -> link = first;

    return second;
}

void insertFront(listPointer *last, listPointer node){
    if (!(*last)){ /* pre is NULL */
        *last = node;
        node -> link = node;
    }
    else {
        node -> link = (*last) -> link;
        (*last) -> link = node;
    }
}

void insertLast(listPointer *last, listPointer node){
    if (!(*last)){ /* pre is NULL */
        *last = node;
        node -> link = node;
    }
    else {
        node -> link = (*last) -> link;
        (*last) -> link = node;
        (*last) = node;
    }
}

int length(listPointer last){
    int count = 0;
    listPointer temp = last;

    do {
        count++;
        temp = temp -> link;
    } while (temp != last);

    return count;
}


