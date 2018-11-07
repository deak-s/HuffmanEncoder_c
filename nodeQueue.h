/*
 * @file nodeQueue.h
 * @author Sophia Deak
 * @date Nov 6th 2018
 * @brief header file for implementation of node queue
 */


typedef struct node Node;
typedef struct queue Queue;

struct node {
    char character;
    int frequency;

    Node * next;
    Node * prev;
};

struct queue {
    Node *head;
    Node *tail;

};

typedef struct pair {
    char character;
    int frequency;
} Pair;

Node * createNode(char c, int f); 

Node *copyNode(Node *original);

Queue *initializeEmptyQueue (); 

Queue *fillQueueFromArray(Pair *array, Queue *theQueue, size_t length);

void  enqueue(Queue *theQueue, Node *theNode);
Node *dequeue(Queue *theQueue);

void printQueue(Queue *theQueue);
