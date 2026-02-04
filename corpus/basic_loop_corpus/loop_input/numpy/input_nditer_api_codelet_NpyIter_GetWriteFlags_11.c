#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int npyiter_opitflags;

char *outwriteflags;
int iop;
int nop;
npyiter_opitflags *op_itflags;

void init_vars() {
    nop = 67108864; // ~64M elements, target ~0.01 sec on modern CPU

    outwriteflags = (char *)malloc(nop * sizeof(char));
    op_itflags = (npyiter_opitflags *)malloc(nop * sizeof(npyiter_opitflags));

    if (!outwriteflags || !op_itflags) {
        exit(1);
    }

    for (int i = 0; i < nop; ++i) {
        op_itflags[i] = rand() & 1;
    }
}