/*
 * @file huffmanTree.h
 * @author Sophia Deak
 * @date Nov 17th
 * @brief header file outlining wrapper functions for huffman tree and codebook
 */

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "nodeQueue.h"
#include "helpers.h"
#include "codeBook.h"


typedef struct htree {
    Node * root;
} HTree;


Node * createTree(Queue **leafQueue);

void grabEncoding(Node *root, int height, int *code);

void iterateThroughEncodings(Node *root, int height, int *code, CodeBook **theBook);

void printTree(Node *theRoot);

int heightOfTree(Node *root);

void deleteTree(Node *root);



#endif

