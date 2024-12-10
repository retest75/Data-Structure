#include <stdio.h>
#include <stdlib.h>
#include "TreeADT.h"

/** an example tree
*        A(1)
*       /   \
*     B(2)  C(3)
*    /   \
*  D(4)  E(5)
*/
treePointer exampleTree(){
    treePointer a, b, c, d, e;
    MALLOC(a, sizeof(*a));
    MALLOC(b, sizeof(*b));
    MALLOC(c, sizeof(*c));
    MALLOC(d, sizeof(*d));
    MALLOC(e, sizeof(*e));

    // node A
    a -> data = 1;
    a -> leftChild = b;
    a -> rightChild = c;

    // node B
    b -> data = 2;
    b -> leftChild = d;
    b -> rightChild = e;

    // node C
    c -> data = 3;
    c -> leftChild = NULL;
    c -> rightChild = NULL;

    //node D
    d -> data = 4;
    d -> leftChild = NULL;
    d -> rightChild = NULL;

    //node E
    e -> data = 5;
    e -> leftChild = NULL;
    e -> rightChild = NULL;

    return a;
}

void FreeTree(treePointer ptr){
    // use postorder traversal to relase
    if (ptr){
        FreeTree(ptr -> leftChild);
        FreeTree(ptr -> rightChild);
        free(ptr);
    }
}

void PrintTree(treePointer ptr){
    // use inorder traversal to print data
    if (ptr){
        PrintTree(ptr -> leftChild);
        printf("%d ", ptr -> data);
        PrintTree(ptr -> rightChild);
    }
}