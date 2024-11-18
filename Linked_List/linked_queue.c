#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

int main(void){
    queuePoint front[MAX_QUEUE_SIZE];
    queuePoint rear[MAX_QUEUE_SIZE];
    element a = {10}, b = {20}, c = {30};

    /* add */
    addq(front, rear, 0, a); /* Front[0] = 10 = Rear[0] */
    addq(front, rear, 0, b); /* Front[0] = 10 20 = Rear[0] */
    addq(front, rear, 0, c); /* Front[0] = 10 20 30 = Rear[0] */

    printLinkedQueue(front, 0); /* Front[0] = 10 20 30 = Rear[0] */

    /* delete */
    deleteq(front, 0);          /* Front[0] = 20 30 = Rear[0] */
    printLinkedQueue(front, 0); /* Front[0] = 20 30 = Rear[0] */
    return 0;
}