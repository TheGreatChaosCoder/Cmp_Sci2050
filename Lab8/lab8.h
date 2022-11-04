#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;


Queue * makeQueue();

int getSize(Queue *q);

int enQueue(Queue *q, void *data);

void * deQueue(Queue *q);

void * peek(Queue *q);

void freeQueue(Queue *q);
