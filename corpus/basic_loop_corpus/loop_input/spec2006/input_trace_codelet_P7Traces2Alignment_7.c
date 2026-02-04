#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int mlen;
int *inserts;
int k;

void init_vars() {
    mlen = (1 << 24) - 1;  // 16,777,215 elements, roughly 64 MB of data
    inserts = (int*)calloc(mlen + 1, sizeof(int));
    if (!inserts) {
        exit(1);
    }

    // Initialize with values > 1 to ensure loop body executes
    for (int i = 0; i <= mlen; i++) {
        inserts[i] = (i % 3) + 1;  // Values: 1, 2, or 3
    }
}