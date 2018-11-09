/*
 * @file main.c
 * @author Sophia Deak
 * @date Nov 5th 2018
 * @brief main function for running huffman encoder
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nodeQueue.h"
#include "helpers.h"




int compare (const void *a, const void *b){
    int fA =  ((Pair *)a)->frequency;
    int fB =  ((Pair *)b)->frequency; 
    return (fB - fA);
}

int compareSmaller (const void *a, const void *b){
    int fA =  ((Pair *)a)->frequency;
    int fB =  ((Pair *)b)->frequency; 
    return (fA - fB);
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
    size_t listSize = 0;
    for( k = 0; frequencyList[k].frequency != 0;  k++){
        printf("%c : %d\n", frequencyList[k].character, frequencyList[k].frequency);
        listSize++;
    }

    printf("%ld\n", listSize);

    //frequency list without 0s
    Pair finalFrequencyList[listSize];
    memcpy(finalFrequencyList, frequencyList, (listSize * sizeof(Pair)));

    for( k = 0; k < listSize;  k++){
        printf("%c : %d\n", finalFrequencyList[k].character, finalFrequencyList[k].frequency);
    }

    qsort(finalFrequencyList, listSize, sizeof(Pair), compareSmaller);

    printf("reversed\n");
    for( k = 0; k < listSize;  k++){
        printf("%c : %d\n", finalFrequencyList[k].character, finalFrequencyList[k].frequency);
    }


    printf("queue\n");
  
    Queue *testQueue = initializeEmptyQueue();

    fillQueueFromArray(finalFrequencyList, testQueue, listSize);

    
    printQueue(testQueue);

    Node *brief = dequeue(testQueue);
    printf("temp %c : %d", brief->character, brief->frequency);

    brief = dequeue(testQueue);
    printf("temp %c : %d", brief->character, brief->frequency);

    
    //test queue is leaf queue
    
    Queue *testMiddle = initializeEmptyQueue();


    //might not be necessary
    Node *testA = (Node *)malloc(sizeof(Node));
    Node *testB = (Node *)malloc(sizeof(Node));


    assignLowestNodes(&testA, &testB, testQueue, testMiddle);


    printf("test a  %c : %d \n", testA->character, testA->frequency);
    
    printf("test b  %c : %d \n", testB->character, testB->frequency);
    

     Node *testC = (Node *)malloc(sizeof(Node));
    Node *testD = (Node *)malloc(sizeof(Node));


    assignLowestNodes(&testC, &testD, testQueue, testMiddle);



    printf("expect g : 1\n");
    printf("test c  %c : %d \n", testC->character, testC->frequency);
    
    printf("expect z : 1\n");
    printf("test d  %c : %d \n", testD->character, testD->frequency);
    



    return 0;
}
