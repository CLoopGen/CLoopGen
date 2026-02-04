#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef float INTFLOAT;
typedef float UINTFLOAT;

INTFLOAT *dst;
INTFLOAT (*src)[2];
int n = 1 << 24; // Approximately 64 million elements, ~256MB total data
int i;

void init_vars() {
    dst = (INTFLOAT*)aligned_alloc(32, n * sizeof(INTFLOAT));
    src = (INTFLOAT(*)[2])aligned_alloc(32, n * 2 * sizeof(INTFLOAT));

    for (int idx = 0; idx < n; idx++) {
        dst[idx] = (INTFLOAT)(idx % 100);
        src[idx][0] = (INTFLOAT)(1.0f + idx) / (1.0f + idx * 0.1f);
        src[idx][1] = (INTFLOAT)(0.5f + idx * 0.05f) / (1.0f + idx * 0.01f);
    }
}