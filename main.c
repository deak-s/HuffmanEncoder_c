/*
 * @file main.c
 * @author Sophia Deak
 * @date Nov 5th 2018
 * @brief main function for running huffman encoder
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pair {
    char character;
    int frequency;
} Pair;


int compare (const void *a, const void *b){
    int fA =  ((Pair *)a)->frequency;
    int fB =  ((Pair *)b)->frequency; 
    return (fB - fA);
}

int main() {

    char shortInput[] = "Lorem ipsum dolor sit amet,";
    char testInput[] = "Lorem ipsum dolor sit amet, vim affert alterum ne. An his adipisci dissentias. Vidit debitis in his. Cu cum graeco prodesset, no has case senserit temporibus. Minim solet vis eu. An mazim liber mei, ius copiosae petentium contentiones ei.";

   // list of pairs of char and int
    Pair frequencyList[256];

    //initialize frequency list  
    for(int i = 0; i < 256; i++){
        char tempChar = (char)(i);
        Pair tempPair = {tempChar, 0};
        frequencyList[i] = tempPair; 
    }

   //iterate through input array
    for(int x = 0; (int)testInput[x] != 0; x++) {
        printf("counting %c\n", testInput[x]);
        frequencyList[((int)testInput[x])].frequency++;
    }

    int k;
    printf("frequency list\n");
    for(k = 32; k < 127; k++){
        printf("%c : %d\n", frequencyList[k].character, frequencyList[k].frequency);
    }
       
    //sort by highest to lowest frequency
    qsort(frequencyList, 256, sizeof(Pair), compare);

    printf("sorted frequency list\n");
    for( k = 0; k < 127; k++){
        printf("%c : %d\n", frequencyList[k].character, frequencyList[k].frequency);
    }
    return 0;
}
