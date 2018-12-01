/*
 * @file codeBook.c
 * @author Sophia Deak
 * @date Nov 18th 2018
 * @brief implemtation of a codeBook data structure for ternary huffman tree
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codeBook.h"

CodeSet *createCodeSet(char character, int *code, int length){

	CodeSet *newCodeSet = (CodeSet *)malloc(sizeof(CodeSet));
	newCodeSet->character = character;
    int * codeCopy = (int*)malloc(length * sizeof(int));
    memmove(codeCopy, code, length * 4);

	newCodeSet->code = codeCopy;
	newCodeSet->length = length;

    newCodeSet->next = NULL;
    newCodeSet->prev = NULL;
    
    printCodeSet(newCodeSet);

	return newCodeSet;
}

int compareCodeSets(CodeSet *A, CodeSet *B){

	//A > B = 1
	//A < B = -1
	//A = B = 0

	if(A->length > B->length){
		return 1;
	}

	else if(A->length < B->length){
		return -1;
	}

	else{
		if(A->character > B->character){
			return 1;
		}

		else if(A->character < B->character){
			return -1;
		}
		else{
			return 99;
		}
	}
	return 44;
}

CodeBook *initializeCodeBook(){

	CodeBook *newBook = (CodeBook *)malloc(sizeof(CodeBook));

	newBook->head = NULL;
	newBook->length = 0;

	return newBook;
};



void addToCodeBook(CodeBook *theBook, char character, int *code, int length){

	CodeSet *newCodeSet = createCodeSet(character, code, length);


	if (theBook->head == NULL){
		theBook->head = newCodeSet;
        theBook->length++;        
		return;
	}

	CodeSet *tempSet = theBook->head;
    // A < B
    // case: front of list
	if(compareCodeSets(newCodeSet, tempSet) == -1){

		tempSet->prev = newCodeSet;
		newCodeSet->next = tempSet;
		theBook->head = newCodeSet;
        printf("added to front of book\n");
        theBook->length++;        
        printf("printing book\n");
        printCodeBook(theBook);
		return;
	}

	while(tempSet != NULL){
        // A < B
        // add to middle
		if(compareCodeSets(newCodeSet, tempSet) == -1){
			tempSet->prev->next = newCodeSet;
			newCodeSet->prev = tempSet->prev;
			newCodeSet->next = tempSet;
			tempSet->prev = newCodeSet;
        theBook->length++;        
        printf("added to middle of book\n");
         printf("printing book\n");
        printCodeBook(theBook);
   return;
		}

		else if(compareCodeSets(newCodeSet, tempSet) == 1 && tempSet->next == NULL){
		tempSet->next = newCodeSet;
		newCodeSet->prev = tempSet;
        theBook->length++;        
        printf("added to end of book\n"); 
        printf("printing book\n");
        printCodeBook(theBook);

		return;
		}
	
		else{
			tempSet = tempSet->next;
		}
	}
    return;
}

void printCodeSet(CodeSet *theSet){

    printf("%c : ", 
            theSet->character);

        for(int j = 0; j < theSet->length; j++){
            printf("%d", theSet->code[j]);
        }
        printf("\n");
}


void printCodeBook(CodeBook *theBook){

    if(theBook->head == NULL){
        printf("book empty\n");
        return;
    }

    CodeSet *temp = theBook->head;
    printCodeSet(temp);

    while(temp->next != NULL){
        temp = temp->next;
        printCodeSet(temp);
    }
    return;
}


void deleteCodeBook(CodeBook *theBook){

    if(theBook->head == NULL){
        printf("book empty\n");
        return;
    }

    CodeSet *temp = theBook->head;
    CodeSet *next;
    printCodeSet(temp);

    while(temp != NULL){
        next = temp->next;
        free(temp->code);
        free(temp);
        temp = next;
    }
    
    free(theBook);
    return;
}
