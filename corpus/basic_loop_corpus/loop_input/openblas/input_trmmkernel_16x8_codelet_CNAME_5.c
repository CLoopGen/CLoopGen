#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG k;
float *ptrba;
float *ptrbb;
float res0_0 = 0.0f;
float res0_1 = 0.0f;
float res1_0 = 0.0f;
float res1_1 = 0.0f;
float res2_0 = 0.0f;
float res2_1 = 0.0f;
float res3_0 = 0.0f;
float res3_1 = 0.0f;
float a0;
float a1;
float b0;
float b1;
float b2;
float b3;
BLASLONG temp;

static float *alloc_ptrba;
static float *alloc_ptrbb;

void init_vars() {
    const size_t vector_size = (1 << 20); // ~8MB total data: 2^20 elements
    temp = vector_size / 2;

    alloc_ptrba = (float*)calloc(2 * vector_size, sizeof(float));
    alloc_ptrbb = (float*)calloc(4 * vector_size, sizeof(float));

    ptrba = alloc_ptrba;
    ptrbb = alloc_ptrbb;

    for (size_t i = 0; i < 2 * vector_size; i++) {
        alloc_ptrba[i] = 1.0f + (i * 0.1f);
    }
    for (size_t i = 0; i < 4 * vector_size; i++) {
        alloc_ptrbb[i] = 0.5f + (i * 0.05f);
    }

    res0_0 = res0_1 = 0.0f;
    res1_0 = res1_1 = 0.0f;
    res2_0 = res2_1 = 0.0f;
    res3_0 = res3_1 = 0.0f;
}