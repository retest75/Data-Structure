#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 3
#define MALLOC(ptr, size) \
    if (!(ptr = malloc(size))) {\
        fprintf(stderr, "Insufficient memory.\n"); \
        exit(EXIT_FAILURE); \
    }
#define REALLOC(ptr, size) \
    if (!(ptr = realloc(ptr, size))) {\
        fprintf(stderr, "Insufficient memory.\n"); \
        exit(EXIT_FAILURE); \
    }

typedef struct{
    int key;
}element;

/* prototype */
void IsFull(int top);
void IsEmpty(int top);
void stackFULL(int top, int *capacity, element stack[]);

void push(int *top, element item, element stack[]);
void dynamic_push(int *top, int *capacity, element item, element stack[]);
element pop(int *top, element stack[]);

