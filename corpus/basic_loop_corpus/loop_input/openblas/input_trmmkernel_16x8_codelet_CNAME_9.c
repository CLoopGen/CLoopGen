#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG k;
float *ptrba;
float *ptrbb;
float res0_0 = 0.0f;
float res0_1 = 0.0f;
float res0_2 = 0.0f;
float res0_3 = 0.0f;
float res1_0 = 0.0f;
float res1_1 = 0.0f;
float res1_2 = 0.0f;
float res1_3 = 0.0f;
float a0;
float a1;
float b0;
float b1;
BLASLONG temp;

static float *alloc_ptrba = NULL;
static float *alloc_ptrbb = NULL;

void init_vars() {
    const size_t size_a = 64 * 1024;     
    const size_t size_b = 32 * 1024;      
    const BLASLONG iterations = 8192;

    alloc_ptrba = (float*)calloc(size_a, sizeof(float));
    alloc_ptrbb = (float*)calloc(size_b, sizeof(float));

    if (!alloc_ptrba || !alloc_ptrbb) {
        exit(1);
    }

    ptrba = alloc_ptrba;
    ptrbb = alloc_ptrbb;
    temp = iterations;

    for (size_t i = 0; i < size_a; i++) {
        alloc_ptrba[i] = 1.0f + (i % 7);
    }
    for (size_t i = 0; i < size_b; i++) {
        alloc_ptrbb[i] = 1.0f - (i % 5) * 0.1f;
    }

    res0_0 = res0_1 = res0_2 = res0_3 = 0.0f;
    res1_0 = res1_1 = res1_2 = res1_3 = 0.0f;
}