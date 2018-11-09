/*
 * @file helpers.c
 * @author Sophia Deak
 * @date Nov 8th 2->head18
 * @brief implementation of helper functions for creation of huffman tree
 */

#include <stdio.h>
#include <stdlib.h>

#include "nodeQueue.h"


void assignLowestNodes(Node **A, Node **B, Queue *leafQueue, Queue *middleQueue){

    
    //initially assume leaves are smallest
    Node *tempA = leafQueue->head;
    Node *tempB = leafQueue->head->next;

    printf("temp a  %c : %d \n", tempA->character, tempA->frequency);
    printf("temp b  %c : %d \n", tempB->character, tempB->frequency);

    //if middle queue is not empty, compare first element
    if(middleQueue->head != NULL){
        printf("middle queue head not null\n");

        if(middleQueue->head->frequency < tempA->frequency){
            printf("tempA gets mid node\n");
            tempA = middleQueue->head;
        }

        else if(middleQueue->head->frequency < tempB->frequency){
            printf("tempB gets mid node\n");
            tempB = middleQueue->head;
        }

    printf("temp a half way %c%d\n", tempA->character, tempA->frequency);
        //same process for 2nd element in mid queue
        if(middleQueue->head->next != NULL){

            printf("middle queue 2nd not null\n");
            if(middleQueue->head->next->frequency < tempA->frequency){
                printf("temp a gets mid head R\n");
                tempA = middleQueue->head->next;
            }

            else if(middleQueue->head->next->frequency < tempB->frequency){
                tempB = middleQueue->head->next;
            }
        }
        printf("middles finished\n");
    }


    printf("leaf queue 1st and 2nd  %c%d  %c%d\n", 
            leafQueue->head->character, 
            leafQueue->head->frequency, 
            leafQueue->head->next->character, 
            leafQueue->head->next->frequency);

    printf("temp a %c%d\n", tempA->character, tempA->frequency);
    printf("temp b  %c : %d \n", tempB->character, tempB->frequency);


    printf("temp a  %c : %d \n", tempA->character, tempA->frequency);
    //if either node came from leaf queue, remove node from queue
    if(tempA == leafQueue->head || tempB == leafQueue->head){ 
        printf("A gets dequeued leaf\n");
            *A = dequeue(leafQueue);

    printf(" A  %c : %d \n", (*A)->character, (*A)->frequency);
            
        //if both nodes came from leaf queue, dequeue another node
        //head of queue has changed bc dequeue
         if(tempA == leafQueue->head || tempB == leafQueue->head){
        printf("B gets dequeued leaf\n");
            *B = dequeue(leafQueue);

            printf(" B  %c : %d \n", (*B)->character, (*B)->frequency);
            //both nodes found
         }
    }

    //if either node came from middle queue
     if(tempA == middleQueue->head || tempB == middleQueue->head){ 
         if((*A)->character == 0){
             printf("A gets dequeued middle\n");
            *A = dequeue(middleQueue);
         }
         else{
             printf("B gets dequeued middle\n");
             *B = dequeue(middleQueue);
         }

         //if both nodes came from middle
         if(tempA == middleQueue->head || tempB == middleQueue->head){ 
              *B = dequeue(middleQueue);
         } 
             return;
     }
}

Node *createMiddleNode(Node *A, Node *B ){

    //created middle node

    int combinedFrequency = (A->frequency + B->frequency);
    Node *newMiddle = createNode( '*', combinedFrequency); 

    //case A is smaller
    if(A->frequency < B->frequency){
        newMiddle->left = A;
        newMiddle->right = B;
    }
    //case B is smaller 
    else if(A->frequency > B->frequency){
        newMiddle->left = B;
        newMiddle->right = A;
    }
    //case both are equal, use alphabetical of char
    //ISSUE what if both are middle nodes? 
    else{
        if(A->character < B->character){
            newMiddle->left = A;
            newMiddle->right = B;
        }
        else{
            newMiddle->left = B;
            newMiddle->right = A;
        }
    }

    return newMiddle;
}
