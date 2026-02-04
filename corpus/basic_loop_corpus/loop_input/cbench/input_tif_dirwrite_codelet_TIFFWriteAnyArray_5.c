#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint32;
typedef unsigned short uint16;

uint32 n;
double *v;
int i;
uint16 *bp;

void init_vars() {
    n = 16777216; // 16M elements -> ~128MB for double array, ~32MB for uint16 array

    v = (double*)aligned_alloc(32, n * sizeof(double));
    bp = (uint16*)aligned_alloc(32, n * sizeof(uint16));

    if (!v || !bp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (uint32 idx = 0; idx < n; idx++) {
        v[idx] = (double)(idx % 65536);
    }
}