/*
 * @file frequencyList.h
 * @author Sophia Deak
 * @date Nov 9th 2018
 * @brief header file outlining functions for analyzing character frequency in text 
 */


#include "nodeQueue.h"


#ifndef FREQUENCYLIST_H
#define FREQUENCYLIST_H

typedef struct frequencylist {
    size_t length;
    Pair *pairList;
} FrequencyList;



int returnLarger(const void *a, const void *b);


int returnSmaller (const void *a, const void *b);

FrequencyList *initializeEmptyList(size_t quantity);

void calculateFrequencies(char *input, FrequencyList **output);


void sortSmallToLarge(FrequencyList **theList);

void sortLargeToSmall(FrequencyList **theList);

int countUnusedChars(FrequencyList **theList);

#endif
