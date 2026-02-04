#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint32;

uint32 n;
double *v;
int i;
uint32 *bp;

void init_vars() {
    n = 32 * 1024 * 1024; // 32M elements, ~256MB total data (v: 8B * 32M = 256MB, bp: 4B * 32M = 128MB)

    v = (double *)aligned_alloc(32, n * sizeof(double));
    bp = (uint32 *)aligned_alloc(32, n * sizeof(uint32));

    if (!v || !bp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize v with non-zero values to ensure meaningful conversion
    for (uint32 j = 0; j < n; j++) {
        v[j] = (double)(j % 1000) + 0.5;
    }

    // Initialize bp to zero
    for (uint32 j = 0; j < n; j++) {
        bp[j] = 0;
    }

    i = 0;
}