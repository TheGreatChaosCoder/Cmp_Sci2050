#include <stdio.h>
#include <stdlib.h>

typedef struct { 
     int ssn, id;
} Employee; 

typedef struct{
    Employee *idDatabase, *ssnDatabase;
    int errorCode, size;
} EmpDatabase;

Employee makeGuy(int ssn, int id){
    Employee guy;
    guy.ssn = ssn;
    guy.id = id;
    return guy;
}


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

Employee * bubbleSortID(Employee *list, int size){
    int i, j;

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (list[j].id > list[j + 1].id)
                swap(&list[j].id, &list[j + 1].id);

    return list;
}

Employee * bubbleSortSSN(Employee *list, int size){
    int i, j;

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (list[j].ssn > list[j + 1].ssn)
                swap(&list[j].ssn, &list[j + 1].ssn);

    return list;
}

EmpDatabase createSearchableEmployeeDB(Employee **list, int size){
    EmpDatabase db;
    db.size = size;
    db.ssnDatabase = bubbleSortSSN(*list, size);
    db.idDatabase = bubbleSortID(*list, size);
    
    return db;
} 

Employee * findEmpBySSN(int ssn, EmpDatabase db){
    int low = 0, high = db.size-1, mid;

    while(high>=low){
        mid = (high+low)/2;
        if(db.ssnDatabase[mid].ssn < ssn) low = mid+1;
        else if(db.ssnDatabase[mid].ssn > ssn) high = mid-1;
        else return db.ssnDatabase + mid;
    }

    if(db.ssnDatabase[mid].ssn == ssn) return db.ssnDatabase + mid;

    return NULL;
}

Employee * findEmpByID(int id, EmpDatabase db){
    int low = 0, high = db.size-1, mid;

    while(high>=low){
        mid = (high+low)/2;
        printf("\nCurrent id: %i", db.idDatabase[mid].id);
        if(db.idDatabase[mid].id < id) low = mid+1;
        else if(db.idDatabase[mid].id > id) high = mid-1;
        else return db.idDatabase + mid;
    }

    if(db.idDatabase[mid].id == id) return db.idDatabase + mid;

    return NULL;
}

void freeEmpDatabase(EmpDatabase *db){
    free(db->idDatabase);
}

void freeEmployeeArray(Employee *array){
    free(array);
}

/*int getErrorCode(EmpDatabase db){

}*/



int main(){
    Employee *list = malloc(sizeof(Employee)*10);
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

    EmpDatabase db = createSearchableEmployeeDB(&list, 10);

    for(int i=0; i<10; i++) printf("\nID: %i", db.idDatabase[i].id);
    for(int i=0; i<10; i++) printf("\nSSN: %i", db.ssnDatabase[i].ssn);

    printf("\n%i", findEmpByID(7, db)->ssn);

    freeEmpDatabase(&db);
}