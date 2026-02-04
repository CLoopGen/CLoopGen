#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 1;
BLASLONG bk = 256;
float alpha = 1.1f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 256;
BLASLONG i;
BLASLONG j;
BLASLONG k;
float *C0;
float *ptrba;
float *ptrbb;
float res0_0;
float res0_1;
float res0_2;
float res0_3;
float res0_4;
float res0_5;
float res0_6;
float res0_7;
float a0;
float a1;
float b0;
BLASLONG off = 0;
BLASLONG temp;

static float ba_data[256 * 256] __attribute__((aligned(32)));
static float bb_data[256 * 1] __attribute__((aligned(32)));
static float c_data[256 * 256] __attribute__((aligned(32)));

void init_vars() {
    ba = ba_data;
    bb = bb_data;
    C = c_data;

    for (int i = 0; i < 256 * 256; i++) {
        ba_data[i] = (float)(i % 100) * 0.01f;
    }
    for (int i = 0; i < 256; i++) {
        bb_data[i] = (float)(i % 50) * 0.02f;
    }
    for (int i = 0; i < 256 * 256; i++) {
        c_data[i] = 0.0f;
    }
}