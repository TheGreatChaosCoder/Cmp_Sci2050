#include "lab7.h"

/**
 * @brief This function will returned a empty linked list with a placeholder
 * node at the beginning of the list. The size of the linked list will be
 * zero as the placeholder node will not contain any data. If the list
 * cannot be created, the function will return NULL.
 * 
 * @return A pointer to the linked list, or NULL if the function fails.
 */
Node * makeList(){
    Node *node = malloc(sizeof(Node));

    //malloc failure check
    if(!node) return NULL;

    return node;
}

/**
 * @brief Given a pointer to a linked list with a placeholder node, it will
 * return the number of elements in the list. The size of the list does not
 * include the placeholder node as it does not contain any data.
 * 
 * @param head A pointer to a linked list
 * @return The number of elements in the linked list
 */
int getSize(Node *head){
    int count = 0;

    //Iterates through all the elements until it reaches the last one
    while(head->next){
        count++;
        head = head->next;
    }

    return count;
}

/**
 * @brief Given a pointer to a linked list with a placeholder node,
 * an element containing the given data will be inserted at the
 * given index (indexing starts at zero). If index equals the size of
 * the list, the element will be added at the end of the list. The 
 * function will return 1 if sucessful. Otherwise, it will return 0
 * if an error occured, NULL data is given, or an invaild index
 * (less than zero or greater than the size of the list) is given.
 * 
 * @param head A pointer to a linked list
 * @param data Data to be added to the list
 * @param index The index where a node containing the data should be added
 * @return 1 if successful, 0 otherwise
 */
int insertAtIndex(Node *head, void *data, int index){
    //Checking for not NULL data and a valid index
    if(!data || index<0 || index>getSize(head)) return 1;

    /*Iterating through the list until the index prior to the
    given index is reached*/
    int currentIndex = 0;

    while(head->next && currentIndex<index){
        currentIndex++;
        head = head->next;
    }

    //makeList is here to make the new Node
    Node *node = makeList();
    //checking for malloc failure (aka makeList() returned NULL)
    if(!node) return 1;

    node->data = data;

    //Inserting the new node
    node->next = head->next;
    head->next = node;

    return 0;
}

/**
 * @brief Given a pointer to a linked list with a placeholder node,
 * the function will remove the first element (aka at the 0th index)
 * of the linked list and return the data value stored there. If the
 * linked list is empty, the function will return NULL.
 * 
 * @param head A pointer to a linked list
 * @return The data value stored at the head, or NULL if the list is empty
 */
void * removeFromHead(Node *head){
    //Check for empty list
    if(!(head->next)) return NULL;

    Node *p = head->next;
    void *data = p->data;
    head->next = head->next->next;

    free(p);
    return data;
}

/**
 * @brief Given a pointer to a linked list with a placeholder node,
 * the function will return the data stored at the node located at the
 * given index. If the index is out of bounds for the list, the function
 * will return NULL.
 * 
 * @param head A pointer to a linked list
 * @param index A index where data will be retrieved from
 * @return The data stored in the node at the given index, 
 *         NULL if the index is invalid
 */
void * getAtIndex(Node *head, int index){
    //Check if index is negative
    if(index<0) return NULL;

    int currentIndex = 0;

    while(head->next && currentIndex<index){
        currentIndex++;
        head = head->next;
    }

    /*If the index is greater or equal than the size of the list,
    then it would have reached the end of the list, where it will
    return NULL with this check*/
    if(!(head->next)) return NULL;

    return head->next->data;
}

/**
 * @brief If a linked list was created using makeList(),
 * this function must be used in order to free it.
 * 
 * @param head A pointer to a linked list created by makeList()
 */
void freeList(Node *head){
    Node *nextNode = head->next;

    while(nextNode){
        free(head);
        head = nextNode;
        nextNode = nextNode->next;
    }

    free(head);
}
