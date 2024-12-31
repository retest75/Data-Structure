#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 3
#define MALLOC(ptr, size) \
    if (!(ptr = malloc(size))) {\
        fprintf(stderr, "Insufficient memory.\n"); \
        exit(EXIT_FAILURE); \
    }
#define REALLOC(ptr, size) \
    if (!(ptr = realloc(ptr, size))) {\
        fprintf(stderr, "Insufficient memory.\n"); \
        exit(EXIT_FAILURE); \
    }

typedef struct{
    int key;
}element ;

/* prototype */
void IsFULL(int rear);
void IsEMPTY(int front, int rear);
void addq(int *front, int *rear, element item, element queue[]);
element deleteq(int *front, int *rear, element queue[]);
void add_cq(int *front, int *rear, element item, element queue[]);
element delete_cq(int *front, int *rear, element queue[]);

void queueFULL(int *front, int *rear, int *capacity, element **queue);
void dynamic_addq(int *front, int *rear, int *capacity, element item, element **queue);
element dynamic_deleteq(int *front, int *rear, int *capacity, element queue[]);