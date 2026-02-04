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
float a0;
float a1;
float b0;
float b1;
BLASLONG temp;

static float array_a[65536] __attribute__((aligned(32)));
static float array_b[32768] __attribute__((aligned(32)));

void init_vars() {
    ptrba = array_a;
    ptrbb = array_b;
    
    for (int i = 0; i < 65536; i++) {
        array_a[i] = (float)(i % 128) * 0.5f;
    }
    
    for (int i = 0; i < 32768; i++) {
        array_b[i] = (float)(i % 64) * 0.25f;
    }
    
    res0_0 = 0.0f;
    res0_1 = 0.0f;
    res0_2 = 0.0f;
    res0_3 = 0.0f;
    res1_0 = 0.0f;
    res1_1 = 0.0f;
    res1_2 = 0.0f;
    res1_3 = 0.0f;
    
    temp = 16384;
}