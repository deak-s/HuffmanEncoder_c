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
    Pair pairList[256];
} FrequencyList;



int returnLarger(const void *a, const void *b);


int returnSmaller (const void *a, const void *b);

FrequencyList *initializeEmptyList();


#endif
