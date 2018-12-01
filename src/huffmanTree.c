/*
 * @file huffmanTree.c
 * @author Sophia Deak
 * @date Nov 17th 2018
 * @brief wrapper functions for building huffman tree and generating codebook
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "huffmanTree.h"
#include "nodeQueue.h"
#include "helpers.h"
#include "codeBook.h"


Node * createTree(Queue **leafQueue){ Queue *middleQueue = initializeEmptyQueue();

    while((*leafQueue)->head != NULL || middleQueue->head->next != NULL){

        Node *A; 
        Node *B;

        newnewAssignLowestNodes(&A, &B, *leafQueue, middleQueue);

        Node *M = createMiddleNode(A, B);
        enqueue(middleQueue, M);

        printf("loop happened\n");
        printQueue(*leafQueue);
        printf("mid queue\n");
        printQueue(middleQueue);

    }

    printf("printing final midqueue\n");
    printQueue(middleQueue);

    Node *x = dequeue(middleQueue);

    printf("test %c %c %c\n", x->left->character, x->right->character, x->left->left->character); 



    deleteQueue(middleQueue);
    free(middleQueue);
 
    return x;
}



void printTree(Node *root){

    Node *theNode = root;

    if(theNode->character != '*'){
        printf("Node %c : %d \n", theNode->character, theNode->frequency);
        return;
    }

        printTree(theNode->left);
        printTree(theNode->right);
}

//counts root as height 1
int heightOfTree(Node *root){
    
    if(root == NULL){
        printf("empty root");
        return 0;
    }

    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);

    if(left >= right){
        return left + 1;
    }
    else{
        return right + 1;
    }
}


void grabEncoding(Node *root, int height, int *code){

    Node *theNode = root;
    

    if(theNode->character != '*'){
        printf("Node %c : %d \n", theNode->character, theNode->frequency);
        for(int j = 0; j < height -1 ; j++){
            printf("%d", code[j]);
        }
        printf("\n");
        return;
    }

    code[height - 1] = 1;
    grabEncoding(theNode->right, height + 1, code);


    code[height - 1] = 0;
   grabEncoding(theNode->left, height + 1, code);
}


void iterateThroughEncodings(Node *root, int height, int *code, CodeBook **theBook){

    Node *theNode = root;

    if(theNode->character != '*'){
        printf("Node %c : %d \n", theNode->character, theNode->frequency);


        for(int j = 0; j < height -1 ; j++){
            printf("%d", code[j]);
        }

        addToCodeBook(*theBook, theNode->character, code, height -1);
        printf("\n");
        return;
    }

    code[height - 1] = 0;
    iterateThroughEncodings(theNode->left, height + 1, code, theBook);

    code[height - 1] = 1;
    iterateThroughEncodings(theNode->right, height + 1, code, theBook); 

}

void deleteTree(Node *root){

    Node *theNode = root;

  if(theNode == NULL){
        return;
    }   

    printf("deleting %c %d\n", theNode->character, theNode->frequency);
    deleteTree(theNode->left);
    deleteTree(theNode->right);

    free(theNode);
    return;

}


