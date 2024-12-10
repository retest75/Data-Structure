#include <stdio.h>
#include <stdlib.h>
#include "TreeADT.h"

int main(void){
    treePointer treeA, treeB;

    treeA = exampleTree();
    printf("treeA: "); // treeA: 4 2 5 1 3
    PrintTree(treeA);
    printf("\n");

    treeB = treeCopy(treeA);
    printf("treeB: "); // treeB: 4 2 5 1 3 
    PrintTree(treeB);
    printf("\n");

    if (treeEqual(treeA, treeB))
        printf("The two trees are equal.\n");
    else
        printf("The two trees are NOT equal.\n");

    FreeTree(treeA);
    FreeTree(treeB);

    return 0;
}