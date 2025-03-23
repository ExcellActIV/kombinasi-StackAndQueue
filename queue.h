#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "convention.h"
#include "linked.h"
#include "utility.h"

typedef struct queue
{
    address HEAD;
    address TAIL;
} Queue;

bool isEmptyQueue(Queue Q);
// Memeriksa apakah queue kosong

void createQueue(Queue *Q);
// Membuat queue kosong

void allocate(address *P, infotype x);
// Mengalokasikan memory untuk node baru

void enqueue(Queue *Q, address P);
// Menambahkan node baru ke queue di akhir

void dequeue(Queue *Q, infotype *x);
// Menghapus node pertama dari queue

void printQueue(Queue Q);
// Menampilkan isi queue

void deallocate(address P);
// Mendealokasikan memory dari node

void deleteQueue(Queue *Q);
// Menghapus seluruh isi queue

#endif