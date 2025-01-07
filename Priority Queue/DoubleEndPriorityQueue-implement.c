#include <stdio.h>
#include <stdlib.h>
#include "DoubleEndPriorityQueueADT.h"

int main(){
    nodePointer header = createQueue();
    nodePointer a, b, c, d, e;
    a = createNode(82);
    b = createNode(24);
    c = createNode(30);
    d = createNode(16);

    puts("After push: ");
    pushPrior(header, a);
    pushPrior(header, b);
    pushPrior(header, c);
    pushPrior(header, d);
    printPQ(header); // [82, 30, 24, 16]

    puts("After pop: ");
    nodePointer maxPrior = getMaxPrior(header);
    nodePointer minPrior = getMinPrior(header);
    nodePointer popMax = popMaxPrior(header);
    nodePointer popMin = popMinPrior(header);
    printPQ(header); // [30, 24]

    printf("maxPrior = %d\n", maxPrior->priority); // 82
    printf("minPrior = %d\n", minPrior->priority); // 16
    printf("popMax = %d\n", popMax->priority);     // 82
    printf("popMin = %d\n", popMin->priority);     // 16

    free(popMax);
    free(popMin);
    freePQ(header);

    return 0;
}