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
#include "huffmanTree.h"


int main(){



    char shortInput[] = "Lorem ipsum dolor sit amet, vim affert alterum ";

    size_t size= 127;
 FrequencyList *tList = initializeEmptyList(size);


 calculateFrequencies(shortInput, &tList);

 sortSmallToLarge(&tList);

int x =  countUnusedChars(&tList);

 Queue *lQueue = initializeEmptyQueue();

 fillQueueFromArray(&tList->pairList[x], lQueue, (tList->length - x));

 printf("printing lQueue\n");
 printQueue(lQueue);


 Node *y = createTree(&lQueue);

 /*

    Queue *middleQueue = initializeEmptyQueue();

   
//    while(lQueue->head != NULL || middleQueue->head->next != NULL){

    for(int p = 0; p < 16; p++){

        Node *A; 
        Node *B;

        newnewAssignLowestNodes(&A, &B, lQueue, middleQueue);
        printf("lowest nodes \n  A %c:%d \n  B %c:%d \n", A->character, A->frequency, B->character, B->frequency);

        Node *M = createMiddleNode(A, B);
        enqueue(middleQueue, M);

        printf("loop happened\n");
        printQueue(lQueue);
        printf("mid queue\n");
        printQueue(middleQueue);
    }

printf("printing final leafqueue\n");
    printQueue(lQueue);


    printf("printing final midqueue\n");
    printQueue(middleQueue);

    Node *y  = copyNode(middleQueue->head);
    //Node *y = dequeue(middleQueue);

    //printf("test %c %c %c\n", x->left->character, x->right->character, x->left->left->character); 


    deleteQueue(middleQueue);
    free(middleQueue);


    */
///// end of create tree function




    printf("test %c %c %c %c %c \n", 
            y->left->character, 
            y->right->character, 
            y->left->left->character,
            y->left->left->left->left->character,
            y->left->left->left->right->character); 

// printTree(y);


 //int code[5] = {0};
 //grabEncoding(y, 0, code);

deleteTree(y);


free(tList->pairList);
free(tList);
deleteQueue(lQueue);
free(lQueue);

    return 0;
}


