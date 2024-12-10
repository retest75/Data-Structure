#include <stdio.h>
#include <stdlib.h>
#include "TreeADT.h"

int main(void){
    treePointer root;
    root = exampleTree();

    // inorder: 4 2 5 1 3
    printf("Inorder traversal: ");
    InOrder(root);
    printf("\n");

    // preorder: 1 2 4 5 3
    printf("Preorder traversal: ");
    PreOrder(root);
    printf("\n");

    // Postorder: 4 5 2 3 1
    printf("Postorder traversal: ");
    PostOrder(root);
    printf("\n");

    // IterInorder: 4 2 5 1 3
    printf("IterInorder traversal: ");
    IterInorder(root);
    FreeTree(root);

    return 0;
}