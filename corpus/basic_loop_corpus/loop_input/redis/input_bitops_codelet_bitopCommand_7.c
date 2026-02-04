#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long numkeys = 65536;
unsigned long i;

unsigned long **lp;
unsigned long *lres;
size_t k = 0;

void init_vars() {
    lres = (unsigned long*)calloc(4, sizeof(unsigned long));
    lp = (unsigned long**)calloc(numkeys + 1, sizeof(unsigned long*));
    if (!lres || !lp) {
        exit(1);
    }

    for (unsigned long idx = 1; idx < numkeys; idx++) {
        unsigned long* row = (unsigned long*)calloc(8, sizeof(unsigned long));
        if (!row) exit(1);
        row[k + 0] = idx * 1UL;
        row[k + 1] = idx * 2UL;
        row[k + 2] = idx * 4UL;
        row[k + 3] = idx * 8UL;
        lp[idx] = row;
    }
}