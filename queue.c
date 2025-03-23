#include "queue.h"

bool isEmptyQueue(Queue Q)
{
    return isEmpty(Q.HEAD) || isEmpty(Q.TAIL);
}
void createQueue(Queue *Q)
{
    (*Q).HEAD = Nil;
    (*Q).TAIL = Nil;
}

void enqueue(Queue *Q, address P)
{
    if (isEmptyQueue(*Q))
    {
        (*Q).HEAD = P;
        (*Q).TAIL = P;
    }
    else
    {
        Ins_Akhir(&(*Q).TAIL, P);
    }
}

void dequeue(Queue *Q, infotype *x)
{
    if (!isEmptyQueue(*Q))
    {
        Del_Awal(&(*Q).HEAD, &(*x));
        printf("Dequeued: %d\n", *x);
    }
}

void printQueue(Queue Q)
{
    Tampil_List(Q.HEAD);
}

void deleteQueue(Queue *Q)
{
    DeAlokasi(&(*Q).HEAD);
}