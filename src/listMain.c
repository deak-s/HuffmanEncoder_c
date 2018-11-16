/*
 * @file listfinalMain.c
 * @author Sophia Deak
 * @date Nov 9th 2018
 * @brief main running huffman encoder (no debugging text)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nodeQueue.h"
#include "helpers.h"
#include "frequencyList.h"
#include "linkedList.h"


int main(){


    List *testList = initializeList();

    Node A ={'a', 3};
    Node B = {'b', 7};
    Node C = {'c', 2};
    Node D = {'d', 9};
    Node E = {'e', 1};


    addToSortedList(&A, testList);
    addToSortedList(&B, testList);
    addToSortedList(&C, testList);
    addToSortedList(&D, testList);
    addToSortedList(&E, testList);

    printList(testList);



    deleteList(testList);


    return 0;
}


