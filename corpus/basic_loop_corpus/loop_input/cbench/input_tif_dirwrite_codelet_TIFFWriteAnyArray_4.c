#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef unsigned int uint32;
typedef signed char int8;

uint32 n;
double *v;
int i;
int8 *bp;

void init_vars() {
    n = 16777216; // 16M elements, ~128MB for double array, ~16MB for int8 array

    v = (double *)aligned_alloc(32, n * sizeof(double));
    bp = (int8 *)aligned_alloc(32, n * sizeof(int8));

    if (!v || !bp) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize v with non-zero values to ensure meaningful conversion
    for (uint32 idx = 0; idx < n; idx++) {
        v[idx] = (double)(idx % 256);
    }

    // Initialize bp to zero to ensure defined state before loop
    memset(bp, 0, n * sizeof(int8));
}