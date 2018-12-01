/*
 * @file codeBook.h
 * @author Sophia Deak
 * @date Nov 18th 2018
 * @brief definitions for codeBook data struct 
 */

#ifndef CODEBOOK_H
#define CODEBOOK_H


typedef struct codeSet CodeSet;
struct codeSet {
	char character;
	int *code;
	int length;

	CodeSet *prev;
	CodeSet *next;
};

typedef struct codebook {
	CodeSet *head;
	int length;
}CodeBook;

CodeSet *createCodeSet(char character, int *code, int length);

int compareCodeSets(CodeSet *A, CodeSet *B);

CodeBook *initializeCodeBook();

void addToCodeBook(CodeBook *theBook, char character, int *code, int length);

void printCodeSet(CodeSet *theSet);
void printCodeBook(CodeBook *theBook);
void deleteCodeBook(CodeBook *theBook);

#endif
