#include <stdlib.h>
#include <stdio.h>

typedef struct nodeStruct{ 
      void *object; 
      struct nodeStruct *next; 
} Node;

typedef struct{
    int *size;
    Node *head;
} Queue;


/* This function returns the error code from the most
recently executed queue operation. 0 implies success,
1 implies out-of-memory error. Some functions may
document additional error conditions. NOTE: All 
queue functions assign an error code.   */
int getQueueErrorCode(Queue queue){
    if(!queue.head) return 1;
    if(!(queue.head -> next)) return 2;

    return 0;
}

/* This function returns an initialized Queue variable. 
Every queue variable must be initialized before     
applying subsequent queue functions. */
Queue queueInit(){
    Queue queue;
    queue.size = malloc(sizeof(int));
    *(queue.size) = 0;
    queue.head = malloc(sizeof(Node));
    queue.head->object = queue.head;

    return queue;
}

/* This function enqueues an object into the queue. 
For convenience, error code is returned directly
(and also can be obtained via getQueueErrorCode) */
int enqueue(void * value, Queue queue){
    Node *newNode = malloc(sizeof(Node));
    newNode->object = value;

    ((Node *)(queue.head->object))->next = newNode;
    queue.head->object = newNode;

    *(queue.size) = *(queue.size) + 1;

    return getQueueErrorCode(queue);
}

/* This function performs dequeue and returns 
object at front of queue. NULL is returned
if queue is empty and error code is set to 2. 
NOTE: User should check error code if null 
objects are permitted in the queue. */ 
void * dequeue(Queue queue){
    if(!(queue.head->next)){
        printf("\nno dequeue?");
        return NULL;
    }

    void *value = queue.head->next->object;

    if(!((queue.head->next->next))){
        free(queue.head->next);
        queue.head->object = (void *) queue.head;
    }
    else{
        Node *temp = queue.head->next;
        queue.head->next = temp->next;
        free(temp);
    }

    *(queue.size) = *(queue.size) -1;
    return value;
}  

/* This function returns the number of objects
in the queue. */
int getQueueSize(Queue queue){
    return *(queue.size);
}

/* This function uninitializes a queue and frees all 
memory associated with it. NOTE: value of Queue 
variable is undefined after this function is 
applied, i.e., it should not be used unless
initialized again using queueInit. */ 
void freeQueue(Queue queue){
    Node *temp;

    while(queue.head->next){
        printf("\n%d", *((int *) queue.head->next->object));
        temp = queue.head->next->next;
        free(queue.head->next);
        queue.head->next = temp;
    }

    free(queue.head);
    free(queue.size);
}

int main(){
    Queue queue = queueInit();
    int one = 10, two = 40, three = 33;

    enqueue(&one, queue);
    enqueue(&two, queue);
    enqueue(&three, queue);
    printf("\n%d", getQueueSize(queue));
    int *value = dequeue(queue);
    printf("\n%d", *value);
    //printf("\n%d", one);

    printf("\nabout to be free");

    freeQueue(queue);
}