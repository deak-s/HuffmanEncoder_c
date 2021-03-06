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

    char shortInput[] = "Lorem ipsum dolor sit amet, vim affert alterum ";

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
    for( k = 0; k <= listSize;  k++){
        printf("%c : %d\n", finalFrequencyList[k].character, finalFrequencyList[k].frequency);
    }


    printf("queue\n");
  
    Queue *testQueue = initializeEmptyQueue();

    fillQueueFromArray(finalFrequencyList, testQueue, listSize);

    
    printQueue(testQueue);

    printf("print queue over\n");
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
    

    // -------------first middle node ------------
    printf("------------1st NODE---------\n");
    Node *testMidNode = createMiddleNode(testA, testB);
    printf("expect * : 2\n");

    printf("test midNode  %c : %d \n", testMidNode->character, testMidNode->frequency);


    printf("middle queue before TMN1: \n");
    printQueue(testMiddle);

    enqueue(testMiddle, testMidNode);

    printf("middle queue after TMN1: \n");
    printQueue(testMiddle);

    // -------------second middle node ------------
    printf("------------2TH NODE---------\n");
    Node *testMidNode2 = createMiddleNode(testC, testD);
    printf("expect * : 2\n");

    printf("test midNode2  %c : %d \n", testMidNode2->character, testMidNode2->frequency);

    printf("middle queue before TMN2: ");
    printQueue(testMiddle);


    enqueue(testMiddle, testMidNode2);


    // -------------third middle node ------------
    printf("------------3TH NODE---------\n");
    Node *testE = (Node *)malloc(sizeof(Node));
    Node *testF = (Node *)malloc(sizeof(Node));

    assignLowestNodes(&testE, &testF, testQueue, testMiddle);

    printf("test e  %c : %d \n", testE->character, testE->frequency);
    printf("test f  %c : %d \n", testF->character, testF->frequency);


    Node *testMidNode3 = createMiddleNode(testE, testF);
    printf("expect * : 4\n");

    printf("test midNode3  %c : %d \n", testMidNode3->character, testMidNode3->frequency);

    printf("middle queue before TMN3: \n");
    printQueue(testMiddle);

    enqueue(testMiddle, testMidNode3);


    // -------------fourth middle node ------------
    printf("------------4TH NODE---------\n");


    printf("middle queue before TMN4: \n");
    printQueue(testMiddle);
    
    Node *testG = (Node *)malloc(sizeof(Node));
    Node *testH = (Node *)malloc(sizeof(Node));

    printf("front of middle queue before testmidnode4: %c %d\n",
            testMiddle->head->right->character,
            testMiddle->head->right->frequency);


    assignLowestNodes(&testG, &testH, testQueue, testMiddle);

    printf("test g  %c : %d \n", testG->character, testH->frequency);
    printf("test h  %c : %d \n", testH->character, testH->frequency);


    printf("test h-child  %c : %d \n", testH->right->character, testH->right->frequency);

//    printf("front of middle queue before testmidnode4: %c %d\n",
 //           testMiddle->head->right->character,
  //          testMiddle->head->right->frequency);


    Node *testMidNode4 = createMiddleNode(testG, testH);
    printf("expect * : 4\n");

    printf("test midNode4  %c : %d \n", testMidNode4->character, testMidNode4->frequency);

    enqueue(testMiddle, testMidNode4);

    // middle node correct children here
    printf("front of middle queue: %c %d\n",
            testMiddle->head->character,
            testMiddle->head->frequency);

    printf("test midNode4  left %c : %d \n", testMidNode4->left->character, testMidNode4->left->frequency);
    printf("test midNode4  right %c : %d \n", 
            testMidNode4->right->character, 
            testMidNode4->right->frequency);

    printf("test midNode4 left left %c : %d \n", testMidNode4->left->left->character, testMidNode4->left->left->frequency);

    printf("middle queue after TMN4: \n");
    printQueue(testMiddle);


    // -------------fifth middle node ------------
    printf("------------5TH NODE---------\n");

     
    Node *testI = (Node *)malloc(sizeof(Node));
    Node *testJ = (Node *)malloc(sizeof(Node));

    assignLowestNodes(&testI, &testJ, testQueue, testMiddle);

    printf("test I  %c : %d \n", testI->character, testI->frequency);
    printf("test J  %c : %d \n", testJ->character, testJ->frequency);


   Node *testMidNode5 = createMiddleNode(testI, testJ);
 
    printf("test midNode5  left %c : %d \n", 
            testMidNode5->left->character, 
            testMidNode5->left->frequency);
    printf("test midNode5  right %c : %d \n", 
            testMidNode5->right->character, 
            testMidNode5->right->frequency);
     printf("test midNode5 left left %c : %d \n", 
            testMidNode5->left->left->character, 
           testMidNode5->left->left->frequency);


    enqueue(testMiddle, testMidNode5);

    printf("middle queue after TMN5: \n");
    printQueue(testMiddle);

return 0;
}
