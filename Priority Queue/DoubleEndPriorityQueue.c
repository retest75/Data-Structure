#include <stdio.h>
#include <stdlib.h>
#include "DoubleEndPriorityQueueADT.h"

// basic
nodePointer createQueue(){
    // create header node
    nodePointer header;
    MALLOC(header, sizeof(struct node));
    header->next = NULL;
    header->prev = NULL;

    return header;
}

nodePointer createNode(int priority){
    nodePointer node;
    MALLOC(node, sizeof(struct node));
    node->next = NULL;
    node->prev = NULL;
    node->priority = priority;

    return node;
}

void printPQ(nodePointer pq){
    nodePointer ptr = pq->next;

    printf("Priority Queue = ");
    while (ptr){
        printf("%d ", ptr->priority);
        ptr = ptr->next;
    }
    puts("");
}

void freePQ(nodePointer pq){
    nodePointer ptr;

    while (pq){
        ptr = pq;
        pq = pq->next;
        free(ptr);
    }
}

// peak
nodePointer getMaxPrior(nodePointer pq){
    nodePointer firstNode = pq->next;

    if (!firstNode){
        fprintf(stderr, "The priority queue is EMPTY.\n");
        return NULL;    
    }
    return firstNode;
}

nodePointer getMinPrior(nodePointer pq){
    nodePointer firstNode = pq->next;
    if (!firstNode){
        fprintf(stderr, "The priority queue is EMPTY.\n");
        return NULL;
    }

    while (firstNode->next){
        firstNode = firstNode->next;
    }
    return firstNode;
}

// insert
void pushPrior(nodePointer pq, nodePointer node){
    nodePointer ptr = pq->next; // firstNode

    // if priority is NULL, node is the first node
    if (!ptr){
        pq->next = node;
        node->prev = pq;
        node->next = NULL;
        return; // if no return, the function will proceed
    }

    // traversal the while list to find correct position until
    //  (1) ptr is last or
    //  (2) ptr < node
    while (ptr->next){
        if (ptr->priority < node->priority){
            break;
        }
        ptr = ptr->next;
    }

    // if ptr is last and ptr > node
    if ((!ptr->next) && ptr->priority >= node->priority){
        node->next = ptr->next;
        node->prev = ptr;
        ptr->next = node;
        return; // if no return, the function will proceed
    }

    // ptr < node
    node->next = ptr;       // node link to next
    node->prev = ptr->prev; // node link to prev
    ptr->prev->next = node; // prev link to node
    ptr->prev = node;       // ptr link to node
}

// delete
nodePointer popMaxPrior(nodePointer pq){
    nodePointer ptr = pq->next;
    
    if (!ptr){
        fprintf(stderr, "The priority queue is EMPTY.\n");
        return NULL;
    }
    pq->next = ptr->next;     // pq link to second node

    // if second node is not NULL
    if (ptr->next){
        ptr->next->prev = pq; // second node link to pq
    }
    
    // split ptr
    ptr->next = NULL;
    ptr->prev = NULL;

    return ptr;
}

nodePointer popMinPrior(nodePointer pq){
    nodePointer ptr = pq->next;

    // null list
    if (!ptr){
        fprintf(stderr, "The priority queue is  EMPTY.\n");
        return NULL;
    }

    // traversal whole list to last node
    // after traversal, ptr is the last node and we have to remove it
    while (ptr->next){
        ptr = ptr->next;
    }
    ptr->prev->next = NULL; // the previous of last node link to NULL

    // split last node
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}