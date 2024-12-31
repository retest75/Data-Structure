#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

void main(){
    
    element *stack;
    element year = {1995}, month = {11}, date = {20};
    element month2 = {10}, date2 = {19};

    int top = -1;
    int i;
    int capacity = 3;

    MALLOC(stack, capacity * sizeof(element)); /* allocate memory space for stack */

    /* push 3 elements */
    dynamic_push(&top, &capacity, year, stack);
    dynamic_push(&top, &capacity, month, stack);
    dynamic_push(&top, &capacity, date, stack);

    for (i = 0; i <= top; i++){
        printf("stack[%d] = %d\n", i, stack[i].key);
    }

    /* stack is FULL, then expand it */
    printf("capacity = %d\n", capacity);           /* capacity = 3 */
    dynamic_push(&top, &capacity, month2, stack);  /* capacity = 6 */
    dynamic_push(&top, &capacity, date2, stack);   /* capacity = 6 */

    for (i = 0; i <= top; i++){
        printf("stack[%d] = %d\n", i, stack[i].key);
    }

    printf("capacity = %d\n", capacity);           /* capacity = 6 */
    free(stack);

}