#include "lab9.h"
#include <time.h>

int main(){
    int size = 20;
    Runner runners[size];
    int i;
    srand ( time(NULL) );
    for(i=0; i<size; i++){
        runners[i].age = rand()%30+10;
        runners[i].height = 2.5 / ((float) i + 1);
        runners[i].kilometers = 1.8 * (double) i;

        printf("\nRunner %i: %i, %f, %f",
                i, runners[i].age,
                runners[i].height, runners[i].kilometers);
    }

    sortByAge(runners, size);

    printf("\n\n\nSorted List:");
    for(i=0; i<size; i++){
        printf("\nRunner %i: %i, %f, %f",
                i, runners[i].age,
                runners[i].height, runners[i].kilometers);
    }

    printf("\nIndex of Age %i: %i", 30, getByAge(runners, size, 30));
}