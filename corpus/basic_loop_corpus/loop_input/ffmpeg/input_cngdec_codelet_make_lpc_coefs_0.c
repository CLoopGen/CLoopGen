#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

float *refl;
int order;
float *next;
float *cur;
int m;
int i;

void init_vars() {
    order = (TOTAL_ELEMENTS > 1000) ? 1000 : TOTAL_ELEMENTS;

    refl = (float*)aligned_alloc(32, order * sizeof(float));
    cur  = (float*)aligned_alloc(32, order * sizeof(float));
    next = (float*)aligned_alloc(32, order * sizeof(float));

    if (!refl || !cur || !next) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < order; idx++) {
        refl[idx] = 1.0f / (idx + 1);
        cur[idx]  = 0.5f;
        next[idx] = 0.0f;
    }
}