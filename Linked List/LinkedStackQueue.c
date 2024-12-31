#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

/* for linked stack and queue */
void push(stackPointer *top, int i, element item){
    stackPointer temp;
    MALLOC(temp, sizeof(*temp));

    temp -> item = item;
    temp -> link = *(top + i);
    *(top + i) = temp;
}

element pop(stackPointer *top, int i){
    element item;
    stackPointer temp;
    
    temp = (*(top + i));
    item = temp -> item;
    (*(top + i)) = temp ->link;

    free(temp);

    return item;
}

void printLinkedStack(stackPointer *top, int i){
    stackPointer temp = *(top+i);

    printf("top[%d] = ", i);
    for (; temp; temp=temp -> link){
        printf("%d ", temp->item);
    }
    printf("\n");
}

void addq(queuePoint *front, queuePoint *rear, int i, element item){
    /* create a node */
    queuePoint temp;
    MALLOC(temp, sizeof(struct queuePoint));

    temp -> item = item;
    temp -> link = NULL;

    if (front[i]){ /* front not NULL */
        rear[i] -> link = temp;
        rear[i] = temp;
    }
    else { /* front is NULL and temp is first and lat  */
        front[i] = temp;
        rear[i] = temp;
    }
}

element deleteq(queuePoint *front, int i){
    queuePoint temp = front[i];
    element item, EMPTY = {0};

    if (!temp){
        printf("The queue is EMPTY.\n");
        return EMPTY;
    }
    
    item = temp->item;       /* get data */
    front[i] = temp -> link; /* delete temp */
    free(temp);

    return item;
}

void printLinkedQueue(queuePoint *front, int i){
    queuePoint temp = *(front + i);

    printf("Front[%d] = ", i);
    for (; temp; temp = temp -> link){
        printf("%d ",temp->item.key);
    }
    printf("= Rear[%d]\n", i);
}

