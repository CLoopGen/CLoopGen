#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef float INTFLOAT;

#define DATA_SIZE_MB 64
#define ELEMENTS_PER_MB (1024 * 1024 / sizeof(INTFLOAT))
#define N (DATA_SIZE_MB * ELEMENTS_PER_MB)

INTFLOAT (*dst)[2];
INTFLOAT (*src0)[2];
INTFLOAT *src1;
int n = N;
int i;

void init_vars() {
    dst = aligned_alloc(32, n * 2 * sizeof(INTFLOAT));
    src0 = aligned_alloc(32, n * 2 * sizeof(INTFLOAT));
    src1 = aligned_alloc(32, n * sizeof(INTFLOAT));

    for (int idx = 0; idx < n; idx++) {
        src0[idx][0] = 1.0f + idx * 0.0001f;
        src0[idx][1] = 2.0f + idx * 0.0002f;
        src1[idx] = 0.5f + idx * 0.00005f;
        dst[idx][0] = 0.0f;
        dst[idx][1] = 0.0f;
    }
}