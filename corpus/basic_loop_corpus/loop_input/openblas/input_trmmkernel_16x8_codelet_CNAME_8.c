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

static float data_ba[2097152] __attribute__((aligned(32)));
static float data_bb[524288] __attribute__((aligned(32)));

void init_vars() {
    ptrba = data_ba;
    ptrbb = data_bb;
    
    for (int i = 0; i < 2097152; i++) {
        data_ba[i] = (float)(i % 128) * 0.5f;
    }
    
    for (int i = 0; i < 524288; i++) {
        data_bb[i] = (float)((i + 1) % 64) * 0.25f;
    }
    
    temp = 65536;
    
    res0_0 = 0.0f;
    res0_1 = 0.0f;
    res0_2 = 0.0f;
    res0_3 = 0.0f;
    res0_4 = 0.0f;
    res0_5 = 0.0f;
    res0_6 = 0.0f;
    res0_7 = 0.0f;
    res1_0 = 0.0f;
    res1_1 = 0.0f;
    res1_2 = 0.0f;
    res1_3 = 0.0f;
    res1_4 = 0.0f;
    res1_5 = 0.0f;
    res1_6 = 0.0f;
    res1_7 = 0.0f;
}