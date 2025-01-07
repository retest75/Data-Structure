#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueueADT.h"

/**
 * The following is an example of max priority queue which is the output of newMaxPrior
 *   82
 *  /  \
 * 49  44
 * The following is an example of min priority queue which is the output of newMinPrior
 *   5
 *  / \
 * 8  12
 * Both of then use 0-index
 */

element *newMaxPrior(){
    element *ptr;
    MALLOC(ptr, sizeof(element) * MAX_SIZE);
    
    ptr[0].priority = 82;
    ptr[1].priority = 49;
    ptr[2].priority = 44;
    
    return ptr;
}

element *newMinPrior(){
    element *ptr;
    MALLOC(ptr, sizeof(element) * MAX_SIZE);

    ptr[0].priority = 5;
    ptr[1].priority = 8;
    ptr[2].priority = 12;

    return ptr;
}

void printPQ(element *pq, int n){
    /** print priority queue
     * Parameter
     * ------------
     * pq: priority queue
     * n: length of priority queue
     */
    printf("Priority Queue = ");
    for (int i = 0; i < n; i++){
        printf("%d ", pq[i].priority);
    }
    puts("");
}

// operation for max priority queue
element getMaxPrior(element *pq){
    /** get element with max priority in max priority queue
     * Parameters
     * ------------
     * pq: a max priority queue
     */
    return pq[0];
}

void pushMaxPrior(element *pq, element item, int *n){
    if (*n >= MAX_SIZE){
        fprintf(stderr, "The queue us FULL.\n");
        exit(EXIT_FAILURE);
    }

    // bubble up
    int i = (*n)++; // index of new element
    int parent = (i - 1) / 2;
    while ((i != 0) && (pq[parent].priority < item.priority)){
        pq[i] = pq[parent];
        i = parent;
        parent = (i - 1) / 2;
    }

    pq[i] = item;
}

element popMaxPrior(element *pq, int *n){
    if ((*n) <= 0){
        fprintf(stderr, "The queue us EMPTY.");
        exit(EXIT_FAILURE);
    }

    // bubble down
    element res = pq[0];      // root
    element temp = pq[--(*n)]; // take last element and minor 1
    int parent = 0, child = 2 * parent + 1;
    while (child < *n){
        // check right node exist and compare two children
        if ((child + 1 < *n) && (pq[child].priority < pq[child+1].priority)){
            child++;
        }

        // if the parent is larger than the largest child, stop
        if (temp.priority > pq[child].priority){
            break;
        }

        // otherwise, move to next level
        pq[parent] = pq[child];
        parent = child;
        child = 2 * parent + 1;
    }

    pq[parent] = temp;
    return res;
}

// operation for min priority queue
element getMinPrior(element *pq){
    return pq[0];
}

void pushMinPrior(element *pq, element item, int *n){
    if (*n >= MAX_SIZE){
        fprintf(stderr, "The priority queue is FULL.\n");
        exit(EXIT_FAILURE);
    }

    // bubble up
    int i = (*n)++; // last index
    int parent = (i - 1) / 2;
    while (i != 0 && pq[parent].priority > item.priority){
        pq[i] = pq[parent];
        i = parent;
        parent = (i - 1) / 2;
    }
    pq[i] = item;
}

element popMinPrior(element *pq, int *n){
    if (*n <= 0){
        fprintf(stderr, "The priority queue is EMPTY.\n");
        exit(EXIT_FAILURE);
    }

    // bubble down
    element res = pq[0];
    element temp = pq[--(*n)];
    int parent = 0, child = 2 * parent - 1;
    while (child < *n){
        if ((child + 1 < *n) && pq[child].priority > pq[child+1].priority){
            child++;
        }

        if (pq[parent].priority > pq[child].priority){
            pq[parent] = pq[child];
            parent = child;
            child = 2 * parent + 1;
        }
        else {
            break;
        }

        pq[parent] = temp;
    }

    return res;
}




