#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(void){
    treePointer ptr = exampleBST();
    element *itemPtr;
    int insertKey = 27;
    char insertCh = 'g';

    printf("org: ");
    traversalBST(ptr);
    printf("\n");

    // search
    itemPtr = search(ptr, 12);
    if (itemPtr)
        printf("(key, value) = (%d, %c)\n", itemPtr->key, itemPtr->ch);
    else
        printf("Not exixt");

    // iter search
    itemPtr = iterSearch(ptr, 12);
    if (itemPtr)
        printf("(key, value) = (%d, %c)\n", itemPtr->key, itemPtr->ch);
    else
        printf("Not exixt");
    
    insert(&ptr, insertKey, insertCh);  
    traversalBST(ptr);

    freeBST(ptr);
    return 0;
}