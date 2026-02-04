#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 128;
BLASLONG bn = 4;
BLASLONG bk = 64;
float alpha = 1.1f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 256;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *C1;
float *ptrba;
float *ptrbb;
float res0_0;
float res0_1;
float res0_2;
float res0_3;
float res1_0;
float res1_1;
float res1_2;
float res1_3;
float a0;
float a1;
float b0;
float b1;
BLASLONG off = 0;
BLASLONG temp;

static float ba_data[16384] __attribute__((aligned(32)));
static float bb_data[512] __attribute__((aligned(32)));
static float c_data[65536] __attribute__((aligned(32)));

void init_vars() {
    ba = ba_data;
    bb = bb_data;
    C = c_data;

    for (int idx = 0; idx < 16384; idx++) {
        ba_data[idx] = (float)(idx % 17) * 0.1f;
    }
    for (int idx = 0; idx < 512; idx++) {
        bb_data[idx] = (float)(idx % 19) * 0.05f;
    }
    for (int idx = 0; idx < 65536; idx++) {
        c_data[idx] = 0.0f;
    }

    i = 0;
    j = 0;
    k = 0;
    ptrba = NULL;
    ptrbb = NULL;
    C0 = NULL;
    C1 = NULL;
    res0_0 = 0.0f;
    res0_1 = 0.0f;
    res0_2 = 0.0f;
    res0_3 = 0.0f;
    res1_0 = 0.0f;
    res1_1 = 0.0f;
    res1_2 = 0.0f;
    res1_3 = 0.0f;
    a0 = 0.0f;
    a1 = 0.0f;
    b0 = 0.0f;
    b1 = 0.0f;
    temp = 0;
}