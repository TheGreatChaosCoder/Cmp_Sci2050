#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float gpa;
	int id;
} Student;

Student * createArray(int size);
int getSize(Student *array);
Student * getStudent(Student *array, int index);
float getGPA(Student *s);
int getID(Student *s);

Student * getMaxID(Student *array);

void freeArray(Student *array);
