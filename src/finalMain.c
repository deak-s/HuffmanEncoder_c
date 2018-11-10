/*
 * @file finalMain.c
 * @author Sophia Deak
 * @date Nov 9th 2018
 * @brief main function for running huffman encoder (no debugging text)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nodeQueue.h"
#include "helpers.h"
#include "frequencyList.h"


int main(){

    char shortInput[] = "Lorem ipsum dolor sit amet, vim affert alterum ";

    size_t size= 127;
 FrequencyList *tList = initializeEmptyList(size);


 for(int k = 0; k < 13; k++){
        printf("%c : %d\n", 
                tList->pairList[k].character, 
                tList->pairList[k].frequency);
 }


 calculateFrequencies(shortInput, &tList);

 for(int k = 0; k < 127; k++){
        printf("%c : %d\n", 
                tList->pairList[k].character, 
                tList->pairList[k].frequency);
 }


 sortSmallToLarge(&tList);

 for(int k = 0; k < 127; k++){
        printf("%c : %d\n", 
                tList->pairList[k].character, 
                tList->pairList[k].frequency);
 }

int x =  countUnusedChars(&tList);

printf("int x %d\n", x);

 for(int k = x; k < 127; k++){
        printf("%c : %d\n", 
                tList->pairList[k].character, 
                tList->pairList[k].frequency);
 }


 Queue *lQueue = initializeEmptyQueue();

 //fill queue from array, skipping unused pairs at beginning of frequency list
 fillQueueFromArray(&tList->pairList[x], lQueue, (tList->length - x));

 printf("printing lQueue\n");
 printQueue(lQueue);

 deleteQueue(lQueue);

 free(tList->pairList);
 free(tList);
 free(lQueue);

    return 0;
}
