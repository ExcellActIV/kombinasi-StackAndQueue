#include <stdlib.h>
#include "stack.h"

void createStack(Stack *S)
{
    (*S).TOP = Nil;
}

void fillStack(Stack *S, infotype x)
{
    address P;
    Create_Node(&P, x);
    if (P != Nil)
    {
        Ins_Awal(&(*S).TOP, P);
    }
}

void push(Stack *S, infotype x)
{
    address P; 
    Create_Node(&P, x);
    if (P != Nil)
    {
        Ins_Awal(&(*S).TOP, P);
    }
}

void pop(Stack *S, infotype *x)
{
    if (!isEmptyStack(*S))
    {
        Del_Awal(&(*S).TOP, x);
        printf("Popped: %d\n", *x);
    }
}

bool isEmptyStack(Stack S)
{
    return isEmpty(S.TOP);
}

void printStack(Stack S)
{
    Tampil_List(S.TOP);
}

void deleteStack(Stack *S)
{
    DeAlokasi(&(*S).TOP);
}