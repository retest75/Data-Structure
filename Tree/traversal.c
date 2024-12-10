#include <stdio.h>
#include <stdlib.h>
#include "TreeADT.h"
#define MAX_STACK_SIZE 10


// traversal
void InOrder(treePointer ptr){
    if (ptr){
        InOrder(ptr -> leftChild);
        printf("%d ", ptr -> data);
        InOrder(ptr -> rightChild);
    }
}

void PreOrder(treePointer ptr){
    if (ptr){
        printf("%d ", ptr -> data);
        PreOrder(ptr -> leftChild);
        PreOrder(ptr -> rightChild);
    }
}

void PostOrder(treePointer ptr){
    if (ptr){
        PostOrder(ptr -> leftChild);
        PostOrder(ptr -> rightChild);
        printf("%d ", ptr -> data);
    }
}

// iteration preorder
void push(int *top, treePointer node, treePointer stack[]){
    if (*top == MAX_STACK_SIZE-1)
        fprintf(stderr, "The stack is FULL.\n");
    else
        stack[++(*top)] = node;
}

treePointer pop(int *top, treePointer stack[]){
    if (*top == -1){
        fprintf(stderr, "The stack is EMPTY.\n");
        return NULL;
    }
    else
        return stack[(*top)--];
}

void IterInorder(treePointer ptr){
    int top = -1;
    treePointer node;
    treePointer stack[MAX_STACK_SIZE];

    for (;;){
        for (; ptr; ptr = ptr -> leftChild){
            push(&top, ptr, stack);
        }
        ptr = pop(&top, stack);
        if (!ptr) break;
        printf("%d ", ptr -> data);
        ptr = ptr -> rightChild;
    }
}




