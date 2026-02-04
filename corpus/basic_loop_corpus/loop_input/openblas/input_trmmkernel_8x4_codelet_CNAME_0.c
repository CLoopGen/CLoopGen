#include <stdio.h>

typedef long BLASLONG;

BLASLONG bm = 256;
BLASLONG bn = 256;
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
float *C2;
float *C3;
float *ptrba;
float *ptrbb;

float res0_0, res0_1, res0_2, res0_3, res0_4, res0_5, res0_6, res0_7;
float res1_0, res1_1, res1_2, res1_3, res1_4, res1_5, res1_6, res1_7;
float res2_0, res2_1, res2_2, res2_3, res2_4, res2_5, res2_6, res2_7;
float res3_0, res3_1, res3_2, res3_3, res3_4, res3_5, res3_6, res3_7;

float a0, a1, b0, b1, b2, b3;

BLASLONG off = 0;
BLASLONG temp;

void init_vars() {
    ba = (float*)__builtin_malloc(bk * bm * sizeof(float));
    bb = (float*)__builtin_malloc(bk * bn * sizeof(float));
    C = (float*)__builtin_malloc(ldc * bn * sizeof(float));

    for (int i = 0; i < bk * bm; i++) {
        ba[i] = (float)(i % 100) / 100.0f;
    }
    for (int i = 0; i < bk * bn; i++) {
        bb[i] = (float)(i % 100) / 100.0f;
    }
    for (int i = 0; i < ldc * bn; i++) {
        C[i] = 0.0f;
    }

    ptrba = ba;
    ptrbb = bb;
}