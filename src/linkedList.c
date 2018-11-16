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



// -1 if a < b
// 1 if a > b

List *initializeList(){

    List *newList = (List *)malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->length = 0;

    return newList;
}

ListNode *createListNode(Node *theData){
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->data = theData;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void addToSortedList(Node *theData, List *theList){

    //case: first node
	if(theList->head == NULL){
		printf("list empty\n");
        theList->head = createListNode(theData);
        theList->length++;
        return;
    }

    ListNode *tempNode = theList->head;
    ListNode *newNode = createListNode(theData);
    

    //case front of list
    if(newNode->data->frequency < tempNode->data->frequency){

        tempNode->prev = newNode;
        newNode->next = tempNode;	
        theList->head = newNode;
        theList->length++;
        return;
    }


    while(tempNode->next != NULL){

        if(newNode->data->frequency < tempNode->data->frequency){
            tempNode->prev->next = newNode;
            newNode->prev = tempNode->prev;
            newNode->next = tempNode;
            tempNode->prev = newNode;
            theList->length++;
            return;	
        }
        tempNode = tempNode->next;
    }

	//case end of list
    tempNode->next = newNode;
    newNode->prev = tempNode;
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

    if(theList == NULL){
        printf("non-existent list\n");
        return;
    }

    if(theList->head == NULL){
        printf("delete empty list\n");
        return;
    }

    ListNode *tempNode = theList->head;
    printf("deleting %c : %d \n", tempNode->data->character, tempNode->data->frequency);

     while(tempNode->next != NULL){
        tempNode = tempNode->next;
        free(tempNode->prev);

    printf("deleting %c : %d \n", tempNode->data->character, tempNode->data->frequency);

     }
     free(tempNode);
     free(theList);
};



