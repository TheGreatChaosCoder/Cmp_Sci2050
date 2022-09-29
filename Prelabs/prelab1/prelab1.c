#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool checkValidPlayer(char player[3]){
    for(int i=0; i<3; i++){
        if(player[i]!='H' && player[i]!='T'){
            return false;
        }
    }

    return true;
}

bool checkPlayer(char player[3], char tosses[3]){
    for(int k=0; k<3; k++){
        if(player[k] != tosses[k]){
            return false;
        }
    }

    return true;
}

void insertCharAtEnd(char arr[3], char newChar){
    char firstChar = arr[1];
    char secondChar = arr[2];
    arr[0] = firstChar;
    arr[1] = secondChar;
    arr[2] = newChar;
}

char toss(){

    int random = rand() % 2;
    if(random==0){
        return 'T';
    }
    else{
        return 'H';
    }
}

int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses){
    //Checks
    if(!checkValidPlayer(player1)) return 1;
    if(!checkValidPlayer(player2)) return 2;
    if(winner==NULL) return 3;
    if(numTosses==NULL) return 4;

    char tosses[3] = {toss(), toss(), toss()};
    int throws = 3;

    //printf("%c\n%c\n%c\n", tosses[0], tosses[1], tosses[2]);

    while(1){
         if(checkPlayer(player1, tosses)){
            *winner = 1;
            break;
        }
        else if(checkPlayer(player2, tosses)){
            *winner = 2;
            break;
        }
        throws++;
        insertCharAtEnd(tosses, toss());
        //printf("%c\n", tosses[2]);
    }

    *numTosses = throws;
    return 0;
}

int main(){
   // char player1[3] = {'T', 'H', 'H'};
    //char player2[3] = {'H', 'H', 'T'};
     srand ( time(NULL) );
    int winner=0, tosses=0;
    int player1Win=0, player2Win=0, i;

    for(i=1; i<=500000; i++){
        coinTossGame("THH", "HHT", &winner, &tosses);
        if(winner==1){ player1Win++;}
        else{player2Win++;}
    }
    printf("\n%f", (float) (player1Win)/ (float) i);

    /*printf("\n%i",coinTossGame("THH", "HHT", &winner, &tosses));
    printf("\n%i,%i\n", winner, tosses);*/
}