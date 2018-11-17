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
#include "linkedList.h"


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
 Queue *mQueue = initializeEmptyQueue();

 //fill queue from array, skipping unused pairs at beginning of frequency list
 fillQueueFromArray(&tList->pairList[x], lQueue, (tList->length - x));

 printf("printing lQueue\n");
 printQueue(lQueue);




//-------------node tests ----------------

Node *nA;
Node *nB;


newnewAssignLowestNodes(&nA, &nB, lQueue, mQueue);

Node *mA = createMiddleNode(nA, nB);
enqueue(mQueue, mA);

printf("-----finshed node 1\n");

//   node 2

Node *nC;
Node *nD;

newnewAssignLowestNodes(&nC, &nD, lQueue, mQueue);

Node *mB = createMiddleNode(nC, nD);

enqueue(mQueue, mB);


//   node 3

Node *nE;
Node *nF;

newnewAssignLowestNodes(&nE, &nF, lQueue, mQueue);

Node *mC = createMiddleNode(nE, nF);

enqueue(mQueue, mC);

printQueue(mQueue);


//   node 4


Node *nG;
Node *nH;

newnewAssignLowestNodes(&nG, &nH, lQueue, mQueue);

Node *mD = createMiddleNode(nG, nH);

enqueue(mQueue, mD);

printf("leaf queue\n");
printQueue(lQueue);

printf(" mid queue\n");
printQueue(mQueue);



//   node 5
printf("STARTING NODE 5\n");

Node *nI;
Node *nJ;

newnewAssignLowestNodes(&nI, &nJ, lQueue, mQueue);
printf("after a l n\n");

Node *mE = createMiddleNode(nI, nJ);

enqueue(mQueue, mE);


printf("-----end frees\n");

free(nA);
free(nB);
free(nC);
free(nD);
free(nE);
free(nF);
free(nG);
free(nH);
free(nI);
free(nJ);


 deleteQueue(lQueue);
 deleteQueue(mQueue);

 free(tList->pairList);
 free(tList);
 free(lQueue);
 free(mQueue);

    return 0;
}
