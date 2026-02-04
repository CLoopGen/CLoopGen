#include <stdio.h>

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
float res2_0 = 0.0f;
float res2_1 = 0.0f;
float res2_2 = 0.0f;
float res2_3 = 0.0f;
float res3_0 = 0.0f;
float res3_1 = 0.0f;
float res3_2 = 0.0f;
float res3_3 = 0.0f;
float a0;
float a1;
float b0;
float b1;
float b2;
float b3;
BLASLONG temp;

static float array_a[65536] __attribute__((aligned(32)));
static float array_b[65536] __attribute__((aligned(32)));

void init_vars() {
    ptrba = array_a;
    ptrbb = array_b;
    
    for (int i = 0; i < 65536; i++) {
        array_a[i] = 1.0f + (i % 7) * 0.1f;
        array_b[i] = 2.0f + (i % 5) * 0.1f;
    }
    
    temp = 16384;
    
    res0_0 = res0_1 = res0_2 = res0_3 = 0.0f;
    res1_0 = res1_1 = res1_2 = res1_3 = 0.0f;
    res2_0 = res2_1 = res2_2 = res2_3 = 0.0f;
    res3_0 = res3_1 = res3_2 = res3_3 = 0.0f;
}