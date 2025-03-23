#include "utility.h"

void allocate(address *P, infotype x) {
    *P = (address) malloc(sizeof(ElmtList));
    if (*P != Nil) {
        info(*P) = x;
        next(*P) = Nil;
    }
}

void deallocate(address P) {
    free(P);
}
