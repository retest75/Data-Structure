#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

int main(void){
    stackPointer top[MAX_STACK_SIZE];
    element a = {10}, b = {20}, c = {30}, d = {40};
    int i;

    /* initialize linked stack */
    for (i=0; i<MAX_STACK_SIZE; i++)
        top[i] = NULL;
    
    /* push */
    push(top, 0, a);
    push(top, 1, b);
    push(top, 2, c);
    push(top, 1, d);

    printLinkedStack(top, 0); /* top[0] = 10 */
    printLinkedStack(top, 1); /* top[1] = 40 20 */
    printLinkedStack(top, 2); /* top[2] = 30 */

    /* pop */
    pop(top, 1);
    printLinkedStack(top, 0); /* top[0] = 10 */
    printLinkedStack(top, 1); /* top[0] = 20 */
    printLinkedStack(top, 2); /* top[0] = 30 */

    return 0;
}