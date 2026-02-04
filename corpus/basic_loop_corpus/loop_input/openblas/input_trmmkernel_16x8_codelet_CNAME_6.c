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
    res0_0 = 0.0f;
    res1_0 = 0.0f;
    res2_0 = 0.0f;
    res3_0 = 0.0f;
    a0 = 0.0f;
    b0 = 0.0f;
    b1 = 0.0f;
    b2 = 0.0f;
    b3 = 0.0f;

    for (int i = 0; i < 65536; i++) {
        array_a[i] = 1.0f + i * 0.0001f;
    }

    for (int i = 0; i < 262144; i++) {
        array_b[i] = 1.0f - (i % 7) * 0.1f;
    }

    ptrba = array_a;
    ptrbb = array_b;
    temp = 65536;
}