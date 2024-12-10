#include <stdio.h>
#include <stdlib.h>
#include "HeapADT.h"

int main(void){
    element *MaxHeap = exampleMaxHeap(); // length = 9
    element item1 = {7}, item2 = {50}, item3;
    int n = 9;

    printHeap(MaxHeap, n);

    printf("--- Push: heap[%d] = %d ---\n", n+1, item1.key);
    push(MaxHeap, item1, &n);
    printHeap(MaxHeap, n);

    printf("--- Push: heap[%d] = %d ---\n", n+1, item2.key);
    push(MaxHeap, item2, &n);
    printHeap(MaxHeap, n);

    printf("--- Pop: heap[1] = %d ---\n",MaxHeap[1].key);
    item3 = pop(MaxHeap, &n);
    printHeap(MaxHeap, n);    

    free(MaxHeap);
    return 0;
}