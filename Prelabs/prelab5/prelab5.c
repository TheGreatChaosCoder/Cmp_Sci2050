#include <stdlib.c>
#include <stdio.c>

typedef struct { 
     int empID, jobType; 
     float salary; 
} Employee; 

Employee * readEmployeeArray(FILE *fp) {
    int size, i=0;
     fscanf(fp, "%i", length);

    Employee *list = malloc(sizeof(int) + size*sizeof(Employee));
    *((int*) list) = size;
    list = ((*int) list) + 1;

    while(!feof(fp)){
        Employee guy= list[i];
        fscanf(fptr, "%i %i %f", guy.empID, guy.jobType, guy.salary);
        i++;
    }

    return list;
}

Employee * getEmployeeByID(Employee *list, int empID){
    return list[empID];
}

int setEmpSalary(Employee *, int empID, float salary){
    
}
int getEmpSalary(Employee *, int empID, float *salary)  
int setEmpJobType(Employee *, int empID, int job) 
int getEmpJobType(Employee *, int empID, int *job)

int getSize(void * array){
    return *(((int*)array)-1);
}

void freeArray(void * array){
    free(((int*)array)-1);
}

int main(){
    FILE *fptr = fopen("data.txt", "r");
    Employee *list = readEmployeeArray(fptr);
}