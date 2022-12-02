#include "lab11.h"

Student * createStudent(int id, float gpa){
    Student *student = malloc(sizeof(student));

    //Malloc failure check
    if(!student) return NULL;

    student->id = id;
    student->gpa = gpa;

    return student;
}

int main(){
    Student *class[8];
    class[0] = createStudent(13, 2.345);
    class[1] = createStudent(2, 3.69420);
    class[2] = createStudent(16, 2.234);
    class[3] = createStudent(25, 1.875);
    class[4] = createStudent(1, 8.432);
    class[5] = createStudent(5, 3.412);
    class[6] = createStudent(6, 9.412);
    class[7] = createStudent(11, 12.5);

    StudentDB *db = createDatabase();

    printDB(db);

    for(int i=0; i<8; i++){
        insertStudent(db, class[i]);
        printf("\nSize = %i\n", getSize(db));
        printDB(db);
    }

    Student *worst = getMin(db);
    printf("\nMinimum ID = %i, GPA = %.2f\n", worst->id, worst->gpa);
    printDB(db);

    Student *thingOne = getStudent(db, 25);
    Student *thingTwo = getStudent(db, 8);

    printf("\nThing One: %.2f\nThing Two: %p", thingOne->gpa, thingTwo);

    freeDatabase(db);
    for(int i=0; i<8; i++){
        free(class[i]);
    }
}