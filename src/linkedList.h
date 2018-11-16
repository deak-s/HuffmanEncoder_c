/*
 * @file linkedList.h
 * @author Sophia Deak
 * @date Nov 16th 2018
 * @brief header file for implementation of a linked list 
 */

#include "nodeQueue.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct listnode ListNode;

struct listnode {

    Node * data;
    ListNode *next;
    ListNode *prev;
};

typedef struct list {

    ListNode *head;
    ListNode *tail;
    int length;

}List;



List *initializeList();

ListNode *createListNode(Node *theData);


void addToSortedList(Node *theNode, List *theList);

void printList(List *theList);

void deleteList(List *theList);

#endif
