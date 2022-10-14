#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct { 
      void *object; 
      struct listStruct *next; 
} List;

/* This function returns an empty List object with a dummy node, 
   i.e., this must be called before operations are performed on the list. 
   The parameter is a reference to an error code. 0 signifies the 
   operation was performed correctly, 1 means there was  
   insufficient memory available to initialize the list. */  
List * initList(int* errorCode){
    List *list = malloc(sizeof(List));

    if(!list) *errorCode = 1;
    else *errorCode = 0;

    return list;
}

 /* This function inserts the object of the first parameter  
   at the head of the list. The last parameter is an error  
   code (0 implies success, 1 implies insufficient memory). 
   Returns pointer to updated list if there is no error; 
   otherwise returns the given list without change.   */  
List * insertAtHead(void* value, List* list, int* errorCode){
    List *node = malloc(sizeof(List));

    if(!node){
        *errorCode = 1;
        return list;
    }

    node->object = value;

    if(list->next){
        List *temp = list->next;
        list->next = node;
        node->next = temp;
    }
    else list->next = node;

    *errorCode = 0;
    return list;
} 

 /* This function returns the object at the index location  
   (starting at 1 for the head) of the first parameter. */  
void * getAtIndex(int index, List* list){
    int i;
    for(i=0; i<index; i++) list = list->next;

    return list->object;
}

 /* This function returns the number of objects in the list. */  
int getListLength(List* list){
    int len = 0;

    while(list->next){
        len++;
        list = list->next;
    }

    return len;
}

 /* This function frees all memory allocated for a list and  
   returns NULL. */  
List * freeList(List* list){
    List *nextNode = list->next;

    while(nextNode){
        free(list);
        list = nextNode;
        nextNode = nextNode->next;
    }

    return NULL;
}

int main(){
    int errorCode = -1;
    int value = 99, value2 = 77;

    List *list = initList(&errorCode);
    printf("\nError Code: %i\n", errorCode);

    list = insertAtHead(&value, list, &errorCode);
    list = insertAtHead(&value2, list, &errorCode);
    printf("\nError Code: %i\n", errorCode);
    printf("\n%i", *((int *) getAtIndex(1, list)));
    printf("\n%i", *((int *) getAtIndex(2, list)));
    printf("\n%i\n", getListLength(list));

    freeList(list);
}