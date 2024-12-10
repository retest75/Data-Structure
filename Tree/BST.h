#include <stdlib.h>
#include <stdio.h>
#define MALLOC(ptr, size)                                \
            if (!(ptr = malloc(size))){                  \
                fprintf(stderr, "Memory insufficiency.\n"); \
                exit(EXIT_FAILURE);                      \
            }


typedef struct node *treePointer;
typedef struct{
    int key;
    char ch;
} element;

struct node{
    treePointer leftChild;
    element data;
    treePointer rightChild;
};

treePointer exampleBST();
void traversalBST(treePointer);
void freeBST(treePointer);
element *search(treePointer, int);
element *iterSearch(treePointer, int);
void insert(treePointer *, int, char);
treePointer modifiedSearch(treePointer, int);