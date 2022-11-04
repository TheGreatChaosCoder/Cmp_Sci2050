#include "lab7.h"

typedef struct {
	int id;
	float gpa;
} Student;

void initializeStudents(Student *array, int size) {
	for(int i = 0; i < size; ++i) {
		Student *s = array + i;
		s->gpa = 1.0 + (float)(rand() % 300 + 1) / 100.0;

		int id = rand();
		char *bytes = (char *)(&id);
		// guarantee unique IDs but still random
		bytes[0] = (char)i;
		s->id = id;
	}
}

void printStudent(Student *s) {
	if(s) {
		printf("Student(%.2f, %10d)", s->gpa, s->id);
	} else {
		printf("Student(NULL)");
	}
}

void printStudents(Node *head) {
	int size = getSize(head);

	for(int i = 0; i < size; ++i) {
		Student *s = getAtIndex(head, i);
		printStudent(s);
		if((i + 1) % 5 == 0) {
			puts("");
		} else if((i + 1) != size) {
            printf(", ");
        } else {
        	puts("");
        }
	}
}

int main() {
	srand(255);
	int size = 10;

	Student array[size];
	initializeStudents(array, size);

	for(int i=0; i<size; i++){
		printStudent(array+i);
		printf("\n");
	}

	Node *list = makeList();
	if(!list) {
		puts("Error: makeList() returned NULL");
		return 1;
	}

	puts("Trying getSize() on empty list");
	int tsize = getSize(list);
	if(tsize) {
		puts("Error: getSize() returned unexpected value");
		printf("Expected 0, got %d\n", tsize);
	}

	Student placeholder = (Student){ 0, 0 };

	puts("Trying insertion at bad indices");
	if(!insertAtIndex(list, &placeholder, -1)) {
		puts("Error, insertAtIndex unexpectedly returned true");
	}
	if(!insertAtIndex(list, &placeholder, 2 * size)) {
		puts("Error, insertAtIndex unexpectedly returned true");
	}
	tsize = getSize(list);
	if(tsize) {
		puts("Error: getSize() returned nonzero after bad insert");
		printf("Expected 0, got %d\n", tsize);
	}

	puts("Filling list partially from head");
	for(int i = 0; i < size - 2; ++i) {
		if(insertAtIndex(list, array + i, 0)) {
			puts("Error: insertAtIndex() unexpectedly returned false");
		}
	}

	puts("Printing list");
	printStudents(list);

	int half = size / 2;
	printf("Inserting at index %d\n", half);
	if(insertAtIndex(list, array + size - 2, half)) {
		puts("Error: insertAtIndex() unexpectedly return false");
	}

	tsize = getSize(list);
	if(tsize != size - 1) {
		puts("Error: getSize() returned unexpected value");
		printf("Expected %d, got %d\n", size - 1, tsize);
	}

	printf("Inserting at index %d\n", size - 1);
	if(insertAtIndex(list, array + size - 1, size - 1)) {
		puts("Error: insertAtIndex() unexpectedly return false");
	}
	tsize = getSize(list);
	if(tsize != size) {
		puts("Error: getSize() returned unexpected value");
		printf("Expected %d, got %d\n", size, tsize);
	}

	printf("%d\n", tsize);
	puts("Printing full list");
	printStudents(list);

	puts("Testing getAtIndex()");
	Student *temp = getAtIndex(list, 0);
	if(temp != array + size - 3) {
		puts("Error: getAtIndex() returned unexpected value");
		printf("Expected: ");
		printStudent(array + size - 3);
		printf(", got: ");
		printStudent(temp);
		puts("");
	}

	temp = getAtIndex(list, half);
	if(temp != array + size - 2) {
		puts("Error: getAtIndex() returned unexpected value");
		printf("Expected: ");
		printStudent(array + size - 2);
		printf(", got: ");
		printStudent(temp);
		puts("");
	}

	temp = getAtIndex(list, size - 1);
	if(temp != array + size - 1) {
		puts("Error: getAtIndex() returned unexpected value");
		printf("Expected: ");
		printStudent(array + size - 1);
		printf(", got: ");
		printStudent(temp);
		puts("");
	}

	temp = getAtIndex(list, -1);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	temp = getAtIndex(list, size);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	temp = getAtIndex(list, 2 * size);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	puts("Emptying list");
	for(int i = 0; i < size; ++i) {
		if(!removeFromHead(list)) {
			printf("Error: removeFromHead() unexpectedly returned NULL\nCurrent iteration: %d\n", i);
		}
		tsize = getSize(list);
		if(tsize != size - (i + 1)) {
			puts("Error: getSize() incorrect after remove");
			printf("Expected: %d, got: %d\n", size - (i + 1), tsize);
		}
	}

	if(removeFromHead(list)) {
		puts("Error: removeFromHead() unexpectedly returned nonnull for empty list");
	}

	temp = getAtIndex(list, -1);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	temp = getAtIndex(list, size);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	temp = getAtIndex(list, 0);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	puts("Refilling list from tail");
	for(int i = 0; i < size; ++i) {
		if(insertAtIndex(list, array + i, i)) {
			puts("Error: insertAtIndex() unexpectedly returned false");
		}
	}

	puts("Printing refilled list");
	printStudents(list);

	puts("Freeing list");
	freeList(list);

	puts("Running additional empty list tests");

	list = makeList();

	if(removeFromHead(list)) {
		puts("Error: removeFromHead() unexpectedly returned nonnull for empty list");
	}

	temp = getAtIndex(list, -1);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	temp = getAtIndex(list, size);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	temp = getAtIndex(list, 0);
	if(temp) {
		puts("Error: getAtIndex() returned nonnull for invalid index");
	}

	freeList(list);
}
