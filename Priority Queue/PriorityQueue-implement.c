#include "PriorityQueueADT.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    element *maxPQ = newMaxPrior();
    int maxPQLen = 3;

    element *minPQ = newMinPrior();
    int minPQLen = 3;

    element item1 = {16}, item2 = {72}, item3 = {31}, item4 = {64};  // push to maxPQ
    element item5 = {101}, item6 = {11}, item7 = {23}, item8 = {10}; // push to minPQ
    element maxPrior, minPrior;

    // max priority queue
    puts("before push: ");
    printPQ(maxPQ, maxPQLen); // [82, 46, 44]
    pushMaxPrior(maxPQ, item1, &maxPQLen);
    pushMaxPrior(maxPQ, item2, &maxPQLen);
    pushMaxPrior(maxPQ, item3, &maxPQLen);
    pushMaxPrior(maxPQ, item4, &maxPQLen);

    puts("After push: ");
    printPQ(maxPQ, maxPQLen); // [82, 72, 64, 16, 49, 31, 44]

    puts("After pop: ");
    printf("pop element: %d\n", popMaxPrior(maxPQ, &maxPQLen).priority); // 82
    printPQ(maxPQ, maxPQLen); // [72, 49, 64, 16, 44, 31]
    
    // min priority queue
    puts("before push: ");
    printPQ(minPQ, minPQLen); // [5, 8, 12]
    pushMinPrior(minPQ, item5, &minPQLen);
    pushMinPrior(minPQ, item6, &minPQLen);
    pushMinPrior(minPQ, item7, &minPQLen);
    pushMinPrior(minPQ, item8, &minPQLen);

    puts("After push: ");
    printPQ(minPQ, minPQLen); // [5, 8, 10, 101, 11, 23, 12]

    puts("After pop: ");
    printf("pop element: %d\n", popMinPrior(minPQ, &minPQLen).priority); // 5
    printPQ(minPQ, minPQLen); // [8, 11, 10, 101, 12, 23]

    free(maxPQ);
    free(minPQ); 
    return 0;
}