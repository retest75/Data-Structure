#include <stdio.h>
#include <stdlib.h>
#include "LinkedListADT.h"

int main(){
    listPointer last;
    listPointer front, behind;
    int len;

    /* initialize node */
    MALLOC(front, sizeof(*front));
    MALLOC(behind, sizeof(*behind));
    front -> data = 0;
    behind -> data = 30;
    front -> link = NULL;
    behind -> link = NULL;

    /* insert */
    last = createCircularList();  /* data = 10, 20 */
    insertFront(&last, front);    /* data = 0, 10, 20 */
    insertLast(&last, behind);    /* data = 0, 10, 20, 30 */

    len = length(last);
    printf("Length = %d\n", len); /* length = 4 */

    return 0;
}