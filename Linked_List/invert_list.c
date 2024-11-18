#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

int main(void){
    listPointer ptr;
    listPointer invert;

    ptr = Create2Node();
    printList(ptr); /* data = 10, 20 */
    
    invert = listInvert(ptr);
    printList(invert); /* data = 20, 10 */

    freeList(ptr);
    return 0;
}