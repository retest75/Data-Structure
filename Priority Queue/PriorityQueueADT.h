#define MALLOC(ptr, size) \
    if (!(ptr = malloc(size))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE); \
    }

#define MAX_SIZE 15


// element in priority queue
typedef struct 
{
    int priority;
} element;

element *newMaxPrior();
element *newMinPrior();
void printPQ(element *, int);

element getMaxPrior(element *);
void pushMaxPrior(element *, element, int *);
element popMaxPrior(element *, int *);

element getMinPrior(element *);
void pushMinPrior(element *, element , int *);
element popMinPrior(element *, int *);



