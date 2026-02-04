#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long numkeys = 1048576; // ~1M iterations for ~0.01 sec runtime
unsigned long i;
unsigned long **lp;
unsigned long *lres;
size_t k = 4;

void init_vars() {
    lres = (unsigned long*)calloc(4, sizeof(unsigned long));
    lp = (unsigned long**)calloc(numkeys + 1, sizeof(unsigned long*));

    for (unsigned long idx = 1; idx < numkeys; idx++) {
        lp[idx] = (unsigned long*)malloc((k + 4) * sizeof(unsigned long));
        for (size_t j = 0; j < 4; j++) {
            lp[idx][k + j] = rand();
        }
    }
}