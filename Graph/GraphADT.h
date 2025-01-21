#include <stdlib.h>
#define MALLOC(ptr, size)           \
        if (!(ptr = malloc(size))){ \
            fprintf(stderr, "Memort insufficient !\n"); \
            exit(EXIT_FAILURE);     \
        }
#define FALSE 0
#define TRUE 1
#define MAXSIZE 10
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef struct node *nodePointer;
struct node {
    int vertexIdx;
    nodePointer link;
};

// basic
nodePointer createNode(int);
void addEdge(nodePointer *, int, int);
void printAdjList(nodePointer *, int);
void resetVisited(int *);
void freeList(nodePointer *, int);

// search
void dfsUsingRecursion(nodePointer *, int *, int);
void dfsUsingStack(nodePointer *, int *, int);
void bfs(nodePointer *, int *, int);

// find connected
void findConnected(nodePointer *, int *, int);

// find biconnected
struct edge{
    int u;
    int v;
};
void init(int*, int*, int *);
void countDFNLOW(nodePointer *, int *, int *, int *, int, int, int *);
void findBCC(nodePointer *, int *, int *,int *, int, int, int *, struct edge *, int *);
