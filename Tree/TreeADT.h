#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, size)                              \
        if (!(ptr = malloc(size))) {                   \
            fprintf(stderr, "Memory insufficient.\n"); \
            exit(EXIT_FAILURE);                        \
        }
    
// representation of binary tree
typedef struct node *treePointer;
struct node {
    treePointer leftChild;
    int data;
    treePointer rightChild;
};

// basic
treePointer exampleTree();
void FreeTree(treePointer);
void PrintTree(treePointer);

// traversal
void InOrder(treePointer);
void PreOrder(treePointer);
void PostOrder(treePointer);

// iteration traversal
void push(int*, treePointer, treePointer*);
treePointer pop(int*, treePointer*);
void IterInorder(treePointer);

// other operation
treePointer treeCopy(treePointer ori);
int treeEqual(treePointer, treePointer);



