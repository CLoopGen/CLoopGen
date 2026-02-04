#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bn = 1;
BLASLONG bk = 1024;
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
float a0;
float a1;
float b0;
BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    ba = (float*)aligned_alloc(64, sizeof(float) * bk * bm);
    bb = (float*)aligned_alloc(64, sizeof(float) * bk * bn);
    C = (float*)aligned_alloc(64, sizeof(float) * ldc * bn);

    for (BLASLONG idx = 0; idx < bk * bm; idx++) {
        ba[idx] = (float)(idx % 128) / 64.0f;
    }
    for (BLASLONG idx = 0; idx < bk * bn; idx++) {
        bb[idx] = (float)(idx % 128) / 64.0f;
    }
    for (BLASLONG idx = 0; idx < ldc * bn; idx++) {
        C[idx] = 0.0f;
    }
}