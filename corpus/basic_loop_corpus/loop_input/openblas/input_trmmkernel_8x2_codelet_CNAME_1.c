#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG bm = 1024;
BLASLONG bn = 2;
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
float a0;
float a1;
float b0;
BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    ba = (float*)aligned_alloc(32, sizeof(float) * bk * bm);
    bb = (float*)aligned_alloc(32, sizeof(float) * bk * bn);
    C = (float*)aligned_alloc(32, sizeof(float) * bm * ldc);

    for (long idx = 0; idx < bk * bm; idx++) {
        ba[idx] = (float)(idx % 100) / 100.0f;
    }
    for (long idx = 0; idx < bk * bn; idx++) {
        bb[idx] = (float)(idx % 100) / 50.0f;
    }
    for (long idx = 0; idx < bm * ldc; idx++) {
        C[idx] = 0.0f;
    }
}