#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

typedef unsigned int uint32;
typedef short int16;

uint32 n;
double *v;
int i;
int16 *bp;

void init_vars() {
    n = 16777216; // 16M elements -> ~128MB of input (double: 8B * 16M), targets ~0.01s on modern CPUs

    v = (double*)aligned_alloc(32, n * sizeof(double));
    bp = (int16*)aligned_alloc(32, n * sizeof(int16));

    if (!v || !bp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (uint32 idx = 0; idx < n; idx++) {
        v[idx] = (double)(idx % 30000); // Populate with small double values within int16 range
    }
}