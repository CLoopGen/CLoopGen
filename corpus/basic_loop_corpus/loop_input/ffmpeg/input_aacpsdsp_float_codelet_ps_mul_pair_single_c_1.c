#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef float INTFLOAT;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(INTFLOAT))
#define N (DATA_SIZE_MB * ELEMENTS_PER_MB)

INTFLOAT (*dst)[2];
INTFLOAT (*src0)[2];
INTFLOAT *src1;
int n;
int i;

void init_vars() {
    n = N;

    dst = aligned_alloc(32, sizeof(INTFLOAT) * n * 2);
    src0 = aligned_alloc(32, sizeof(INTFLOAT) * n * 2);
    src1 = aligned_alloc(32, sizeof(INTFLOAT) * n);

    for (int idx = 0; idx < n; idx++) {
        src0[idx][0] = 1.0f + idx % 7;
        src0[idx][1] = 2.0f + idx % 5;
        src1[idx] = 0.5f + idx % 3;
        dst[idx][0] = 0.0f;
        dst[idx][1] = 0.0f;
    }
}