#include <stdlib.h>
#include <stdio.h>

typedef struct { 
     int empID, jobType; 
     float salary; 
} Employee; 

Employee * readEmployeeArray(FILE *fp) {
    int size, i=0;
    fscanf(fp, "%i", &size);

    Employee *list = malloc(sizeof(int) + size*sizeof(Employee));

    if(!list) return NULL;

    *((int*) list) = size;
    list = (Employee*) (((int*) list) + 1);

    while(!feof(fp)){
        //fscanf(fp, "%i,%i,%f", &(id), &(job), &(salary));
        fscanf(fp,"%i %i %f", &(list[i].empID), &(list[i].jobType), &(list[i].salary));
        printf("\n%i %i %.2f", list[i].empID, list[i].jobType, list[i].salary);
        i++;
    }

    return list;
}

Employee * getEmployeeByID(Employee *list, int empID){
    return &(list[empID-1]);
}

int setEmpSalary(Employee *list, int empID, float salary){
    if(salary<0) return -1;
    
    getEmployeeByID(list, empID)->salary = salary;
    return 0;
}
int getEmpSalary(Employee *list, int empID, float *salary)  {
    *salary = getEmployeeByID(list, empID)->salary;
    return  0;
}
int setEmpJobType(Employee *list, int empID, int job){
    if(job<0) return -1;
    
    getEmployeeByID(list, empID)->jobType = job;
    return 0;
}
int getEmpJobType(Employee *list, int empID, int *job){
    *job = getEmployeeByID(list, empID)->jobType;
    return 0;
}

int getSize(void * array){
    return *(((int*)array)-1);
}

void freeArray(void * array){
    free(((int*)array)-1);
}

int main(){
    FILE *fptr = fopen("data.txt", "r");
    Employee *list = readEmployeeArray(fptr);
    fclose(fptr);
    float s1;
    int j2;
    setEmpJobType(list, 2, 99);
    getEmpSalary(list, 1, &s1);
    getEmpJobType(list, 2, &j2);

    printf("\n\n%i", j2);
    printf("\n%i\n", getSize(list));

    freeArray(list);
}