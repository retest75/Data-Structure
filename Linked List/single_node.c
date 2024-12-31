#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

int main(void){
    listPointer first = NULL;      /* create a linked list whose name is first */

    MALLOC(first, sizeof(*first)); /* create a node */

    first->data = 50;   /* assign data */
    first->link = NULL; /* assign link */

    printf("The data in first node: %d\n", first->data);
    printf("The link in first node: %p\n", first->link);
    free(first);
    
    return 0;
}