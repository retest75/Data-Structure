#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

int main(void){
    listPointer ptr1, ptr2, temp, cont;

    /**
     * since the Create2Node() can create 2 node linked lists having same data.
     * we must change one of their data field to distinguish it.
     * finally, ptr1 = 10, 20 and ptr2 = 30, 40.
     */
    ptr1 = Create2Node();
    ptr2 = Create2Node();
    for (temp = ptr2; temp; temp = temp -> link){
        temp -> data = (temp -> data) + 20;
    }
    
    cont = concatenate(ptr1, ptr2);
    printList(ptr1); /* data = 10, 20, 30, 40 */

    freeList(ptr1);
    return 0;
}