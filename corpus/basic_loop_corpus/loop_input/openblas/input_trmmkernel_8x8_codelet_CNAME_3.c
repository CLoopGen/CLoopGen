#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bk = 256;
float alpha = 1.5f;
float *bb;
BLASLONG i;
BLASLONG k;
float *C0;
float *C1;
float *C2;
float *C3;
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
float res1_0;
float res1_1;
float res1_2;
float res1_3;
float res1_4;
float res1_5;
float res1_6;
float res1_7;
float res2_0;
float res2_1;
float res2_2;
float res2_3;
float res2_4;
float res2_5;
float res2_6;
float res2_7;
float res3_0;
float res3_1;
float res3_2;
float res3_3;
float res3_4;
float res3_5;
float res3_6;
float res3_7;
float a0;
float a1;
float b0;
float b1;
float b2;
float b3;
BLASLONG off = 0;
BLASLONG temp;

static float bb_data[1024 * 256];
static float ba_data[8 * 1024 * 32];
static float c0_data[8 * 1024];
static float c1_data[8 * 1024];
static float c2_data[8 * 1024];
static float c3_data[8 * 1024];

void init_vars() {
    bb = bb_data;
    C0 = c0_data;
    C1 = c1_data;
    C2 = c2_data;
    C3 = c3_data;
    ptrba = ba_data;
    ptrbb = bb_data;

    for (int i = 0; i < 1024 * 256; i++) {
        bb_data[i] = 1.0f + (i & 1) * 0.1f;
    }
    for (int i = 0; i < 8 * 1024 * 32; i++) {
        ba_data[i] = 1.0f - (i & 1) * 0.2f;
    }
    for (int i = 0; i < 8 * 1024; i++) {
        c0_data[i] = 0.0f;
        c1_data[i] = 0.0f;
        c2_data[i] = 0.0f;
        c3_data[i] = 0.0f;
    }
}