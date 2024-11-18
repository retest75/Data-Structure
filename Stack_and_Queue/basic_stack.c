#include <stdio.h>
#include "stackADT.h"

/* MAX_STACK_SIZE = 3 */

int main (void){

    element stack[MAX_STACK_SIZE]; /* create a stack */
    element year = {1995};
    element month = {11};
    element date = {20};
    element item;
    int top = -1;
    int i;

    /* push 3 elements */
    push(&top, year, stack);
    push(&top, month, stack);
    push(&top, date, stack);

    printf("sizeof(stack) = %d\n", sizeof(stack));
    for (i = 0; i <= top; i++){
        printf("stack[%d] = %d\n", i, stack[i].key);
    }
     /* pop one element */
    item = pop(&top, stack);
    printf("poped item = %d\n", item.key);
    
    for (i = 0; i <= top; i++){
        printf("stack[%d] = %d\n", i, stack[i].key);
    }

    return 0;
}