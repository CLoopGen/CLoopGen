#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bn = 2;
BLASLONG bk = 512;
float alpha = 1.5f;
float *ba;
float *bb;
float *C;
BLASLONG ldc = 1024;
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
float a0;
float a1;
float b0;
BLASLONG off = 0;
BLASLONG temp;

static float ba_data[1024 * 512] __attribute__((aligned(32)));
static float bb_data[2 * 512] __attribute__((aligned(32)));
static float C_data[1024 * 1024] __attribute__((aligned(32)));

void init_vars() {
    ba = ba_data;
    bb = bb_data;
    C = C_data;
    ldc = 1024;
    bm = 1024;
    bn = 2;
    bk = 512;
    alpha = 1.5f;
    off = 0;

    for (int i = 0; i < 1024 * 512; i++) {
        ba_data[i] = (float)(i % 128) / 64.0f;
    }
    for (int i = 0; i < 2 * 512; i++) {
        bb_data[i] = (float)(i % 128) / 64.0f;
    }
    for (int i = 0; i < 1024 * 1024; i++) {
        C_data[i] = 0.0f;
    }
}