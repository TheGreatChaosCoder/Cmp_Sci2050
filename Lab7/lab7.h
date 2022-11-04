#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	void *data;
	Node *next;
};

Node * makeList();
int getSize(Node *head);
int insertAtIndex(Node *head, void *data, int index);
void * removeFromHead(Node *head);
void * getAtIndex(Node *head, int index);

void freeList(Node *head);
