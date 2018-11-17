/*
 * @file helpers.c
 * @author Sophia Deak
 * @date Nov 8th 2->head18
 * @brief implementation of helper functions for creation of huffman tree
 */

#include <stdio.h>
#include <stdlib.h>

#include "nodeQueue.h"
#include "linkedList.h"

int compareNodes(Node *A, Node *B){
    printf("starting compare\n");

    //A > B  = 1
    //A < B = -1
    //A = B = 0
    //

    if(A == NULL && B == NULL){
        return 99;
    }

    else if(B == NULL){
        return -1;
    }
    else if(A == NULL){
        return 1;
    }
    else if (A->frequency <= B->frequency){
        return -1;
    }
    else if(A->frequency > B->frequency){
        return 1;
    }
}

void newnewAssignLowestNodes(Node **A, Node **B, Queue *leafQueue, Queue *middleQueue){
    //--------assigning A-------------
    //if A <= C OR C is null 
    if(compareNodes(leafQueue->head, middleQueue->head) == -1){
        printf("a gets leaf\n");
            *A = dequeue(leafQueue); 
            printf("a got leaf\n");
    }
    else{
        printf("a gets mid\n");
        *A = dequeue(middleQueue);
    }

    //------assigning B-----------

    //if A <= C OR C is null 
    if(leafQueue->head == NULL){
        printf("leaf empty\n");
    }
    if(compareNodes(leafQueue->head, middleQueue->head) == -1){
        printf("b gets leaf\n");
        *B = dequeue(leafQueue);
    }

    else{
        printf("b gets mid\n");
        *B = dequeue(middleQueue);
    }
}


Node *createMiddleNode(Node *A, Node *B ){

    int combinedFrequency = (A->frequency + B->frequency);
    Node *newMiddle = createNode( '*', combinedFrequency); 

    newMiddle->left = A;
    newMiddle->right = B;
    return newMiddle;
}
