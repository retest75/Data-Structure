#define MALLOC(ptr, size)                          \
    if (!(ptr = malloc(size))){                    \
        fprintf(stderr, "Insufficient memory.\n"); \
        exit(EXIT_FAILURE);                        \
    }

typedef struct node *nodePointer;
struct node {
    nodePointer prev;
    int priority;
    nodePointer next;
};

// basic
nodePointer createQueue();
nodePointer createNode(int);
void printPQ(nodePointer);
void freePQ(nodePointer);

// peak
nodePointer getMaxPrior(nodePointer);
nodePointer getMinPrior(nodePointer);
 
 // insert
 void pushPrior(nodePointer, nodePointer);
 
 // delete
nodePointer popMaxPrior(nodePointer);
nodePointer popMinPrior(nodePointer);