#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

void IsFULL(int rear){
    if (rear == (MAX_QUEUE_SIZE - 1)){
        fprintf(stderr, "The queue is FULL.\n");
        exit(EXIT_FAILURE);
    }
}

/*
 * There are two methods to judge if queue is EMPTY:
 * (1) When front = -1 or rear = -1, queue is EMPTY.
 * (2) When rear > front, queue is FULL.
 */
void IsEMPTY(int front, int rear){
    if ((front < 0) || (front > rear)){
        fprintf(stderr, "The queue is EMPTY.\n");
        exit(EXIT_FAILURE);
    }
}

void addq(int *front, int *rear, element item, element queue[]){
    IsFULL(*rear);
    queue[++(*rear)] = item;
    
    /* if insert the first item, then initialize front */
    if ((*front) == -1)
        *front = 0;
    
    printf("front = %d, rear = %d\n", *front, *rear);
}

/**
 * When delete the last item, queue is EMPTY.
 * Then must initialize front and rear to -1.
 */
element deleteq(int *front, int *rear, element queue[]){
    element item ;

    IsEMPTY(*front, *rear);
    item = queue[(*front)++];

    /* initialize the queue */
    if ((*front) > (*rear)){
        *front = -1;
        *rear = -1;
    }

    printf("front = %d, rear = %d\n", *front, *rear);

    return item;
}

/**
 * The following 2 functions are used for circular queue.
 */
void add_cq(int *front, int *rear, element item, element queue[]){
    *rear = (*rear + 1) % MAX_QUEUE_SIZE; /* rear plus 1, first */

    /* if insert the first item, then initialize front */
    if (*front == -1)
        *front = 0;
    
    if ((*front == *rear)){ /* if (rear plus 1) equal front, ten queue is full */
        fprintf(stderr, "The queue is FULL.\n"); 
        exit(EXIT_FAILURE);
    }
    
    queue[*rear] = item;
    printf("front = %d, rear = %d\n", *front, *rear);
}

element delete_cq(int *front, int *rear, element queue[]){
    element item;

    if (*front == *rear){
        fprintf(stderr, "The queue is EMPTY.\n");
        exit(EXIT_FAILURE);
    }

    item = queue[*front];
    *front = (*front + 1) % MAX_QUEUE_SIZE;
    printf("front = %d, rear = %d\n", *front, *rear);
    
    return item;
}

/**
 * The following function are used for dynamic queue
 */
void copy(int a, int b, int c, element old_queue[], element new_queue[]){
    int i, length;

    length = (b - a) + 1;
    
    for (i = 0; i < length; i++){
        new_queue[c+i] = old_queue[a+i];
    }
}

void queueFULL(int *front, int *rear, int *capacity, element **queue){
    int start;
    element *new_queue;
    
    MALLOC(new_queue, 2 * (*capacity) * sizeof(element));
    start = (*front + 1) % (*capacity); /* the first element in old_queue */
    
    if (start < 2){
        copy(start, *rear, 0, *queue, new_queue);
    }
    else{
        copy(start, *capacity-1, 0, *queue, new_queue);
        copy(0, *rear, (*capacity) - (*front) - 1, *queue, new_queue);
    }
    
    *rear = *capacity - 2;
    *front = (*capacity) * 2 - 1;
    *capacity *= 2;

    free(*queue);
    *queue = new_queue;
}

void dynamic_addq(int *front, int *rear, int *capacity, element item, element **queue){
    int next;
    
    next = (*rear + 1) % (*capacity);

    if (next == *front)
        queueFULL(front, rear, capacity, queue);
    
    (*queue)[++(*rear)] = item;
    printf("front = %d, rear = %d\n", *front, *rear);
}

element dynamic_deleteq(int *front, int *rear, int *capacity, element queue[]){
    element item;
    
    if (*front == *rear){
        fprintf(stderr, "The queue is EMPTY.\n");
        exit(EXIT_FAILURE);
    }

    *front = (*front + 1) % (*capacity);
    item = queue[*front];
    printf("front = %d, rear = %d\n", *front, *rear);
    
    return item;
}
