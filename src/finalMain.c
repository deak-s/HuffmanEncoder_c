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
 Queue *mQueue = initializeEmptyQueue();

 //fill queue from array, skipping unused pairs at beginning of frequency list
 fillQueueFromArray(&tList->pairList[x], lQueue, (tList->length - x));

 printf("printing lQueue\n");
 printQueue(lQueue);




//-------------node tests ----------------

Node *nA;
Node *nB;

//dequeue(lQueue);

assignLowestNodes(&nA, &nB, lQueue, mQueue);

Node *mA = createMiddleNode(nA, nB);

enqueue(mQueue, mA);

//   node 2

Node *nC;
Node *nD;

assignLowestNodes(&nC, &nD, lQueue, mQueue);

Node *mB = createMiddleNode(nC, nD);

enqueue(mQueue, mB);


//   node 3

Node *nE;
Node *nF;

assignLowestNodes(&nE, &nF, lQueue, mQueue);

Node *mC = createMiddleNode(nE, nF);

enqueue(mQueue, mC);


printQueue(mQueue);

//   node 4

Node *nG;
Node *nH;

assignLowestNodes(&nG, &nH, lQueue, mQueue);

Node *mD = createMiddleNode(nG, nH);

enqueue(mQueue, mD);


//   node 5

Node *nI;
Node *nJ;

assignLowestNodes(&nI, &nJ, lQueue, mQueue);

//Node *mE = createMiddleNode(nI, nJ);

//enqueue(mQueue, mE);




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
