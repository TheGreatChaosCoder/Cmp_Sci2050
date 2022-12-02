#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	float gpa;
} Student;

typedef struct StudentDB StudentDB;

StudentDB * createDatabase();

int getSize(StudentDB *db);

int insertStudent(StudentDB *db, Student *s);

void printDB(StudentDB *db);

Student * getStudent(StudentDB *db, int id);

Student * getMin(StudentDB *db);

void freeDatabase(StudentDB *db);
