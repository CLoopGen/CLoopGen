#include <stdio.h>

typedef long BLASLONG;

BLASLONG k;
float *ptrba;
float *ptrbb;
float res0_0;
float res0_1;
float res1_0;
float res1_1;
float a0;
float a1;
float b0;
float b1;
BLASLONG temp;

static float array_a[65536] __attribute__((aligned(32)));
static float array_b[65536] __attribute__((aligned(32)));

void init_vars() {
    ptrba = array_a;
    ptrbb = array_b;
    temp = 32768; 

    res0_0 = 0.0f;
    res0_1 = 0.0f;
    res1_0 = 0.0f;
    res1_1 = 0.0f;
    a0 = 0.0f;
    a1 = 0.0f;
    b0 = 0.0f;
    b1 = 0.0f;
    k = 0;

    for (int i = 0; i < 65536; i++) {
        array_a[i] = 1.0f + (i % 7) * 0.1f;
        array_b[i] = 1.5f + (i % 5) * 0.2f;
    }
}