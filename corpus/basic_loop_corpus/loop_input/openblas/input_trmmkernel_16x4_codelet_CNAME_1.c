#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long BLASLONG;

BLASLONG bm = 32;
BLASLONG bn = 1;
BLASLONG bk = 64;
float alpha = 1.5f;
float *ba;
float *bb;
float *C;
BLASLONG ldc;
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
    ldc = 64;

    size_t ba_size = bm * bk * sizeof(float);
    size_t bb_size = bk * bn * sizeof(float);
    size_t c_size = ldc * bn * sizeof(float);

    ba = (float*)aligned_alloc(64, ba_size);
    bb = (float*)aligned_alloc(64, bb_size);
    C = (float*)aligned_alloc(64, c_size);

    if (!ba || !bb || !C) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < bm * bk; i++) {
        ba[i] = (float)((i % 100) * 0.01f);
    }
    for (size_t i = 0; i < bk * bn; i++) {
        bb[i] = (float)((i % 100) * 0.02f);
    }
    for (size_t i = 0; i < ldc * bn; i++) {
        C[i] = 0.0f;
    }

    ptrba = ba;
    ptrbb = bb;
    C0 = C;
}