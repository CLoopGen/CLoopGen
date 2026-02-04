#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned long numkeys = 1048576; // ~1M iterations for ~0.01 sec runtime
unsigned long i;
unsigned long **lp;
unsigned long *lres;
size_t k = 0;
unsigned long lcommon_bits[4] = {0};

void init_vars() {
    lres = (unsigned long*)calloc(4, sizeof(unsigned long));
    if (!lres) exit(1);

    lp = (unsigned long**)calloc(numkeys, sizeof(unsigned long*));
    if (!lp) exit(1);

    for (unsigned long idx = 0; idx < numkeys; idx++) {
        unsigned long* row = (unsigned long*)malloc(8 * sizeof(unsigned long));
        if (!row) exit(1);
        for (int j = 0; j < 8; j++) {
            row[j] = rand() | ((unsigned long)rand() << 32);
        }
        lp[idx] = row;
    }

    lres[0] = rand() | ((unsigned long)rand() << 32);
    lres[1] = rand() | ((unsigned long)rand() << 32);
    lres[2] = rand() | ((unsigned long)rand() << 32);
    lres[3] = rand() | ((unsigned long)rand() << 32);

    k = 0; // Ensure k+3 is within bounds (k <= 4)
}