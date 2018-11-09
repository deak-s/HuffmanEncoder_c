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
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node *copyNode(Node *original){
    Node  *newNode = createNode(original->character, original->frequency);
    newNode->next = original->next;
    newNode->prev = original->prev;
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
        currentNode->next = tempNode;
        tempNode->prev = currentNode;
        
        currentNode = currentNode->next;
    }
}


void enqueue(Queue *theQueue, Node *theNode){
    //case: first node
    if(theQueue->head == NULL){
        theQueue->head = theNode;
        return;
    }
    
    Node *currentNode = theQueue->head;
    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }

    currentNode->next = theNode;
    theNode->prev = currentNode;
};

Node *dequeue(Queue *theQueue){
    
    Node *tempNode = copyNode(theQueue->head);

    theQueue->head = tempNode->next;
    free(theQueue->head->prev);

    return tempNode;
};


void printQueue(Queue *theQueue){
    
    Node *tempNode = theQueue->head;

    while(tempNode->next != NULL){

        printf(" %c : %d \n", tempNode->character, tempNode->frequency);
        tempNode = tempNode->next;
    }
};
