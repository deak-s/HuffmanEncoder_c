/*
 * @file frequencyList.c
 * @author Sophia Deak
 * @date Nov 9th 2018
 * @brief implementations of functions for analyzing character frequency in text 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "frequencyList.h"
#include "nodeQueue.h"


int returnLarger(const void *a, const void *b){
    int fA =  ((Pair *)a)->frequency;
    int fB =  ((Pair *)b)->frequency; 
    return (fB - fA);
}

int returnSmaller (const void *a, const void *b){
    int fA =  ((Pair *)a)->frequency;
    int fB =  ((Pair *)b)->frequency; 
    return (fA - fB);
}


FrequencyList *initializeEmptyList (size_t listSize){

    //allocating space for FL which is basically just a pointer
    FrequencyList *newList = (FrequencyList *)malloc(sizeof(FrequencyList));
            
            
    //alloc for pairList within FL, allows space for listSize # of Pairs  
    newList->pairList = (Pair *)malloc(sizeof(Pair) * listSize);

    newList->length = listSize;


     for(int i = 0; i < listSize; i++){
        char tempChar = (char)(i);
        Pair tempPair = {tempChar, 0};
        printf("size of pair %ld\n", sizeof(tempPair));
        newList->pairList[i] = tempPair; 
    }

   return newList;
}

	void  calculateFrequencies(char *input, FrequencyList **output){

         for(int x = 0; (int)input[x] != 0; x++) {
                    printf("counting %c\n", input[x]);
                   ( *output)->pairList[((int)input[x])].frequency++;
                }	
    }



void sortSmallToLarge(FrequencyList **theList){
    qsort((void *)(*theList)->pairList, (*theList)->length, sizeof(Pair), returnSmaller);
}


void sortLargeToSmall(FrequencyList **theList){
    qsort((void *)(*theList)->pairList, (*theList)->length, sizeof(Pair), returnLarger);
}



int countUnusedChars(FrequencyList **theList){
    int numberOfUnusedChars = 0;
    for(int k = 0; (*theList)->pairList[k].frequency == 0; k++){
        numberOfUnusedChars++;
    }

    //printf("unused chars %d\n", numberOfUnusedChars);
    return numberOfUnusedChars;
}
