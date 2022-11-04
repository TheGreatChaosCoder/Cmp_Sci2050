#include "lab8.h"

int main(){
    printf("\nMaking queue");
    Queue *queue = makeQueue();

    printf("\nfreeing empty"); freeQueue(queue);

    printf("\nMaking queue (again)");
    queue = makeQueue();

    int one = 25, two=44, three=1, four=109;

    printf("\nempty queue testing");
    printf("\nEmpty dequeue: %s", !((char *)deQueue(queue)) ? "Good": "Uh oh");
    printf("\nEmpty peek: %s", !((char *) peek(queue)) ? "Good": "Uh oh");

    printf("\nqueuing one");
    enQueue(queue, &one);
    printf("\nqueuing two");
    enQueue(queue, &two);
    printf("\nqueuing three");
    enQueue(queue, &three);
    printf("\npeek: %i", *((int *) peek(queue)));
    printf("\ndequeuing");
    printf("\n%i", *((int *) deQueue(queue)));
    printf("\nqueuing four");
    enQueue(queue, &four);
    printf("\npeek: %i", *((int *) peek(queue)));
    printf("\ndequeuing");
    printf("\n%i", *((int *) deQueue(queue)));
    printf("\nSize: %i", getSize(queue));
    printf("\nfreeing\n");
    freeQueue(queue);
}