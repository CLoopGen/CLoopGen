#include <stdio.h>

typedef long BLASLONG;

BLASLONG k;
float *ptrba;
float *ptrbb;
float res0_0 = 0.0f;
float res0_1 = 0.0f;
float res0_2 = 0.0f;
float res0_3 = 0.0f;
float res0_4 = 0.0f;
float res0_5 = 0.0f;
float res0_6 = 0.0f;
float res0_7 = 0.0f;
float res1_0 = 0.0f;
float res1_1 = 0.0f;
float res1_2 = 0.0f;
float res1_3 = 0.0f;
float res1_4 = 0.0f;
float res1_5 = 0.0f;
float res1_6 = 0.0f;
float res1_7 = 0.0f;
float a0;
float a1;
float b0;
float b1;
BLASLONG temp;

static float array_b[256 * 1024] __attribute__((aligned(32)));
static float array_a[8 * 256 * 1024] __attribute__((aligned(32)));

void init_vars() {
    for (int i = 0; i < 256 * 1024; i++) {
        array_b[i] = (float)(i % 128) / 64.0f;
    }
    for (int i = 0; i < 8 * 256 * 1024; i++) {
        array_a[i] = (float)(i % 256) / 128.0f;
    }

    ptrba = array_a;
    ptrbb = array_b;
    temp = 256 * 1024 / 2;

    res0_0 = res0_1 = res0_2 = res0_3 = res0_4 = res0_5 = res0_6 = res0_7 = 0.0f;
    res1_0 = res1_1 = res1_2 = res1_3 = res1_4 = res1_5 = res1_6 = res1_7 = 0.0f;
}