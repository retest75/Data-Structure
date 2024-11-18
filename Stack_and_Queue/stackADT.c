#include "stackADT.h"

void IsFull(int top){
    if (top == MAX_STACK_SIZE - 1){
        fprintf(stderr, "The stack is FULL.\n");
        exit(EXIT_FAILURE);
    }
}

void IsEmpty(int top){
    if (top < 0){
        fprintf(stderr, "The stack is EMPTY.\n");
        exit(EXIT_FAILURE);
    }
}

void stackFULL(int top, int *capacity, element stack[]){
    if (top == (*capacity - 1)){
        REALLOC(stack, 2 * (*capacity) * sizeof(element));
        *capacity *= 2;
    }
}

void push(int *top, element item, element stack[]){
    IsFull(*top);
    stack[++(*top)] = item; /* top plus 1 then save new item */
}

void dynamic_push(int *top, int *capacity, element item, element stack[]){
    stackFULL(*top, capacity, stack);
    stack[++(*top)] = item;
}

element pop(int *top, element stack[]){
    IsEmpty(*top);
    return stack[(*top)--]; /* return item then top subtract 1 */
}
   
