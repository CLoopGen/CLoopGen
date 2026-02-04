#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long numkeys = 1000000;
unsigned long i;
unsigned long **lp;
unsigned long *lres;
size_t k = 4;

void init_vars() {
    lres = (unsigned long*)calloc(4, sizeof(unsigned long));
    if (!lres) exit(1);

    lp = (unsigned long**)calloc(numkeys, sizeof(unsigned long*));
    if (!lp) exit(1);

    for (unsigned long idx = 0; idx < numkeys; idx++) {
        unsigned long* row = (unsigned long*)malloc(8 * sizeof(unsigned long));
        if (!row) exit(1);
        for (size_t j = 0; j < 8; j++) {
            row[j] = 0xFFFFFFFFFFFFFFFFUL;
        }
        lp[idx] = row;
    }

    lres[0] = 0xFFFFFFFFFFFFFFFFUL;
    lres[1] = 0xFFFFFFFFFFFFFFFFUL;
    lres[2] = 0xFFFFFFFFFFFFFFFFUL;
    lres[3] = 0xFFFFFFFFFFFFFFFFUL;
}