#include <stdlib.h>
#include <stdio.h>

typedef struct { 
     int ssn, id;
} Employee; 

typedef struct nodeStruct{
    Employee *guy;
    struct nodeStruct *leftNode, *rightNode;
} TreeNode;

typedef struct{
    TreeNode *idDatabase, *ssnDatabase;
    int errorCode, size;
} EmpDatabase;

Employee *makeGuy(int ssn, int id){
    Employee *guy = malloc(sizeof(Employee));
    guy->ssn = ssn;
    guy->id = id;
    return guy;
}

 // Just inits your struct 
EmpDatabase createSearchableEmployeeDB(){
    EmpDatabase db;
    db.idDatabase = NULL;
    db.ssnDatabase = NULL;

    return db;
}

TreeNode *insertIntoTreeSSN(Employee *guy, TreeNode *tree){
    if(tree == NULL){
        TreeNode *node = malloc(sizeof(TreeNode));
        node->guy = guy;
        return node;
    }
    else{
        if(tree->guy->ssn <= guy->ssn){
            tree->leftNode = insertIntoTreeSSN(guy, tree->leftNode);
        }
        else{
            tree->rightNode= insertIntoTreeSSN(guy, tree->rightNode);
        }
    }

    return tree;
}

TreeNode *insertIntoTreeID(Employee *guy, TreeNode *tree){
    if(tree == NULL){
        TreeNode *node = malloc(sizeof(TreeNode));
        node->guy = guy;
        return node;
    }
    else{
        printf("\n%i", tree->guy->id);

        if(tree->guy->id >= guy->id){
            tree->leftNode = insertIntoTreeID(guy, tree->leftNode);
        }
        else{
            tree->rightNode = insertIntoTreeID(guy, tree->rightNode);
        }
    }

    return tree;
}

EmpDatabase insertEmp(Employee *guy, EmpDatabase db){
    printf("\n%i:", guy->id);
    if(db.idDatabase == NULL){
        db.idDatabase = malloc(sizeof(TreeNode));
        db.idDatabase->guy = guy;
        db.idDatabase->leftNode = NULL;
        db.idDatabase->rightNode = NULL;

        db.ssnDatabase = malloc(sizeof(TreeNode));
        db.ssnDatabase->guy = guy;
        db.ssnDatabase->leftNode = NULL;
        db.ssnDatabase->rightNode = NULL;
    }
    else{
        db.idDatabase= insertIntoTreeID(guy, db.idDatabase);
        db.ssnDatabase = insertIntoTreeSSN(guy, db.ssnDatabase);
    }
    printf("\n");

    return db;
}

Employee *searchBSTBySSN(int ssn, TreeNode *node){
    if(!node) return NULL;

    else{
        if(node->guy->ssn >= ssn){
            return searchBSTBySSN(ssn, node->leftNode);
        }
        else{
           return searchBSTBySSN(ssn, node->rightNode);
        }
    }
}

Employee *searchBSTByID(int id, TreeNode *node){

    if(!node) return NULL;

    if(node->guy->id == id) return node->guy;
    else{
        printf("\n%i", node->guy->id);
        if(node->guy->id >= id){
            return searchBSTByID(id, node->leftNode);
        }
        else{
           return searchBSTByID(id, node->rightNode);
        }
    }
}

Employee * findEmpBySSN(int ssn, EmpDatabase db){
    if(!db.ssnDatabase) return NULL;
    return searchBSTBySSN(ssn, db.ssnDatabase);
}

Employee * findEmpByID(int id, EmpDatabase db){
    if(!db.idDatabase) return NULL;
    return searchBSTByID(id, db.idDatabase);
}

void freeTree(TreeNode *node, char freeGuy){
    if(!node) return ;
    else{
        //printf("\nFreeing %p, %p", node, node->guy);

        freeTree(node->leftNode, freeGuy);
        freeTree(node->rightNode, freeGuy);

        if(freeGuy){
            printf("\nFreeing %i, %p", node->guy->id, node->guy);
            free(node->guy);
        }

        free(node);
    }
}

void freeEmpDatabase(EmpDatabase db){
    freeTree(db.idDatabase,1);
    freeTree(db.ssnDatabase,0);
}  

int main(){
    Employee *list[10];
    list[0] = makeGuy(89, 7);
    list[1] = makeGuy(95, 11);
    list[2] = makeGuy(12, 4);
    list[3] = makeGuy(67, 1);
    list[4] = makeGuy(45, 3);
    list[5] = makeGuy(54, 8);
    list[6] = makeGuy(33, 20);
    list[7] = makeGuy(108, 19);
    list[8] = makeGuy(66, 18);
    list[9] = makeGuy(77, 17);

    EmpDatabase db = createSearchableEmployeeDB();

    for(int i=0; i<10; i++){
        db = insertEmp(list[i], db);
    }

    Employee *someGuy = findEmpByID(20, db);
    Employee *anotherGuy = findEmpBySSN(90, db);

    printf("\n%i\n%p\n", someGuy->ssn, anotherGuy);

    freeEmpDatabase(db);

}
