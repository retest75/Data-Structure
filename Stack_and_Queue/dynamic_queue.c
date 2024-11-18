#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

int main(){
    
    element a = {10};
    element b = {20};
    element c = {30};
    element d = {40};

    int i;
    int rear = 0, front = 0;
    int capacity = 3;
    element *queue;

    MALLOC(queue, capacity * sizeof(element));
    printf("Original address:   %x\n", queue);

    dynamic_addq(&front, &rear, &capacity, a, &queue); /* front = 0, rear = 1 */
    dynamic_addq(&front, &rear, &capacity, b, &queue); /* front = 0, rear = 2 */
    dynamic_addq(&front, &rear, &capacity, c, &queue); /* front = 5, rear = 2 */
    dynamic_addq(&front, &rear, &capacity, d, &queue); /* front = 5, rear = 3 */


    dynamic_deleteq(&front, &rear, &capacity, queue);  /* front = 0, rear = 3 */
    dynamic_deleteq(&front, &rear, &capacity, queue);  /* front = 1, rear = 3 */

    for (i=front+1; i<=rear; i++){
        printf("queue[%d] = %d\n", i, queue[i].key);
    }

    free(queue);
    printf("After expand queue: %x\n", queue);

    return 0;
}