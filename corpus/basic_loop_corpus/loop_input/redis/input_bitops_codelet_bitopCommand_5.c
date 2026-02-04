#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long numkeys = 65536;
unsigned long i;
unsigned long **lp;
unsigned long *lres;
size_t k = 4;

void init_vars() {
    lres = (unsigned long*)calloc(4, sizeof(unsigned long));
    lp = (unsigned long**)calloc(numkeys + 1, sizeof(unsigned long*));
    for (unsigned long idx = 1; idx < numkeys; idx++) {
        lp[idx] = (unsigned long*)calloc(8, sizeof(unsigned long));
        lp[idx][k + 0] = (idx * 1) & 0xFF;
        lp[idx][k + 1] = (idx * 2) & 0xFF;
        lp[idx][k + 2] = (idx * 3) & 0xFF;
        lp[idx][k + 3] = (idx * 4) & 0xFF;
    }
}