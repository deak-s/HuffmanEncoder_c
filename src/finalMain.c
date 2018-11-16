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

//dequeue(lQueue);

assignLowestNodes(&nA, &nB, lQueue, mQueue);


Node *mA = createMiddleNode(nA, nB);

enqueue(mQueue, mA);

printf("!!!! finished first node\n");

//   node 2

Node *nC;
Node *nD;

newAssignLowestNodes(&nC, &nD, lQueue, mQueue);

Node *mB = createMiddleNode(nC, nD);

enqueue(mQueue, mB);


free(nA);
free(nB);
free(nC);
free(nD);



 deleteQueue(lQueue);
 deleteQueue(mQueue);

 free(tList->pairList);
 free(tList);
 free(lQueue);
 free(mQueue);




/*
//   node 3

Node *nE;
Node *nF;

newAssignLowestNodes(&nE, &nF, lQueue, mQueue);

Node *mC = createMiddleNode(nE, nF);

enqueue(mQueue, mC);


printQueue(mQueue);


free(nA);
free(nB);
free(nC);
free(nD);
free(nE);
free(nF);



 deleteQueue(lQueue);
 deleteQueue(mQueue);

 free(tList->pairList);
 free(tList);
 free(lQueue);
 free(mQueue);



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


Queue *listQueue = initializeEmptyQueue();

addToSortedList(nA, listQueue);
printf("node a: %c %d\n", nA->character, nA->frequency);
printf("node c: %c %d\n", nC->character, nC->frequency);
printf("node e: %c %d\n", nE->character, nE->frequency);
printf("node b: %c %d\n", nB->character, nB->frequency);
printf("node f: %c %d\n", nF->character, nF->frequency);
printf("node j: %c %d\n", nJ->character, nJ->frequency);

addToSortedList(nC, listQueue);
addToSortedList(nE, listQueue);
addToSortedList(nB, listQueue);
addToSortedList(nF, listQueue);


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

 */
    return 0;
}
