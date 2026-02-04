#include <stdio.h>

typedef long BLASLONG;

BLASLONG k;
float *ptrba;
float *ptrbb;
float res0_0;
float res1_0;
float res2_0;
float res3_0;
float a0;
float b0;
float b1;
float b2;
float b3;
BLASLONG temp;

static float array_a[65536];
static float array_b[262144]; // 65536 * 4

void init_vars() {
    // Initialize accumulators to zero
    res0_0 = 0.0f;
    res1_0 = 0.0f;
    res2_0 = 0.0f;
    res3_0 = 0.0f;

    // Set up data size: aim for ~65536 iterations to target ~0.01 sec runtime
    temp = 65536;

    // Initialize input arrays with non-zero values to make computation meaningful
    for (BLASLONG i = 0; i < temp; i++) {
        array_a[i] = 1.0f + (i & 0xFF) * 0.01f;
    }
    for (BLASLONG i = 0; i < temp * 4; i++) {
        array_b[i] = 1.0f + ((i >> 2) & 0xFF) * 0.02f;
    }

    // Initialize pointers
    ptrba = array_a;
    ptrbb = array_b;
}