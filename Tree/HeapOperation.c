#include <stdio.h>
#include <stdlib.h>
#include "HeapADT.h"

/** an example max heap 
 *          82
 *        /     \
 *      49      44
 *     /  \    /   \
 *    16  31  7     6
 *   /  \
 *  5    2
 * 
 */
element *exampleMaxHeap(){
    element *MaxHeap = (element *) malloc(MAX_ELEMENT * sizeof(element));
    if (!MaxHeap){
        fprintf(stderr, "Memory Insufficient.\n");
        exit(EXIT_FAILURE);
    }

    MaxHeap[0].key = 0;
    MaxHeap[1].key = 82;
    MaxHeap[2].key = 49;
    MaxHeap[3].key = 44;
    MaxHeap[4].key = 16;
    MaxHeap[5].key = 31;
    MaxHeap[6].key = 7;
    MaxHeap[7].key = 6;
    MaxHeap[8].key = 5;
    MaxHeap[9].key = 2;

    return MaxHeap;
}

void printHeap(element *heap, int n){
    printf("length of tree = %d\n", n);
    for (int i=1; i<=n; i++)
        printf("Heap[%d] = %d\n", i, (heap+i)->key);
}

void push(element *heap, element item, int *n){
    int i;
    if (HEAP_FULL(*n)){
        fprintf(stderr, "The heap is FULL.\n");
        exit(EXIT_FAILURE);
    }

    i = ++(*n); // index of new element
    
    // bubbling up
    while ((i != 1) && (item.key > heap[i / 2].key)){
        heap[i] = heap[i / 2]; // parent down
        i = i / 2;             // new node up
    }
    
    heap[i] = item;
}

element pop(element *heap, int *n){
    int parent, child;
    element item, temp;

    if (HEAP_EMPTY(*n)){
        fprintf(stderr, "The heap is EMPTY.\n");
        exit(EXIT_FAILURE);
    }

    item = heap[1];      // the root element
    temp = heap[(*n)--]; // take the last element and minor 1
    parent = 1;
    child = 2;

    while (child <= *n){

        // compare the value of two children
        if ((child < *n) && heap[child].key < heap[child+1].key)
        child++;

        // correct index for the last element
        if (temp.key > heap[child].key)
            break;

        heap[parent] = heap[child]; // bubbling up
        parent = child;             // scan next level
        child = parent * 2;         // scan next level
    }

    heap[parent] = temp;
    return item;
}
