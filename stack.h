#ifndef STACK_H
#define STACK_H

#include "convention.h"
#include "linked.h"
#include "utility.h"

typedef struct {
    address TOP;
} Stack;

void createStack(Stack *S); 
// Membuat stack kosong

void allocate(address *P, infotype x);
// Mengalokasikan memori untuk node

void fillStack(Stack *S, infotype x); 
// Mengisi stack dengan nilai x

void deallocate(address P); 
// Mendealokasi memori node

void push(Stack *S, infotype x); 
// Menambahkan nilai x ke stack

void pop(Stack *S, infotype *x); 
// Menghapus nilai dari stack

bool isEmptyStack(Stack S); 
// Mengecek apakah stack kosong

void printStack(Stack S); 
// Mencetak isi stack

void deleteStack(Stack *S);
// Menghapus seluruh isi stack

#endif