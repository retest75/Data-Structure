#include <stdio.h>
#include <stdlib.h>
#include "TreeADT.h"

treePointer treeCopy(treePointer ori){
    treePointer temp;

    if (ori){ // original tree is not empty
        MALLOC(temp, sizeof(struct node));
        temp->leftChild = treeCopy(ori->leftChild);
        temp->rightChild = treeCopy(ori->rightChild);
        temp->data = ori->data;
        return temp;
    }
    return NULL;
}

int treeEqual(treePointer first, treePointer second){
    return ((!first && !second) ||
            (first && second && (first->data == second->data)) &&
            treeEqual(first->leftChild, second->leftChild) &&
            treeEqual(first->rightChild, second->rightChild));
}