#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int npyiter_opitflags;

int nop = 65536;
int iop;
char *outreadflags;
npyiter_opitflags *op_itflags;

void init_vars() {
    outreadflags = (char *)malloc(nop * sizeof(char));
    op_itflags = (npyiter_opitflags *)malloc(nop * sizeof(npyiter_opitflags));
    for (int i = 0; i < nop; ++i) {
        op_itflags[i] = rand() % 4;
    }
}