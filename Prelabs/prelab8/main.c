#include <stdlib.h>
#include <stdio.h>

typedef struct nodeStruct{ 
      void *object; 
      struct nodeStruct *next; 
} Node;

typedef struct{ 
    Node *head; 
} List;

List *initList(){
    List *list = malloc(sizeof(List));
    printf("List: %p\n", list);
    list->head = malloc(sizeof(Node));
    printf("Head Node: %p\n", list->head);

    return list;
}

/* These functions insert the object of the first parameter  
   at the head/tail of the list and returns an error code:  
   0 = success, 1 means there was insufficient memory 
   and the list is not changed. */  
int insertAtHead(void* value, List list){
    Node *node = malloc(sizeof(Node));
    printf("New Node: %p\n", node);
    if(!node) return 1;

    node->next = list.head->next;
    list.head->next = node;
    node->object = value;

    return 0;
}

int insertAtTail(void* value, List list){
    Node *p = list.head;
    while(p->next) p = p->next;

    Node *node = malloc(sizeof(Node));
    printf("New Node: %p\n", node);
    if(!node) return 1;

    node->object = value;
    p->next = node;
    return 0;
}
 
/* These functions delete and return the object at 
   the head/tail. If list is empty, NULL is returned. */     
void * removeHead(List list){
    if(!(list.head->next)) return NULL;

    Node *p = list.head->next;
    list.head->next = p->next;

    void *value = p->object;
    printf("Freed Node: %p\n", p);
    free(p);
    p=NULL;
    //printf("Freed Node: %p\n", p);
    return value;
}

void * removeTail(List list){
    if(!(list.head->next)) return NULL;

    Node *p = list.head, *prev;
    while(p->next){
        prev = p;
        p = p->next;
    }

    void *value = p->object;
    printf("Freed Node: %p\n", p);
    free(p);
    p=NULL;
    prev->next = NULL;
    //printf("Freed Node: %p\n", p);
    return value;
}

void freeList(List *list){
    printf("About to free list: %p\n", list);
    Node *nextNode = list->head, *tmp=nextNode->next;
    free(list);

    while(tmp){
        printf("Freed Node !: %p\n", nextNode);
        free(nextNode);
        nextNode = tmp;
        //free(nextNode);
        tmp = tmp->next;
    }
    printf("Freed Node !: %p\n", nextNode);
    free(nextNode);
}

int main(){
    int value = 99, value2 = 77, val3 = 5;

    List *list = initList();

    insertAtHead(&value, *list);
    insertAtHead(&val3, *list);
    insertAtTail(&value2, *list);

    //printf("%i\n", *((int *)(list.head->object)));
    //printf("%i\n", *((int *)(list.head->next->object)));
    //printf("%i\n", *((int *)(list.head->next->next->object)));
    printf("Head: %i\n", *((int *)removeHead(*list)));
    printf("Tail: %i\n", *((int *)removeTail(*list)));
    //printf("%p", NULL);

    freeList(list);

    printf("\nall good");
}