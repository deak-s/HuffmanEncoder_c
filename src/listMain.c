/*
 * @file listfinalMain.c
 * @author Sophia Deak
 * @date Nov 9th 2018
 * @brief main running huffman encoder (no debugging text)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nodeQueue.h"
#include "helpers.h"
#include "frequencyList.h"
#include "linkedList.h"
#include "huffmanTree.h"
#include "codeBook.h"


int main(){


    char shortInput[] = "Lorem ipsum dolor sit amet, vim affert alterum ";

    size_t size= 127;
 FrequencyList *tList = initializeEmptyList(size);

 calculateFrequencies(shortInput, &tList);

 sortSmallToLarge(&tList);

int x =  countUnusedChars(&tList);

 Queue *lQueue = initializeEmptyQueue();

 fillQueueFromArray(&tList->pairList[x], lQueue, (tList->length - x));

 printf("printing lQueue\n");
 printQueue(lQueue);


 Node *y = createTree(&lQueue);

    printf("test %c %c %c %c %c \n", y->left->character, y->right->character, 
            y->left->left->character,
            y->left->left->left->left->character,
            y->left->left->left->right->character); 

 printTree(y);

 int h = heightOfTree(y);


 int *code = (int *)calloc(h, sizeof(int));

 CodeBook *testBook = initializeCodeBook();

 grabEncoding(y, 1, code);

 iterateThroughEncodings(y, 1, code, &testBook);
 printCodeBook(testBook);

 free(code);

 deleteCodeBook(testBook);

 deleteQueue(lQueue);
 free(lQueue);

 deleteTree(y);
 free(tList->pairList);
 free(tList);

    return 0;
}

