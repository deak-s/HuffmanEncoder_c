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


FrequencyList *initializeEmptyList(){

    FrequencyList *newList = (FrequencyList *)malloc(sizeof(FrequencyList));

     for(int i = 0; i < 256; i++){
        char tempChar = (char)(i);
        Pair tempPair = {tempChar, 0};
        newList->pairList[i] = tempPair; 
    }

   return newList;

}

//function to collect input


//function to iterate through input

