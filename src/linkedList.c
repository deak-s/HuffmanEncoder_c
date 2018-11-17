/*
 * @file linkedList.c
 * @author Sophia Deak
 * @date Nov 16th 2018
 * @brief implementation of a linked list to be used for huffman encoder 
 */


#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"
#include "nodeQueue.h"


List *initializeList(){

    List *newList = (List *)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;
    return newList;
}

ListNode *createListNode(Node *theData){

    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));

    //newNode->data = createNode(theData->character, theData->frequency);
    newNode->data = theData;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void addToSortedList(Node *theData, List *theList){
    //case: first node
	if(theList->head == NULL){
		printf("first node\n");
        theList->head = createListNode(theData);
        theList->tail = theList->head;
        theList->length++;
        return;
    }

    ListNode *tempNode = theList->head;
    ListNode *newNode = createListNode(theData);

    //case front of list
    
    if(newNode->data->frequency < tempNode->data->frequency){

        printf(" --front of list\n");
        tempNode->prev = newNode;
        newNode->next = tempNode;	
        theList->head = newNode;
        theList->length++;
        return;
    }


    while(tempNode != NULL){

        //case front of list
        if(newNode->data->frequency < tempNode->data->frequency){
            printf("adding %c %d to middle\n", newNode->data->character, newNode->data->frequency);
            tempNode->prev->next = newNode;
            newNode->prev = tempNode->prev;
            newNode->next = tempNode;
            tempNode->prev = newNode;
            theList->length++;
            return;
        }


        else if(newNode->data->frequency >= tempNode->data->frequency && tempNode->next == NULL){
            printf("adding to end of list\n");

            tempNode->next = newNode;
            newNode->prev = tempNode;
            theList->tail = tempNode;
            return;
        }

        else{ 
            tempNode = tempNode->next;
        }
    }

	//case end of list
    tempNode->next = newNode;
    newNode->prev = tempNode;
    theList->tail = newNode;
    theList->length++;
    return;
}


void printList(List *theList){

    if(theList->head == NULL){
        return;
    }

    ListNode *tempNode = theList->head;
    printf(" %c : %d \n", tempNode->data->character, tempNode->data->frequency);
     while(tempNode->next != NULL){
        tempNode = tempNode->next;

        printf(" %c : %d \n", tempNode->data->character, tempNode->data->frequency);
     }
};



void deleteList(List *theList){
    printf("starting delete list\n");
    printList(theList);

    if(theList == NULL){
        printf("tried to delete null list\n");
        return;
    }
    if(theList->head == NULL){
        printf("tried to delete list null head\n");
        return;
    }

    ListNode *tempNode = theList->tail;
    if(theList->tail == NULL){
        printf("error null tail\n");
    }

    while(tempNode->prev != NULL){
        
        printf("on  %c : %d \n", tempNode->data->character, tempNode->data->frequency);

        tempNode = tempNode->prev;
        if(tempNode->next == NULL){
            printf("next null\n");
        }

        printf("deleting  %c : %d \n", tempNode->next->data->character, tempNode->next->data->frequency);

        free(tempNode->next);
    }

    free(tempNode);
    free(theList);
    };



