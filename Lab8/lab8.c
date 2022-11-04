#include "lab8.h"

struct Node {
	Node *next;
	void *data;
};

struct Queue {
	Node *list;
	int size;
};

/**
 * @brief This function returns a pointer to a Queue, or NULL if it fails to create the Queue.
 * Size will initially be zero. This functions performs with a O(1) time complexity.
 * 
 * @return A pointer to the Queue 
 */
Queue * makeQueue(){
	Queue *queue = malloc(sizeof(Queue));

	//Malloc Fail Check for Queue
	if(!queue) return NULL;

	queue->list = malloc(sizeof(Node));

	//Malloc Fail Check for List Node
	if(!(queue->list)) return NULL;

	queue->size = 0;
	return queue;
}

/**
 * @brief Given a pointer to a queue, it returns the size of the queue.
 * This functions performs with a O(1) time complexity.
 * 
 * @param q A pointer to a queue
 * @return The size of the queue
 */
int getSize(Queue *q){
	return q->size;
}

/**
 * @brief Given a queue passed by reference, it enqueues a given data pointer onto the queue.
 * Returns 0 if it sucessfully enqueues, 1 otherwise. This functions performs with a O(n) 
 * time complexity where n is the size of the queue.
 * 
 * @param q A pointer to a queue
 * @param data A pointer to data
 * @return Error Code: 0 - Successful, 1 - Failed to Enqueue
 */
int enQueue(Queue *q, void *data){
	Node *node = q->list;

	//Goes through the list until it reaches the last node
	while(node->next) node = node->next;

	//Creating the new node
	node->next = malloc(sizeof(Node));
	//Malloc fail check
	if(!(node->next)) return 1;

	node->next->data = data;
	q->size = q->size + 1;
	return 0;
}

/**
 * @brief Given a pointer to a queue, it will dequeue it. It will return the data pointer
 * that got dequeued or NULL if the queue was already empty. This functions performs at
 * a O(1) time complexity.
 * 
 * @param q A pointer to a queue
 * @return A pointer to the data that got dequeued 
 */
void * deQueue(Queue *q){
	//Check if the queue exists and it is not empty
	if(!q || !(q->list->next)) return NULL;

	void *data = q->list->next->data;
	//This node is the dequeued node
	Node *tmp = q->list->next;

	q->list->next = tmp->next;
	free(tmp);

	q->size = q->size - 1;
	return data;
}

/**
 * @brief Given a pointer to a queue, it returns a pointer to the data at
 * the front of the queue without dequeuing it. If the queue is empty, the
 * function will return NULL. This functions performs with a O(1) time complexity.
 * 
 * @param q A pointer to a queue
 * @return A pointer to the data at the front of the queue
 */
void * peek(Queue *q){
	return q->list->next ?
		   q->list->next->data : NULL;
}

/**
 * @brief If a queue was created by makeQueue(), this function must be used
 * to free it. This functions performs with a O(n) time complexity where n
 * is the size of the queue.
 * 
 * @param q A pointer to a queue created by makeQueue()
 */
void freeQueue(Queue *q){
	//The tmp node stays ahead of the node that will be freed
	Node *tmp = q->list->next;

	while(tmp){
		free(q->list);
		q->list = tmp;
		tmp = q->list->next;
	}

	free(q->list);
	free(q);
}
