#include <stdio.h>
#include <stdlib.h>
#define MALLOC(ptr, size) \
    if (!(ptr = malloc(size))){\
        fprintf(stderr, "Insufficient memory.\n");\
        exit(EXIT_FAILURE);\
    }
#define MAX_STACK_SIZE 3
#define MAX_QUEUE_SIZE 3

/* for basic linked list */
typedef struct listNode listNode;
typedef struct listNode *listPointer;
struct listNode{
    int data ;
    listPointer link;
};

listPointer Create2Node();
void insert(listPointer *, listPointer);
void delete(listPointer *, listPointer , listPointer);
void printList(listPointer);
void freeList(listPointer);

/* for linked stack */
typedef struct {
    int key;
} element;

typedef struct stack *stackPointer;
struct stack{
    element item;
    stackPointer link;
};

void push(stackPointer *, int, element);
element pop(stackPointer *, int);
void printLinkedStack(stackPointer *, int);

/* for linked queue */
typedef struct queuePoint *queuePoint;
struct queuePoint{
    element item;
    queuePoint link;
};

void addq(queuePoint *, queuePoint *, int, element);
element deleteq(queuePoint *, int i);
void printLinkedQueue(queuePoint *, int);

/* for other linked list operation */
listPointer listInvert(listPointer);
listPointer concatenate(listPointer, listPointer);
listPointer createCircularList();
void insertFront(listPointer *, listPointer);
void insertLast(listPointer *, listPointer);
int length(listPointer);

/* for doubly linked list */
typedef struct node *nodePointer;
struct node {
    int data;
    nodePointer llink, rlink;
};


