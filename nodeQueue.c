/*
 * @file nodeQueue.c
 * @author Sophia Deak
 * @date Nov 6th 2018
 * @brief queue for nodes, used in creation of Huffman tree
 */


#include <stdio.h>
#include <stdlib.h>

#include "nodeQueue.h"

Node * createNode(char c, int f) {

    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->character = c;
    newNode->frequency = f;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

Node *copyNode(Node *original){
    Node  *newNode = createNode(original->character, original->frequency);
    newNode->right = original->right;
    newNode->left = original->left;
    return newNode;
}

Queue *initializeEmptyQueue () {
    Queue *newQueue;
    newQueue = (Queue *)malloc(sizeof(Queue));
    newQueue->head = NULL;
    newQueue->tail = NULL;

    return newQueue;
}


Queue *fillQueueFromArray(Pair *array, Queue *theQueue, size_t length){

    printf("length %ld\n", length);

    //start at head of queue
    Pair *tempPair = &array[0];

    theQueue->head = createNode(tempPair->character, tempPair->frequency);

    Node *currentNode = theQueue->head;
    for (int k = 1; k <= length; k++){
        Pair *tempPair = &array[k];

        Node *tempNode = createNode(tempPair->character, tempPair->frequency);
        currentNode->right = tempNode;
        tempNode->left = currentNode;
        
        currentNode = currentNode->right;
    }
}


void enqueue(Queue *theQueue, Node *theNode){
    
   
    Node *currentNode = theQueue->head;
    while(currentNode->right != NULL){
        currentNode = currentNode->right;
    }

    currentNode->right = theNode;
    theNode->left = currentNode;
    
};

Node *dequeue(Queue *theQueue){
    
    Node *tempNode = copyNode(theQueue->head);

    theQueue->head = tempNode->right;
    free(theQueue->head->left);

    return tempNode;
};


void printQueue(Queue *theQueue){
    
    Node *tempNode = theQueue->head;

    while(tempNode->right != NULL){

        printf(" %c : %d \n", tempNode->character, tempNode->frequency);
        tempNode = tempNode->right;
    }
};
