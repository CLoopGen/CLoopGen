#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 1024;
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

static float ba_data[256 * 256] __attribute__((aligned(32)));
static float bb_data[256 * 1024] __attribute__((aligned(32)));
static float C_data[256 * 1024] __attribute__((aligned(32)));

void init_vars() {
    ba = ba_data;
    bb = bb_data;
    C = C_data;

    for (int idx = 0; idx < 256 * 256; idx++) {
        ba_data[idx] = (float)(idx % 128) * 0.01f;
    }
    for (int idx = 0; idx < 256 * 1024; idx++) {
        bb_data[idx] = (float)(idx % 256) * 0.005f;
    }
    for (int idx = 0; idx < 256 * 1024; idx++) {
        C_data[idx] = 0.0f;
    }
}