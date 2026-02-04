#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint32;

uint32 n;
double *v;
int i;
float *bp;

void init_vars() {
    n = 16777216; // 16M elements, ~128MB for double array, ~64MB for float array

    v = (double *)aligned_alloc(32, n * sizeof(double));
    bp = (float *)aligned_alloc(32, n * sizeof(float));

    if (!v || !bp) {
        exit(1);
    }

    for (uint32 idx = 0; idx < n; idx++) {
        v[idx] = (double)(idx * 1.5);
        bp[idx] = 0.0f;
    }
}