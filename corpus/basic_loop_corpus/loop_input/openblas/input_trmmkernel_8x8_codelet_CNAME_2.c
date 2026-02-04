#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
BLASLONG off = 128;
BLASLONG temp;

void init_vars() {
    BLASLONG total_ba_size = bm * bk;
    BLASLONG total_bb_size = bk * bn;
    BLASLONG total_C_size = bm * ldc;

    ba = (float*)aligned_alloc(32, total_ba_size * sizeof(float));
    bb = (float*)aligned_alloc(32, total_bb_size * sizeof(float));
    C = (float*)aligned_alloc(32, total_C_size * sizeof(float));

    for (BLASLONG i = 0; i < total_ba_size; i++) {
        ba[i] = (float)((i % 100) * 0.01f);
    }
    for (BLASLONG i = 0; i < total_bb_size; i++) {
        bb[i] = (float)((i % 100) * 0.02f);
    }
    for (BLASLONG i = 0; i < total_C_size; i++) {
        C[i] = 0.0f;
    }

    i = 0;
    j = 0;
    k = 0;
    C0 = C;
    ptrba = ba;
    ptrbb = bb;
    res0_0 = 0.0f;
    res0_1 = 0.0f;
    res0_2 = 0.0f;
    res0_3 = 0.0f;
    res0_4 = 0.0f;
    res0_5 = 0.0f;
    res0_6 = 0.0f;
    res0_7 = 0.0f;
    a0 = 0.0f;
    a1 = 0.0f;
    b0 = 0.0f;
    temp = 0;
}