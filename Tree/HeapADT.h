#define MAX_ELEMENT 15
#define HEAP_FULL(n) (n == MAX_ELEMENT - 1)
#define HEAP_EMPTY(n) (!n)

typedef struct 
{
    int key;
} element;

element *exampleMaxHeap();
void printHeap(element *, int);
void push(element *, element, int *);
element pop(element *, int *);

