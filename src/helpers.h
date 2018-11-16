/*
 * @file helpers.h
 * @author Sophia Deak
 * @date Nov 8th 2018
 * @brief header file outlining helper functions for creation of huffman tree
 */


#include "nodeQueue.h"

#ifndef HELPERS_H
#define HELPERS_H

typedef struct huffmantree {
    Node * root;
} HuffmanTree;

void newAssignLowestNodes(Node **A, Node **B, Queue *leafQueue, Queue *middleQueue);

void assignLowestNodes(Node **A, Node **B, Queue *leafQueue, Queue *middleQueue);

Node *createMiddleNode(Node *A, Node *B );

#endif 
