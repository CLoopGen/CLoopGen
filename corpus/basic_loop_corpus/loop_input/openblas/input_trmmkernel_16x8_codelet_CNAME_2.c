#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 16000;
BLASLONG bk = 1000;
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
float res0_8;
float res0_9;
float res0_10;
float res0_11;
float res0_12;
float res0_13;
float res0_14;
float res0_15;
float res1_0;
float res1_1;
float res1_2;
float res1_3;
float res1_4;
float res1_5;
float res1_6;
float res1_7;
float res1_8;
float res1_9;
float res1_10;
float res1_11;
float res1_12;
float res1_13;
float res1_14;
float res1_15;
float res2_0;
float res2_1;
float res2_2;
float res2_3;
float res2_4;
float res2_5;
float res2_6;
float res2_7;
float res2_8;
float res2_9;
float res2_10;
float res2_11;
float res2_12;
float res2_13;
float res2_14;
float res2_15;
float res3_0;
float res3_1;
float res3_2;
float res3_3;
float res3_4;
float res3_5;
float res3_6;
float res3_7;
float res3_8;
float res3_9;
float res3_10;
float res3_11;
float res3_12;
float res3_13;
float res3_14;
float res3_15;
float a0;
float a1;
float b0;
float b1;
float b2;
float b3;
BLASLONG off = 0;
BLASLONG temp;

static float bb_data[400000];
static float ba_data[16000000];
static float c0_data[160000];
static float c1_data[160000];
static float c2_data[160000];
static float c3_data[160000];

void init_vars() {
    bb = bb_data;
    C0 = c0_data;
    C1 = c1_data;
    C2 = c2_data;
    C3 = c3_data;
    ptrba = ba_data;
    ptrbb = bb;

    for (int i = 0; i < 400000; i++) {
        bb_data[i] = 1.0f;
    }
    for (int i = 0; i < 16000000; i++) {
        ba_data[i] = 1.0f;
    }
    for (int i = 0; i < 160000; i++) {
        c0_data[i] = 0.0f;
        c1_data[i] = 0.0f;
        c2_data[i] = 0.0f;
        c3_data[i] = 0.0f;
    }
}