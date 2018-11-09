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
    Node *tempB = leafQueue->head->right;



    printf("temp a  %c : %d \n", tempA->character, tempA->frequency);
    printf("temp b  %c : %d \n", tempB->character, tempB->frequency);
    //if middle queue is not empty, compare first element
    if(middleQueue->head != NULL){
        printf("middle queue head not null\n");

        if(middleQueue->head->frequency < tempA->frequency){
            tempA = middleQueue->head;
        }

        else if(middleQueue->head->frequency < tempB->frequency){
            tempB = middleQueue->head;
        }
    

        //same process for 2nd element in mid queue
        if(middleQueue->head->right != NULL){

            printf("middle queue 2nd not null\n");
            if(middleQueue->head->right->frequency < tempA->frequency){
                tempA = middleQueue->head->right;
            }

            else if(middleQueue->head->right->frequency < tempB->frequency){
                tempB = middleQueue->head->right;
            }
        }

    }


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
            return;
         }
         return;
    }

    //if either node came from middle queue
     if(tempA == middleQueue->head || tempB == middleQueue->head){ 
         if(A == NULL){
            *A = dequeue(middleQueue);
         }
         else{
             *B = dequeue(middleQueue);
         }

         //if both nodes came from middle
         if(tempA == middleQueue->head || tempB == middleQueue->head){ 
              *B = dequeue(middleQueue);
             return;
         } 
     }


}

Node *addTreeNode(Queue *leafQueue, Queue *middleQueue){

}
