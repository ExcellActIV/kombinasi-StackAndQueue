#ifndef CONVENTION_H
#define CONVENTION_H

#include <stdio.h>
#include <stdbool.h>

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList
{
    infotype info;
    address next;
} ElmtList;

#define Nil NULL
#define info(P) (P)->info
#define next(P) (P)->next

#endif