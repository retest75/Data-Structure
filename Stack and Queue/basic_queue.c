#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

int main(){
    
    element a = {10};
    element b = {20};
    element c = {30};
    element d = {40};

    int i;
    int rear = -1, front = -1;
    element queue[MAX_QUEUE_SIZE]; /* create a queue */

    addq(&front, &rear, a, queue); /* front = 0, rear = 0 */
    addq(&front, &rear, b, queue); /* front = 0, rear = 1 */
    addq(&front, &rear, c, queue); /* front = 0, rear = 2 */

    deleteq(&front, &rear, queue); /* front = 1, rear = 2 */

    for (i = front; i <= rear; i++){
        printf("queue[%d] = %d\n", i, queue[i].key);
    }

    return 0;
}