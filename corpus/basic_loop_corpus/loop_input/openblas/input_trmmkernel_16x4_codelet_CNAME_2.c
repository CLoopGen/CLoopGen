#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 16000;
BLASLONG bk = 100;
float alpha = 1.5f;
float *bb;
float *C0;
float *C1;
float *ptrba;
float *ptrbb;
BLASLONG i;
BLASLONG k;
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
float a0;
float a1;
float b0;
float b1;
BLASLONG off = 0;
BLASLONG temp;

static float bb_data[200] __attribute__((aligned(32)));
static float C0_data[256000] __attribute__((aligned(32)));
static float C1_data[256000] __attribute__((aligned(32)));
static float ptrba_data[2560000] __attribute__((aligned(32)));

void init_vars() {
    bb = bb_data;
    C0 = C0_data;
    C1 = C1_data;
    ptrba = ptrba_data;
    ptrbb = bb;

    for (int i = 0; i < 200; i++) {
        bb_data[i] = 1.0f;
    }
    for (int i = 0; i < 256000; i++) {
        C0_data[i] = 0.0f;
        C1_data[i] = 0.0f;
    }
    for (int i = 0; i < 2560000; i++) {
        ptrba_data[i] = 1.0f;
    }
}