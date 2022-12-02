#include "lab11.h"

/**
 * @brief The Node struct will help to build a binary search tree
 * for the StudentDB struct defined below.
 */
typedef struct Node Node;
struct Node { 
    Student *student;
    Node *leftNode, *rightNode;
};

/**
 * @brief The StudentDB struct will be further defined from its
 * implementation in the lab11 header file to be used like a dummy node
 * to a binary search tree that will contain all of the student data.
 * The size of the tree will also be stored in the struct.
 */
struct StudentDB {
    Node *tree;
    int size;
};

/**
 * @brief The function will create and return a pointer to an empty StudentDB struct.
 * If the struct fails to be allocated memory, the function will return NULL
 * 
 * @return An empty StudentDB struct
 */
StudentDB * createDatabase(){
    StudentDB *db = malloc(sizeof(StudentDB));

    //Malloc failure check
    if(!db) return NULL;

    //Initializing all members in the struct to be nothing
    db->tree = NULL;
    db->size = 0;

    return db;
}

/**
 * @brief Creates a node with a given Student struct passed by reference. 
 * If the node fails to be allocated memory, the function will return NULL.
 * 
 * @param s 
 * @return Node* 
 */
Node * createNode(Student *s){
    Node *newNode = malloc(sizeof(StudentDB));

    //Malloc failure check
    if(!newNode) return NULL;

    newNode->student = s;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    return newNode;
}

/**
 * @brief Given a StudentDB struct passed by reference, it will return
 * the size of the student database. This function has a time complexity
 * of O(1).
 * 
 * @param db A StudentDB struct passed by reference.
 * @return The size of the student database.
 */
int getSize(StudentDB *db){
    return db->size;
}

/**
 * @brief This is a helper function to help insert a Student struct into
 * the Binary Search Tree stored by the StudentDb struct. This functions
 * runs a recursive search that has a time complexity of O(log(n)), where
 * n is the amount of students in the tree.
 * 
 * @param tree A node to a binary search tree
 * @param studentNode A Node struct that holds the student to be inserted
 * @return The updated binary search tree
 */
Node * insertIntoTree(Node *tree, Node *studentNode){
    if(!tree){ //If there is no more tree to traverse, then it will be inserted
        return studentNode;
    }
    else{
        if(tree->student->id >= studentNode->student->id){
            tree->leftNode = insertIntoTree(tree->leftNode, studentNode);
        }
        else{
            tree->rightNode = insertIntoTree(tree->rightNode, studentNode);
        }
    }

    return tree;
}

/**
 * @brief Given a StudentDB and a Student struct, both passed by
 * reference, it will insert the student into the database. The function
 * will return 0 on a sucessful insert and 1 otherwise. The time complexity
 * for the insertion is O(log(n)), where n is the number of students already
 * in the database.
 * 
 * @param db A StudentDB struct passed by reference
 * @param s A Student struct passed by reference that will be inserted
 * @return 0 if sucessfully inserted, 1 otherwise
 */
int insertStudent(StudentDB *db, Student *s){
    /*You can always insert a NULL student correctly as it doesn't affect
    the rest of the database*/
    if(!s) return 0;

    //Create the Node first to perform failure checks early on
    Node *newStudent = createNode(s);

    //Malloc failure check
    if(!newStudent) return 1;

    /*Checks if the the current tree is not initalize (aka it is NULL).
    If it is, make the new node the head of the tree, otherwise, traverse
    the current tree*/
    if(!db->tree) db->tree = newStudent;
    else db->tree = insertIntoTree(db->tree,newStudent);

    db->size++;
    return 0;
}

/**
 * @brief This is a helper function to print all of the nodes of a
 * binary search tree in order. The function runs a recursive function
 * to print out all of the nodes. The function is expected to traverse the
 * tree in O(n) time, where n is the number of students in the tree.
 * 
 * @param tree A binary search tree
 */
void printTree(Node *tree){
    //If the node is NULL (this is the basis condition of the recursive algorithm)
    if(!tree) return ;

    //Prints left, head, then right to print in order
    printTree(tree->leftNode);
    printf("\nStudent: ID: %i, GPA: %.2f", 
            tree->student->id, tree->student->gpa);
    printTree(tree->rightNode);
}

/**
 * @brief Given a StudentDB struct, it will print out all of the students
 * in ID ascending order. It will print out the student's ID and GPA, rounded
 * to two decimal places. The function has a time complexity of O(n), where
 * n is the number of students in the database.
 * 
 * @param db A StudentDB struct passed by reference
 */
void printDB(StudentDB *db){
    //If there is no tree to traverse
    if(!db->tree){
        printf("\nThere are no students in the database\n");
        return ;
    }

    printf("\nPrinting all students: ");
    printTree(db->tree);
    printf("\n");
}

/**
 * @brief This is a helper function to help search the binary search tree
 * to find a student with a given ID. The function returns the Student struct
 * with the matching ID, or NULL otherwise. This functions runs a recursive 
 * search that has a time complexity of O(log(n)), where n is the amount of 
 * students in the tree.
 * 
 * @param tree A Node struct to a binary search tree
 * @param id An ID that will be used to search for a studetn
 * @return A Student struct with the corresponding ID, NULL otherwise
 */
Student * searchTree(Node *tree, int id){
    //If the node is NULL (this is the basis condition of the recursive algorithm)
    if(!tree) return NULL;

    if(tree->student->id == id) return tree->student;
    else{
        if(tree->student->id > id){
            return searchTree(tree->leftNode, id);
        }
        else{
            return searchTree(tree->rightNode, id);
        }
    }
}

/**
 * @brief Given a StudentDB struct passed by reference and an ID integer,
 * the function will return a student in the database that has the corresponding
 * ID. If no such thing is found, the function will return NULL. The function has
 * a time complexity of O(log(n)), where n is the number of students in the
 * database.
 * 
 * @param db A StudentDB passed by reference
 * @param id A ID integer
 * @return A Student struct with the corresponding ID, NULL otherwise
 */
Student * getStudent(StudentDB *db, int id){
    return searchTree(db->tree, id);
}

/**
 * @brief Given a StudentDB struct passed by reference, it will return the
 * Student struct with the smallest ID, or NULL if the database is empty.
 * The function will run with a time complexity of O(log(n)), where n is the
 * number of students in the database
 * 
 * @param db 
 * @return Student* 
 */
Student * getMin(StudentDB *db){
    //Make sure that the database has students
    if(!db->tree) return NULL;

    Node *currentNode = db->tree;

    //The node with the smallest ID number is the leftmost node
    while(currentNode->leftNode){
        currentNode = currentNode->leftNode;
    }

    return currentNode->student;
}

/**
 * @brief This is a helper function to free the binary tree in a StudentDB
 * struct. The function runs recursively to free all nodes in the tree.
 * The function runs with a time complexity of O(n), where n is the
 * number of nodes in the tree.
 * 
 * @param tree A Node struct to a binary tree
 */
void freeTree(Node *tree){
    //If the node is NULL (this is the basis condition of the recursive algorithm)
    if(!tree) return ;
    else{
        freeTree(tree->leftNode);
        freeTree(tree->rightNode);
        free(tree);
    }
}

/**
 * @brief If a StudentDB struct was created by createDatabase(), this
 * function must be used to free it.
 * 
 * @param db A StudentDB struct that will be freed.
 */
void freeDatabase(StudentDB *db){
    //Free the tree first
    freeTree(db->tree);
    //Then the database struct
    free(db);
}
