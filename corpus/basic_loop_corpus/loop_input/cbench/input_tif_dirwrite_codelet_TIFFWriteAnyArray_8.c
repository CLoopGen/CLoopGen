#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned int uint32;
typedef int int32;

uint32 n = 16777216; // 16M elements, ~128 MB of input data (double: 8 bytes * 2 arrays)

double *v;
int i;
int32 *bp;

void init_vars() {
    v = (double*)aligned_alloc(32, n * sizeof(double));
    bp = (int32*)aligned_alloc(32, n * sizeof(int32));

    for (uint32 i = 0; i < n; i++) {
        v[i] = (double)(i * 1.5);
    }
}