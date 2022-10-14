#include "lab6.h"

int main(){
    Student *array = createArray(5);
    Student *oneStudent = createArray(1);
    float gpa[] = {0.3, 3.4, 4.5, 2.4, 5.6};
    int id[] = {1,5,7,2,4};
    int i;

    oneStudent[0].gpa = gpa[3];
    oneStudent[0].id = id[4];

    for(i=0; i<5; i++){
        getStudent(array, i) -> gpa = gpa[i];
        getStudent(array, i) -> id = id[i];
    }

    for(i=0; i<5; i++){
        printf("\n%i, %f", getID(getStudent(array, i)), getGPA(getStudent(array, i)));
    }

    printf("\n%i, %f", getID(getStudent(oneStudent, 0)), getGPA(getStudent(oneStudent, 0)));

    printf("\nMax Id: %i", getID(getMaxID(array)));
    printf("\nMax Id: %i", getID(getMaxID(oneStudent)));

    printf("\nSize: %i", getSize(oneStudent));

    freeArray(array);
    freeArray(oneStudent);
}